#include <iostream>
#include <functional> // std::bind() 를 위한 헤더
using namespace std::placeholders;  // _1, _2, _3 ... 

// foo 는 "4항(인자가 4개)" 함수
void foo(int a, int b, int c, int d)
{
	printf("foo : %d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	foo(1, 2, 3, 4); // ok. 4항 함수이므로 인자가 4개 전달


	// std::bind : M 항 함수의 특정 인자로 고정한 N 항 함수 만드는 도구(단, M >= N)

	// 사용법 : std::bind( M항 함수 주소, M개 인자 )

	auto f1 = std::bind(&foo, 1, 2, 3, 4);  // "4항 함수 => 0 항 함수" 만들기

	f1(); // foo(1,2,3,4) 의미.. 

	
	auto f2 = std::bind(&foo, 3, _1, 7, _2); // "4항함수 => 2항 함수" 만들기. 

	f2(9, 5); // foo(3, 9, 7, 5)


	auto f3 = std::bind(&foo, _3, 2, _1, _2);  // ? 채우세요

	f3(9, 3, 1);  // foo(1, 2, 9, 3) 되도록 위 ? 채우세요

	// std::bind() 의 반환 값은
	// => std::bind 인자에 따라 다른 타입이 반환 됩니다.
	// => 따라서, auto 에 담아서 사용해야 합니다.

	// std::bind 의미
	// => 함수의 인자를 고정하거나, 순서를 변경한 새로운 함수 만들기

	// 파이썬 : functools.partial() 이 위와 동일한 도구
}
