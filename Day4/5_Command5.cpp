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

	void execute() override { v.push_back(create_shape()); }
	bool can_undo() override { return true; }
	void undo() override
	{
		Shape* s = v.back();
		v.pop_back();
		delete s;
	}
	virtual Shape* create_shape() = 0;
};

class AddRectCommand : public AddCommand
{
public:
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

// 여러개 명령을 보관했다가 한번에 실행하면 Macro 명령
class Macro : public ICommand // Composite 패턴!!!!
{
	std::vector<ICommand*> v;
public:
	void add(ICommand* c) { v.push_back(c); }

	void execute()
	{
		for (auto c : v)
			c->execute();
	}
};

int main()
{
	std::vector<Shape*> v;

	Macro* mc1 = new Macro;

	mc1->add(new AddRectCommand(v));
	mc1->add(new AddCircleCommand(v));
	mc1->add(new DrawCommand(v));
	mc1->execute(); // 3개 명령 한번에 실행

	Macro* mc2 = new Macro;

	mc2->add(new AddRectCommand(v));

	mc2->add(mc1);

	mc2->execute();






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

