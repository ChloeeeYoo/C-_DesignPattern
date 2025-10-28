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

	// 아래 2개는 PopupMenu 만 필요하고 MenuItem 에서는 필요 없습니다.
	// 그런데, 사용자가 캐스팅 없이 사용하기 위해서 BaseMenu 에서 제공
	virtual void add(BaseMenu*) { throw unsupported_operation(); }
	virtual BaseMenu* submenu(int idx) { throw unsupported_operation(); }

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
	
	// 해결책 #2. 캐스팅 없이 add 사용
	root->submenu(0)->add(new MenuItem("BLACK", 24)); // ok

	try
	{
		root->submenu(1)->add(new MenuItem("BLACK", 24)); // exeception 발생
		// 오류 처리하려면 try ~ catch 사용
	}
	catch (const unsupported_operation& e)
	{

	}

	root->command();

}

// menu7 : 안전성을 강조하는 모델(개발자가 명시적으로 캐스팅해라!!)
// menu8 : 편의성을 강조하는 모델(캐스팅 없이도 add 가능)