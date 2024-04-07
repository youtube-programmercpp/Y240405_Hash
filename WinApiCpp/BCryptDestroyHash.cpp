// BCryptDestroyHash ƒNƒ‰ƒX Copyright(C) https://www.youtube.com/@ProgrammerCpp
#include "BCryptDestroyHash.h"
#include <string>
#include <assert.h>

WinApiCpp::BCryptDestroyHash::BCryptDestroyHash() noexcept
	: hHash       {}
	, pbHashObject{}
	, cbHashObject{}
	, valid_handle{}
{
}
WinApiCpp::BCryptDestroyHash::BCryptDestroyHash
( BCRYPT_ALG_HANDLE    hHash       
, PUCHAR               pbHashObject
, ULONG                cbHashObject
) noexcept
	: hHash       (hHash       )
	, pbHashObject(pbHashObject)
	, cbHashObject(cbHashObject)
	, valid_handle(true        )
{
}
WinApiCpp::BCryptDestroyHash::~BCryptDestroyHash()
{
	if (valid_handle) {
		Execute(hHash);
	}
	delete[] pbHashObject;
}
WinApiCpp::BCryptDestroyHash::BCryptDestroyHash(BCryptDestroyHash&& r) noexcept
	: hHash       (r.hHash            )
	, pbHashObject(r.pbHashObject     )
	, cbHashObject(r.cbHashObject     )
	, valid_handle(r.valid_handle     )
{
	r.hHash            = {};
	r.pbHashObject     = {};
	r.cbHashObject     = {};
	r.valid_handle     = {};
}
auto WinApiCpp::BCryptDestroyHash::operator=(BCryptDestroyHash&& r) noexcept->BCryptDestroyHash&
{
	std::swap(hHash       , r.hHash            );
	std::swap(pbHashObject, r.pbHashObject     );
	std::swap(cbHashObject, r.cbHashObject     );
	std::swap(valid_handle, r.valid_handle     );
	return *this;
}
WinApiCpp::BCryptDestroyHash::operator bool() const noexcept
{
	return valid_handle;
}
BCRYPT_ALG_HANDLE WinApiCpp::BCryptDestroyHash::get() const noexcept
{
	assert(valid_handle);
	return hHash;
}
BCRYPT_HASH_HANDLE WinApiCpp::BCryptDestroyHash::release() noexcept
{
	assert(valid_handle);
	auto retval  = hHash  ;
	hHash        = nullptr;
	valid_handle = false  ;
	return retval;
}
void WinApiCpp::BCryptDestroyHash::Execute(_Inout_ BCRYPT_HASH_HANDLE  hHash) noexcept
{
	if (const auto status = ::BCryptDestroyHash
	( /*_Inout_ BCRYPT_HASH_HANDLE  hHash*/hHash
	)) {
#ifdef _DEBUG
		OutputDebugStringA((__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): BCryptDestroyHash failed with "+std::to_string(status) + "\n").c_str());
#endif
	}
}
