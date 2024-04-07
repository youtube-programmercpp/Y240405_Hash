// ConsoleApplication3 サンプルプログラム Copyright(C) https://www.youtube.com/@ProgrammerCpp
// 解説動画未作成
#include "Sha256ByCertUtil.h"
#include "Sha256ByWinApiCpp.h"
#include "Sha256ByBCryptCpp.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <Windows.h>

//32バイトのUCHAR配列を64桁の16進数文字列に変換する
static std::string make_hex_string(const std::array<UCHAR, 32>& buf)
{
	std::ostringstream ostm;
	ostm << std::hex << std::setfill('0');
	for (unsigned i = 0; i < sizeof buf; ++i)
		ostm << std::setw(2) << static_cast<unsigned short>(buf[i]);
	return ostm.str();
}

//	3種類の処理で得たハッシュ値を並べて表示する（同じハッシュ値が得られる）
//	Sha256ByCertUtil  ... certutil -hashfile コマンドを利用してファイルのハッシュ値を求める関数
//	Sha256ByWinApiCpp ... WinApiCpp 経由の Windows API を使用して文字列のハッシュ値を求める関数
//	Sha256ByBCryptCpp ... BCryptCpp 経由の Windows API を使用して文字列のハッシュ値を求める関数
int main()
{
	try {
		const std::string filename = R"(..\ConsoleApplication1\ConsoleApplication1.cpp)";
		const auto contents = (std::ostringstream() << std::ifstream(filename, std::ios_base::binary).rdbuf()).str();
		std::cout
			<<                 Sha256ByCertUtil (filename)  << " " _CRT_STRINGIZE(Sha256ByCertUtil ) "\n"
			<< make_hex_string(Sha256ByWinApiCpp(contents)) << " " _CRT_STRINGIZE(Sha256ByWinApiCpp) "\n"
			<< make_hex_string(Sha256ByBCryptCpp(contents)) << " " _CRT_STRINGIZE(Sha256ByBCryptCpp) "\n"
			;
	}
	catch (const std::exception& e) {
		OutputDebugStringA(e.what());
		OutputDebugStringA("\n");
	}
}
