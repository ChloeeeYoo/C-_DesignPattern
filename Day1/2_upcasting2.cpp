#include <iostream>
class Animal
{
public:
	virtual ~Animal() {}  // 가상 소멸자..!! 오후에 자세히 설명
						  // 가상함수가 있으면 "가상함수 테이블생성"
						  // 테이블 안에 타입 정보 관리
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;
	Animal a;

//	Animal* p = &d; // upcasting
	Animal* p = &a; // p가 가리키는 것은 Dog 아닌 Animal

	// upcasting : 파생 클래스 주소를 기반 클래스 포인터로 
	// downcasting  : 기반 클래스 주소를 파생 클래스 포인터로!
	//				  반드시 명시적 캐스팅 필요

	// static_cast : 컴파일 시간 캐스팅
	// => 컴파일러는 p가 가리키는 곳이 Dog 인지 알수 없다
	// => 하지만 사용자 요청이므로 "무조건 허용" 해서
	//    주소를 반환 한다.
	// => 이경우 p가 가기키는 곳이 Dog 가 아니라면 "pd->color = 10" 은
	//    잘못된 동작(사용자 책임)
	// Dog* pd = static_cast<Dog*>(p); 


	// dynamic_cast : 실행시간 캐스팅
	// => p가 가리키는 곳이 Dog 가 아니라면 0(nullptr) 반환.
	// => p가 가리키는 곳이 Dog 가 맞는 경우만 주소 반환
	// => 단, 사용하려면 "가상함수가 한개 이상 있는 클래스"만 사용가능
	//    가상함수 테이블을 사용해서 타입 정보를 관리하므로!

	Dog* pd = dynamic_cast<Dog*>(p);

	std::cout << pd << std::endl;
}











