// BCryptCreateHash ä÷êî Copyright(C) https://www.youtube.com/@ProgrammerCpp
#pragma once
#include "BCryptDestroyHash.h"
#include <Windows.h>
#include <bcrypt.h>
#pragma comment(lib, "bcrypt")
namespace WinApiCpp {
	auto BCryptCreateHash
	( _Inout_                                  BCRYPT_ALG_HANDLE   hAlgorithm  
	, _In_reads_bytes_opt_(cbSecret)           PUCHAR              pbSecret    
	, _In_                                     ULONG               cbSecret    
	, _In_                                     ULONG               dwFlags     
	)-> BCryptDestroyHash;
}
