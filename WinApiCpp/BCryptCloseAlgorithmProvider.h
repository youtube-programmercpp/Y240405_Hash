#pragma once
#include <Windows.h>
#include <bcrypt.h>
#pragma comment(lib, "bcrypt")
namespace WinApiCpp {
	class BCryptCloseAlgorithmProvider {
		BCRYPT_ALG_HANDLE   hAlgorithm;
		ULONG               dwFlags   ;
		bool                valid     ;//—LŒøƒtƒ‰ƒO
	public:
		BCryptCloseAlgorithmProvider() noexcept;
		BCryptCloseAlgorithmProvider
		( BCRYPT_ALG_HANDLE   hAlgorithm
		, ULONG               dwFlags   
		) noexcept;
		~BCryptCloseAlgorithmProvider();
		BCryptCloseAlgorithmProvider(BCryptCloseAlgorithmProvider&& r) noexcept;
		auto operator=(BCryptCloseAlgorithmProvider&& r) noexcept->BCryptCloseAlgorithmProvider&;
		explicit operator bool() const noexcept;
		BCRYPT_ALG_HANDLE get() const noexcept;
	};
}
