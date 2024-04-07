#include "AlgorithmProvider.h"
#include <WinApiCpp/BCryptOpenAlgorithmProvider.h>
#pragma comment(lib, "WinApiCpp")
#include <stdexcept>
#include <string>
#include <assert.h>

BCryptCpp::AlgorithmProvider::AlgorithmProvider() noexcept
	: hAlgorithm  ()
	, valid_handle()
{
}
BCryptCpp::AlgorithmProvider::AlgorithmProvider
( _In_z_      LPCWSTR               pszAlgId              
, _In_opt_z_  LPCWSTR               pszImplementation     
, _In_        ULONG                 dwFlags               
)
	: hAlgorithm
		( WinApiCpp::BCryptOpenAlgorithmProvider
			( pszAlgId
			, pszImplementation
			, dwFlags
			).release()
		)
	, valid_handle(true)
{
}
BCryptCpp::AlgorithmProvider::~AlgorithmProvider()
{
	if (valid_handle)
		WinApiCpp::BCryptCloseAlgorithmProvider::Execute(hAlgorithm, 0UL);

}
BCryptCpp::AlgorithmProvider::AlgorithmProvider(AlgorithmProvider&& r) noexcept
	: hAlgorithm       (r.hAlgorithm       )
	, valid_handle     (r.valid_handle     )
{
	r.hAlgorithm        = nullptr;
	r.valid_handle      = false  ;
}
auto BCryptCpp::AlgorithmProvider::operator=(AlgorithmProvider&& r) noexcept->AlgorithmProvider&
{
	std::swap(hAlgorithm       , r.hAlgorithm       );
	std::swap(valid_handle     , r.valid_handle     );
	return *this;
}
BCryptCpp::AlgorithmProvider::operator bool() const noexcept
{
	return valid_handle;
}
auto BCryptCpp::AlgorithmProvider::CreateHash
( _Out_writes_bytes_all_opt_(cbHashObject) PUCHAR              pbHashObject
, _In_                                     ULONG               cbHashObject
, _In_reads_bytes_opt_(cbSecret)           PUCHAR              pbSecret    
, _In_                                     ULONG               cbSecret    
, _In_                                     ULONG               dwFlags     
) const->Hash
{
	assert(valid_handle);
	BCRYPT_HASH_HANDLE hHash;
	if (const auto status = /*_Must_inspect_result_ NTSTATUS WINAPI*/::BCryptCreateHash
	( /*_Inout_                                  BCRYPT_ALG_HANDLE   hAlgorithm  */hAlgorithm  
	, /*_Out_                                    BCRYPT_HASH_HANDLE* phHash      */&hHash      
	, /*_Out_writes_bytes_all_opt_(cbHashObject) PUCHAR              pbHashObject*/pbHashObject
	, /*_In_                                     ULONG               cbHashObject*/cbHashObject
	, /*_In_reads_bytes_opt_(cbSecret)           PUCHAR              pbSecret    */pbSecret    
	, /*_In_                                     ULONG               cbSecret    */cbSecret    
	, /*_In_                                     ULONG               dwFlags     */dwFlags     
	))
		throw std::runtime_error(__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): BCryptCreateHash failed with " + std::to_string(status));
	else
		return hHash;
}
BCRYPT_ALG_HANDLE BCryptCpp::AlgorithmProvider::get() const noexcept
{
	assert(valid_handle);
	return hAlgorithm;
}
void BCryptCpp::AlgorithmProvider::GetProperty
( _In_z_                                          LPCWSTR   pszProperty
, _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PUCHAR    pbOutput   
, _In_                                            ULONG     cbOutput   
, _Out_                                           ULONG   * pcbResult  
, _In_                                            ULONG     dwFlags    
) const
{
	if (const auto status = /*_Must_inspect_result_ NTSTATUS WINAPI*/::BCryptGetProperty
	( /*_In_                                            BCRYPT_HANDLE   hObject    */hAlgorithm 
	, /*_In_z_                                          LPCWSTR         pszProperty*/pszProperty
	, /*_Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PUCHAR          pbOutput   */pbOutput   
	, /*_In_                                            ULONG           cbOutput   */cbOutput   
	, /*_Out_                                           ULONG         * pcbResult  */pcbResult  
	, /*_In_                                            ULONG           dwFlags    */dwFlags    
	))
		throw std::runtime_error(__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): BCryptGetProperty failed with " + std::to_string(status));
}
