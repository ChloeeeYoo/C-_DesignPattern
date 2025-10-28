#include <iostream>

// ��� #2. strategy ����
// => ���ϴ� ���� �ٸ� Ŭ������ �и�
// => �޸� �Ҵ� ��å�� ������ Ŭ������ ����

// Ư¡ : vector ��ɰ� �޸� �Ҵ���(MallocVector)�� ������ �и��Ǿ� �ִ�.
// => �޸� �Ҵ��(MallocVector)�� vector �� �ƴ϶� list, set, map ��� ���
//    ��밡��

// �׷���!!!
// => �޸� �Ҵ�/���� �� å������ �Լ��� �����Լ��̴�.
// => �����Լ��� �ణ�� ������尡 �ִ�.
// => vector, list, set, map�� ���̺귯�� �̹Ƿ� ������ ��� C++�����ڰ� ����Ѵ�.
//    ������ �ȵȴ�.


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
		// null check ����.. �����Ҷ� �߰��� ������
		allocator->deallocate(ptr, sz);

		ptr = allocator->allocate(newsize);

		sz = newsize;
	}
};

// ���� �����̳ʰ� ����� �پ��� �޸��Ҵ�� Ŭ������ �����ϸ� �˴ϴ�.
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
	v.set_allocator(&ma); // �����̳ʿ� �޸� �Ҵ�� ����
	
	v.resize(10);
}

