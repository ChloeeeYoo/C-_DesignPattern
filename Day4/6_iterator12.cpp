#include <iostream>
#include <vector>
#include <ranges> 

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// ��ø ����
//	std::ranges::take_view tv(v, 5);
//	std::ranges::reverse_view rv(tv); 
	
	// �� 2���� �Ʒ� ó�� ����ص� �˴ϴ�. 
	// => ������ ��ũ���� ����ؼ� �ű��ϰ� ������ϻ�.. ���� ������ ����
	// => | �����ڸ� �����ε��Ѱ�. 
	auto rv = v | std::views::take(5) | std::views::reverse;

//	for (int e : rv )
	for (int e : v | std::views::take(5) | std::views::reverse)
	{
		std::cout << e << std::endl;
	}
}
// cppreference.com ���� "range library" ����
// => take_view ã�� ������