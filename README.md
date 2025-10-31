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
