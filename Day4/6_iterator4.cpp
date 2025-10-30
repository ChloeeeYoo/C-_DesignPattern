#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// #1. ��� �ݺ��ڴ� ������ �����ؾ� �մϴ�
// => �ݺ����� �������̽�
template<typename T> struct IIterator
{
	virtual bool hasNext() = 0;
	virtual T    next() = 0;
	virtual ~IIterator() {}
};

// slist �� �ݺ��� �����
// => ����� �ʽ��ϴ�
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
//slist_iterator<int> it(400����);
//it.next();

// ��� �÷����� �ݺ��ڸ� ������ �־�� �Ѵ�.
// => �������̽��� ���
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

	// java �ݺ��ڰ� �Ʒ� ó�� ����մϴ�.
	while (it->hasNext())
	{
		int n = it->next();

		std::cout << n << std::endl;
	}
	delete it;
}

// �� ��Ÿ�� ��κ��� ��ü���� ����� �ݺ��� ��Ÿ�� �Դϴ�.
// �׷���!!!

// 1. �ݺ��ڸ� ������ iterator() �Լ��� ������ ������
// => �ݺ��� ���鶧 "new" ����մϴ�
// => ���� ����ڴ� �ݵ�� delete �ؾ� �մϴ�.

// 2. �ݺ��ڸ� �̵��ϴ� next() �Լ��� ������ ������
// => �����Լ� �Դϴ�.
// => ��Ұ� ���ٸ� �����̽��� �ֽ��ϴ�.

// 3. �迭�� �����̳�(�÷���)�Դϴ�. 
// => �迭.iterator() �� �����ϴ�. 
// => �迭�� �����͸� ������ ++�� �̵��ϴµ�,
//    �� �ڵ�� .next()�� �̵�
//    ������ �ٸ��ϴ�.
