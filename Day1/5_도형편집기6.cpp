#include <iostream>
#include <vector>

// 핵심  : template method 패턴

// 기반 클래스가 변하지 않은 전체적인 흐름을 담은 함수를 제공하는 데(public, non-virtual)
// 변해야 하는 부분만 가상함수로(protected 또는 private, virtual) 제공해서
// => 파생클래스에서 변하는 부분만 변경 할수 있도록 디자인 하는것
// => 가장 널리 사용되는 패턴.

// 공통성에서 "가변성"을 분리하는 것



class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }


	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 있는 "변해야 하는 코드" 는 분리되어야한다.
	// => 변하는 코드는 "별도의 가상함수"로 분리

protected:
	virtual void draw_imp()
	{
		std::cout << "draw Shape\n"; 
	}
public:
	void draw() 
	{ 
		std::cout << "mutex.lock\n";
		draw_imp()
		std::cout << "mutex.unlock\n";
	}


	virtual Shape* clone() 	{return new Shape(*this);	}
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


