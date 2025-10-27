#include <iostream>
#include <vector>

// ���� ���� Ŭ����
class unsupported_operation {};

// �ڵ� ����!!

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
	// �����Լ� override �ÿ� 
	// => ��ȯ Ÿ�� ���� �����մϴ�.
	// => ��, ��Ӱ���Ÿ�����θ� �˴ϴ�.
	// => "���� ��ȯ" �̶�� �����Դϴ�.
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

		// �����غ� ���� #1. ��ü�� ���� ������ OCP �� �����ϰ� �Ҽ� ������ ?
		// => factory ������ �˸� �˴ϴ�. "����ϳ�!!"
		// 
		// �����غ� ���� #2. undo/redo ����� �������� ��� �ؾ� �ұ�� ?
		// => command ������ �˸� �˴ϴ�. "����� �Ǵ� ����"

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);

		else if (cmd == 9)
		{
			for (auto s : v)
			{
				s->draw();	// ������. OCP ����
			}
		}
		else if (cmd == 8)
		{
			std::cout << "���° ���� ������ �����ұ�� >> ";

			int k = 0;
			std::cin >> k;
			v.push_back(v[k]->clone());	// ������. OCP ����
		}
		else if (cmd == -1)
			break;
	}

	// new �� ������ ���� ����
	// => �Ǵ� ����Ʈ �����ͷ�
	for (auto s : v)
		delete s;
}


