#include <iostream>

// 방법 #3. Policy Base Design(단위 전략)

// strategy vs policy base design
// => 2개 모두 변하는 것(정책)을 다른 클래스로 분리하는 것

// strategy			  : 인터페이스를 통해서 교체
// policy base design : 템플릿 인자로 교체

//				strategy							policy base design
// 성능	   :	가상함수이므로 약간의 오버헤드			인라인 치환도 가능. 빠르다.
// 유연성   :	실행시간 교체 가능					실행시간 교체 안됨
//				e.set_validator(&v)					vector<int, MallocAllocator<int>> v
//				e.set_validator(&v2)				=> v의 메모리 할당기는 실행시 교체 안됨
//													=> 하지만 실전에서 
//													vector 의 메모리 할당 방법을 변경할일은 없다.

// 디자인 패턴 : C++ 뿐 아니라 대부분 객체지향 언어에서 적용 가능한 디자인
//				strategy, template method 등 23개가 유명한 패턴
// 
// IDioms     : 각 언어의 특징을 고려하는 디자인.
//				Policy Base Design, CRTP... 등 백여가지.. 
//			   C++ IDioms, Java IDioms, C# IDioms, Rust IDioms 등
//			   구글 "C++ IDioms" 검색 1번째 링크


// std::allocator<T>  : C++ 표준이 제공하는 메모리 할당기
//						allocate, deallocate 함수를 제공하고 있습니다.
template<typename T, typename Allocator = std::allocator<T> >
class vector
{
	T* ptr = nullptr;
	std::size_t sz;

	Allocator alloc;
public:

	void resize(std::size_t newsize)
	{
		alloc.deallocate(ptr, sz);

		ptr = alloc.allocate(newsize);

		sz = newsize;
	}
};


template<typename T>
class MallocAllocator 
{
public:
	inline T* allocate(std::size_t size) 
	{
		void* p = malloc(sizeof(T) * size);
		return static_cast<T*>(p);
	}
	inline void deallocate(T* p, std::size_t size) 
	{
		free(p);
	}
};

int main()
{
	vector<int> v1;
	vector<int, MallocAllocator<int>> v2;

	v1.resize(10);
	v2.resize(10);
}

