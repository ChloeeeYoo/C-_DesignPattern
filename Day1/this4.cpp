// this1
#include <iostream>

// �ٽ� #1. ����Լ��� this �� ���ڷ� �߰��˴ϴ�. - "thiscall" �̶�� ��� ���
//      #2. static ��� �Լ��� ���ڷ� this�� �߰����� �ʽ��ϴ�.

class Point
{
	int x = 0;
	int y = 0;
public:
	// ���̽� : ��� �Լ� �ۼ��� ��ü�� ������ �����ڰ� ���� �ڵ忡 ǥ���մϴ�.
	//         def set( self, a, b )

	// C++ : �����Ϸ��� this �߰�

	void set(int a, int b)  // void set(Point* this, int a, int b)
	{						
		x = a;				
		y = b;				
	}
	// C++ 23 : ���̽� ó�� �����ڰ� ���� ��ü�� self �� �޴� ������ �߰��˴ϴ�.
	// => C++23 ����, Ŭ���� ����� ����� �� ���������� ���� ����ǰ� �˴ϴ�.
	// => �� set �� set2 �� �����մϴ�.
	void set2(this Point& self, int a, int b)
	{
		self.x = a;
		self.y = b;
	}
};
int main()
{	
	Point p1;
		
	p1.set(1, 2);	
	p1.set2(1, 2);	
}
