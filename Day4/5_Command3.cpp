#include <iostream>
#include <vector>
#include <stack>

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};


struct ICommand
{
	virtual void execute() = 0;
	virtual void undo() {}
	virtual bool can_undo() { return false; }

	virtual ~ICommand() {}
};

// 사각형을 추가하는 명령
// => "vector 의 push_back( new Rect) 를 클래스로 만든것"
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Rect); }
	bool can_undo() override { return true; }
	void undo() override 
	{
		Shape* s = v.back(); // 꺼내기만. 제거 안됨.
		v.pop_back();
		delete s;
	}
};


class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back(new Circle); }
	bool can_undo() override { return true; }
	void undo() override
	{
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
};

class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override 
	{ 
		for (auto s : v)
			s->draw();			
	}

	bool can_undo() override { return true; }
	void undo() override  {	system("cls");	}
};

int main()
{
	std::vector<Shape*> v;


	std::stack<ICommand*> undo_stack;

	ICommand* command = nullptr;


	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			command = new AddRectCommand(v);
			command->execute();
			undo_stack.push(command);
		}
		else if (cmd == 2)
		{
			command = new AddCircleCommand(v);
			command->execute();
			undo_stack.push(command);
		}
		else if (cmd == 9)
		{
			command = new DrawCommand(v);
			command->execute();
			undo_stack.push(command);
		}
		else if (cmd == 0)
		{
			if (!undo_stack.empty())
			{
				command = undo_stack.top();
				undo_stack.pop();

				if (command->can_undo())
				{
					command->undo();

					delete command; // redo 를 지원하려면 지우지 말고
									// redo_stack.push(command)
				}
			}
		}
	}
}




// C# 의 WPF 라는 GUI 라이브러리가
// => 메뉴 선택, 버튼 클릭등의 이벤트 처리시
// => "함수를 연결해도 되고 클래스로 만들어서 객체를 연결해도 됩니다."

// C++ QT 에 QUndoManager 가 있습니다. - 위 코드와 거의 동일
// IOS      NSUndoManager 가 있습니다. - 위 코드와 동일한 것을 Swift로 작성

// Command
// 장점 1. 동작, 취소, 취소 데이타를 한개의 클래스로 관리
// 장점 2. 명령을 저장(vector<ICommand*>)했다가, 취소하는 기능을 만들수 있다.