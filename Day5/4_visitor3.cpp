#include <iostream>
#include <list>
#include <vector>

void foo(int& e) { e *= 2; }

template<typename T>
class mylist : public std::list<T>
{
public:
	using std::list<T>::list; // ������ ���

	template<typename F>
	void accept(F f)	// F �� ����(���ڰ� �Ѱ�) �Լ�
	{
		for (auto& e : *this)
			f(e);
	}
};



int main()
{
	mylist<int> s = { 1,2,3,4,5,6,7,8,9,10 };

//	TwiceVisitor<int> tv;
//	s.accept(&tv);		// �̷��� ��ü�� ��������

//	s.accept(&foo); // ��ҿ� ���� ������ ���� �ϴ� �Լ��� ����

	s.accept([](int& e) { e *= 2; });
	s.accept([](int& e) { std::cout << e << std::endl; });
}





