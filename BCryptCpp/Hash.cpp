#include "Hash.h"
#include <WinApiCpp/BCryptCreateHash.h>
#pragma comment(lib, "WinApiCpp")
#include <stdexcept>
#include <string>
#include <assert.h>

BCryptCpp::Hash::Hash() noexcept
	: hHash       ()
	, valid_handle()
{
}
BCryptCpp::Hash::Hash(BCRYPT_HASH_HANDLE hHash) noexcept
	: hHash       (hHash)
	, valid_handle(true )
{
}
BCryptCpp::Hash::~Hash()
{
	if (valid_handle)
		WinApiCpp::BCryptDestroyHash::Execute(hHash);
}
BCryptCpp::Hash::Hash(Hash&& r) noexcept
	: hHash       (r.hHash       )
	, valid_handle(r.valid_handle)
{
	r.hHash        = nullptr;
	r.valid_handle = false  ;

}
auto BCryptCpp::Hash::operator=(Hash&& r) noexcept->Hash&
{
	std::swap(hHash       , r.hHash       );
	std::swap(valid_handle, r.valid_handle);
	return *this;
}
BCryptCpp::Hash::operator bool() const noexcept
{
	return valid_handle;
}
auto BCryptCpp::Hash::HashData
( _In_reads_bytes_(cbInput)    PUCHAR   pbInput
, _In_                         ULONG    cbInput
, _In_                         ULONG    dwFlags
) const->const Hash&
{
	assert(valid_handle);
	if (const auto status = BCryptHashData
	( /*_Inout_                      BCRYPT_HASH_HANDLE  hHash  */hHash
	, /*_In_reads_bytes_(cbInput)    PUCHAR              pbInput*/pbInput
	, /*_In_                         ULONG               cbInput*/cbInput
	, /*_In_                         ULONG               dwFlags*/dwFlags
	))
		throw std::runtime_error(__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): BCryptHashData failed with " + std::to_string(status));
	else
		return *this;
}
void BCryptCpp::Hash::FinishHash
( _Out_writes_bytes_all_(cbOutput) PUCHAR             pbOutput
, _In_                             ULONG              cbOutput
, _In_                             ULONG              dwFlags 
) const
{
	if (const auto status = BCryptFinishHash
	( /*_Inout_                          BCRYPT_HASH_HANDLE hHash   */hHash   
	, /*_Out_writes_bytes_all_(cbOutput) PUCHAR             pbOutput*/pbOutput
	, /*_In_                             ULONG              cbOutput*/cbOutput
	, /*_In_                             ULONG              dwFlags */dwFlags 
	))
		throw std::runtime_error(__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): BCryptFinishHash failed with " + std::to_string(status));
}
