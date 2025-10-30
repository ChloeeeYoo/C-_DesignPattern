#include <iostream>
#include "monitor.h"

// "�޴����� ���ý� � ���� �����Ҷ�"

// C ��� : �Լ����ۼ�
//		   => "� �ϸ� ����"
//		   => "��� ���", "��Ҹ� ���� ����Ÿ" �� ������ �ۼ��ϰų�, �����ؾ��Ѵ�


// Command ���� : �ؾ��� ���� Ŭ������ �ۼ�
//		   => "� ��" + "��� ���" + "��ҿ� �ʿ��� ����Ÿ" ���� ��� 
//			  �ϳ��� Ŭ�������� ����

// �ᱹ �������� ���� ��

// ���� ���   : ����� ====================================> monitor.set_xxx()
// Command���� : ����� ====== ResolutionChangeCommand =====> monitor.set_xxx()
struct ICommand
{
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual ~ICommand() {}
};

// ��� ����� ICommand �� �����ؾ� �Ѵ�.
class ResolutionChangeCommand : public ICommand
{
	Monitor& m;
	int value;
	int old_value = 0;
public:
	ResolutionChangeCommand(Monitor& m, int v) : m(m), value(v) {}

	void execute() 
	{ 
		// �����ϱ� ���� "undo" �� ����ؼ� ���� ���¸� �����Ѵ�.
		old_value = m.get_resolution(); 
		m.set_resolution(value); 
	}

	void undo()
	{
		m.set_resolution(old_value);
	}
};

int main()
{
	Monitor m;

	int old = m.get_resolution();
	m.set_resolution(1920);	

	// ������ �ߴ� �۾��� ��� �ϰ� �ʹ�.
	m.set_resolution(old);


	ResolutionChangeCommand cmd(m, 1920);
	cmd.execute();	

	// ������ �ߴ� �۾��� ��� �ϰ� �ʹ�.
	cmd.undo();
}
