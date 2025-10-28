#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() { return title; }

	virtual void command() = 0;
};



class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		std::cout << get_title() << " �޴� ���õ�\n";

		_getch();
	}
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
};











int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("���󺯰�");
	PopupMenu* pm2 = new PopupMenu("�ػ󵵺���");

	root->add(pm1);
//	root->add(pm2);
	pm1->add(pm2);

	root->add(new MenuItem("�������뺸", 11));

	pm1->add(new MenuItem("RED",   21));
	pm1->add(new MenuItem("GREEN", 22));
	pm1->add(new MenuItem("BLUE",  23));
	pm1->add(new MenuItem("WHITE", 24));

	pm2->add(new MenuItem("HD",  31));
	pm2->add(new MenuItem("FHD", 32));
	pm2->add(new MenuItem("UHD", 33));

	// �� �ڵ�� �޴� ��ü�� ���� ���谡 "Tree" ������ ������ �˴ϴ�.
	// => Composite ������ Ư¡
	// ���� �޴��� �����Ϸ��� ??
	root->command();

}

// ��ü���� ���α׷����� �������� ���α׷��̶� ?
// 1. ��ü�� �����ϰ�
// 2. ��ü���� ���踦 �����ϰ�
// 3. ��ü���� �޼����� �ְ� �޴� �����̴�(������ ��� �Լ� ȣ��)
// 4. ���α׷��� �⺻ ������ "�Լ�"�� �ƴ� "Ŭ����" �̴�.

// ���� : ���������� ����, Ȯ�强�� �ִ�.

// ���� : ��ƴ�!!
//		  �޸𸮵� �����ɼ� �ְ�, C���� ������(�����Լ����� ���)



