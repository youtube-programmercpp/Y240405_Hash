#pragma once
#include <BCryptCpp/Hash.h>
namespace BCryptClr {
	public ref class Hash
	{
		BCryptCpp::Hash    * handle     ;
		array<System::Byte>^ output;
	internal:
		Hash
		( BCryptCpp::Hash    * handle
		, array<System::Byte>^ output
		);
	public:
		~Hash();
		auto HashData(array<System::Byte>^ input)->Hash^;
		array<System::Byte>^ FinishHash();
	};
}
