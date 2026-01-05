// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePeleaMelee_init() {}
	PELEAMELEE_API UFunction* Z_Construct_UDelegateFunction_PeleaMelee_OnHealthChangedSignature__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_PeleaMelee;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_PeleaMelee()
	{
		if (!Z_Registration_Info_UPackage__Script_PeleaMelee.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_PeleaMelee_OnHealthChangedSignature__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/PeleaMelee",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x37DB26C6,
				0x85B34450,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_PeleaMelee.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_PeleaMelee.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_PeleaMelee(Z_Construct_UPackage__Script_PeleaMelee, TEXT("/Script/PeleaMelee"), Z_Registration_Info_UPackage__Script_PeleaMelee, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x37DB26C6, 0x85B34450));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
