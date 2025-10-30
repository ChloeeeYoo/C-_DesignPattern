#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// 아래 코드에서 "v" 의 위치에 놓일수 있는 것의 정확한 요구조건은?
	for (int e : v )
	{
		std::cout << e << std::endl;
	}

	// 위 for 문은 컴파일러에 의해서 아래 코드로 변경됩니다.
	// v가 컨테이너				// v가 배열
	auto first = v.begin();		// auto first = v;
	auto last = v.end();		// auto last = v + 배열의크기(5);

	for (; first != last; ++first)
	{
		auto e = *first;
		//---------------------------------------
		std::cout << e << std::endl;
	}
}