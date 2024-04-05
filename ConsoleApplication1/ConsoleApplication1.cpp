#include <stdio.h>
#include <fstream>
#include <numeric>
#include <string>
#include <iostream>

/*
SHA256 ハッシュ (対象 C:\Users\cat\source\repos\Y240405_Hash\ConsoleApplication1\ConsoleApplication1.cpp):
938cca59c009056a98f22c9c456caf6f8a2d6d70c185dc0664e2a612c204247c
CertUtil: -hashfile コマンドは正常に完了しました。
*/
int main()
{
	//Unixの用語
	// マニュアル man コマンド
	// pipe(2)
	// popen(3)
	//(2)システムコールと(3)ライブラリ関数の違い

	if (const auto fp = _popen("certutil -hashfile \"" __FILE__ "\" SHA256", "r")) {
		std::ifstream file(fp);
		std::string hash;
		if (std::getline(file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'), hash)) {
			std::cout << "このファイルのハッシュ値は " << hash << " です。" << std::endl;
		}
		_pclose(fp);
	}
}
