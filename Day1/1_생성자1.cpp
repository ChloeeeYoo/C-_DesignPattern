// 빌드 : Ctrl + F5
// 폰트 변경등 : 도구 메뉴 - 옵션메뉴 선택

// 생성자1.cpp - 3page
#include <iostream>
// 핵심 : 상속에서의 "생성자 호출의 정확한 원리"

class Base
{
public:
	Base()     { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:
	// 사용자 코드		// 컴파일러가 변경한 코드
	Derived()			// Derived() : Base()
	{ 
		std::cout << "Derived()" << std::endl; 
	}
	Derived(int a)		// Derived(int a) : Base() <= 컴파일러 추가 코드는
						//					       기반 클래스의 디폴트 생성자호출
	{ 
		std::cout << "Derived(int)" << std::endl; 
	}
	~Derived()		
	{ 
		std::cout << "~Derived()" << std::endl; 

		// Base::~Base() <= 컴파일러 추가 코드
	}
};
int main()
{
//	Derived d1;		// "call Derived::Derived()"
//	Derived d2(5);	// "call Derived::Derived(int)"
	Derived d2{ 5 }; // C++11 이후 문법

}
