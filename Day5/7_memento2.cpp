// 8_메멘토 - 178
#include <iostream>
#include <vector>
#include <map>

class Graphics
{
	int penWidth = 1;
	int penColor = 0;
	int temporary_data;

	// 저장되어야 하는 것만 별도의 타입으로 설계
	struct Memento
	{
		int penWidth;
		int penColor;

		Memento(int w, int c) : penWidth(w), penColor(c) {}
	};

	std::map<int, Memento*> memento_map;

public:
	int Save()
	{
		static int key = 0;
		++key;

		Memento* m = new Memento(penWidth, penColor);
		memento_map[key] = m;
		return key;
	}

	void Restore(int key)
	{
		// 복습하실때 map 에 key 가 있는지 먼저 찾아 보세요
		Memento* m = memento_map[key];

		penColor = m->penColor;
		penWidth = m->penWidth;
	}






	void DrawLine(int x1, int y1, int x2, int y2)
	{
	}
	void SetStrokeColor(int c) { penColor = c; }
	void SetStrokeWidth(int w) { penWidth = w; }
};

int main()
{
	Graphics g;

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200); 

	int token = g.Save();		// memento 패턴
								// => 객체가 자신의 상태를 저장했다가
								// => 원할때 복구 할수 있다.
								// => 캡슐화를 위배하지 않고, 객체의 저장/복구 지원


	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// 처음에 그렸던 선과 동일하게 그리고 싶다.
	g.Restore(token); // 이전에 저장한 상태로 복구해 달라.
}









