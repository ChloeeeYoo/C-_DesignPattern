// this1
#include <iostream>

// 핵심 #1. 멤버함수는 this 가 인자로 추가됩니다. - "thiscall" 이라는 용어 사용
//      #2. static 멤버 함수는 인자로 this가 추가되지 않습니다.

class Point
{
	int x = 0;
	int y = 0;
public:
	// 사용자 코드			// 컴파일러가 변경한 코드
	void set(int a, int b)  // void set(Point* this, int a, int b)
	{						// {
		x = a;				//		this->x = a;
		y = b;				//		this->y = b;

		// 멤버 함수에서 this 사용할수 있습니다.
		// => 현재 멤버함수를 호출시 사용한 객체의 주소
		std::cout << this << std::endl;
	}

	static void foo(int a)	// void foo(int a) 즉 this 없음.
	{						// {
		x = a;				//		this->x = a 가 되야 하는데 this 가 없다.
	}						//					그래서, error
							//      그래서, static 멤버 함수에서는 멤버 데이타 접근안됨
};
int main()
{
	Point::foo(3); // "call Point::foo(3)"

	Point p1;
	Point p2;
	std::cout << "&p1 : " << &p1 << std::endl;
	std::cout << "&p2 : " << &p2 << std::endl;

	p1.set(1, 2);	// 컴파일러가 객체의 주소를
					// 함수 인자 처럼 전달
					// set(&p1, 1, 2) 
	p2.set(1, 2);	// set(&p2, 1, 2)
}

// inside c++ object : C++ 코드를 컴파일러가 어떻게 변경하는지 설명
// 199X 정도 출판.