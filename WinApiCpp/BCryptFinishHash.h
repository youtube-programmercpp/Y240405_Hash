// BCryptFinishHash ä÷êî Copyright(C) https://www.youtube.com/@ProgrammerCpp
#pragma once
#include <Windows.h>
#include <bcrypt.h>
#pragma comment(lib, "bcrypt")
namespace WinApiCpp {
	void BCryptFinishHash
	( _Inout_                          BCRYPT_HASH_HANDLE hHash   
	, _Out_writes_bytes_all_(cbOutput) PUCHAR             pbOutput
	, _In_                             ULONG              cbOutput
	, _In_                             ULONG              dwFlags 
	);
}
