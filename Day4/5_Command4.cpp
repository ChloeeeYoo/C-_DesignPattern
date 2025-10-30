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
// 도형을 추가하는 명령은 공통된 특징이 있습니다.
// => 기반 클래스로 제공합니다.

class AddCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	void execute() override { v.push_back( create_shape() ); }
	bool can_undo() override { return true; }
	void undo() override
	{
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
	// factory method
	virtual Shape* create_shape() = 0;
};

class AddRectCommand : public AddCommand
{
public:
//	AddRectCommand(std::vector<Shape*>& v) : AddCommand(v) {}

	// 생성자 상속 문법
	// => "원래 생성자는 상속되지 않습니다."
	// => 아래 처럼 작성하면 생성자도 상속됩니다.
	// => 아래 한줄이 위 주석과 완전히 동일합니다.
	using AddCommand::AddCommand;

	Shape* create_shape() override { return new Rect; }
};

class AddCircleCommand : public AddCommand
{
public:
	using AddCommand::AddCommand;

	Shape* create_shape() override { return new Circle; }
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
	void undo() override { system("cls"); }
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

					delete command; 
				}
			}
		}
	}
}

