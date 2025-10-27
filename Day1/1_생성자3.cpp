// 1_생성자2.cpp
#include <string>
#include <iostream>

class Person
{
	std::string name;
	int age;
public:
	Person(const std::string& name, int age) : name(name), age(age) {}
};
// 1. Person 에서 파생된 Student 만들어 보세요
// 2. Student 에 멤버로 int id 추가해 보세요
// 3. Student 생성자 만들어 보세요 <== 핵심
// 4. main 에서 Student 객체 생성해 보세요

// 핵심
// 1. Student 를 만드는 사람은 Person 에 디폴트 생성자가 없다는 것을
//    반드시 알아야 합니다.
// 2. Person 의 생성자 모양을 정확히 알고 있어야 합니다.
// 3. Student 의 생성자 에서 name, age 를 받아서 Person생성자로 전달
//    해야 합니다.!!

class Student : public Person
{
	int id;
public:
//	Student( int id ) : id(id)	// Student( int id ) : Person(), id(id)
	Student( const std::string& name, int age, int id)
		: Person(name, age), id(id)
	{	
	}
};


int main()
{
//	Person p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
	Person p1("alice", 29); // ok. 초기화된 안전한 객체
}


