#include "BCryptDestroyHash.h"
#include <string>

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
		if (const auto status = ::BCryptDestroyHash
		( hHash
		))
			OutputDebugStringA((__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): BCryptDestroyHash failed with "+std::to_string(status) + "\n").c_str());
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
	return hHash;
}
