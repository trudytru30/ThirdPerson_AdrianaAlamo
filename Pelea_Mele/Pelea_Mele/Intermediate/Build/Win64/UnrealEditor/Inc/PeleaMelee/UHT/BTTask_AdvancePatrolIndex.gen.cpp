// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BTTask_AdvancePatrolIndex.h"
#include "BehaviorTree/BehaviorTreeTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeBTTask_AdvancePatrolIndex() {}

// ********** Begin Cross Module References ********************************************************
AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FBlackboardKeySelector();
PELEAMELEE_API UClass* Z_Construct_UClass_UBTTask_AdvancePatrolIndex();
PELEAMELEE_API UClass* Z_Construct_UClass_UBTTask_AdvancePatrolIndex_NoRegister();
UPackage* Z_Construct_UPackage__Script_PeleaMelee();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UBTTask_AdvancePatrolIndex ***********************************************
void UBTTask_AdvancePatrolIndex::StaticRegisterNativesUBTTask_AdvancePatrolIndex()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UBTTask_AdvancePatrolIndex;
UClass* UBTTask_AdvancePatrolIndex::GetPrivateStaticClass()
{
	using TClass = UBTTask_AdvancePatrolIndex;
	if (!Z_Registration_Info_UClass_UBTTask_AdvancePatrolIndex.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("BTTask_AdvancePatrolIndex"),
			Z_Registration_Info_UClass_UBTTask_AdvancePatrolIndex.InnerSingleton,
			StaticRegisterNativesUBTTask_AdvancePatrolIndex,
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
	return Z_Registration_Info_UClass_UBTTask_AdvancePatrolIndex.InnerSingleton;
}
UClass* Z_Construct_UClass_UBTTask_AdvancePatrolIndex_NoRegister()
{
	return UBTTask_AdvancePatrolIndex::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UBTTask_AdvancePatrolIndex_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BTTask_AdvancePatrolIndex.h" },
		{ "ModuleRelativePath", "Public/BTTask_AdvancePatrolIndex.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PatrolRouteKey_MetaData[] = {
		{ "Category", "Blackboard" },
		{ "ModuleRelativePath", "Public/BTTask_AdvancePatrolIndex.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PatrolIndexKey_MetaData[] = {
		{ "Category", "Blackboard" },
		{ "ModuleRelativePath", "Public/BTTask_AdvancePatrolIndex.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_PatrolRouteKey;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PatrolIndexKey;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTTask_AdvancePatrolIndex>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTTask_AdvancePatrolIndex_Statics::NewProp_PatrolRouteKey = { "PatrolRouteKey", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTTask_AdvancePatrolIndex, PatrolRouteKey), Z_Construct_UScriptStruct_FBlackboardKeySelector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PatrolRouteKey_MetaData), NewProp_PatrolRouteKey_MetaData) }; // 815030858
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UBTTask_AdvancePatrolIndex_Statics::NewProp_PatrolIndexKey = { "PatrolIndexKey", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTTask_AdvancePatrolIndex, PatrolIndexKey), Z_Construct_UScriptStruct_FBlackboardKeySelector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PatrolIndexKey_MetaData), NewProp_PatrolIndexKey_MetaData) }; // 815030858
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBTTask_AdvancePatrolIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTTask_AdvancePatrolIndex_Statics::NewProp_PatrolRouteKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTTask_AdvancePatrolIndex_Statics::NewProp_PatrolIndexKey,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_AdvancePatrolIndex_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UBTTask_AdvancePatrolIndex_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
	(UObject* (*)())Z_Construct_UPackage__Script_PeleaMelee,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_AdvancePatrolIndex_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTTask_AdvancePatrolIndex_Statics::ClassParams = {
	&UBTTask_AdvancePatrolIndex::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UBTTask_AdvancePatrolIndex_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_AdvancePatrolIndex_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTTask_AdvancePatrolIndex_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTTask_AdvancePatrolIndex_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBTTask_AdvancePatrolIndex()
{
	if (!Z_Registration_Info_UClass_UBTTask_AdvancePatrolIndex.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTTask_AdvancePatrolIndex.OuterSingleton, Z_Construct_UClass_UBTTask_AdvancePatrolIndex_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBTTask_AdvancePatrolIndex.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBTTask_AdvancePatrolIndex);
UBTTask_AdvancePatrolIndex::~UBTTask_AdvancePatrolIndex() {}
// ********** End Class UBTTask_AdvancePatrolIndex *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_BTTask_AdvancePatrolIndex_h__Script_PeleaMelee_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBTTask_AdvancePatrolIndex, UBTTask_AdvancePatrolIndex::StaticClass, TEXT("UBTTask_AdvancePatrolIndex"), &Z_Registration_Info_UClass_UBTTask_AdvancePatrolIndex, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTTask_AdvancePatrolIndex), 457156009U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_BTTask_AdvancePatrolIndex_h__Script_PeleaMelee_707287027(TEXT("/Script/PeleaMelee"),
	Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_BTTask_AdvancePatrolIndex_h__Script_PeleaMelee_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_BTTask_AdvancePatrolIndex_h__Script_PeleaMelee_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
