#include <WinApiCpp/BCryptOpenAlgorithmProvider.h>
#include <WinApiCpp/BCryptGetProperty.h>
#include <WinApiCpp/BCryptCreateHash.h>
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
		const auto contents = (std::ostringstream() << std::ifstream(R"(C:\Users\cat\source\repos\Y240405_Hash\ConsoleApplication1\ConsoleApplication1.cpp)", std::ios_base::binary).rdbuf()).str();
		const auto cbHash   = WinApiCpp::BCryptGetProperty<DWORD>(hAlg.get(), BCRYPT_HASH_LENGTH  , 0UL);
		const auto hHash    = WinApiCpp::BCryptCreateHash(hAlg.get(), nullptr, 0UL, 0UL);
		if (const auto status = BCryptHashData(hHash.get(), PBYTE(contents.c_str()), ULONG(contents.length()), 0UL))
			throw std::runtime_error("**** Error 0x" + std::to_string(status) + " returned by BCryptHashData");
		std::unique_ptr<BYTE[]> pbHash      { new BYTE[cbHash      ] };
		if (const auto status = BCryptFinishHash(hHash.get(), pbHash.get(), cbHash, 0UL))
			throw std::runtime_error("**** Error 0x" + std::to_string(status) + " returned by BCryptFinishHash");
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
