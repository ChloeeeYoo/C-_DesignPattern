class Dialog
{
public:
	void close(int a) {}		//void close(Dialog* this, int a) {}  //
	static void close2(int a) {}//void close2( int a) {} 
};

void foo(int a) {}

// �Լ� �����Ϳ� this : �ణ ��ٷο� ����. ���� ������ ����� �˾� �μ���

int main()
{
	// �ٽ� #1. �Ϲ� �Լ� �����Ϳ� ����Լ��� �ּҸ� ������ �����ϴ�.
	//      #2. �Ϲ� �Լ� �����Ϳ� static ����Լ��� �ּҸ� ������ �ֽ��ϴ�.

	void(*f1)(int) = &foo; // ok
	void(*f2)(int) = &Dialog::close; // error. ���ڰ� 2���� �Լ�
	void(*f3)(int) = &Dialog::close2;// ok

}