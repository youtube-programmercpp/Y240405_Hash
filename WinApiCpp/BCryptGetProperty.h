#pragma once
#include <Windows.h>
#include <bcrypt.h>
#pragma comment(lib, "bcrypt")
#include <stdexcept>
#include <string>
namespace WinApiCpp {
	template<class T>T BCryptGetProperty
		( _In_                                            BCRYPT_HANDLE   hObject    
		, _In_z_                                          LPCWSTR         pszProperty
		, _In_                                            ULONG           dwFlags    
		)
	{
		T Output;
		ULONG cbResult;
		if (const auto status = /*_Must_inspect_result_ NTSTATUS WINAPI*/::BCryptGetProperty
		( /*_In_                                            BCRYPT_HANDLE   hObject    */hObject
		, /*_In_z_                                          LPCWSTR         pszProperty*/pszProperty
		, /*_Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PUCHAR          pbOutput   */PUCHAR(&Output)
		, /*_In_                                            ULONG           cbOutput   */sizeof Output
		, /*_Out_                                           ULONG         * pcbResult  */&cbResult
		, /*_In_                                            ULONG           dwFlags    */dwFlags
		))
			throw std::runtime_error(__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): BCryptGetProperty failed with " + std::to_string(status));
		else if (cbResult == sizeof Output)
			return Output;
		else
			throw std::runtime_error(__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): BCryptGetProperty returned unexpected cbResult " + std::to_string(cbResult));
	}
}
