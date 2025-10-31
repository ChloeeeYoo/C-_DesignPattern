#include <iostream>

// 방법 #3. 변하는 것을 다른 클래스로
// => 아이템에 따라 캐릭터의 모든 동작은 변경되어야 한다.
// => 멤버 함수를 한개가 아닌 "여러벌" 로준비

struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// 이외에 slide(), jump(), fly() 등의 모든 동작을 선언...
};

// 각 아이템에 따른 동작 객체를 설계
class NoItem : public IState
{
public:
	void run()    override { std::cout << "run" << std::endl; }
	void attack() override { std::cout << "attack" << std::endl; }
};
class RedItem : public IState
{
public:
	void run()    override { std::cout << "fast run" << std::endl; }
	void attack() override { std::cout << "weak attack" << std::endl; }
};
class BlueItem : public IState
{
public:
	void run()    override { std::cout << "slow run" << std::endl; }
	void attack() override { std::cout << "power attack" << std::endl; }
};
class SuperItem : public IState
{
public:
	void run()    override { std::cout << "fast run" << std::endl; }
	void attack() override { std::cout << "power attack" << std::endl; }
};

class Character
{
	// 동작 객체는 여러개 만들어질 필요 없습니다.
	NoItem noitem;
	RedItem reditem;
	BlueItem blueitem;
	SuperItem superitem;

	IState* state = &noitem;

	int gold;
	int item;
public:
	void run() { state->run(); }
	void attack() { state->attack(); }

	void acquire_super_item()
	{
		state = &superitem;

		// 타이머를 설치 해서 "10초" 뒤에 다시 아래 코드 실행
		// state = &noitem;
	}
};
int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	p->acquire_super_item();
	p->run();
	p->attack();
}

// State 패턴 vs Strategy
// => 클래스 Diagram 은 완전히 동일합니다.
// => 결국 변하는 것을 다른 클래스로 분리하자는 것


// Stategy : 객체가 사용하는 알고리즘이 교체(Edit 의 Validation 정책)
//			 외부 코드에서 변경
//			 e.set_validator(&v)

// State : 객체의 모든 동작을 교체( 대부분의 멤버 함수를 여러벌 준비하는 개념)
//			내부적으로 변경
//			=> 달리다가 캐릭터를 획득하면 변경

// 자판기를 생각해 봅시다.
// => insert_coin();
// => push_button();
// => take_out();
// 동전을 넣을때와 넣지 않을때의 가 완전히 다르게 동작합니다.
// => 2벌의 멤버함수를 준비하세요
// => 1. 처음은 동전이 없을때 동작 사용
// => 2. 동전을 넣으면 "동작을 교체" 하세요..



