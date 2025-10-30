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

	// ������ ++
	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	// ������++ : �������� �����ϱ� ���� ���ڷ� int ���.
	//			 => ���� ������� ���� ����
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

	// C++ iterator �� ��¥ �����Ϳ� ������ ���ƾ� �մϴ�.
	// ==, != ������ ������ �ؾ� �մϴ�.
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

	auto p1 = s.begin(); // ó����Ҹ� ����Ű�� �ݺ���
	auto p2 = s.end();   // ������ ���� ��Ҹ� ����Ű�� �ݺ���

	while (p1 != p2)
	{
		std::cout << *p1 << std::endl;
		++p1;
	}
}
