# C-_DesignPattern
## Basic Grammer
### Constructor
```
	// 핵심 #1. Base 에 디폴트 생성자가 없으면 아래 2줄은
	//			에러 입니다.
	// => 컴파일러가 변경한 코드를 알고 있어야 합니다.
	// 사용자 코드		// 컴파일러 변경한 코드
//	Derived()      { }	// Derived()      : Base() { }
//	Derived(int a) { }  // Derived(int a) : Base() { }

	// 핵심 #2. 해결책 
	// => Derived 클래스 제작자가 Base 의 다른 생성자를 명시적으로
	//    호출해야 합니다.

// 핵심
// 1. Student(Derived Class) 를 만드는 사람은 Person(Based Class) 에 디폴트 생성자가 없다는 것을
//    반드시 알아야 합니다.
// 2. Person 의 생성자 모양을 정확히 알고 있어야 합니다.
// 3. Student 의 생성자 에서 name, age 를 받아서 Person생성자로 전달
//    해야 합니다.!!

// protected 생성자의 의미
// => 자신의 객체는 만들수 없지만 ( 추상 적인 개념 )
// => 파생 클래스의 객체는 만들수 있도록(구체적개념) 할때 사용하는 문법

// "동물"  : 실제 객체가 존재하지 않은 추상적(abstract) 개념
// "강아지": 실제 객체가 존재하지 않은 구체적(concrete) 개념
```
### Up-casting
```
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
```
