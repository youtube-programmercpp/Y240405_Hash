// ConsoleApplication2 サンプルプログラム Copyright(C) https://www.youtube.com/@ProgrammerCpp
// 解説動画URL https://youtube.com/live/6-vZXCu0MS0
#include <WinApiCpp/BCryptOpenAlgorithmProvider.h>
#include <WinApiCpp/BCryptGetProperty.h>
#include <WinApiCpp/BCryptCreateHash.h>
#include <WinApiCpp/BCryptHashData.h>
#include <WinApiCpp/BCryptFinishHash.h>
#pragma comment(lib, "WinApiCpp")
#include <windows.h>
#include <stdio.h>
#include <bcrypt.h>
#include <stdexcept>
#include <string>
#include <memory>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
int main()
{
	try {
		const auto hAlg     = WinApiCpp::BCryptOpenAlgorithmProvider(BCRYPT_SHA256_ALGORITHM, nullptr, 0UL);
		const auto contents = (std::ostringstream() << std::ifstream(R"(..\ConsoleApplication1\ConsoleApplication1.cpp)", std::ios_base::binary).rdbuf()).str();
		const auto cbHash   = WinApiCpp::BCryptGetProperty<DWORD>(hAlg.get(), BCRYPT_HASH_LENGTH  , 0UL);
		const auto hHash    = WinApiCpp::BCryptCreateHash(hAlg.get(), nullptr, 0UL, 0UL);
		WinApiCpp::BCryptHashData(hHash.get(), PBYTE(contents.c_str()), ULONG(contents.length()), 0UL);
		std::unique_ptr<BYTE[]> pbHash      { new BYTE[cbHash      ] };
		WinApiCpp::BCryptFinishHash(hHash.get(), pbHash.get(), cbHash, 0UL);
		std::cout << std::hex << std::setfill('0');
		for (unsigned i = 0; i < cbHash; ++i) {
			std::cout << std::setw(2) << static_cast<unsigned short>(pbHash[i]);
		}
		std::cout << std::setfill(' ') << std::dec << std::endl;
	}
	catch (const std::exception& e) {
		OutputDebugStringA(e.what());
		OutputDebugStringA("\n");
	}
}
