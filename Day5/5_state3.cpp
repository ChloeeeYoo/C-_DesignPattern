#include <iostream>

// ��� #2. ���ϴ� ���� �����Լ���!

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

	p = new PowerCharacter; // ���ο� ������ ȹ�� ?
							// ���ڵ�� ���� ��ü�� ���۸� �����ϴ� ���� �ƴ϶�
							// ��ü ��ü�� �����Ѱ�
							// => �츮�� �ʿ��Ѱ��� "���´� ����" "������ ����"
	p->run();
	p->attack();
}



