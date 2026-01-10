// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BTTask_PatrolIndexSynced.h"
#include "BehaviorTree/BehaviorTreeTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeBTTask_PatrolIndexSynced() {}

// ********** Begin Cross Module References ********************************************************
AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FBlackboardKeySelector();
PELEAMELEE_API UClass* Z_Construct_UClass_UBTTask_PatrolIndexSynced();
PELEAMELEE_API UClass* Z_Construct_UClass_UBTTask_PatrolIndexSynced_NoRegister();
UPackage* Z_Construct_UPackage__Script_PeleaMelee();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UBTTask_PatrolIndexSynced ************************************************
void UBTTask_PatrolIndexSynced::StaticRegisterNativesUBTTask_PatrolIndexSynced()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UBTTask_PatrolIndexSynced;
UClass* UBTTask_PatrolIndexSynced::GetPrivateStaticClass()
{
	using TClass = UBTTask_PatrolIndexSynced;
	if (!Z_Registration_Info_UClass_UBTTask_PatrolIndexSynced.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("BTTask_PatrolIndexSynced"),
			Z_Registration_Info_UClass_UBTTask_PatrolIndexSynced.InnerSingleton,
			StaticRegisterNativesUBTTask_PatrolIndexSynced,
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
	return Z_Registration_Info_UClass_UBTTask_PatrolIndexSynced.InnerSingleton;
}
UClass* Z_Construct_UClass_UBTTask_PatrolIndexSynced_NoRegister()
{
	return UBTTask_PatrolIndexSynced::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UBTTask_PatrolIndexSynced_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BTTask_PatrolIndexSynced.h" },
		{ "ModuleRelativePath", "Public/BTTask_PatrolIndexSynced.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PatrolRouteKey_MetaData[] = {
		{ "Category", "Blackboard" },
		{ "ModuleRelativePath", "Public/BTTask_PatrolIndexSynced.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PatrolIndexKey_MetaData[] = {
		{ "Category", "Blackboard" },
		{ "ModuleRelativePath", "Public/BTTask_PatrolIndexSynced.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PatrolNeedsResyncKey_MetaData[] = {
		{ "Category", "Blackboard" },
		{ "ModuleRelativePath", "Public/BTTask_PatrolIndexSynced.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_PatrolRouteKey;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PatrolIndexKey;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PatrolNeedsResyncKey;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTTask_PatrolIndexSynced>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTTask_PatrolIndexSynced_Statics::NewProp_PatrolRouteKey = { "PatrolRouteKey", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTTask_PatrolIndexSynced, PatrolRouteKey), Z_Construct_UScriptStruct_FBlackboardKeySelector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PatrolRouteKey_MetaData), NewProp_PatrolRouteKey_MetaData) }; // 815030858
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTTask_PatrolIndexSynced_Statics::NewProp_PatrolIndexKey = { "PatrolIndexKey", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTTask_PatrolIndexSynced, PatrolIndexKey), Z_Construct_UScriptStruct_FBlackboardKeySelector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PatrolIndexKey_MetaData), NewProp_PatrolIndexKey_MetaData) }; // 815030858
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTTask_PatrolIndexSynced_Statics::NewProp_PatrolNeedsResyncKey = { "PatrolNeedsResyncKey", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTTask_PatrolIndexSynced, PatrolNeedsResyncKey), Z_Construct_UScriptStruct_FBlackboardKeySelector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PatrolNeedsResyncKey_MetaData), NewProp_PatrolNeedsResyncKey_MetaData) }; // 815030858
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBTTask_PatrolIndexSynced_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTTask_PatrolIndexSynced_Statics::NewProp_PatrolRouteKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTTask_PatrolIndexSynced_Statics::NewProp_PatrolIndexKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTTask_PatrolIndexSynced_Statics::NewProp_PatrolNeedsResyncKey,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_PatrolIndexSynced_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UBTTask_PatrolIndexSynced_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
	(UObject* (*)())Z_Construct_UPackage__Script_PeleaMelee,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_PatrolIndexSynced_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTTask_PatrolIndexSynced_Statics::ClassParams = {
	&UBTTask_PatrolIndexSynced::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UBTTask_PatrolIndexSynced_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_PatrolIndexSynced_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_PatrolIndexSynced_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTTask_PatrolIndexSynced_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBTTask_PatrolIndexSynced()
{
	if (!Z_Registration_Info_UClass_UBTTask_PatrolIndexSynced.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTTask_PatrolIndexSynced.OuterSingleton, Z_Construct_UClass_UBTTask_PatrolIndexSynced_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBTTask_PatrolIndexSynced.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBTTask_PatrolIndexSynced);
UBTTask_PatrolIndexSynced::~UBTTask_PatrolIndexSynced() {}
// ********** End Class UBTTask_PatrolIndexSynced **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_BTTask_PatrolIndexSynced_h__Script_PeleaMelee_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBTTask_PatrolIndexSynced, UBTTask_PatrolIndexSynced::StaticClass, TEXT("UBTTask_PatrolIndexSynced"), &Z_Registration_Info_UClass_UBTTask_PatrolIndexSynced, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTTask_PatrolIndexSynced), 592287353U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_BTTask_PatrolIndexSynced_h__Script_PeleaMelee_2029551135(TEXT("/Script/PeleaMelee"),
	Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_BTTask_PatrolIndexSynced_h__Script_PeleaMelee_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_BTTask_PatrolIndexSynced_h__Script_PeleaMelee_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
