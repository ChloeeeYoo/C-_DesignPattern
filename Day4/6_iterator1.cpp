#include <iostream>
#include <vector>
#include <list>
// iterator(반복자)
// => C 언어를 제외한 모든 객체지향 언어의 표준 라이브러리가 제공하는 핵심 디자인
// => C++, Python, C#, Java, Swift, Rust 

int main()
{
	// 1. list 와 vector 의 메모리 구조를 다릅니다.
	std::list<int>   s = { 1,2,3,4,5 };	// 5개 요소를 각각 별개의 메모리에 보관
	std::vector<int> v = { 1,2,3,4,5 }; // 5개 요소를 연속된 메모리에 보관





	// 2. s, v 의 모든 요소를 "동일한 방법" 으로 접근할수 없을까?
	// => 반복자(iterator) 를 사용하면 됩니다.
	auto p1 = s.begin();
	auto p2 = v.begin();


	// 3. p1 과 p2 는 사용법이 동일합니다.
	++p1;
	++p2;

	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
}

// iterator(반복자) 패턴
// => 복합객체 내부구조를 외부에 노출하지 않고
// => 서로 다른 구조를 가진 복합객체의 모든 요소를
// => "동일한 방법으로 순차적으로 접근" 할수 있게 한다.