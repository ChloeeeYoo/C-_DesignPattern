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

	using CREATOR = Shape*(*)(); // CREATOR �� �Լ������� Ÿ��

	std::map<int, CREATOR> create_map; // (������ȣ, �����Լ�)�� ������ �ڷᱸ��

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
			s = it->second();	// �� �ݺ����� second �� value
								// ��, �����Լ�
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




