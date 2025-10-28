#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// C 언어 학습시 : 메모리 구조를 이해하기 위해 메모리 그림을 그리게 됩니다.
// 객체지향 설계 : 클래스 구조를 이해하려면 "클래스 Diagram" 을 그리세요




class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() { return title; }

	// 모든 메뉴는 "선택" 될수 있다.
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
	std::vector<BaseMenu*> v; // <===  핵심 !!!!
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
};











int main()
{
	MenuItem m1("참치 김밥", 11);
	MenuItem m2("소고기 김밥", 12);

	MenuItem m9("라면", 21);

	PopupMenu kimbab("김밥류");
	kimbab.add(&m1);
	kimbab.add(&m2);

	PopupMenu pm("오늘의 점심 메뉴");
	pm.add(&kimbab); 
	pm.add(&m9); 


	pm.command();
}




