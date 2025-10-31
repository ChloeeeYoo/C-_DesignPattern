#include <iostream>
#include <list>
#include <vector>
// ��� �湮���� �������̽�
template<typename T> 
struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// ���� �پ��� ������ �����ϴ� �湮�ڸ� ����� �˴ϴ�.
// �ٽ� : �湮�ڴ� "��� �Ѱ��� ���� ������ ����"
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
// �湮�� ���(�����̳�)�� accept �� �־�� �մϴ�.
// => STL list �� Ȯ���ؼ� accept �߰� 
template<typename T>
class mylist : public std::list<T>
{
public:
	using std::list<T>::list; // ������ ���

	void accept(IVisitor<T>* visitor)
	{
		// �Ʒ� ������ �ٽ�
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


	ZeroVisitor<int> zv; // �湮�ϴ� ��Ҹ� 0 ���� ����� �湮��
	s.accept(&zv); 

	s.accept(&sv);

}





