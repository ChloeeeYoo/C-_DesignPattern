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

int main()
{


	// 사용자들이 파일에 쓸때 "암호화" 하는 기능을 요구한다.
	// 방법 #1. 사용자가 직접 데이타를 암호화 해서 파일에 쓰자
	// => 불편하다.

	// 방법 #2. FileStream 에서 파생된 클래스를 만들어서 암호화 기능추가	
	// => 단점 1. NetworStream, PipeStream 도 파생클래스 만들어야 한다.
	// => 단점 2. 압축기능도 필요 하면 다시 파생 클래스 필요
	//			 압축, 암호화 모두 필요하면 ??? 다시 다중 상속!!

	// 방법 #3. Decorator 패턴을 사용하면 어떨까 ?
	FileStream fs("a.txt");
	fs.write("hello");

	ZipDecorator zd(&fs); // fs 에 압축기능 추가
	zd.write("hello");		// 1. "hello" 압축
							// 2. fs.write(압축된 데이타)

	CryptoStream cs(&zd); 
	cs.write("hello"); // 1. 암호화 기능 수행
					   // 2. zd.write(암호화된 데이타)
}
