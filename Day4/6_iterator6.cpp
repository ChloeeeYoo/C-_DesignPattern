#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

template<typename T>
class slist_iterator
{
	Node<T>* current = nullptr;
public:
	slist_iterator(Node<T>* p = nullptr) : current(p) {}

	// 전위형 ++
	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	// 후위형++ : 전위형과 구별하기 위해 인자로 int 사용.
	//			 => 실제 사용하지 않은 인자
	inline slist_iterator& operator++(int)
	{
		auto tmp = *this;
		current = current->next;
		return tmp;
	}


	inline T& operator*()
	{
		return current->data;
	}

	// C++ iterator 는 진짜 포인터와 사용법이 같아야 합니다.
	// ==, != 연산자 재정의 해야 합니다.
	inline bool operator==(const slist_iterator& s)
	{
		return current == s.current;
	}
	inline bool operator!=(const slist_iterator& s)
	{
		return current != s.current;
	}
};


template<typename T>
struct slist
{
	Node<T>* head = nullptr;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	inline slist_iterator<T> begin()
	{
		slist_iterator<T> it(head);
		return it;
	}

	inline slist_iterator<T> end()
	{
		slist_iterator<T> it(nullptr);
		return it;
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	auto p1 = s.begin(); // 처음요소를 가리키는 반복자
	auto p2 = s.end();   // 마지막 다음 요소를 가리키는 반복자

	while (p1 != p2)
	{
		std::cout << *p1 << std::endl;
		++p1;
	}
}
