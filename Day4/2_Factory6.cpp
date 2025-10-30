#include <iostream>
#include <vector>
#include <map>
#include "singleton.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	virtual Shape* clone() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
	static Shape* create() { return new Rect; }

	Rect* clone() override { return new Rect(*this); }
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
	static Shape* create() { return new Circle; }

	Circle* clone() override { return new Circle(*this); }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> sample_map; 

public:
	void register_shape(int key, Shape* c)
	{
		sample_map[key] = c;
	}
	Shape* create(int key)
	{
		Shape* s = nullptr;

		auto it = sample_map.find(key);

		if (it != sample_map.end())
		{
			s = it->second->clone(); // sample �� ���纻�� ���� ��ȯ
		}

		return s;
	}
};



int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// ���忡 ��ǰ(����)�� ����մϴ�.
	// => ��Ȯ���� ���� ��ȣ�� ���� �Լ��� ���
	// => �Ʒ� �ڵ�� �ᱹ ���忡 "Ŭ����"�� ����ϴ� �����Դϴ�.
	// factory.register_shape(1, &Rect::create);
	// factory.register_shape(2, &Circle::create);

	// ���忡 ��ü�� ����� ���ô�.
	// => ���� ����ϴ� ������ �ߺ��� ���� ���忡 �ߺ��� ���
	Rect* red_rect = new Rect;  // ������, ũ�Ⱑ 10
	Rect* blue_rect = new Rect; // �Ķ���, ũ�Ⱑ 20
	Circle* red_circle = new Circle;

	factory.register_shape(1, red_rect);
	factory.register_shape(2, blue_rect);
	factory.register_shape(3, red_circle);


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




