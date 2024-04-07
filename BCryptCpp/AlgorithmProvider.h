#pragma once
#include "Hash.h"
namespace BCryptCpp {
	class __declspec(
#ifdef BCRYPTCPP_EXPORTS
		dllexport
#else
		dllimport
#endif
		) AlgorithmProvider  {
		BCRYPT_ALG_HANDLE hAlgorithm;
		bool              valid_handle     ;
	public:
		AlgorithmProvider() noexcept;
		AlgorithmProvider
		( _In_z_      LPCWSTR               pszAlgId              
		, _In_opt_z_  LPCWSTR               pszImplementation     
		, _In_        ULONG                 dwFlags               
		);
		~AlgorithmProvider();
		AlgorithmProvider(AlgorithmProvider&& r) noexcept;
		auto operator=(AlgorithmProvider&& r) noexcept->AlgorithmProvider&;
		explicit operator bool() const noexcept;
		auto CreateHash
		( _Out_writes_bytes_all_opt_(cbHashObject) PUCHAR              pbHashObject
		, _In_                                     ULONG               cbHashObject
		, _In_reads_bytes_opt_(cbSecret)           PUCHAR              pbSecret    
		, _In_                                     ULONG               cbSecret    
		, _In_                                     ULONG               dwFlags     
		) const->Hash;
		BCRYPT_ALG_HANDLE get() const noexcept;
		void GetProperty
		( _In_z_                                          LPCWSTR   pszProperty
		, _Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PUCHAR    pbOutput   
		, _In_                                            ULONG     cbOutput   
		, _Out_                                           ULONG   * pcbResult  
		, _In_                                            ULONG     dwFlags    
		) const;
	};
}
