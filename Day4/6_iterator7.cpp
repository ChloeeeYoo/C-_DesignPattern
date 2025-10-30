#include <iostream>
#include <list>

int main()
{
//	slist<int> s;
	std::list<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	auto p1 = s.begin(); 
	auto p2 = s.end();   

	while (p1 != p2)
	{
		std::cout << *p1 << std::endl;
		++p1;
	}
}
