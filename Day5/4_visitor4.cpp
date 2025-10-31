#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// std::list : 모든 요소의 타입이 동일. 선형구조.   iterator 있음.
// 메뉴예제   : 요소의 타입이 다름.     tree 구조   iterator 없음. 

// 일반적으로 "visitor" 패턴은
// => 요소들의 타입이 다를때 사용하는 기술입니다.
// => 모든 요소가 동일한경우는 거의 사용되지 않습니다.

class PopupMenu;
class MenuItem;

struct IMenuVisitor
{
	virtual void visit(PopupMenu* pm) = 0;
	virtual void visit(MenuItem* pm) = 0;
	
	// 아래 처럼해도 되지만
	// => 이경우 PopupMenu/MenuItem 모두 이곳으로 전달
	// => 이안에서 다시 조사하는 코드 필요
	// virtual void visit(BaseMenu* pm) = 0;


	virtual ~IMenuVisitor() {}
};





class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }

	void set_title(const std::string& s) { title = s; }


	virtual void command() = 0;

	virtual void accept(IMenuVisitor* visitor) = 0;
};


class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void accept(IMenuVisitor* visitor)
	{
		// MenuItem 은 자식 없습니다.
		// 아래 코드면 됩니다.
		visitor->visit(this); // this 의 타입 MenuItem*
	}

	void command() override
	{
		std::cout << get_title() << " 메뉴가 선택됨" << std::endl;
		_getch();
	}
};

class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	// 아래 코드가 방문자 핵심
	// => 방문자 객체가 "Popup"에 도착할때를 생각하세요
	void accept(IMenuVisitor* visitor)
	{
		// #1. 자신을 방문자에 전달
		visitor->visit(this);// this 의 타입 PopupMenu*


		// #2. 자신의 자식 메뉴도 방문자에 전달하면 안됩니다.
		/*
		for (auto m : v)
			visitor->visit(m);
		*/
		// #2. 방문자를 자식에게도 방문 시킵니다.
		for (auto m : v)
		{
			m->accept(visitor);
		}


	}





	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command() override
	{
		while (1)
		{
			system("cls");

			int sz = v.size();

			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}

			std::cout << sz + 1 << ". 종료" << std::endl;

			int cmd;
			std::cout << "메뉴를 선택하세요 >> ";
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1)
				break;

			v[cmd - 1]->command(); 
		}

	}

};



// 방문하는 메뉴의 타이틀을 수정하는 방문자
class TitleChangeVisitor : public IMenuVisitor
{
	std::string pm_tag;
	std::string mi_tag;
public:
	TitleChangeVisitor(const std::string& s1, const std::string& s2)
		: pm_tag(s1), mi_tag(s2) {
	}

	void visit(PopupMenu* pm) override
	{
		std::string s = pm->get_title();
		s = s + pm_tag; // "해상도>"
		pm->set_title(s);
	}
	void visit(MenuItem* pm)
	{
		std::string s = pm->get_title();
		s = s + mi_tag;
		pm->set_title(s);
	}
};




int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->add_menu(pm1);
	root->add_menu(pm2);


	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));

	TitleChangeVisitor tv(" >", " *"); // 타이틀을 수정하는 방문자
	root->accept(&tv);				 // 방문자를 root 메뉴에 넣기

	root->command();

}




