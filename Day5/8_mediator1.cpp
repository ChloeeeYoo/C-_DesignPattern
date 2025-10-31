// Mediator - 171
#include <iostream>

class CheckBox
{
	bool state;
public:
	CheckBox() : state(false) {}
	
	// 핵심 : check 상태가 변경되면 가상함수가 호출되도록 디자인
	//  => check 변경시 어떤 작업을 하려면 "파생 클래스 만들라는 의도"
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	virtual void ChangeState() {}
};


class MyCheckBox : public CheckBox
{
public:
	void ChangeState() override
	{
		std::cout << "check box 상태변경\n";

		if (GetCheck() == false)
			std::cout << "버튼 disable\n";
		else 
			std::cout << "버튼 enable\n";
	}
};
int main()
{
	MyCheckBox c;
	c.SetCheck(false);
	c.SetCheck(true);
}



