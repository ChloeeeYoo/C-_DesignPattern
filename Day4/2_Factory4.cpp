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

// 공장에 도형을 등록할때 사용할 클래스
class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*f)())
	{
		ShapeFactory::get_instance().register_shape(key, f);
	}
};

// 전역변수의 생성자는 언제 호출될까요 ?
// 1. 모든 전역변수의 생성자가 먼저 호출되고
// 2. main 함수가 실행.
// AutoRegister ar(1, &Rect::create);








class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	// static 멤버 데이타의 특징을 생각해 보세요
	// => Rect 객체를 한개도 만들지 않아도 static 멤버 데이타는 생성됩니다.
	// => lifecycle 은 결국 전역변수와 동일합니다.
	// => 즉, 아래 ar의 생성자는 main 함수 이전에 호출됩니다
	// => 공장에 등록하는 작업을 main 함수 이전에 Rect 가 스스로 한것.
	inline static AutoRegister ar{ 1, &Rect::create };
};
/*
					 // Rect::ar 생성자 호출 => 즉, 객체가 아닌 클래스의 생성자
					 //						=> Rect 라는 타입에 대해서 1회 초기화 가능			
Rect* r1 = new Rect; // Rect 생성자 호출
Rect* r2 = new Rect; // Rect 생성자 호출
Rect* r3 = new Rect; // Rect 생성자 호출
					 // => "즉, 생성자는 객체당 1회 호출"

/*
// C# 에는 "static 생성자" 라는 문법이 있습니다.
class Car
{
	public Car() {} // 생성자
	static Car() {} // static 생성자
};

					// static 생성자가 1회 호출
Car c1 = new Car(); // 생성자 호출
Car c2 = new Car(); // 생성자 호출
Car c3 = new Car(); // 생성자 호출
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




