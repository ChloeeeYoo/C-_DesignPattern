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
		std::cout << get_title() << " 메뉴 선택됨\n";

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











int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상변경");

	root->add(pm1);
	root->add(new MenuItem("관리자통보", 11));

	pm1->add(new MenuItem("RED", 21));
	pm1->add(new MenuItem("GREEN", 22));
	//-----------------------------------------
	// #1. 하위 메뉴 얻기
	auto m1 = root->submenu(0);  // 색상 메뉴 반환


	// #2. 아래 코드를 생각해 봅시다.
	// root->submenu(0)->add(new MenuItem("BLACK", 24));
				// error.
				// root->submenu(0) 이 PopupMenu 인 "색상"메뉴가 맞지만
				// 반환 타입이 PopupMenu*가 아닌 BaseMenu* 타입 이므로.


	// 해결책 #1. 캐스팅
	static_cast<PopupMenu*>(root->submenu(0))->add(new MenuItem("BLACK", 24));

	root->command();

}

