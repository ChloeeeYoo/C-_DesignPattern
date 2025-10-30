#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// 반복자(iterator)
// => 결국, 1번째 요소를 가리키다가
// => 약속된 방법을 이동할수 있으면 됩니다.

// 전통적인 객체지향 : "약속된 방법" 을 위해 인터페이스 설계
//					 => 가상함수 기반이므로 느리다.

// C++ 스타일 : 그냥 문서로 약속하자. 이동함수는 inline 함수로 하자.
//				=> operator++() 함수를 사용하자.
//				=> 진짜 포인터와 동일하게 보이도록
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

	// it 는 포인터는 아닙니다.
	// => 하지만 포인터와 동일하게 사용할수 있도록 ++, * 가 연산자 재정의
	//    되어 있습니다.
	std::cout << *it << std::endl; // 40
	
	++it;
	std::cout << *it << std::endl; // 30
}

// 위 코드는 

// 1. 반복자를 꺼낼때 begin()
// => 반복자 만들때 "new" 사용 안합니다.
// => delete 필요 없음.

// 2. 반복자를 이동하는 operator++() 함수를 생각해 보세요
// => 인라인 함수 입니다.
// => C 스타일로 직접 list 이동하는 것과 완벽히 동일한 성능 보장 합니다.

// 3. 배열도 컨테이너(컬렉션)입니다. 
// => 배열과 동일하게 ++, * 를 사용해서 요소이동/접근합니다.
// => 배열과 동일한 사용법
