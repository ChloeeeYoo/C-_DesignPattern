#include <iostream>
#include "monitor.h"

// "메뉴등을 선택시 어떤 일을 수행할때"

// C 언어 : 함수로작성
//		   => "어떤 일만 수행"
//		   => "취소 방법", "취소를 위한 데이타" 는 별도로 작성하거나, 보관해야한다


// Command 패턴 : 해야할 일을 클래스로 작성
//		   => "어떤 일" + "취소 방법" + "취소에 필요한 데이타" 등을 모두 
//			  하나의 클래스에서 관리

// 결국 간접층을 만든 것

// 직접 명령   : 사용자 ====================================> monitor.set_xxx()
// Command패턴 : 사용자 ====== ResolutionChangeCommand =====> monitor.set_xxx()
struct ICommand
{
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual ~ICommand() {}
};

// 모든 명령은 ICommand 를 구현해야 한다.
class ResolutionChangeCommand : public ICommand
{
	Monitor& m;
	int value;
	int old_value = 0;
public:
	ResolutionChangeCommand(Monitor& m, int v) : m(m), value(v) {}

	void execute() 
	{ 
		// 실행하기 전에 "undo" 를 고려해서 이전 상태를 보관한다.
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

	// 위에서 했던 작업을 취소 하고 싶다.
	m.set_resolution(old);


	ResolutionChangeCommand cmd(m, 1920);
	cmd.execute();	

	// 위에서 했던 작업을 취소 하고 싶다.
	cmd.undo();
}
