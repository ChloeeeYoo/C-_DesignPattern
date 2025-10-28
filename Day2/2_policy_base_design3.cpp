#include <iostream>

// 방법 #2. strategy 패턴
// => 변하는 것을 다른 클래스로 분리
// => 메모리 할당 정책을 별도의 클래스로 제공

// 특징 : vector 기능과 메모리 할당기능(MallocVector)가 완전히 분리되어 있다.
// => 메모리 할당기(MallocVector)는 vector 뿐 아니라 list, set, map 등에서 모두
//    사용가능

// 그런데!!!
// => 메모리 할당/해지 를 책임지는 함수가 가상함수이다.
// => 가상함수는 약간의 오버헤드가 있다.
// => vector, list, set, map은 라이브러리 이므로 전세계 모든 C++개발자가 사용한다.
//    느리면 안된다.


template<typename T>
struct IAllocator
{
	virtual T* allocate(std::size_t size) = 0;
	virtual void deallocate(T* p, std::size_t size) = 0;
	virtual ~IAllocator() {}
};


template<typename T>
class vector
{
	T* ptr = nullptr;
	std::size_t sz;

	IAllocator<T>* allocator = nullptr;
public:
	void set_allocator(IAllocator<T>* a) { allocator = a; }

	void resize(std::size_t newsize)
	{
		// null check 생략.. 복습할때 추가해 보세요
		allocator->deallocate(ptr, sz);

		ptr = allocator->allocate(newsize);

		sz = newsize;
	}
};

// 이제 컨테이너가 사용할 다양한 메모리할당기 클래스를 제공하면 됩니다.
template<typename T>
class MallocAllocator: public IAllocator<T>
{
public:
	T* allocate(std::size_t size) override
	{
		void* p = malloc(sizeof(T) * size);
		return static_cast<T*>(p);
	}
	void deallocate(T* p, std::size_t size) override
	{
		free(p);
	}
};

int main()
{
	vector<int> v;

	MallocAllocator<int> ma;
	v.set_allocator(&ma); // 컨테이너에 메모리 할당기 연결
	
	v.resize(10);
}

