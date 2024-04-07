// BCryptFinishHash ä÷êî Copyright(C) https://www.youtube.com/@ProgrammerCpp
#include "BCryptFinishHash.h"
#include <stdexcept>
#include <string>

void WinApiCpp::BCryptFinishHash
( _Inout_                          BCRYPT_HASH_HANDLE hHash   
, _Out_writes_bytes_all_(cbOutput) PUCHAR             pbOutput
, _In_                             ULONG              cbOutput
, _In_                             ULONG              dwFlags 
)
{
	if (const auto status = ::BCryptFinishHash
	( /*_Inout_                          BCRYPT_HASH_HANDLE hHash   */hHash   
	, /*_Out_writes_bytes_all_(cbOutput) PUCHAR             pbOutput*/pbOutput
	, /*_In_                             ULONG              cbOutput*/cbOutput
	, /*_In_                             ULONG              dwFlags */dwFlags 
	))
		throw std::runtime_error(__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): BCryptFinishHash failed with " + std::to_string(status));
}
