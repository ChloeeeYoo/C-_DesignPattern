#include <iostream>
#include <vector>

// 예외 전용 클래스
class unsupported_operation {};

// 코드 정리!!

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
	virtual void draw_imp() = 0;

public:
	virtual Shape* clone() { throw unsupported_operation(); }
	virtual int get_area() { return -1; }
};

class Rect : public Shape
{
protected:
	void draw_imp() override { std::cout << "draw rect\n"; }

public:
	// 가상함수 override 시에 
	// => 반환 타입 변경 가능합니다.
	// => 단, 상속관계타입으로만 됩니다.
	// => "공변 반환" 이라는 문법입니다.
	Rect* clone() override  { return new Rect(*this); }
};
// Rect* p = new Rect;
// auto p2 = p->clone();

class Circle : public Shape
{
protected:
	void draw_imp() override  { std::cout << "draw circle\n"; }

public:
	Circle* clone() override  { return new Circle(*this); }
};

int main()
{
	std::vector<Shape*> v;

	while (true)
	{
		int cmd;
		std::cin >> cmd;

		// 생각해볼 문제 #1. 객체의 생성 과정을 OCP 를 만족하게 할수 없을까 ?
		// => factory 패턴을 알면 됩니다. "목요일날!!"
		// 
		// 생각해볼 문제 #2. undo/redo 기능을 넣으려면 어떻게 해야 할까요 ?
		// => command 패턴을 알면 됩니다. "목요일 또는 내일"

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto s : v)
			{
				s->draw();	// 다형성. OCP 만족
			}
		}
		else if (cmd == 8)
		{
			std::cout << "몇번째 만든 도형을 복사할까요 >> ";

			int k = 0;
			std::cin >> k;
			v.push_back(v[k]->clone());	// 다형성. OCP 만족
		}
		else if (cmd == -1)
			break;
	}

	// new 로 생성한 도형 삭제
	// => 또는 스마트 포인터로
	for (auto s : v)
		delete s;
}


