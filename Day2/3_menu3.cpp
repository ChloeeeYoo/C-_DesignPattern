#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}

	std::string get_title() { return title; }

	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨\n";

		_getch(); 
	}
};

class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v; // 핵심
public:
	PopupMenu(const std::string& title) : title(title) {}

	void add(MenuItem* m) { v.push_back(m); }

	// 핵심 :  팝업메뉴 선택시 동작
	void command()
	{
		while (true)
		{
			system("cls"); // 화면 지우기


			auto sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". 종료\n";

			std::cout << "메뉴를 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1) // 종료 선택
				break;

			if (cmd < 0 || cmd > sz + 1) // 잘못된 입력
				continue ;

			
			v[cmd - 1]->command(); // 선택한 메뉴 실행.

		}

	}
};











int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	PopupMenu pm("오늘의 점심 메뉴");
	pm.add(&m1);
	pm.add(&m2);
	pm.command();  // 팝업 메뉴 선택시 동작을 생각해 보세요
}




