// BCryptHashData ä÷êî Copyright(C) https://www.youtube.com/@ProgrammerCpp
#pragma once
#include <Windows.h>
#include <bcrypt.h>
#pragma comment(lib, "bcrypt")
namespace WinApiCpp {
	void BCryptHashData
	( _Inout_                   BCRYPT_HASH_HANDLE  hHash  
	, _In_reads_bytes_(cbInput) PUCHAR              pbInput
	, _In_                      ULONG               cbInput
	, _In_                      ULONG               dwFlags
	);
}

