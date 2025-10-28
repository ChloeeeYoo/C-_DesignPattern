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

	void(*handler)(); // 함수 포인터 사용하면
					  // => 제약이 너무 많습니다.
					  // => signature 가 동일한 함수만 가능하고
					  // => 멤버 함수도 안됩니다.
					  // => 해결책... 다음예제 부터.. 

public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command()
	{
		// 메뉴 선택시 event 처리를 여기서 직접하면
		// => 모든 종류의 메뉴아이템이 "동일한 작업을 하게 됩니다."

		// => 메뉴 이벤트 처리를 위한 함수을 등록했다가
		// => 등록된 함수를 호출해야 합니다.
		std::cout << get_title() << " 메뉴 선택됨\n";

		_getch();
	}
};





int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("색상변경");

	root->add(pm1);
	root->add(new MenuItem("관리자통보", 11));

	pm1->add(new MenuItem("RED", 21));
	pm1->add(new MenuItem("GREEN", 22));


	root->command();

}
