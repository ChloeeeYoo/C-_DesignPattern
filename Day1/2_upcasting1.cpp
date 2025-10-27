class Animal
{
public:
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
	Dog* p1 = &d; // ok
	int* p2 = &d; // error. 

	// 핵심 #1. 기반 클래스 포인터로 파생 클래스 객체의 주소를 담을수 있다
	// => upcasting
	// => 이유는 "메모리 그림"을 생각해 보세요
	Animal* p3 = &d; // ok

	// 핵심 #2. 컴파일러는 
	// => p3가 가리키는 곳에 있는 객체가 실제 어떤 타입인지 알수 없다.
	// => 컴파일러가 아는 것은 p3 자체의 타입만 알수 있다. p3는 Animal* 타입

//	if (사용자 입력 == 1) p3 = new Animal;


	// 핵심 #3. Animal* 인 p3로는 Animal 로 부터 상속된 멤버만 접근가능
	// => Dog 가 추가한 고유 멤버는 접근 안됨.
	// => 이유는 "C++ 은 static type check" 언어이므로
	// -> compile 할 때 p3가 가리키는 &d가 dog의 주소인 지 모른다.
	
	// static type check  : 컴파일 시간에 타입을 확인하는 것
	//						(C++, Java, C# 등의 대부분의 언어)
	// dynamic type check : 실행시간에 타입을 확인하는 것
	//						(Python)

	p3->age = 10;   // ok
	p3->color = 10; // error
					// 컴파일러는 p3가 가리키는 곳에 Dog 가 있다는
					// 확신이 없다.
					// 그래서 무조건 error 발생

	// 핵심 #4. p3 를 가지고 color 에 접근하려면
	// => 캐스팅 해야한다.
	// => 개발자가 책임 질테니 허용해 달라는 요청
	static_cast<Dog*>(p3)->color = 10;
	// => 이 경우 p3가 가리키는 곳이 Dog 객체가 아니라면
	//    잘못된 코드!!
	//    undefined behavior 발생.. 잘못된 메모리 참조

	// 조사할수 없나요 ??
	// => 다음 예제
}












