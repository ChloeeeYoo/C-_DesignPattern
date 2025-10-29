// Decorator vs Adaptor
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

FileStream fs("a.txt");
ZipDecorator zd(&fs);

fs.write("hello");
zd.write("hello");

