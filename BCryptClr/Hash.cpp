#include "Hash.h"
#include <exception>

BCryptClr::Hash::Hash
( BCryptCpp::Hash    * handle
, array<System::Byte>^ output
)
	: handle(handle)
	, output(output)
{
}
BCryptClr::Hash::~Hash()
{
	delete handle;
}
auto BCryptClr::Hash::HashData(array<System::Byte>^ input)->Hash^
{
	try {
		const pin_ptr<UCHAR> pbInput = &input[0];
		handle->HashData
		( /*_In_reads_bytes_(cbInput) PUCHAR             pbInput*/pbInput
		, /*_In_                      ULONG              cbInput*/input->Length
		);
		return this;
	}
	catch (const std::exception& e) {
		throw gcnew System::Exception(gcnew System::String(e.what()));
	}
}
array<System::Byte>^ BCryptClr::Hash::FinishHash()
{
	try {
		const pin_ptr<UCHAR> pbOutput = &output[0];
		handle->FinishHash
		( /*_Out_writes_bytes_all_(cbOutput) PUCHAR             pbOutput*/pbOutput
		, /*_In_                             ULONG              cbOutput*/output->Length
		, /*_In_                             ULONG              dwFlags */0UL
		);
		return output;
	}
	catch (const std::exception& e) {
		throw gcnew System::Exception(gcnew System::String(e.what()));
	}
}
