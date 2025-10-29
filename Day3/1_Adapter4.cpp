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
		printf("%s ¾²±â\n", s.c_str());
	}
};

class ZipDecorator : public Stream
{
	Stream* origin;
public:
	ZipDecorator(Stream* s) : origin(s) {}

	void write(const std::string& s) override
	{
		auto s2 = "[ " + s + "] ¾ÐÃàµÊ";

		origin->write(s2);
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.write("hello");

	ZipDecorator zd(&fs);	
	zd.write("hello");		

}
