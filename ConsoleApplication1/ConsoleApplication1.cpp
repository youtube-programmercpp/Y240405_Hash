#include <stdio.h>
#include <fstream>
#include <numeric>
#include <string>
#include <iostream>

/*
SHA256 �n�b�V�� (�Ώ� C:\Users\cat\source\repos\Y240405_Hash\ConsoleApplication1\ConsoleApplication1.cpp):
938cca59c009056a98f22c9c456caf6f8a2d6d70c185dc0664e2a612c204247c
CertUtil: -hashfile �R�}���h�͐���Ɋ������܂����B
*/
int main()
{
	//Unix�̗p��
	// �}�j���A�� man �R�}���h
	// pipe(2)
	// popen(3)
	//(2)�V�X�e���R�[����(3)���C�u�����֐��̈Ⴂ

	if (const auto fp = _popen("certutil -hashfile \"" __FILE__ "\" SHA256", "r")) {
		std::ifstream file(fp);
		std::string hash;
		if (std::getline(file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'), hash)) {
			std::cout << "���̃t�@�C���̃n�b�V���l�� " << hash << " �ł��B" << std::endl;
		}
		_pclose(fp);
	}
}
