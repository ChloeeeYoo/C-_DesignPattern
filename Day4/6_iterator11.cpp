#include <iostream>
#include <vector>
#include <ranges> // 이안에 take_view 있습니다.
				  // C++20

// take_view 클래스 : 컨테이너의 앞에서 일부분만 바라보는 뷰
// => std::ranges::클래스이름 
// 
// take()    함수   : take_view 를 만드는 함수 
// => std::views::클래스이름
int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	std::ranges::reverse_view rv(v); // v 를 거꾸로 볼수 있는 뷰

//	for (int e : rv )
	for (int e : std::views::reverse(v) ) 
	{
		std::cout << e << std::endl;
	}
}