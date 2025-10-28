#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class unsupported_operation {};

class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() { return title; }

	virtual void command() = 0;
	virtual void add(BaseMenu*) { throw unsupported_operation(); }
	virtual BaseMenu* submenu(int idx) { throw unsupported_operation(); }
};




class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add(BaseMenu* m) { v.push_back(m); }

	void command()
	{
		while (true)
		{
			system("cls");


			auto sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". ����\n";

			std::cout << "�޴��� �����ϼ��� >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 0 || cmd > sz + 1)
				continue;


			v[cmd - 1]->command();

		}
	}
	BaseMenu* submenu(int idx) { return v[idx]; }
};






class MenuItem : public BaseMenu
{
	int id;

	void(*handler)(); // �Լ� ������ ����ϸ�
					  // => ������ �ʹ� �����ϴ�.
					  // => signature �� ������ �Լ��� �����ϰ�
					  // => ��� �Լ��� �ȵ˴ϴ�.
					  // => �ذ�å... �������� ����.. 

public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		// �޴� ���ý� event ó���� ���⼭ �����ϸ�
		// => ��� ������ �޴��������� "������ �۾��� �ϰ� �˴ϴ�."

		// => �޴� �̺�Ʈ ó���� ���� �Լ��� ����ߴٰ�
		// => ��ϵ� �Լ��� ȣ���ؾ� �մϴ�.
		std::cout << get_title() << " �޴� ���õ�\n";

		_getch();
	}
};





int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("���󺯰�");

	root->add(pm1);
	root->add(new MenuItem("�������뺸", 11));

	pm1->add(new MenuItem("RED", 21));
	pm1->add(new MenuItem("GREEN", 22));


	root->command();

}
