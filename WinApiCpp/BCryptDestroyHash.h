#pragma once
#include <Windows.h>
#include <bcrypt.h>
#pragma comment(lib, "bcrypt")
namespace WinApiCpp {
	class BCryptDestroyHash {
		BCRYPT_HASH_HANDLE  hHash       ;
		PUCHAR              pbHashObject;
		ULONG               cbHashObject;
		bool                valid_handle       ;//—LŒøƒtƒ‰ƒO
	public:
		BCryptDestroyHash() noexcept;
		BCryptDestroyHash
		( BCRYPT_HASH_HANDLE   hHash       
		, PUCHAR               pbHashObject
		, ULONG                cbHashObject
		) noexcept;
		~BCryptDestroyHash();
		BCryptDestroyHash(BCryptDestroyHash&& r) noexcept;
		auto operator=(BCryptDestroyHash&& r) noexcept->BCryptDestroyHash&;
		explicit operator bool() const noexcept;
		BCRYPT_HASH_HANDLE get() const noexcept;
	};
}
