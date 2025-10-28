#include <iostream>
#include <string>

// 모든 Stream 의 공통의 인터페이스 설계
struct Stream
{
	virtual void write(const std::string& s) = 0;
	virtual ~Stream() {}

	// write 외에도, read(), flush(), open(), close() 등도 있다고 가정
};

// 모든 Stream 은 Stream 인터페이스를 구현하기로 약속 
class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const std::string& name, const std::string& mode = "wt")
	{
		fopen_s(&file, name.c_str(), mode.c_str() );
	}
	~FileStream() { fclose(file); }

	void write(const std::string& s)
	{
		printf("%s 쓰기\n", s.c_str());
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	/*
	// FileStream 외에도 다양한 Stream 이 있다고 가정해 봅시다.
	NetworkStream ns("100.100.100.100", 3000);
	ns.write("hello");

	PipeStream ps("named_pipe");
	ps.write("hello");
	*/
}
