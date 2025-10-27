// protected 생성자의 의미
// => 자신의 객체는 만들수 없지만 ( 추상 적인 개념 )
// => 파생 클래스의 객체는 만들수 있도록(구체적개념) 할때 사용하는 문법

// "동물"  : 실제 객체가 존재하지 않은 추상적(abstract) 개념
// "강아지": 실제 객체가 존재하지 않은 구체적(concrete) 개념

class Animal
{
//public:			// #1, #2 모두 에러 아님
//private:			// #1, #2 모두 에러
protected:			// #1 만 에러. #2 는 에러 아님. 
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {}	// Dog() : Animal() {}
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
	Animal a;	// #1 error
	Dog    d;	// #2 ok 
}



