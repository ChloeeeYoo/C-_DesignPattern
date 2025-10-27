// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};

int main()
{
	// 활용 #2. 동종을 보관하는 컨테이너 만들기 
	// => 이번 주에 이 개념이 아주 널리 사용됩니다.
	std::vector<Dog*>    v1;	// Dog 객체만 저장 가능한 컨테이너
	std::vector<Animal*> v2;	// 동종을 저장 가능한 컨테이너
}
