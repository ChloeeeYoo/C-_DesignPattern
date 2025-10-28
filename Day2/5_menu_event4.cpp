#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <functional>
using namespace std::placeholders; 

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

//	std::function<void()> handler; // ���ڰ� ���� �Լ��� ��ϰ���
									// �׷���, std::bind()�� ����ϸ� 
									// �ᱹ "��� �Լ�(����Լ�����)" ��ϰ���

	using HANDLER = std::function<void()>; // typedef

	std::vector<HANDLER> v;	// �޴� ���ý� ȣ��� �Լ��� �����ϱ� ���� vector

public:
	MenuItem(const std::string& title, int id, HANDLER h = nullptr)
		: BaseMenu(title), id(id)
	{
		if (h != nullptr)
			v.push_back(h);
	}

	void add_handler(HANDLER h) { v.push_back(h); }

	void command()
	{
		for (auto f : v) // f�� function �̹Ƿ�(���ھ��� �Լ� ����)
			f();		 // ��ϵ� �Լ� ȣ��
	}
};

//-----------------------
// �׽�Ʈ�� �Լ�
void foo()		 { std::cout << "foo\n"; _getch(); }
void goo(int id) { std::cout << "goo : " << id << "\n"; _getch(); }

class Dialog
{
public:
	void close(int exitcode) { printf("Dialog::close, %d\n", exitcode); _getch(); }
	void move(int x, int y) { printf("Dialog::move, %d, %d\n", x, y);  _getch(); }
};


int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("���󺯰�");

	root->add(pm1);
	root->add(new MenuItem("�������뺸", 11, &foo ));

	pm1->add(new MenuItem("RED", 21,   std::bind(&goo, 21) ));
	pm1->add(new MenuItem("GREEN", 22, std::bind(&goo, 22)));

	Dialog dlg;
	pm1->add(new MenuItem("Blue", 23,
					std::bind(&Dialog::close, &dlg, 23)));

	pm1->add(new MenuItem("WHITE", 24, 
					[]() { std::cout << "lambda\n"; _getch(); } ));

	static_cast<MenuItem*>(pm1->submenu(3))->add_handler(&foo);

	root->command();

}
