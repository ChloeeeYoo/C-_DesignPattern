#include <iostream>
#include <list>
#include <vector>

void foo(int& e) { e *= 2; }

template<typename T>
class mylist : public std::list<T>
{
public:
	using std::list<T>::list; // 생성자 상속

	template<typename F>
	void accept(F f)	// F 는 단항(인자가 한개) 함수
	{
		for (auto& e : *this)
			f(e);
	}
};



int main()
{
	mylist<int> s = { 1,2,3,4,5,6,7,8,9,10 };

//	TwiceVisitor<int> tv;
//	s.accept(&tv);		// 이렇게 객체로 하지말고

//	s.accept(&foo); // 요소에 대한 연산을 정의 하는 함수로 전달

	s.accept([](int& e) { e *= 2; });
	s.accept([](int& e) { std::cout << e << std::endl; });
}





