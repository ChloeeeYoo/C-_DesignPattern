class Color
{
	int _red, _green, _blue;
public:
	Color(int r, int g, int b) : _red(r), _green(g), _blue(b) {}
	// static factory method
	// => 디자인 패턴에는 없지만, java 진영에서 널리 사용하는 용어
	// => 자신의 객체를 만드는 static 멤버 함수
	// => 아래 Red(),   Factory 예제의 Rect::create()
	static Color* Red() { return new Color(255, 0, 0); }

	// Color 에서 더좋은 방식은 "flyweight" 입니다.
	// inline static 문법의 한계
	// => 자신 타입을 static 멤버로 할때는 inline static 할수 없습니다.
	//    반드시 외부 선언 필요 합니다.
	//inline static const Color red{ 255, 0, 0 };
	//inline static const Color green{ 0, 255, 0 };
	static const Color red;
	static const Color green;
};
const Color Color::red{ 255, 0, 0 };
const Color Color::green{ 0, 255, 0 };





int main()
{
	// 아래 c1은 무슨 색상인가요 ?
	// => 빨간색(red)
	 
	// 다음중 가독성이 좋은 코드는 ?
	Color* c1 = new Color(255, 0, 0);
	Color* c2 = Color::Red();

	const Color& c3 = Color::red;
}

// 구글에서 "static factory method" 검색하면 java 코드 볼수 있습니다.