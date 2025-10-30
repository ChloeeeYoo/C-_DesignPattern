#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// �ݺ���(iterator)
// => �ᱹ, 1��° ��Ҹ� ����Ű�ٰ�
// => ��ӵ� ����� �̵��Ҽ� ������ �˴ϴ�.

// �������� ��ü���� : "��ӵ� ���" �� ���� �������̽� ����
//					 => �����Լ� ����̹Ƿ� ������.

// C++ ��Ÿ�� : �׳� ������ �������. �̵��Լ��� inline �Լ��� ����.
//				=> operator++() �Լ��� �������.
//				=> ��¥ �����Ϳ� �����ϰ� ���̵���
template<typename T>
class slist_iterator 
{
	Node<T>* current = nullptr;
public:
	slist_iterator(Node<T>* p = nullptr) : current(p) {}

	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	inline T& operator*() 
	{ 
		return current->data; 
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
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	auto it = s.begin();

	// it �� �����ʹ� �ƴմϴ�.
	// => ������ �����Ϳ� �����ϰ� ����Ҽ� �ֵ��� ++, * �� ������ ������
	//    �Ǿ� �ֽ��ϴ�.
	std::cout << *it << std::endl; // 40
	
	++it;
	std::cout << *it << std::endl; // 30
}

// �� �ڵ�� 

// 1. �ݺ��ڸ� ������ begin()
// => �ݺ��� ���鶧 "new" ��� ���մϴ�.
// => delete �ʿ� ����.

// 2. �ݺ��ڸ� �̵��ϴ� operator++() �Լ��� ������ ������
// => �ζ��� �Լ� �Դϴ�.
// => C ��Ÿ�Ϸ� ���� list �̵��ϴ� �Ͱ� �Ϻ��� ������ ���� ���� �մϴ�.

// 3. �迭�� �����̳�(�÷���)�Դϴ�. 
// => �迭�� �����ϰ� ++, * �� ����ؼ� ����̵�/�����մϴ�.
// => �迭�� ������ ����
