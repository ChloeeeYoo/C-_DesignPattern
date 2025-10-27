// this1
#include <iostream>

// �ٽ� #1. ����Լ��� this �� ���ڷ� �߰��˴ϴ�. - "thiscall" �̶�� ��� ���
//      #2. static ��� �Լ��� ���ڷ� this�� �߰����� �ʽ��ϴ�.

class Point
{
	int x = 0;
	int y = 0;
public:
	// ����� �ڵ�			// �����Ϸ��� ������ �ڵ�
	void set(int a, int b)  // void set(Point* this, int a, int b)
	{						// {
		x = a;				//		this->x = a;
		y = b;				//		this->y = b;

		// ��� �Լ����� this ����Ҽ� �ֽ��ϴ�.
		// => ���� ����Լ��� ȣ��� ����� ��ü�� �ּ�
		std::cout << this << std::endl;
	}

	static void foo(int a)	// void foo(int a) �� this ����.
	{						// {
		x = a;				//		this->x = a �� �Ǿ� �ϴµ� this �� ����.
	}						//					�׷���, error
							//      �׷���, static ��� �Լ������� ��� ����Ÿ ���پȵ�
};
int main()
{
	Point::foo(3); // "call Point::foo(3)"

	Point p1;
	Point p2;
	std::cout << "&p1 : " << &p1 << std::endl;
	std::cout << "&p2 : " << &p2 << std::endl;

	p1.set(1, 2);	// �����Ϸ��� ��ü�� �ּҸ�
					// �Լ� ���� ó�� ����
					// set(&p1, 1, 2) 
	p2.set(1, 2);	// set(&p2, 1, 2)
}

// inside c++ object : C++ �ڵ带 �����Ϸ��� ��� �����ϴ��� ����
// 199X ���� ����.