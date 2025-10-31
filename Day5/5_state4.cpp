#include <iostream>

// ��� #3. ���ϴ� ���� �ٸ� Ŭ������
// => �����ۿ� ���� ĳ������ ��� ������ ����Ǿ�� �Ѵ�.
// => ��� �Լ��� �Ѱ��� �ƴ� "������" ���غ�

struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// �̿ܿ� slide(), jump(), fly() ���� ��� ������ ����...
};

// �� �����ۿ� ���� ���� ��ü�� ����
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
	// ���� ��ü�� ������ ������� �ʿ� �����ϴ�.
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

		// Ÿ�̸Ӹ� ��ġ �ؼ� "10��" �ڿ� �ٽ� �Ʒ� �ڵ� ����
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

// State ���� vs Strategy
// => Ŭ���� Diagram �� ������ �����մϴ�.
// => �ᱹ ���ϴ� ���� �ٸ� Ŭ������ �и����ڴ� ��


// Stategy : ��ü�� ����ϴ� �˰����� ��ü(Edit �� Validation ��å)
//			 �ܺ� �ڵ忡�� ����
//			 e.set_validator(&v)

// State : ��ü�� ��� ������ ��ü( ��κ��� ��� �Լ��� ������ �غ��ϴ� ����)
//			���������� ����
//			=> �޸��ٰ� ĳ���͸� ȹ���ϸ� ����

// ���Ǳ⸦ ������ ���ô�.
// => insert_coin();
// => push_button();
// => take_out();
// ������ �������� ���� �������� �� ������ �ٸ��� �����մϴ�.
// => 2���� ����Լ��� �غ��ϼ���
// => 1. ó���� ������ ������ ���� ���
// => 2. ������ ������ "������ ��ü" �ϼ���..



