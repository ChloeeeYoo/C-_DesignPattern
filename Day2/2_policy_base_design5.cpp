#include <iostream>
#include <vector>

// C++ 표준 STL 에서 사용할 메모리 할당기를 만들어 봅시다
// => 반드시 템플릿일 필요는 없지만, 다양한 타입에 사용가능하도록 
//    template 으로 만드는 것이 관례
template<typename T>
class debug_alloc
{
public:

	// 반드시 C++ 표준 문서에 약속된 멤버를 제공해야 합니다.
	inline T* allocate(std::size_t size)
	{
		void* p = malloc(sizeof(T) * size);
		
		printf("[allocate] %p, %zd\n", p, size);

		return static_cast<T*>(p);
	}
	inline void deallocate(T* p, std::size_t size)
	{
		printf("[deallocate] %p, %zd\n", p, size);
		free(p);
	}  

	// 위 2개 외에 아래 3개가 더 필요
	// => 관례적인 코드 이므로 항상 복사해서 사용하면 됩니다.
	using value_type = T;

	debug_alloc() {}		// 디폴트 생성자

	template<typename U> debug_alloc(const debug_alloc<U>& ) {} // template 생성자
};

int main()
{
//	std::vector<int> v; // std::vector<int, std::allocator<T> > v; 

	std::vector<int, debug_alloc<int>> v; 

	std::cout << "-----------------" << std::endl;

	v.resize(5);

	std::cout << "-----------------" << std::endl;

	v.resize(10);	// 1. 10개 버퍼 메모리 할당		  - 로그
					// 2. 5개 버퍼 => 10개 버퍼로 복사
					// 3. 5개 버퍼 메모리 제거		 - 로그

	std::cout << "-----------------" << std::endl;

	v.clear(); // 버퍼 메모리 제거 될까요 ????
				// size 만 0으로 하고.. 메모리는 계속 사용(캐패시티 개념)

	std::cout << "-----------------" << std::endl;

	v.shrink_to_fit(); // 이 순간 메모리 제거

	std::cout << "-----------------" << std::endl;
}

// 우리 예제는
// => "메모리 할당기" 에 적용된 policy base design 만 본것!!!
// => STL 에는 "이외에도 많은 정책을 교체 하기 위해 policy base design" 사용합니다.