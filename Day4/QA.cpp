// QA
#include <iostream>
#include <list>
// STL ���� ��� �޴� ����
// => �Ҹ��ڰ� virtual �� �ƴϹǷ� �����մϴ�.
// => ��, �Ļ� Ŭ���� �Ҹ��ڰ� �ϴ� ���� ����, ��� �Լ� 1~2�� ������ �߰��Ѵٸ�
//    ����ص� �˴ϴ�.

template<typename T> 
class mylist : public std::list<T>
{
public:
	
	// ��� Ŭ������ ��� �����ڸ� ���� ����Ҽ� �ְ� �ش޶�!
	using std::list<T>::list;	// using Ÿ���̸�::�������̸�

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