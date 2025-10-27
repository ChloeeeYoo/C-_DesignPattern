// 생성자1.cpp - 3page
#include <iostream>

// 아래 코드에서 에러를 모두 찾아 보세요
class Base
{
public:
	Base(int a) {  }
};
class Derived : public Base
{
public:
	// 핵심 #1. Base 에 디폴트 생성자가 없으면 아래 2줄은
	//			에러 입니다.
	// => 컴파일러가 변경한 코드를 알고 있어야 합니다.
	// 사용자 코드		// 컴파일러 변경한 코드
//	Derived()      { }	// Derived()      : Base() { }
//	Derived(int a) { }  // Derived(int a) : Base() { }

	// 핵심 #2. 해결책 
	// => Derived 클래스 제작자가 Base 의 다른 생성자를 명시적으로
	//    호출해야 합니다.
	Derived()      : Base(0) {}
	Derived(int a) : Base(a) {}
};
int main()
{
}
