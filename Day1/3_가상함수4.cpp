#include <iostream>

// 가상함수4.cpp

// 핵심 정리
// => 상속을 사용한다면
// => 반드시 기반 클래스 소멸자는 "virtual" 로 해야 합니다.

// C++ 격언
// => 상속을 고려하고 만든 클래스가 아니라면 "상속받지 말라"
// => 이유 : 소멸자는 가상이 아닐것이다.!!
// => 단, 파생 클래스 소멸자가 하는일이 없고, 위내용을 모두 알고, 
//    버그를 피할수 있다면 사용가능!!!@

class Base
{
public:
	virtual ~Base() {}	// 가상소멸자 문법
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
//	Derived d;	// 아무 문제 없는 코드

//	Derived* p = new Derived;	// 아무 문제 없는 코드
//	delete p;

	// 이예제의 핵심은 아래 코드!
	Base* p = new Derived; // 1. 객체를 만들기 때문에 생성자 호출
	delete p;				// 2. 객체를 제거 하므로 소멸자를 호출해야 한다.
	// 소멸자 호출
	// => 결국 함수의 호출 입니다.
	// => p->소멸자()

	// 컴파일러 원리
	// 1. 컴파일러는 p가 Base* 라는 것만 알고 있다.
	// 2. 따라서, 컴파일러는 Base 클래스에서 소멸자가 가상인지 아닌지 조사
	// => Base 소멸자가 non-virtual 이면 : static binding 하므로 p의 타입인 ~Base()호출
	// => Base 소멸자가     virtual 이면 : dynamic binding 하므로 실제 객체의 타입에
	//									  맞도록 호출
}	
