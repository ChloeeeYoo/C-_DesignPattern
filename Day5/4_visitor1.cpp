#include <iostream>
#include <list>
#include <vector>

// visitor 패턴 ( 약간 까다로운 패턴, 많이 사용하지는 않지만, 개념은 중요 )
// 
// 반복자(iterator) : 복합객체의 모든 요소를 동일한 방식으로 열거
// 방문자(visitor)  : 복합객체의 모든 요소를 동일한 방식으로 연산수행
//					 복합객체의 모든 요소에 적용할 연산을 정의하는 객체


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.
	// 
	// 방법 #1. for
	// => 원리는 "iterator" 를 사용. 즉, iterator 가 있는 타입만 가능
	// => 각 요소를 외부로 꺼내와서 작업하는 것
	for (auto& e : s)
		e *= 2;

	// 방법 #2. 방문자 패턴
	TwiceVisitor<int> tv; // 방문하는 요소를 2배로 하는 방문자
	s.accept(&tv);	      // list 에 방문자를 넣기 

	ShowVisitor<int> sv; // 방문하는 요소를 화면에 출력하는 방문자 
	s.accept(&sv);

	// list "s" 의 "accept" 는  모든 방문자을 받을수 있어야 합니다.
	// => 방문자의 인터페이스가 필요

	// list 뿐 아니라 vector 에도 accept 가 있어야 합니다.
	// => 모든 컨테이너에 대한 인터페이스(accept) 필요
}





