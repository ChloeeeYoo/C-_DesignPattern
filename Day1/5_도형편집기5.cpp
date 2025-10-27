#include <iostream>
#include <vector>

// 핵심 #1. 디자인 패턴이란 ?
// => 1995년 발표된 책의 제목
// => 4명의 저자가 작성한 책
// => 당시 유명한 C++로 작성된 오픈소스를 분석해서,
//    공통으로 사용되는 기법에 "이름을 부여" 한것
// => 23개의 이름!
// => 남이 만든 코드를 "훔쳐서 이름만 붙였다" 는 의미로
//    4명의 갱단 이라고 합니다. "Gangs of Four"
//    "GOF's Design Pattern" 이라고 합니다.

// 핵심 #2. prototype 패턴
// => 복사본이 필요하면 clone() 가상함수를 사용하라는 것
// => 목요일에 좋은 예제 등장



class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }

	virtual void draw() { std::cout << "draw Shape\n"; }

	// 자신의 복사본을 만드는 가상함수는 아주 유용하게 활용됩니다.
	virtual Shape* clone()
	{
//		Shape* s = new Shape;
//		s->color = color;	// 모든 멤버를 나와 동일하게 설정
//		return s;

		// 복사생성자 사용하면 아래 한줄이 위와 동일!!
		return new Shape(*this);
	}
};


class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect\n"; }

	virtual Shape* clone() { return new Rect(*this); }

};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle\n"; }

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

			// k번째 만든 도형의 복제본을 만들어서 v에 추가
			// => 어떻게 구현해야 할까요 ?
			// => k번째 도형은 뭘까요 ?

			// 해결책 #1. 조사			
			// => OCP 를 만족할수 없는 좋지 않은 디자인 
			/*
			if (dynamic_cast<Rect*>(k) != nullptr)
			{
				// Rect 임. 복사해서 v에 추가
			}
			else if (dynamic_cast<Circle*>(k) != nullptr)
			{
				//....
			}
			*/

			// 해결책 #2. 다형성(가상함수) 사용
			// => k 번째 도형이 뭔지 알필요 없다.
			v.push_back(v[k]->clone()); // 다형성

			// java 진영에서 널리 사용되는 용어 입니다. 의미를 이해해 보세요

			// "Don't Ask Do It"
		}
	}
}


