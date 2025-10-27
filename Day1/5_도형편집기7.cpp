#include <iostream>
#include <vector>

// 예외 전용 클래스
class unsupported_operation {};


class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }

	void draw()
	{
		std::cout << "mutex.lock\n";
		draw_imp()
			std::cout << "mutex.unlock\n";
	}

protected:

	// 가상함수     : 파생 클래스에서 override 하지 않으면 "기본구현제공"
	// 순수가상함수 : 파생 클래스에게 반드시 만들라고 지시하는 것

	// #1. draw()
//	virtual void draw_imp()	{std::cout << "draw Shape\n"; }
	virtual void draw_imp() = 0;

public:
	// #2. clone	
	// => 순수 가상함수로 해도 좋고
	// virtual Shape* clone() = 0;
	// 
	// => 아래 처럼 하는 기술도 있음.
	// => 기본 구현을 제공하는데, 기본 구현에서 예외 발생.
	// 1. 다시 만들지 않고 사용하면 예외(비정상 종료)
	// 2. 다시 만들지 않고, 사용하지도 않으면 ok
	// 3. 다시 만들고, 사용하면 ok. 
	virtual Shape* clone() { throw unsupported_operation(); }


	// #3. get_area()
	// => 순수 가상함수도 좋고
	// => 위 처럼 예외 발생도 좋다..
	// => 아래 처럼 C 스타일도 가능		
	// => 기본 구현에서 실패로 약속된 약속된 반환
	virtual int get_area() { return -1; }
};









class Rect : public Shape
{
protected:
	void draw_imp() { std::cout << "draw rect\n"; }

public:
	virtual Shape* clone() { return new Rect(*this); }

};

class Circle : public Shape
{
protected:
	void draw_imp() { std::cout << "draw circle\n"; }

public:
	virtual Shape* clone() { return new Circle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (true)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
			{
				s->draw();
			}
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 만든 도형을 복사할까요 >> ";

			int k = 0;
			std::cin >> k;
			v.push_back(v[k]->clone());
		}
	}
}


