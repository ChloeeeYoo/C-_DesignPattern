#include <iostream>
#include <vector>
#include <ranges> 

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// 중첩 가능
//	std::ranges::take_view tv(v, 5);
//	std::ranges::reverse_view rv(tv); 
	
	// 위 2줄은 아래 처럼 사용해도 됩니다. 
	// => 문법적 테크닉을 사용해서 신기하게 만든것일뿐.. 위와 완전히 동일
	// => | 연산자를 오버로딩한것. 
	auto rv = v | std::views::take(5) | std::views::reverse;

//	for (int e : rv )
	for (int e : v | std::views::take(5) | std::views::reverse)
	{
		std::cout << e << std::endl;
	}
}
// cppreference.com 에서 "range library" 선택
// => take_view 찾아 보세요