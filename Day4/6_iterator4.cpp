#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// #1. 모든 반복자는 사용법이 동일해야 합니다
// => 반복자의 인터페이스
template<typename T> struct IIterator
{
	virtual bool hasNext() = 0;
	virtual T    next() = 0;
	virtual ~IIterator() {}
};

// slist 이 반복자 만들기
// => 어렵지 않습니다
template<typename T>
class slist_iterator : public IIterator<T>
{
	Node<T>* current = nullptr;
public:
	slist_iterator(Node<T>* p = nullptr) : current(p) {}

	T next() override 
	{ 
		T tmp = current->data;
		current = current->next;
		return tmp;
	}
	bool hasNext() override
	{
		return current != nullptr;
	}
};
//slist_iterator<int> it(400번지);
//it.next();

// 모든 컬렉션은 반복자를 꺼낼수 있어야 한다.
// => 인터페이스로 약속
template<typename T>
struct ICollection
{
	virtual IIterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};

template<typename T>
struct slist : public ICollection<T>
{
	Node<T>* head = nullptr;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	IIterator<T>* iterator() override
	{
		return new slist_iterator<T>(head);
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

//	IIterator<int>* it = s.iterator();
	auto it = s.iterator();

	// java 반복자가 아래 처럼 사용합니다.
	while (it->hasNext())
	{
		int n = it->next();

		std::cout << n << std::endl;
	}
	delete it;
}

// 위 스타일 대부분의 객체지향 언어의 반복자 스타일 입니다.
// 그런데!!!

// 1. 반복자를 꺼내는 iterator() 함수를 생각해 보세요
// => 반복자 만들때 "new" 사용합니다
// => 따라서 사용자는 반드시 delete 해야 합니다.

// 2. 반복자를 이동하는 next() 함수를 생각해 보세요
// => 가상함수 입니다.
// => 요소가 많다면 성능이슈가 있습니다.

// 3. 배열도 컨테이너(컬렉션)입니다. 
// => 배열.iterator() 는 없습니다. 
// => 배열은 포인터를 꺼내서 ++로 이동하는데,
//    위 코드는 .next()이 이동
//    사용법이 다릅니다.
