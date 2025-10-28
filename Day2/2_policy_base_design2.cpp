#include <iostream>

// ��� #1. template method ���� ���
// => ���ϴ� ���� �����Լ���!

// ���� : MallocVector �� �޸� �Ҵ� ��å�� �����Ѵ�.
// => �ٸ� �����̳ʿ��� ����Ҽ� ����.
// 
// vector �� �ƴ϶�, list, set, map �� �ٸ� �����̳ʵ� �޸��Ҵ� �����
// �����Ϸ���
// => ���� �Ļ� Ŭ������ �����
// => �޸� �Ҵ� ��å�� �����ؾ� �Ѵ�.




template<typename T>
class vector
{
	T* ptr = nullptr;
	std::size_t sz;
public:
	void resize(std::size_t newsize)
	{
		deallocate(ptr, sz);		// �����Լ� ȣ��

		ptr = allocate(newsize);	// �����Լ� ȣ��

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

