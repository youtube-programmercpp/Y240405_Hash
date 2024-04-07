// certutil -hashfile コマンドを利用してファイルのハッシュ値を求める関数 Copyright(C) https://www.youtube.com/@ProgrammerCpp
#include "Sha256ByCertUtil.h"
#include <stdio.h>
#include <fstream>
#include <numeric>
#include <string>
#include <memory>
#include <stdexcept>

std::string Sha256ByCertUtil(const std::string& filename)
{
	if (const std::unique_ptr<FILE, decltype(_pclose)*> fp{ _popen(("certutil -hashfile \"" + filename + "\" SHA256").c_str(), "r"), _pclose }) {
		std::ifstream file(fp.get());
		std::string hash;
		if (std::getline(file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'), hash))
			return hash;
		else
			throw std::runtime_error(__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): std::getline failed");
	}
	else
		throw std::runtime_error(__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): _popen failed");
}
