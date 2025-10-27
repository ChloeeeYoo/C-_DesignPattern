#include <iostream>
#include <vector>

// �ٽ� #1. ������ �����̶� ?
// => 1995�� ��ǥ�� å�� ����
// => 4���� ���ڰ� �ۼ��� å
// => ��� ������ C++�� �ۼ��� ���¼ҽ��� �м��ؼ�,
//    �������� ���Ǵ� ����� "�̸��� �ο�" �Ѱ�
// => 23���� �̸�!
// => ���� ���� �ڵ带 "���ļ� �̸��� �ٿ���" �� �ǹ̷�
//    4���� ���� �̶�� �մϴ�. "Gangs of Four"
//    "GOF's Design Pattern" �̶�� �մϴ�.

// �ٽ� #2. prototype ����
// => ���纻�� �ʿ��ϸ� clone() �����Լ��� ����϶�� ��
// => ����Ͽ� ���� ���� ����



class Shape
{
	int color;
public:
	virtual ~Shape() {}
	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }

	virtual void draw() { std::cout << "draw Shape\n"; }

	// �ڽ��� ���纻�� ����� �����Լ��� ���� �����ϰ� Ȱ��˴ϴ�.
	virtual Shape* clone()
	{
//		Shape* s = new Shape;
//		s->color = color;	// ��� ����� ���� �����ϰ� ����
//		return s;

		// ��������� ����ϸ� �Ʒ� ������ ���� ����!!
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
			std::cout << "���° ���� ������ �����ұ�� >> ";

			int k = 0;
			std::cin >> k;

			// k��° ���� ������ �������� ���� v�� �߰�
			// => ��� �����ؾ� �ұ�� ?
			// => k��° ������ ����� ?

			// �ذ�å #1. ����			
			// => OCP �� �����Ҽ� ���� ���� ���� ������ 
			/*
			if (dynamic_cast<Rect*>(k) != nullptr)
			{
				// Rect ��. �����ؼ� v�� �߰�
			}
			else if (dynamic_cast<Circle*>(k) != nullptr)
			{
				//....
			}
			*/

			// �ذ�å #2. ������(�����Լ�) ���
			// => k ��° ������ ���� ���ʿ� ����.
			v.push_back(v[k]->clone()); // ������

			// java �������� �θ� ���Ǵ� ��� �Դϴ�. �ǹ̸� ������ ������

			// "Don't Ask Do It"
		}
	}
}


