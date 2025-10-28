#include <iostream>

// ��� #3. Policy Base Design(���� ����)

// strategy vs policy base design
// => 2�� ��� ���ϴ� ��(��å)�� �ٸ� Ŭ������ �и��ϴ� ��

// strategy			  : �������̽��� ���ؼ� ��ü
// policy base design : ���ø� ���ڷ� ��ü

//				strategy							policy base design
// ����	   :	�����Լ��̹Ƿ� �ణ�� �������			�ζ��� ġȯ�� ����. ������.
// ������   :	����ð� ��ü ����					����ð� ��ü �ȵ�
//				e.set_validator(&v)					vector<int, MallocAllocator<int>> v
//				e.set_validator(&v2)				=> v�� �޸� �Ҵ��� ����� ��ü �ȵ�
//													=> ������ �������� 
//													vector �� �޸� �Ҵ� ����� ���������� ����.

// ������ ���� : C++ �� �ƴ϶� ��κ� ��ü���� ���� ���� ������ ������
//				strategy, template method �� 23���� ������ ����
// 
// IDioms     : �� ����� Ư¡�� ����ϴ� ������.
//				Policy Base Design, CRTP... �� �鿩����.. 
//			   C++ IDioms, Java IDioms, C# IDioms, Rust IDioms ��
//			   ���� "C++ IDioms" �˻� 1��° ��ũ


// std::allocator<T>  : C++ ǥ���� �����ϴ� �޸� �Ҵ��
//						allocate, deallocate �Լ��� �����ϰ� �ֽ��ϴ�.
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

