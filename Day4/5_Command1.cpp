#include <iostream>
#include "monitor.h"

// Command
// => � ����� ���� �������� �ʰ�
// => ��ü�� ���� ����..

class ResolutionChangeCommand
{
	Monitor& m;
	int value;
public:
	ResolutionChangeCommand(Monitor& m, int v) : m(m), value(v) {}

	void execute() { m.set_resolution(value); }
};

int main()
{
	Monitor m;

	// m �� �ػ�(resolution)�� 1920���� �����ϰ� �ʹ�.
	m.set_resolution(1920);	// Command ������ ������� ���� �ڵ�

	ResolutionChangeCommand cmd(m, 1920);
	cmd.execute();	// Command ������ ����ϴ� �ڵ�
}