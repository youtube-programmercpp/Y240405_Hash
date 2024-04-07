// BCryptHashData ä÷êî Copyright(C) https://www.youtube.com/@ProgrammerCpp
#include "BCryptHashData.h"
#include <stdexcept>
#include <string>

void WinApiCpp::BCryptHashData
( _Inout_                   BCRYPT_HASH_HANDLE  hHash  
, _In_reads_bytes_(cbInput) PUCHAR              pbInput
, _In_                      ULONG               cbInput
, _In_                      ULONG               dwFlags
)
{
	if (const auto status = ::BCryptHashData
	( /*_Inout_                      BCRYPT_HASH_HANDLE  hHash  */hHash
	, /*_In_reads_bytes_(cbInput)    PUCHAR              pbInput*/pbInput
	, /*_In_                         ULONG               cbInput*/cbInput
	, /*_In_                         ULONG               dwFlags*/dwFlags
	))
		throw std::runtime_error(__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): BCryptHashData failed with " + std::to_string(status));
}
