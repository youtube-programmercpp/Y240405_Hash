#include "BCryptCloseAlgorithmProvider.h"
#include <string>

WinApiCpp::BCryptCloseAlgorithmProvider::BCryptCloseAlgorithmProvider() noexcept
	: hAlgorithm{}
	, dwFlags   {}
	, valid     {}
{
}
WinApiCpp::BCryptCloseAlgorithmProvider::BCryptCloseAlgorithmProvider
( BCRYPT_ALG_HANDLE   hAlgorithm
, ULONG               dwFlags   
) noexcept
	: hAlgorithm(hAlgorithm)
	, dwFlags   (dwFlags   )
	, valid     (true      )
{
}
WinApiCpp::BCryptCloseAlgorithmProvider::~BCryptCloseAlgorithmProvider()
{
	if (valid) {
		if (const auto status = ::BCryptCloseAlgorithmProvider
		( hAlgorithm
		, dwFlags   
		))
			OutputDebugStringA((__FILE__ "(" _CRT_STRINGIZE(__LINE__) "): BCryptCloseAlgorithmProvider failed with "+std::to_string(status) + "\n").c_str());
	}
}
WinApiCpp::BCryptCloseAlgorithmProvider::BCryptCloseAlgorithmProvider(BCryptCloseAlgorithmProvider&& r) noexcept
	: hAlgorithm(r.hAlgorithm)
	, dwFlags   (r.dwFlags   )
	, valid     (r.valid     )
{
	r.hAlgorithm = {};
	r.dwFlags    = {};
	r.valid      = {};
}
auto WinApiCpp::BCryptCloseAlgorithmProvider::operator=(BCryptCloseAlgorithmProvider&& r) noexcept->BCryptCloseAlgorithmProvider&
{
	std::swap(hAlgorithm, r.hAlgorithm);
	std::swap(dwFlags   , r.dwFlags   );
	std::swap(valid     , r.valid     );
	return *this;
}
WinApiCpp::BCryptCloseAlgorithmProvider::operator bool() const noexcept
{
	return valid;
}
BCRYPT_ALG_HANDLE WinApiCpp::BCryptCloseAlgorithmProvider::get() const noexcept
{
	return hAlgorithm;
}
