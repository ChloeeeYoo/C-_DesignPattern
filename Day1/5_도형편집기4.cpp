#include <iostream>
#include <vector>

// �ٽ� #1 ��� �Ļ� Ŭ������ ������ Ư¡�� "�ݵ�� ��� Ŭ�������� �־�� �մϴ�."
// => �������� ������ �ƴ�
// => �������� ��Ģ

// �ٽ� #2. ��� �Լ��� �Ļ� Ŭ������ �ٽ� ����� �Ǵ� ����
// => ��κ� "virtual" �� �ؾ� �Ѵ�.

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	// �Ʒ� �Լ��� virtual �� �ұ�� ? non-virtual �� �ұ�� ?
	// => �Ļ� Ŭ������ �ٽ� �����ʿ� �����ϴ� - non-virtual
	// => virtual �� �ص� ������ "virtual" �� �����ϴ�!!
	// => �ٽ� �����ʿ䰡 �������� virtual!!
	void set_color(int c) { color = c; }

	// ������ ���ϴ� ����� �������� �ٸ��ϴ�.
	// => virtual �� �ϰ�.
	// => �Ļ� Ŭ�������� override 
	virtual int get_area() { return 0; }

	virtual void draw() { std::cout << "draw Shape\n"; }
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

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
			{
				s->draw();	// ������(polymorphism)
							// => ������ �ڵ尡 ��Ȳ�� ����(���� ��ü ����)
							//    �ٸ��� �����ϴ� ��
							// OCP �� �����ϴ� ���� �ڵ� ��Ÿ��!!!
				
				// ��ü���� ����� 3�� Ư¡ : ĸ��ȭ, ���, ������
			}
		}
	}
}


