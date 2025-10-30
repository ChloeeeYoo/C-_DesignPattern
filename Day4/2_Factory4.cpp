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

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)();

	std::map<int, CREATOR> create_map;

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
			s = it->second();
		}

		return s;
	}
};

// ���忡 ������ ����Ҷ� ����� Ŭ����
class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*f)())
	{
		ShapeFactory::get_instance().register_shape(key, f);
	}
};

// ���������� �����ڴ� ���� ȣ��ɱ�� ?
// 1. ��� ���������� �����ڰ� ���� ȣ��ǰ�
// 2. main �Լ��� ����.
// AutoRegister ar(1, &Rect::create);








class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	// static ��� ����Ÿ�� Ư¡�� ������ ������
	// => Rect ��ü�� �Ѱ��� ������ �ʾƵ� static ��� ����Ÿ�� �����˴ϴ�.
	// => lifecycle �� �ᱹ ���������� �����մϴ�.
	// => ��, �Ʒ� ar�� �����ڴ� main �Լ� ������ ȣ��˴ϴ�
	// => ���忡 ����ϴ� �۾��� main �Լ� ������ Rect �� ������ �Ѱ�.
	inline static AutoRegister ar{ 1, &Rect::create };
};
/*
					 // Rect::ar ������ ȣ�� => ��, ��ü�� �ƴ� Ŭ������ ������
					 //						=> Rect ��� Ÿ�Կ� ���ؼ� 1ȸ �ʱ�ȭ ����			
Rect* r1 = new Rect; // Rect ������ ȣ��
Rect* r2 = new Rect; // Rect ������ ȣ��
Rect* r3 = new Rect; // Rect ������ ȣ��
					 // => "��, �����ڴ� ��ü�� 1ȸ ȣ��"

/*
// C# ���� "static ������" ��� ������ �ֽ��ϴ�.
class Car
{
	public Car() {} // ������
	static Car() {} // static ������
};

					// static �����ڰ� 1ȸ ȣ��
Car c1 = new Car(); // ������ ȣ��
Car c2 = new Car(); // ������ ȣ��
Car c3 = new Car(); // ������ ȣ��
*/




class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }

	inline static AutoRegister ar{ 2, &Circle::create };
};






int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

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




