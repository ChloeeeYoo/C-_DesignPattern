#include <iostream>

class Animal
{
	int age = 0; // sizeof(int) 는 4입니다.

public:
	// non-virtual : 호출시 기본 바인딩인 static binding 해달라는 것
	//				 컴파일러가 포인터 타입으로 함수 호출 결정
	//				오버헤드 없음. 빠름
	void cry1() { std::cout << "Animal Cry1" << std::endl; }


	// virtual : 함수 호출시 dynamic binding 해달라는 것
	//			 포인터 타입이 아닌 메모리를 조사해서 실제 객체 타입으로
	//			 호출 결정
	//			약간의 오버헤드
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; }
};







class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog Cry1" << std::endl; }
	void cry2() { std::cout << "Dog Cry2" << std::endl; }
};



int main()
{
	std::cout << sizeof(Animal) << std::endl;
				// sizeof(멤버 데이타 age) +  sizeof(포인터)
				//							=>타입정보 때문에
	Dog    d; 

	Animal* p = &d;

	p->cry1();  // non-virtual, static binding, 컴파일러가 포인터타입으로 결정
				// Animal Cry1 호출, 빠름.
	p->cry2();  // virtual, dynamic binding, 실행시 메모리 조사후 결정
				// Dog Cry1 호출. 느림.
}

// godbolt.org 사이트 접속
// => 다양한 언어의 컴파일 결과(기계어, 어셈블리 언어)를 확인 가능한 사이트

// virtual 함수 사용시
// => 객체 마다 타입정보를 가리키는 포인터가 추가되므로 약간의 메모리 오버헤드
// => 가상함수 테이블이라는 존재 때문에 메모리 오버헤드

// => 호출시, 실행시간에 메모리 조사에 따른 성능 오버헤드
//    (move 기계어 코드  3~4번 정도 추가, 컴파일러 마다 다를수 있다)

// 가끔 호출되는 함수 라면 "무시 해도 됩니다."
// 하지만, 루프 안에서 호출이라면 성능 고려해야 합니다.