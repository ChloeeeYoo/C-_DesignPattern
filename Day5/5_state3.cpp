#include <iostream>

// 방법 #2. 변하는 것을 가상함수로!

class Character
{
	int gold;
	int item;
public:
	virtual void run() { std::cout << "run" << std::endl; }
	virtual void attack() { std::cout << "attack" << std::endl; }
};
class PowerCharacter : public Character
{
public:
	void run()    { std::cout << "fast run" << std::endl; }
	void attack() { std::cout << "power  attack" << std::endl; }
};
int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	p = new PowerCharacter; // 새로운 아이템 획득 ?
							// 이코드는 기존 객체의 동작만 변경하는 것이 아니라
							// 객체 자체를 변경한것
							// => 우리가 필요한것은 "상태는 유지" "동작은 변경"
	p->run();
	p->attack();
}



