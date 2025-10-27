// 3_가상함수4-1

#include <iostream>

// 가상함수4.cpp

// 가상소멸자 문법을 사용하면
// => 가상함수를 사용하게 되므로, 가상함수 테이블의 오버헤드가 생기게 됩니다.

class Base
{
	// protected 소멸자의도
	// => 아래 main 함수의 "A" 부분 처럼 사용하지 못하게 하기 위한 코드
	// => A 처럼 사용시 컴파일 에러.
protected:
	~Base() {}	
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
	Base* p = new Derived; 

//	delete p;	// A. error

	delete static_cast<Derived*>(p); // ok

}

// 결론
// 1. 위내용이 완벽히 이해  안되면
// => 무조건 기반 클래스 소멸자는 virtual 하세요!!!

// 2. 위 내용을 정확히 이해하고
// => 기반 클래스가 아주 가볍고, 성능이 중요하면
// => 위 기술 사용

// isocpp.org 접속
// => 상단 메뉴에서 "Core Guidelines" 선택
// => C35 번 확인