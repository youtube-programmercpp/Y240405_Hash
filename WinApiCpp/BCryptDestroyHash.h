// BCryptDestroyHash クラス Copyright(C) https://www.youtube.com/@ProgrammerCpp
#pragma once
#include <Windows.h>
#include <bcrypt.h>
#pragma comment(lib, "bcrypt")
namespace WinApiCpp {
	class BCryptDestroyHash {
		BCRYPT_HASH_HANDLE  hHash       ;
		PUCHAR              pbHashObject;
		ULONG               cbHashObject;
		bool                valid_handle       ;//有効フラグ
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
		BCRYPT_HASH_HANDLE release() noexcept;
		static void Execute(_Inout_ BCRYPT_HASH_HANDLE  hHash) noexcept;
	};
}
