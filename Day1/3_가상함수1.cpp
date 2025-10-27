#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal Cry" << std::endl; } 
};
class Dog : public Animal
{
public:
	// function override : 기반 클래스 함수를 파생클래스가 다시 만드는 것
	//						=> 구현을 다시 제공.
	void cry() { std::cout << "Dog Cry" << std::endl; } 
};
int main()
{
	Animal a; a.cry();	// "Animal Cry"
	Dog    d; d.cry();	// "Dog Cry"

	Animal* p = &d; 

	p->cry(); // ? 객체는 Dog, 포인터 타입 Animal*
			  // C++/C# : Animal Cry
			  // Java, Python, Kotlin, Objective-c, Swift등 대부분언어 : Dog Cry
}

// p->cry() 를 어떤 함수와 연결할것인가 ?
// => 함수 바인딩(function binding) 이라고 합니다.

// 1. static binding : 컴파일 시간에 "컴파일러가 결정"
//				[핵심] 컴파일러는 p가 가리키는 객체가 어떤 타입인지 알수 없다
//					   컴파일러가 아는 것은 p자체의 타입이 Animal* 라는 것만 알고 있다
//						따라서 컴파일러가 결정하면 "Animal Cry" 호출.
// 빠르지만 논리적이지 않다.
// C++/C# 의 기본 방식

// 2. dynamic binding : 컴파일 시간에는 p가 가리키는 곳을 조사하는 기계어 코드 생성
//						실행시간에 위 기계어 코드를 사용해서 메모리 조사해서 결정
//						P가 가리키는 대상체가 Dog 객체라면 "Dog Cry" 호출
// 느리지만 논리적이다.
// Java, Swift, Python 등의 대부분의 객체지향 언어의 방식
// C++/C# 의 virtual function 의방식

