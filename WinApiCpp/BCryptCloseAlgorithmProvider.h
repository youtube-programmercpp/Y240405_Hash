// BCryptCloseAlgorithmProvider ƒNƒ‰ƒX Copyright(C) https://www.youtube.com/@ProgrammerCpp
#pragma once
#include <Windows.h>
#include <bcrypt.h>
#pragma comment(lib, "bcrypt")
namespace WinApiCpp {
	class BCryptCloseAlgorithmProvider {
		BCRYPT_ALG_HANDLE   hAlgorithm       ;
		ULONG               dwFlags          ;
		bool                valid_handle     ;
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
		BCRYPT_ALG_HANDLE release() noexcept;
		static void Execute
		( _Inout_ BCRYPT_ALG_HANDLE   hAlgorithm
		, _In_    ULONG               dwFlags   
		) noexcept;
	};
}
