// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Ninja.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeNinja() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
PELEA_MELE_API UClass* Z_Construct_UClass_ANinja();
PELEA_MELE_API UClass* Z_Construct_UClass_ANinja_NoRegister();
UPackage* Z_Construct_UPackage__Script_Pelea_Mele();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ANinja *******************************************************************
void ANinja::StaticRegisterNativesANinja()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_ANinja;
UClass* ANinja::GetPrivateStaticClass()
{
	using TClass = ANinja;
	if (!Z_Registration_Info_UClass_ANinja.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("Ninja"),
			Z_Registration_Info_UClass_ANinja.InnerSingleton,
			StaticRegisterNativesANinja,
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
	return Z_Registration_Info_UClass_ANinja.InnerSingleton;
}
UClass* Z_Construct_UClass_ANinja_NoRegister()
{
	return ANinja::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ANinja_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Ninja.h" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShurikensCount_MetaData[] = {
		{ "Category", "Inventory|Ammo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Variables que en tu BP salen como \"Shurikens Count\" y \"Bomb Count\"\n" },
#endif
		{ "ModuleRelativePath", "Public/Ninja.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Variables que en tu BP salen como \"Shurikens Count\" y \"Bomb Count\"" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BombCount_MetaData[] = {
		{ "Category", "Inventory|Ammo" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ShurikensCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BombCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANinja>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_ShurikensCount = { "ShurikensCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, ShurikensCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShurikensCount_MetaData), NewProp_ShurikensCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_BombCount = { "BombCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, BombCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BombCount_MetaData), NewProp_BombCount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANinja_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_ShurikensCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_BombCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANinja_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ANinja_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Pelea_Mele,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANinja_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ANinja_Statics::ClassParams = {
	&ANinja::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ANinja_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ANinja_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ANinja_Statics::Class_MetaDataParams), Z_Construct_UClass_ANinja_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ANinja()
{
	if (!Z_Registration_Info_UClass_ANinja.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANinja.OuterSingleton, Z_Construct_UClass_ANinja_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ANinja.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ANinja);
ANinja::~ANinja() {}
// ********** End Class ANinja *********************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Pelea_Mele_Source_Pelea_Mele_Public_Ninja_h__Script_Pelea_Mele_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ANinja, ANinja::StaticClass, TEXT("ANinja"), &Z_Registration_Info_UClass_ANinja, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANinja), 2139941361U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Pelea_Mele_Source_Pelea_Mele_Public_Ninja_h__Script_Pelea_Mele_1307324993(TEXT("/Script/Pelea_Mele"),
	Z_CompiledInDeferFile_FID_Pelea_Mele_Source_Pelea_Mele_Public_Ninja_h__Script_Pelea_Mele_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Pelea_Mele_Source_Pelea_Mele_Public_Ninja_h__Script_Pelea_Mele_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
