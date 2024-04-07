#include "AlgorithmProvider.h"
#include <vcclr.h>
#include <exception>
#include <memory>

BCryptClr::AlgorithmProvider::AlgorithmProvider(System::String^ AlgId)
	: handle()
{
	const pin_ptr<const wchar_t> pszAlgId = PtrToStringChars(AlgId);
	try {
		handle = new BCryptCpp::AlgorithmProvider(pszAlgId, nullptr, 0UL);
	}
	catch (const std::exception& e) {
		throw gcnew System::Exception(gcnew System::String(e.what()));
	}
}
BCryptClr::AlgorithmProvider::~AlgorithmProvider()
{
	delete handle;
}
auto BCryptClr::AlgorithmProvider::CreateHash() -> Hash^
{
	try {
		auto pHash = std::make_unique<BCryptCpp::Hash>(handle->CreateHash
		( /*_Out_writes_bytes_all_opt_(cbHashObject) PUCHAR pbHashObject*/nullptr
		, /*_In_                                     ULONG  cbHashObject*/0UL    
		, /*_In_reads_bytes_opt_(cbSecret)           PUCHAR pbSecret    */nullptr
		, /*_In_                                     ULONG  cbSecret    */0UL    
		, /*_In_                                     ULONG  dwFlags     */0UL    
		));
		ULONG cbHash;
		ULONG cbResult;
		handle->GetProperty
		( /*_In_z_                                          LPCWSTR         pszProperty*/BCRYPT_HASH_LENGTH
		, /*_Out_writes_bytes_to_opt_(cbOutput, *pcbResult) PUCHAR          pbOutput   */PUCHAR(&cbHash)
		, /*_In_                                            ULONG           cbOutput   */sizeof cbHash
		, /*_Out_                                           ULONG         * pcbResult  */&cbResult
		, /*_In_                                            ULONG           dwFlags    */0UL    
		);
		auto retval = gcnew Hash
		( /*WinApiCpp::BCryptDestroyHash * handle*/pHash.get()
		, /*array<System::Byte>          ^ output*/gcnew array<System::Byte>(cbHash)
		);
		(void)pHash.release();
		return retval;
	}
	catch (const std::exception& e) {
		throw gcnew System::Exception(gcnew System::String(e.what()));
	}
}
