class Color
{
	int _red, _green, _blue;
public:
	Color(int r, int g, int b) : _red(r), _green(g), _blue(b) {}
	// static factory method
	// => ������ ���Ͽ��� ������, java �������� �θ� ����ϴ� ���
	// => �ڽ��� ��ü�� ����� static ��� �Լ�
	// => �Ʒ� Red(),   Factory ������ Rect::create()
	static Color* Red() { return new Color(255, 0, 0); }

	// Color ���� ������ ����� "flyweight" �Դϴ�.
	// inline static ������ �Ѱ�
	// => �ڽ� Ÿ���� static ����� �Ҷ��� inline static �Ҽ� �����ϴ�.
	//    �ݵ�� �ܺ� ���� �ʿ� �մϴ�.
	//inline static const Color red{ 255, 0, 0 };
	//inline static const Color green{ 0, 255, 0 };
	static const Color red;
	static const Color green;
};
const Color Color::red{ 255, 0, 0 };
const Color Color::green{ 0, 255, 0 };





int main()
{
	// �Ʒ� c1�� ���� �����ΰ��� ?
	// => ������(red)
	 
	// ������ �������� ���� �ڵ�� ?
	Color* c1 = new Color(255, 0, 0);
	Color* c2 = Color::Red();

	const Color& c3 = Color::red;
}

// ���ۿ��� "static factory method" �˻��ϸ� java �ڵ� ���� �ֽ��ϴ�.