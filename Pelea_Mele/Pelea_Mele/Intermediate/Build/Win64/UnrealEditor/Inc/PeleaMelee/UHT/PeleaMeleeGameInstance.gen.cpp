// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PeleaMeleeGameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePeleaMeleeGameInstance() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
PELEAMELEE_API UClass* Z_Construct_UClass_UPeleaMeleeGameInstance();
PELEAMELEE_API UClass* Z_Construct_UClass_UPeleaMeleeGameInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_PeleaMelee();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UPeleaMeleeGameInstance **************************************************
void UPeleaMeleeGameInstance::StaticRegisterNativesUPeleaMeleeGameInstance()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UPeleaMeleeGameInstance;
UClass* UPeleaMeleeGameInstance::GetPrivateStaticClass()
{
	using TClass = UPeleaMeleeGameInstance;
	if (!Z_Registration_Info_UClass_UPeleaMeleeGameInstance.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PeleaMeleeGameInstance"),
			Z_Registration_Info_UClass_UPeleaMeleeGameInstance.InnerSingleton,
			StaticRegisterNativesUPeleaMeleeGameInstance,
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
	return Z_Registration_Info_UClass_UPeleaMeleeGameInstance.InnerSingleton;
}
UClass* Z_Construct_UClass_UPeleaMeleeGameInstance_NoRegister()
{
	return UPeleaMeleeGameInstance::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UPeleaMeleeGameInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "PeleaMeleeGameInstance.h" },
		{ "ModuleRelativePath", "Public/PeleaMeleeGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShurikensCount_MetaData[] = {
		{ "Category", "RunState" },
		{ "ModuleRelativePath", "Public/PeleaMeleeGameInstance.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BombCount_MetaData[] = {
		{ "Category", "RunState" },
		{ "ModuleRelativePath", "Public/PeleaMeleeGameInstance.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ShurikensCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BombCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPeleaMeleeGameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPeleaMeleeGameInstance_Statics::NewProp_ShurikensCount = { "ShurikensCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPeleaMeleeGameInstance, ShurikensCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShurikensCount_MetaData), NewProp_ShurikensCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPeleaMeleeGameInstance_Statics::NewProp_BombCount = { "BombCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPeleaMeleeGameInstance, BombCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BombCount_MetaData), NewProp_BombCount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPeleaMeleeGameInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPeleaMeleeGameInstance_Statics::NewProp_ShurikensCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPeleaMeleeGameInstance_Statics::NewProp_BombCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPeleaMeleeGameInstance_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UPeleaMeleeGameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_PeleaMelee,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPeleaMeleeGameInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPeleaMeleeGameInstance_Statics::ClassParams = {
	&UPeleaMeleeGameInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UPeleaMeleeGameInstance_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UPeleaMeleeGameInstance_Statics::PropPointers),
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPeleaMeleeGameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UPeleaMeleeGameInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPeleaMeleeGameInstance()
{
	if (!Z_Registration_Info_UClass_UPeleaMeleeGameInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPeleaMeleeGameInstance.OuterSingleton, Z_Construct_UClass_UPeleaMeleeGameInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPeleaMeleeGameInstance.OuterSingleton;
}
UPeleaMeleeGameInstance::UPeleaMeleeGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPeleaMeleeGameInstance);
UPeleaMeleeGameInstance::~UPeleaMeleeGameInstance() {}
// ********** End Class UPeleaMeleeGameInstance ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_PeleaMeleeGameInstance_h__Script_PeleaMelee_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPeleaMeleeGameInstance, UPeleaMeleeGameInstance::StaticClass, TEXT("UPeleaMeleeGameInstance"), &Z_Registration_Info_UClass_UPeleaMeleeGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPeleaMeleeGameInstance), 3778356646U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_PeleaMeleeGameInstance_h__Script_PeleaMelee_2135671077(TEXT("/Script/PeleaMelee"),
	Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_PeleaMeleeGameInstance_h__Script_PeleaMelee_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_PeleaMeleeGameInstance_h__Script_PeleaMelee_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
