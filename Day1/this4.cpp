// this1
#include <iostream>

// 핵심 #1. 멤버함수는 this 가 인자로 추가됩니다. - "thiscall" 이라는 용어 사용
//      #2. static 멤버 함수는 인자로 this가 추가되지 않습니다.

class Point
{
	int x = 0;
	int y = 0;
public:
	// 파이썬 : 멤버 함수 작성시 객체의 참조를 개발자가 직접 코드에 표기합니다.
	//         def set( self, a, b )

	// C++ : 컴파일러가 this 추가

	void set(int a, int b)  // void set(Point* this, int a, int b)
	{						
		x = a;				
		y = b;				
	}
	// C++ 23 : 파이썬 처럼 개발자가 직접 객체를 self 로 받는 문법이 추가됩니다.
	// => C++23 이후, 클래스 만드는 방법이 이 문법때문에 많이 변경되게 됩니다.
	// => 위 set 과 set2 는 동일합니다.
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
