#include <iostream>
#include <string>

struct Stream
{
	virtual void write(const std::string& s) = 0;
	virtual ~Stream() {}
};

class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const std::string& name, const std::string& mode = "wt")
	{
		fopen_s(&file, name.c_str(), mode.c_str());
	}
	~FileStream() { fclose(file); }

	void write(const std::string& s)
	{
		printf("%s ����\n", s.c_str());
	}
};

int main()
{


	// ����ڵ��� ���Ͽ� ���� "��ȣȭ" �ϴ� ����� �䱸�Ѵ�.
	// ��� #1. ����ڰ� ���� ����Ÿ�� ��ȣȭ �ؼ� ���Ͽ� ����
	// => �����ϴ�.

	// ��� #2. FileStream ���� �Ļ��� Ŭ������ ���� ��ȣȭ ����߰�	
	// => ���� 1. NetworStream, PipeStream �� �Ļ�Ŭ���� ������ �Ѵ�.
	// => ���� 2. �����ɵ� �ʿ� �ϸ� �ٽ� �Ļ� Ŭ���� �ʿ�
	//			 ����, ��ȣȭ ��� �ʿ��ϸ� ??? �ٽ� ���� ���!!

	// ��� #3. Decorator ������ ����ϸ� ��� ?
	FileStream fs("a.txt");
	fs.write("hello");

	ZipDecorator zd(&fs); // fs �� ������ �߰�
	zd.write("hello");		// 1. "hello" ����
							// 2. fs.write(����� ����Ÿ)

	CryptoStream cs(&zd); 
	cs.write("hello"); // 1. ��ȣȭ ��� ����
					   // 2. zd.write(��ȣȭ�� ����Ÿ)
}
