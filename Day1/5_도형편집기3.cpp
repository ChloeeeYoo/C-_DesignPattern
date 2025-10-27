#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	virtual ~Shape() {}
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

class Triangle : public Shape
{
public:
	void draw() { std::cout << "draw triangle\n"; }
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
				// 해결책 #1. 캐스팅
				// => 단, 조사를 먼저 해야한다.
				// => dynamic_cast

				// C++17 에서 새로나온 if 문
				if (Rect* rc = dynamic_cast<Rect*>(s); rc != nullptr)
				{
					rc->draw();
				}	// <== rc 파괴.. 

				else if (Circle* c = dynamic_cast<Circle*>(s); c != nullptr)
				{
					c->draw();
				}
			}
		}
	}
}



// 위 코드는 "OCP" 위반 입니다.
// => 좋지 않은 디자인
// => dynamic_cast 는 대부분 OCP 위반 입니다.
// => 되도록 사용하지 마세요.
// 
// => 기능 확장에는 열려있고(Open, 나중에 새로운 클래스/모듈이 추가되어도)
// => 코드 수정에는 닫혀있어야(Close, 기존 코드는 수정되지 않도록)
// => 만들어야 한다는 이론(Principle)

// => Open Close Principle(개방 폐쇄의 법칙)

// 객체 지향 디자인의 5개 원칙 
// => SRP, OCP, LSP, ISP, DIP  => 약자로 SOLID