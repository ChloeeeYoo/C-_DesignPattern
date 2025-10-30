#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// �Ʒ� �ڵ忡�� "v" �� ��ġ�� ���ϼ� �ִ� ���� ��Ȯ�� �䱸������?
	for (int e : v )
	{
		std::cout << e << std::endl;
	}

	// �� for ���� �����Ϸ��� ���ؼ� �Ʒ� �ڵ�� ����˴ϴ�.
	// v�� �����̳�				// v�� �迭
	auto first = v.begin();		// auto first = v;
	auto last = v.end();		// auto last = v + �迭��ũ��(5);

	for (; first != last; ++first)
	{
		auto e = *first;
		//---------------------------------------
		std::cout << e << std::endl;
	}
}