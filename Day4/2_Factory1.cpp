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
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

// 도형을 생성하는 공장
// => 새로운 도형이 추가되면 "공장"은 수정(case 추가) 되어야 합니다.
// => 외부에서 직접 만들면 새로운 도형 추가시 "여러곳" 이수정될수 있습니다.
// => 하지만 공장을 사용하면 한곳(공장)만 수정하면 됩니다.
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

		if (cmd >= 1 && cmd <= 8) // 1 ~ 8 번을 도형 번호로 예약
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




