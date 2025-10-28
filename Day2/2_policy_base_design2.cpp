#include <iostream>

// 방법 #1. template method 패턴 사용
// => 변하는 것을 가상함수로!

// 단점 : MallocVector 가 메모리 할당 정책을 소유한다.
// => 다른 컨테이너에서 사용할수 없다.
// 
// vector 뿐 아니라, list, set, map 등 다른 컨테이너도 메모리할당 방법을
// 변경하려면
// => 역시 파생 클래스를 만들고
// => 메모리 할당 정책을 구현해야 한다.




template<typename T>
class vector
{
	T* ptr = nullptr;
	std::size_t sz;
public:
	void resize(std::size_t newsize)
	{
		deallocate(ptr, sz);		// 가상함수 호출

		ptr = allocate(newsize);	// 가상함수 호출

		sz = newsize;
	}
	virtual T* allocate(std::size_t size) { return new T[size]; }
	virtual void deallocate(T* p, std::size_t size) { delete[] p; }
};

template<typename T>
class MallocVector : public vector<T>
{
public:
	T* allocate(std::size_t size) override
	{ 
		void* p = malloc(sizeof(T) * size);
		return static_cast<T*>(p);
	}
	void deallocate(T* p, std::size_t size) 
	{ 
		free(p);
	}
};
int main()
{
//	vector<int> v;
	MallocVector<int> v;
	v.resize(10);
}

