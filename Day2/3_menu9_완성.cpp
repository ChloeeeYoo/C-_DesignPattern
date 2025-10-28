// 3_menu9_완성.cpp

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

	~PopupMenu()
	{
		for (auto m : v)
			delete m;
	}



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

	using HANDLER = std::function<void()>; 

	std::vector<HANDLER> v;	

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
		for (auto f : v) 
			f();		 
	}
};

//-----------------------
// 테스트용 함수
void foo() { std::cout << "foo\n"; _getch(); }
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
	root->add(new MenuItem("관리자통보", 11, &foo));

	pm1->add(new MenuItem("RED", 21, std::bind(&goo, 21)));
	pm1->add(new MenuItem("GREEN", 22, std::bind(&goo, 22)));


	root->command();

	// 위 코드에서 모든 메뉴 객체는 new 로 만들었으므로 "delete" 필요 합니다.
	// 
	// 방법 #1. 스마트포인터(std::shared_ptr) 사용 - 복습시 해보세요
	// 방법 #2. root 만 제거하고
	//			PopupMenu 소멸자에서 자신이 포함한 메뉴 delete
	delete root;
}

