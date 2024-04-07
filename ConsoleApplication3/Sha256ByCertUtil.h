// certutil -hashfile コマンドを利用してファイルのハッシュ値を求める関数 Copyright(C) https://www.youtube.com/@ProgrammerCpp
#pragma once
#include <string>
std::string Sha256ByCertUtil(const std::string& filename);
