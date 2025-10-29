#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter


int main()
{
	// C++ 표준에는 linked list 가 이미 있습니다.
	std::list<int> s;

	s.push_back(10);
	s.push_front(10);

	// 그런데 사용자가 stack 을 요구합니다.
	// => stack 도 C++ 표준에 있지만 없다고... 가정..
} 
