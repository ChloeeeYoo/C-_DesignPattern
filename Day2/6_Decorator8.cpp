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
		printf("%s 쓰기\n", s.c_str());
	}
};

// Stream 객체에 압축기능을 추가하는 "기능추가 클래스(Decorator)"
class ZipDecorator : public Stream
{
	Stream* origin;
public:
	ZipDecorator(Stream* s) : origin(s) {}

	void write(const std::string& s) override
	{
		auto s2 = "[ " + s + "] 압축됨";

		origin->write(s2);
	}
};

class CryptoDecorator : public Stream
{
	Stream* origin;
public:
	CryptoDecorator(Stream* s) : origin(s) {}

	void write(const std::string& s) override
	{
		auto s2 = "[ " + s + "] 암호화됨";

		origin->write(s2);
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	ZipDecorator zd(&fs);	// fs 에 압축기능 추가
	zd.write("hello");		// 1. "hello" 압축
						// 2. fs.write(압축된 데이타)

//	CryptoDecorator cd(&zd);
//	cd.write("hello");	// 1. 암호화 기능 수행
						// 2. zd.write(암호화된 데이타)
}
