// State - 46 page
#include <iostream>

// 방법 #1. 제어문
// 단점 1. 모든 동작에 제어문 필요
// 단점 2. 새로운 아이템 추가시 모든 동작함수가 수정되어야 한다. OCP 위반. 
class Character
{
	int gold;
	int item;
public:
	void run() 
	{ 
		if ( item == 1 )
			std::cout << "run" << std::endl; 
		else if ( item == 2 )
			std::cout << "fast run" << std::endl;
	}
	void attack() { std::cout << "attack" << std::endl; }
};
int main()
{
	Character* p = new Character;
	p->run();
	p->attack();
}



