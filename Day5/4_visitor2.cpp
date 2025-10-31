#include <iostream>
#include <list>
#include <vector>
// 모든 방문자의 인터페이스
template<typename T> 
struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// 이제 다양한 연산을 정의하는 방문자만 만들면 됩니다.
// 핵심 : 방문자는 "요소 한개에 대한 연산을 정의"
template<typename T>
class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { e *= 2; }
};

template<typename T>
class ShowVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { std::cout << e << std::endl; }
};

template<typename T>
class ZeroVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { e = 0; }
};
//---------------------------------------
// 방문의 대상(컨테이너)는 accept 가 있어야 합니다.
// => STL list 를 확장해서 accept 추가 
template<typename T>
class mylist : public std::list<T>
{
public:
	using std::list<T>::list; // 생성자 상속

	void accept(IVisitor<T>* visitor)
	{
		// 아래 구현이 핵심
		for (auto& e : *this)
			visitor->visit(e);
	}
};

int main()
{
//	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	mylist<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv; 
	s.accept(&tv);	      

	ShowVisitor<int> sv;
	s.accept(&sv);


	ZeroVisitor<int> zv; // 방문하는 요소를 0 으로 만드는 방문자
	s.accept(&zv); 

	s.accept(&sv);

}





