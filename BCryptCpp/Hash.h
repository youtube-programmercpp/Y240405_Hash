#pragma once
#include <Windows.h>
#include <bcrypt.h>
#include <array>
namespace BCryptCpp {
	class __declspec(
#ifdef BCRYPTCPP_EXPORTS
		dllexport
#else
		dllimport
#endif
		) Hash {
		BCRYPT_HASH_HANDLE hHash       ;
		bool               valid_handle;
	public:
		Hash() noexcept;
		Hash(BCRYPT_HASH_HANDLE hHash) noexcept;
		~Hash();
		Hash(Hash&& r) noexcept;
		auto operator=(Hash&& r) noexcept->Hash&;
		explicit operator bool() const noexcept;

		auto HashData
		( _In_reads_bytes_(cbInput)    PUCHAR   pbInput
		, _In_                         ULONG    cbInput
		, _In_                         ULONG    dwFlags = 0UL
		) const->const Hash&;
		void FinishHash
		( _Out_writes_bytes_all_(cbOutput) PUCHAR             pbOutput
		, _In_                             ULONG              cbOutput
		, _In_                             ULONG              dwFlags 
		) const;
		template<ULONG cbOutput>std::array<UCHAR, cbOutput> FinishHash(_In_ ULONG dwFlags = 0UL) const
		{
			std::array<UCHAR, cbOutput> retval;
			FinishHash(retval.data(), cbOutput, dwFlags);
			return retval;
		}
	};
}
