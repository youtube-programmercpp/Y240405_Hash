// BCryptCpp �o�R�� Windows API ���g�p���ĕ�����̃n�b�V���l�����߂�֐� Copyright(C) https://www.youtube.com/@ProgrammerCpp
#pragma once
#include <string>
#include <array>
std::array<unsigned char, 32> Sha256ByBCryptCpp(const std::string& contents);
