// BCryptCloseAlgorithmProvider ƒNƒ‰ƒX Copyright(C) https://www.youtube.com/@ProgrammerCpp
#include "BCryptCloseAlgorithmProvider.h"
#include <string>
#include <assert.h>

WinApiCpp::BCryptCloseAlgorithmProvider::BCryptCloseAlgorithmProvider() noexcept
	: hAlgorithm       {}
	, dwFlags          {}
	, valid_handle     {}
{
}
WinApiCpp::BCryptCloseAlgorithmProvider::BCryptCloseAlgorithmProvider
( BCRYPT_ALG_HANDLE   hAlgorithm
, ULONG               dwFlags   
) noexcept
	: hAlgorithm       (hAlgorithm)
	, dwFlags          (dwFlags   )
	, valid_handle     (true      )
{
}
WinApiCpp::BCryptCloseAlgorithmProvider::~BCryptCloseAlgorithmProvider()
{
	if (valid_handle) {
		Execute(hAlgorithm, 0UL);
	}
}
WinApiCpp::BCryptCloseAlgorithmProvider::BCryptCloseAlgorithmProvider(BCryptCloseAlgorithmProvider&& r) noexcept
	: hAlgorithm       (r.hAlgorithm       )
	, dwFlags          (r.dwFlags          )
	, valid_handle     (r.valid_handle     )
{
	r.hAlgorithm        = {};
	r.dwFlags           = {};
	r.valid_handle      = {};
}
auto WinApiCpp::BCryptCloseAlgorithmProvider::operator=(BCryptCloseAlgorithmProvider&& r) noexcept->BCryptCloseAlgorithmProvider&
{
	std::swap(hAlgorithm       , r.hAlgorithm       );
	std::swap(dwFlags          , r.dwFlags          );
	std::swap(valid_handle     , r.valid_handle     );
	return *this;
}
WinApiCpp::BCryptCloseAlgorithmProvider::operator bool() const noexcept
{
	return valid_handle;
}
BCRYPT_ALG_HANDLE WinApiCpp::BCryptCloseAlgorithmProvider::get() const noexcept
{
	assert(valid_handle);
	return hAlgorithm;
}

BCRYPT_ALG_HANDLE WinApiCpp::BCryptCloseAlgorithmProvider::release() noexcept
{
	assert(valid_handle);
	auto retval        = hAlgorithm;
	dwFlags            = 0UL       ;
	hAlgorithm         = nullptr   ;
	valid_handle       = false     ;
	return retval;
}

void WinApiCpp::BCryptCloseAlgorithmProvider::Execute
( _Inout_ BCRYPT_ALG_HANDLE   hAlgorithm
, _In_    ULONG               dwFlags   
) noexcept
{
	if (const auto status = ::BCryptCloseAlgorithmProvider
	( /*_Inout_ BCRYPT_ALG_HANDLE   hAlgorithm*/hAlgorithm
	, /*_In_    ULONG               dwFlags   */dwFlags   
	)) {
#ifdef _DEBUG
		OutputDebugStringA((__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): BCryptCloseAlgorithmProvider failed with "+std::to_string(status) + "\n").c_str());
#endif
	}
}
