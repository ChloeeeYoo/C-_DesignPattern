#include <iostream>
#include <vector>

// ���� ���� Ŭ����
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

	// �����Լ�     : �Ļ� Ŭ�������� override ���� ������ "�⺻��������"
	// ���������Լ� : �Ļ� Ŭ�������� �ݵ�� ������ �����ϴ� ��

	// #1. draw()
//	virtual void draw_imp()	{std::cout << "draw Shape\n"; }
	virtual void draw_imp() = 0;

public:
	// #2. clone	
	// => ���� �����Լ��� �ص� ����
	// virtual Shape* clone() = 0;
	// 
	// => �Ʒ� ó�� �ϴ� ����� ����.
	// => �⺻ ������ �����ϴµ�, �⺻ �������� ���� �߻�.
	// 1. �ٽ� ������ �ʰ� ����ϸ� ����(������ ����)
	// 2. �ٽ� ������ �ʰ�, ��������� ������ ok
	// 3. �ٽ� �����, ����ϸ� ok. 
	virtual Shape* clone() { throw unsupported_operation(); }


	// #3. get_area()
	// => ���� �����Լ��� ����
	// => �� ó�� ���� �߻��� ����..
	// => �Ʒ� ó�� C ��Ÿ�ϵ� ����		
	// => �⺻ �������� ���з� ��ӵ� ��ӵ� ��ȯ
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
			std::cout << "���° ���� ������ �����ұ�� >> ";

			int k = 0;
			std::cin >> k;
			v.push_back(v[k]->clone());
		}
	}
}


