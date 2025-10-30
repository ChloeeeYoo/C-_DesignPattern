#include <iostream>
#include <vector>

// C#, Java, C++, Python, Rust, Swift 등 거의 모든 언어의
// => for 문(C 스타일 말고, Python 스타일)의 원리는
// => 반복자 입니다.

// => 그래서 for 에 놓을수 있는 객체의 요구 조건은
// => "iterable 한 객체" 입니다.

struct Point3D
{
	int x = 1;
	int y = 2;
	int z = 3;

	int* begin() { return &x ; }
	int* end()   { return &z + 1 ; }
};

int main()
{
	Point3D p;

	for (int e : p)
	{
		std::cout << e << std::endl;
	}

	/*
	for (; first != last; ++first)
	{
		auto e = *first;
		//---------------------------------------
		std::cout << e << std::endl;
	}
	*/
}
// 위 코드 에러 입니다.
// 1. 왜 에러일까요 ?
// 2. 에러 메세지 확인
// 3. 에러 없도록 완성해 보세요