#pragma once
#include "Hash.h"
#include <BCryptCpp/AlgorithmProvider.h>
#pragma comment(lib, "BCryptCpp")
namespace BCryptClr {
	public ref class AlgorithmProvider
	{
		BCryptCpp::AlgorithmProvider* handle;
	public:
		AlgorithmProvider(System::String^ AlgId);
		~AlgorithmProvider();
		auto CreateHash() -> Hash^;
	};
}
