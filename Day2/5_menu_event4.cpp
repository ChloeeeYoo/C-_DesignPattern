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
			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴를 선택하세요 >> ";

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

//	std::function<void()> handler; // 인자가 없는 함수를 등록가능
									// 그런데, std::bind()를 사용하면 
									// 결국 "모든 함수(멤버함수포함)" 등록가능

	using HANDLER = std::function<void()>; // typedef

	std::vector<HANDLER> v;	// 메뉴 선택시 호출될 함수를 보관하기 위한 vector

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
		for (auto f : v) // f는 function 이므로(인자없는 함수 보관)
			f();		 // 등록된 함수 호출
	}
};

//-----------------------
// 테스트용 함수
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
	PopupMenu* pm1 = new PopupMenu("색상변경");

	root->add(pm1);
	root->add(new MenuItem("관리자통보", 11, &foo ));

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
