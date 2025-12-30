// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PeleaMeleGameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePeleaMeleGameInstance() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
PELEA_MELE_API UClass* Z_Construct_UClass_UPeleaMeleGameInstance();
PELEA_MELE_API UClass* Z_Construct_UClass_UPeleaMeleGameInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_Pelea_Mele();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPeleaMeleGameInstance ***************************************************
void UPeleaMeleGameInstance::StaticRegisterNativesUPeleaMeleGameInstance()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UPeleaMeleGameInstance;
UClass* UPeleaMeleGameInstance::GetPrivateStaticClass()
{
	using TClass = UPeleaMeleGameInstance;
	if (!Z_Registration_Info_UClass_UPeleaMeleGameInstance.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PeleaMeleGameInstance"),
			Z_Registration_Info_UClass_UPeleaMeleGameInstance.InnerSingleton,
			StaticRegisterNativesUPeleaMeleGameInstance,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UPeleaMeleGameInstance.InnerSingleton;
}
UClass* Z_Construct_UClass_UPeleaMeleGameInstance_NoRegister()
{
	return UPeleaMeleGameInstance::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPeleaMeleGameInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "PeleaMeleGameInstance.h" },
		{ "ModuleRelativePath", "Public/PeleaMeleGameInstance.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPeleaMeleGameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UPeleaMeleGameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_Pelea_Mele,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPeleaMeleGameInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPeleaMeleGameInstance_Statics::ClassParams = {
	&UPeleaMeleGameInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPeleaMeleGameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UPeleaMeleGameInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPeleaMeleGameInstance()
{
	if (!Z_Registration_Info_UClass_UPeleaMeleGameInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPeleaMeleGameInstance.OuterSingleton, Z_Construct_UClass_UPeleaMeleGameInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPeleaMeleGameInstance.OuterSingleton;
}
UPeleaMeleGameInstance::UPeleaMeleGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPeleaMeleGameInstance);
UPeleaMeleGameInstance::~UPeleaMeleGameInstance() {}
// ********** End Class UPeleaMeleGameInstance *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Pelea_Mele_Source_Pelea_Mele_Public_PeleaMeleGameInstance_h__Script_Pelea_Mele_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPeleaMeleGameInstance, UPeleaMeleGameInstance::StaticClass, TEXT("UPeleaMeleGameInstance"), &Z_Registration_Info_UClass_UPeleaMeleGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPeleaMeleGameInstance), 3906866800U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Pelea_Mele_Source_Pelea_Mele_Public_PeleaMeleGameInstance_h__Script_Pelea_Mele_2039257651(TEXT("/Script/Pelea_Mele"),
	Z_CompiledInDeferFile_FID_Pelea_Mele_Source_Pelea_Mele_Public_PeleaMeleGameInstance_h__Script_Pelea_Mele_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Pelea_Mele_Source_Pelea_Mele_Public_PeleaMeleGameInstance_h__Script_Pelea_Mele_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
