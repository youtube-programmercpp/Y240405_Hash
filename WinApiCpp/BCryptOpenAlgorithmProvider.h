// BCryptOpenAlgorithmProvider ä÷êî Copyright(C) https://www.youtube.com/@ProgrammerCpp
#pragma once
#include "BCryptCloseAlgorithmProvider.h"
#include <Windows.h>
#include <bcrypt.h>
#pragma comment(lib, "bcrypt")
namespace WinApiCpp {
	auto BCryptOpenAlgorithmProvider
	( _In_z_      LPCWSTR               pszAlgId              
	, _In_opt_z_  LPCWSTR               pszImplementation     
	, _In_        ULONG                 dwFlags               
	)-> BCryptCloseAlgorithmProvider;
}
