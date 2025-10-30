// QA
#include <iostream>
#include <list>
// STL 에서 상속 받는 것은
// => 소멸자가 virtual 이 아니므로 위험합니다.
// => 단, 파생 클래스 소멸자가 하는 일이 없고, 멤버 함수 1~2개 정도만 추가한다면
//    상속해도 됩니다.

template<typename T> 
class mylist : public std::list<T>
{
public:
	
	// 기반 클래스의 모든 생성자를 나도 사용할수 있게 해달라!
	using std::list<T>::list;	// using 타입이름::생성자이름

	void print_all() {}
};
int main()
{
//	std::list<int> s1(5, 0);
//	std::list<int> s2 = { 1,2,3,4,5 };

	mylist<int> s1(5, 0);
	mylist<int> s2 = { 1,2,3,4,5 };

	s1.print_all();
	s2.print_all();
}