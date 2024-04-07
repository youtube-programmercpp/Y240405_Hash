// BCryptCpp 経由の Windows API を使用して文字列のハッシュ値を求める関数 Copyright(C) https://www.youtube.com/@ProgrammerCpp
#include "Sha256ByBCryptCpp.h"
#include <BCryptCpp/AlgorithmProvider.h>
#include <BCryptCpp/Hash.h>
#pragma comment(lib, "BCryptCpp")
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <exception>

std::array<unsigned char, 32> Sha256ByBCryptCpp(const std::string& contents)
{
	const BCryptCpp::AlgorithmProvider algorithm(BCRYPT_SHA256_ALGORITHM, nullptr, 0UL);
	return algorithm
		.CreateHash(nullptr, 0UL, nullptr, 0UL, 0UL)
		.HashData(PUCHAR(contents.c_str()), ULONG(contents.length()))
		.FinishHash<32>()
		;
}