#include <iostream>
#include <vector>
#include <ranges> // �̾ȿ� take_view �ֽ��ϴ�.
				  // C++20

// take_view Ŭ���� : �����̳��� �տ��� �Ϻκи� �ٶ󺸴� ��
// => std::ranges::Ŭ�����̸� 
// 
// take()    �Լ�   : take_view �� ����� �Լ� 
// => std::views::Ŭ�����̸�
int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	std::ranges::reverse_view rv(v); // v �� �Ųٷ� ���� �ִ� ��

//	for (int e : rv )
	for (int e : std::views::reverse(v) ) 
	{
		std::cout << e << std::endl;
	}
}