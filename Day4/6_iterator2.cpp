#include <iostream>
#include <vector>
#include <list>

// 아래 코드는 java 스타일의 반복자 사용하는 코드를 
// => C++로 흉내 낸것
// => 빌드는 되지 않습니다.

int main()
{
	slist<int>  s = { 1,2,3 };
	vector<int> v = { 1,2,3 };


	// 핵심 #1. java 의 모든 컬렉션(컨테이너)에는 "iterator()" 함수가 있다
	// => 모든 컬렉션의 공통의 인터페이스가 있다. 
	auto it1 = s.iterator();
	auto it2 = v.iterator();

	// 핵심 #2. list 반복자와 vector 반복자는 사용법이 같아야 합니다.
	// => 모든 종류의 반복자를 위한 "인터페이스" 가 있다.
	while (it1.hasNext())
	{
		std::cout << it1.next() << std::endl;
	}

	while (it2.hasNext())
	{
		std::cout << it2.next() << std::endl;
	}
}
