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

	static Shape* create() { return new Rect; }
};



class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	using CREATOR = Shape*(*)(); // CREATOR 는 함수포인터 타입

	std::map<int, CREATOR> create_map; // (도형번호, 생성함수)를 보관할 자료구조

public:
	void register_shape(int key, CREATOR c)
	{
		create_map[key] = c;
	}
	Shape* create(int key)
	{
		Shape* s = nullptr;
		
		auto it = create_map.find(key);

		if (it != create_map.end())
		{
			s = it->second();	// 맵 반복자의 second 는 value
								// 즉, 생성함수
		}

		return s;
	}
};



int main()
{
	std::vector<Shape*> v;
	
	ShapeFactory& factory = ShapeFactory::get_instance();

	// 공장에 제품(도형)을 등록합니다.
	// => 정확히는 도형 번호와 생성 함수를 등록
	factory.register_shape(1, &Rect::create);
	factory.register_shape(2, &Circle::create);


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




