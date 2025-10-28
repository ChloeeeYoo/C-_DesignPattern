using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;

// 파일 스트림 생성
FileStream fs = new FileStream("a.dat", FileMode.Create);

byte[] data = new byte[1024*1024*1024]; // 1G

GZipStream zs = new GZipStream(fs, CompressionMode.Compress);

//fs.Write(data, 0, data.Length);
zs.Write(data, 0, data.Length);


fs.Dispose();

