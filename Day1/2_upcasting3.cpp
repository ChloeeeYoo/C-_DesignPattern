// upcasting3.cpp
class Animal 
{
public: 
	int age;
};
class Cat : public Animal 
{
};
class Dog : public Animal
{
public:
	int color;
};
// upcpasing 활용 #1. 동종을 처리하는 함수 만들기
//void NewYear(Dog* pDog)	// 인자로 Dog 객체만 전달 가능
void NewYear(Animal* p)		// 인자로 모든 동물을 받을수 있다.
{							// "동종(동일 기반 클래스를 사용하는 타입)
							//  을 처리하는 함수 만들기"
	++(p->age); 
	
//	p->color = 10; // error
}
int main()
{
	Cat c; NewYear(&c);
	Dog d; NewYear(&d);
}











