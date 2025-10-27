#include <iostream>
#include <vector>

// �ٽ�  : template method ����

// ��� Ŭ������ ������ ���� ��ü���� �帧�� ���� �Լ��� �����ϴ� ��(public, non-virtual)
// ���ؾ� �ϴ� �κи� �����Լ���(protected �Ǵ� private, virtual) �����ؼ�
// => �Ļ�Ŭ�������� ���ϴ� �κи� ���� �Ҽ� �ֵ��� ������ �ϴ°�
// => ���� �θ� ���Ǵ� ����.

// ���뼺���� "������"�� �и��ϴ� ��



class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }


	// ���뼺�� �������� �и�
	// => ������ ���� �ڵ� ���ο� �ִ� "���ؾ� �ϴ� �ڵ�" �� �и��Ǿ���Ѵ�.
	// => ���ϴ� �ڵ�� "������ �����Լ�"�� �и�

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
			std::cout << "���° ���� ������ �����ұ�� >> ";

			int k = 0;
			std::cin >> k;
			v.push_back(v[k]->clone()); 
		}
	}
}


