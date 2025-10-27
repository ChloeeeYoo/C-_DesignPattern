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

int main()
{
	std::vector<Shape*> v;

	while (true)
	{
		int cmd;
		std::cin >> cmd;

		if      (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)	
				s->draw();	// A. s는 Shape* 인데, Shape 에는 draw()가 없다
		}
	}
}
// 위 코드는 에러가 있습니다.
// 어디에서 왜에러 일까요 ? 
// => A 부분에서 에러
// => s의 타입은 Shape* 인데, Shape* 에는 draw 가 없다.!!
// 해결책은 뭘까요 ?
// => 다음 소스에서

