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
				// �ذ�å #1. ĳ����
				// => ��, ���縦 ���� �ؾ��Ѵ�.
				// => dynamic_cast

				// C++17 ���� ���γ��� if ��
				if (Rect* rc = dynamic_cast<Rect*>(s); rc != nullptr)
				{
					rc->draw();
				}	// <== rc �ı�.. 

				else if (Circle* c = dynamic_cast<Circle*>(s); c != nullptr)
				{
					c->draw();
				}
			}
		}
	}
}



// �� �ڵ�� "OCP" ���� �Դϴ�.
// => ���� ���� ������
// => dynamic_cast �� ��κ� OCP ���� �Դϴ�.
// => �ǵ��� ������� ������.
// 
// => ��� Ȯ�忡�� �����ְ�(Open, ���߿� ���ο� Ŭ����/����� �߰��Ǿ)
// => �ڵ� �������� �����־��(Close, ���� �ڵ�� �������� �ʵ���)
// => ������ �Ѵٴ� �̷�(Principle)

// => Open Close Principle(���� ����� ��Ģ)

// ��ü ���� �������� 5�� ��Ģ 
// => SRP, OCP, LSP, ISP, DIP  => ���ڷ� SOLID