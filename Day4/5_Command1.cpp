#include <iostream>
#include "monitor.h"

// Command
// => 어떤 명령을 직접 수행하지 않고
// => 객체로 만들어서 수행..

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

	// m 의 해상도(resolution)를 1920으로 변경하고 싶다.
	m.set_resolution(1920);	// Command 패턴을 사용하지 않은 코드

	ResolutionChangeCommand cmd(m, 1920);
	cmd.execute();	// Command 패턴을 사용하는 코드
}