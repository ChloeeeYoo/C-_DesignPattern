#include <iostream>
#include <vector>
#include <map>
#include "singleton.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	// 자기 자신을 만드는 "satic 멤버함수"는 아주 유용하게 사용되는 기술입니다.
	static Shape* create() { return new Rect; }
};

// Rect 객체를 만드는 2가지 방법
// 1. Rect* rc = new Rect;			// "Rect" 라는 클래스 이름을 알아야만 합니다.
// 2. Rect* rc = Rect::create();	// "Rect" 이름 몰라도, Rect::create 함수 주소만 알면 됩니다.
/*
// C++ 언어에서는 "클래스"를 자료구조에 보관할수 없습니다.
v.push_back("Rect"); // 이 코드는 "Rect" 라는 문자열을 보관한것
					 // 문자열 "Rect" 로는 Rect 객체 생성할수 없습니다.

// 하지만 "함수 포인터" 는 자료구조에 보관 가능합니다.
v.push_back(&Rect::create); // ok. 보관된 값으로 Rect 객체 생성도 가능.
							// 결국 도형을 만들기 위한 정보를 자료구조에 보관가능
							// 결국, "클래스"를 보관하는 것과 유사한 의미
*/





class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* create(int key)
	{
		Shape* s = nullptr;

		switch (key)
		{
		case 1: s = new Rect;   break;
		case 2: s = new Circle; break;
		}
		return s;
	}
};



int main()
{
	std::vector<Shape*> v;
	ShapeFactory& factory = ShapeFactory::get_instance();

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd >= 1 && cmd <= 8) 
		{
			Shape* s = factory.create(cmd);

			if (s != nullptr)
				v.push_back(s);
		}

		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}




