#include "BCryptCreateHash.h"
#include "BCryptGetProperty.h"
#include <stdexcept>
#include <string>
#include <memory>

auto WinApiCpp::BCryptCreateHash
( _Inout_                                  BCRYPT_ALG_HANDLE   hAlgorithm  
, _In_reads_bytes_opt_(cbSecret)           PUCHAR              pbSecret    
, _In_                                     ULONG               cbSecret    
, _In_                                     ULONG               dwFlags     
)-> BCryptDestroyHash
{
	const auto cbHashObject = WinApiCpp::BCryptGetProperty<DWORD>(hAlgorithm, BCRYPT_OBJECT_LENGTH, 0UL);
	std::unique_ptr<BYTE[]> pbHashObject{ new BYTE[cbHashObject] };
	BCRYPT_HASH_HANDLE hHash;
	if (const auto status = /*_Must_inspect_result_ NTSTATUS WINAPI*/::BCryptCreateHash
	( /*_Inout_                                  BCRYPT_ALG_HANDLE   hAlgorithm  */hAlgorithm  
	, /*_Out_                                    BCRYPT_HASH_HANDLE* phHash      */&hHash      
	, /*_Out_writes_bytes_all_opt_(cbHashObject) PUCHAR              pbHashObject*/pbHashObject.get()
	, /*_In_                                     ULONG               cbHashObject*/cbHashObject
	, /*_In_reads_bytes_opt_(cbSecret)           PUCHAR              pbSecret    */pbSecret    
	, /*_In_                                     ULONG               cbSecret    */cbSecret    
	, /*_In_                                     ULONG               dwFlags     */dwFlags     
	))
		throw std::runtime_error(__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): BCryptCreateHash failed with " + std::to_string(status));
	else
		return
		{ /*BCRYPT_HASH_HANDLE   hHash       */hHash
		, /*PUCHAR               pbHashObject*/pbHashObject.release()
		, /*ULONG                cbHashObject*/cbHashObject
		};
}
