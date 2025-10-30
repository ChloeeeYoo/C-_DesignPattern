// iterator10.cpp
#include <iostream>
#include <vector>

template<typename T>
class take_view
{
	T& rg;
	int cnt;
public:
	take_view(T& c, int n) : rg(c), cnt(n) {}

	auto begin() { return rg.begin(); }
	auto end()   { return rg.begin() + cnt; }
};

// take_view 를 만드는 함수
template<typename T>
take_view<T> take(T& c, int cnt)
{
	take_view<T> tv(c, cnt);
	return tv;
}
int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

//	take_view tv(v, 5); // v에서 5개만 접근하도록 만드는 view
//	for (int e : v)
//	for (int e : tv)

	for (int e : take(v, 5) ) 
	{
		std::cout << e << std::endl;
	}
}