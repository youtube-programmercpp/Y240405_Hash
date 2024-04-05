#include "BCryptOpenAlgorithmProvider.h"
#include <stdexcept>
#include <string>

auto WinApiCpp::BCryptOpenAlgorithmProvider
( _In_z_      LPCWSTR               pszAlgId              
, _In_opt_z_  LPCWSTR               pszImplementation     
, _In_        ULONG                 dwFlags               
)-> BCryptCloseAlgorithmProvider
{
	BCRYPT_ALG_HANDLE hAlgorithm;
	if (const auto status = /*_Must_inspect_result_ NTSTATUS WINAPI*/::BCryptOpenAlgorithmProvider
	( /*_Out_       BCRYPT_ALG_HANDLE   * phAlgorithm      */&hAlgorithm      
	, /*_In_z_      LPCWSTR               pszAlgId         */pszAlgId         
	, /*_In_opt_z_  LPCWSTR               pszImplementation*/pszImplementation
	, /*_In_        ULONG                 dwFlags          */dwFlags          
	))
		throw std::runtime_error(__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): BCryptOpenAlgorithmProvider failed with " + std::to_string(status));
	else
		return { hAlgorithm , 0UL };
}
