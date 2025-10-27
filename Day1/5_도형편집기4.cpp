#include <iostream>
#include <vector>

// 핵심 #1 모든 파생 클래스의 공통의 특징은 "반드시 기반 클래스에도 있어야 합니다."
// => 문법적인 제약이 아닌
// => 디자인의 원칙

// 핵심 #2. 멤버 함수중 파생 클래스가 다시 만들게 되는 것은
// => 대부분 "virtual" 로 해야 한다.

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	// 아래 함수는 virtual 로 할까요 ? non-virtual 로 할까요 ?
	// => 파생 클래스가 다시 만들필요 없습니다 - non-virtual
	// => virtual 로 해도 되지만 "virtual" 은 느립니다!!
	// => 다시 만들필요가 있을때만 virtual!!
	void set_color(int c) { color = c; }

	// 면적을 구하는 방법은 도형마다 다릅니다.
	// => virtual 로 하고.
	// => 파생 클래스에서 override 
	virtual int get_area() { return 0; }

	virtual void draw() { std::cout << "draw Shape\n"; }
};


class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect\n"; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle\n"; }
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
				s->draw();	// 다형성(polymorphism)
							// => 동일한 코드가 상황에 따라(실제 객체 종류)
							//    다르게 동작하는 것
							// OCP 를 만족하는 좋은 코딩 스타일!!!
				
				// 객체지향 언어의 3대 특징 : 캡슐화, 상속, 다형성
			}
		}
	}
}


