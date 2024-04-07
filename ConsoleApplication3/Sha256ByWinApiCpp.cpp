// WinApiCpp 経由の Windows API を使用して文字列のハッシュ値を求める関数 Copyright(C) https://www.youtube.com/@ProgrammerCpp
#include "Sha256ByWinApiCpp.h"
#include <WinApiCpp/BCryptOpenAlgorithmProvider.h>
#include <WinApiCpp/BCryptCreateHash.h>
#include <WinApiCpp/BCryptHashData.h>
#include <WinApiCpp/BCryptFinishHash.h>
#pragma comment(lib, "WinApiCpp")

std::array<unsigned char, 32> Sha256ByWinApiCpp(const std::string& contents)
{
	const auto hAlg     = WinApiCpp::BCryptOpenAlgorithmProvider(BCRYPT_SHA256_ALGORITHM, nullptr, 0UL);
	const auto hHash    = WinApiCpp::BCryptCreateHash(hAlg.get(), nullptr, 0UL, 0UL);
	WinApiCpp::BCryptHashData(hHash.get(), PBYTE(contents.c_str()), ULONG(contents.length()), 0UL);
	std::array<unsigned char, 32> buf;
	WinApiCpp::BCryptFinishHash(hHash.get(), buf.data(), buf.size(), 0UL);
	return buf;
}
