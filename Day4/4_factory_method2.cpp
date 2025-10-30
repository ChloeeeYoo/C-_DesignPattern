// 5_팩토리메소드 - 148
#include <iostream>

// 모든 종류의 컨트롤은 공통의 기반 클래스 필요
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
//--------------------------------------
// Style 옵션과 상관없이 항상 Windows 모양의 Dialog

class BaseDialog
{
public:
	void init()
	{
		IButton* btn = CreateButton();
		IEdit* edit = CreateEdit();

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
	// factory method
	// => 객체를 생성하기 위한 인터페이스를 제공하고 사용도 하지만
	// => 어떤 객체를 생성할지는 파생 클래스가 결정한다.
	// => 객체의 종류(생성)을 파생 클래스에 위임하는 패턴

	// template method와 동일(template method의 한가지 응용)하지만
	// => 가상함수가 하는일이 "동작"이 아닌 "객체의 생성" 이라서
	//    별도의 이름 부여

	virtual IButton* CreateButton() = 0;
	virtual IEdit*   CreateEdit() = 0;
};

class WinDialog : public BaseDialog
{
public:
	IButton* CreateButton() override { return new WinButton; }
	IEdit* CreateEdit() override { return new WinEdit; }
};
// Factory 사용시 "테마별 컨트롤 전체" 를 변경하지만
// 위 코드는 컨트롤 각각을 결정할수 있습니다
class MixDialog : public BaseDialog
{
public:
	IButton* CreateButton() override { return new WinButton; }
	IEdit* CreateEdit() override { return new OSXEdit; }
};


int main(int argc, char** argv)
{

}





// 23개 디자인 패턴을 기능에 따라 3가지로 분류 합니다.

// 생성 패턴 5개 
// => 현재 까지 4개 배웠습니다
// => singleton, prototype, abstract factory, factory method
// => builder => 내일 

// 구조 7개


// 행위 11개


