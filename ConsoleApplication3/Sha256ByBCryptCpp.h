// BCryptCpp 経由の Windows API を使用して文字列のハッシュ値を求める関数 Copyright(C) https://www.youtube.com/@ProgrammerCpp
#pragma once
#include <string>
#include <array>
std::array<unsigned char, 32> Sha256ByBCryptCpp(const std::string& contents);
