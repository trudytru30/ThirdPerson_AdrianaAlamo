// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PatrolRoute.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodePatrolRoute() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_ATargetPoint_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
PELEAMELEE_API UClass* Z_Construct_UClass_APatrolRoute();
PELEAMELEE_API UClass* Z_Construct_UClass_APatrolRoute_NoRegister();
UPackage* Z_Construct_UPackage__Script_PeleaMelee();
// ********** End Cross Module References **********************************************************

// ********** Begin Class APatrolRoute Function GetNearestIndex ************************************
struct Z_Construct_UFunction_APatrolRoute_GetNearestIndex_Statics
{
	struct PatrolRoute_eventGetNearestIndex_Parms
	{
		FVector WorldLocation;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Patrol" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Retorna el indice del punto de la ruta m\xc3\xa1s cercano. Si no existe devuelve -1\x09\n" },
#endif
		{ "ModuleRelativePath", "Public/PatrolRoute.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Retorna el indice del punto de la ruta m\xc3\xa1s cercano. Si no existe devuelve -1" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_WorldLocation;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APatrolRoute_GetNearestIndex_Statics::NewProp_WorldLocation = { "WorldLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PatrolRoute_eventGetNearestIndex_Parms, WorldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldLocation_MetaData), NewProp_WorldLocation_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_APatrolRoute_GetNearestIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PatrolRoute_eventGetNearestIndex_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APatrolRoute_GetNearestIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APatrolRoute_GetNearestIndex_Statics::NewProp_WorldLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APatrolRoute_GetNearestIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APatrolRoute_GetNearestIndex_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APatrolRoute_GetNearestIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_APatrolRoute, nullptr, "GetNearestIndex", Z_Construct_UFunction_APatrolRoute_GetNearestIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APatrolRoute_GetNearestIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_APatrolRoute_GetNearestIndex_Statics::PatrolRoute_eventGetNearestIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APatrolRoute_GetNearestIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_APatrolRoute_GetNearestIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_APatrolRoute_GetNearestIndex_Statics::PatrolRoute_eventGetNearestIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APatrolRoute_GetNearestIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APatrolRoute_GetNearestIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APatrolRoute::execGetNearestIndex)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_WorldLocation);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetNearestIndex(Z_Param_Out_WorldLocation);
	P_NATIVE_END;
}
// ********** End Class APatrolRoute Function GetNearestIndex **************************************

// ********** Begin Class APatrolRoute Function GetPoint *******************************************
struct Z_Construct_UFunction_APatrolRoute_GetPoint_Statics
{
	struct PatrolRoute_eventGetPoint_Parms
	{
		int32 Index;
		ATargetPoint* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Patrol" },
		{ "ModuleRelativePath", "Public/PatrolRoute.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_APatrolRoute_GetPoint_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PatrolRoute_eventGetPoint_Parms, Index), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APatrolRoute_GetPoint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PatrolRoute_eventGetPoint_Parms, ReturnValue), Z_Construct_UClass_ATargetPoint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APatrolRoute_GetPoint_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APatrolRoute_GetPoint_Statics::NewProp_Index,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APatrolRoute_GetPoint_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APatrolRoute_GetPoint_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APatrolRoute_GetPoint_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_APatrolRoute, nullptr, "GetPoint", Z_Construct_UFunction_APatrolRoute_GetPoint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APatrolRoute_GetPoint_Statics::PropPointers), sizeof(Z_Construct_UFunction_APatrolRoute_GetPoint_Statics::PatrolRoute_eventGetPoint_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APatrolRoute_GetPoint_Statics::Function_MetaDataParams), Z_Construct_UFunction_APatrolRoute_GetPoint_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_APatrolRoute_GetPoint_Statics::PatrolRoute_eventGetPoint_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APatrolRoute_GetPoint()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APatrolRoute_GetPoint_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APatrolRoute::execGetPoint)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Index);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ATargetPoint**)Z_Param__Result=P_THIS->GetPoint(Z_Param_Index);
	P_NATIVE_END;
}
// ********** End Class APatrolRoute Function GetPoint *********************************************

// ********** Begin Class APatrolRoute Function NumPoints ******************************************
struct Z_Construct_UFunction_APatrolRoute_NumPoints_Statics
{
	struct PatrolRoute_eventNumPoints_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Patrol" },
		{ "ModuleRelativePath", "Public/PatrolRoute.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_APatrolRoute_NumPoints_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PatrolRoute_eventNumPoints_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APatrolRoute_NumPoints_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APatrolRoute_NumPoints_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APatrolRoute_NumPoints_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APatrolRoute_NumPoints_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_APatrolRoute, nullptr, "NumPoints", Z_Construct_UFunction_APatrolRoute_NumPoints_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APatrolRoute_NumPoints_Statics::PropPointers), sizeof(Z_Construct_UFunction_APatrolRoute_NumPoints_Statics::PatrolRoute_eventNumPoints_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APatrolRoute_NumPoints_Statics::Function_MetaDataParams), Z_Construct_UFunction_APatrolRoute_NumPoints_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_APatrolRoute_NumPoints_Statics::PatrolRoute_eventNumPoints_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APatrolRoute_NumPoints()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APatrolRoute_NumPoints_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APatrolRoute::execNumPoints)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->NumPoints();
	P_NATIVE_END;
}
// ********** End Class APatrolRoute Function NumPoints ********************************************

// ********** Begin Class APatrolRoute *************************************************************
void APatrolRoute::StaticRegisterNativesAPatrolRoute()
{
	UClass* Class = APatrolRoute::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetNearestIndex", &APatrolRoute::execGetNearestIndex },
		{ "GetPoint", &APatrolRoute::execGetPoint },
		{ "NumPoints", &APatrolRoute::execNumPoints },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_APatrolRoute;
UClass* APatrolRoute::GetPrivateStaticClass()
{
	using TClass = APatrolRoute;
	if (!Z_Registration_Info_UClass_APatrolRoute.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("PatrolRoute"),
			Z_Registration_Info_UClass_APatrolRoute.InnerSingleton,
			StaticRegisterNativesAPatrolRoute,
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
	return Z_Registration_Info_UClass_APatrolRoute.InnerSingleton;
}
UClass* Z_Construct_UClass_APatrolRoute_NoRegister()
{
	return APatrolRoute::GetPrivateStaticClass();
}
struct Z_Construct_UClass_APatrolRoute_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "PatrolRoute.h" },
		{ "ModuleRelativePath", "Public/PatrolRoute.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLoop_MetaData[] = {
		{ "Category", "Patrol" },
		{ "ModuleRelativePath", "Public/PatrolRoute.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Points_MetaData[] = {
		{ "Category", "Patrol" },
		{ "ModuleRelativePath", "Public/PatrolRoute.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Root_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PatrolRoute.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bLoop_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLoop;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Points_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Points;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Root;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_APatrolRoute_GetNearestIndex, "GetNearestIndex" }, // 3390093591
		{ &Z_Construct_UFunction_APatrolRoute_GetPoint, "GetPoint" }, // 3483135718
		{ &Z_Construct_UFunction_APatrolRoute_NumPoints, "NumPoints" }, // 3658914838
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APatrolRoute>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_APatrolRoute_Statics::NewProp_bLoop_SetBit(void* Obj)
{
	((APatrolRoute*)Obj)->bLoop = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_APatrolRoute_Statics::NewProp_bLoop = { "bLoop", nullptr, (EPropertyFlags)0x0010000000000815, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(APatrolRoute), &Z_Construct_UClass_APatrolRoute_Statics::NewProp_bLoop_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLoop_MetaData), NewProp_bLoop_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APatrolRoute_Statics::NewProp_Points_Inner = { "Points", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ATargetPoint_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APatrolRoute_Statics::NewProp_Points = { "Points", nullptr, (EPropertyFlags)0x0010000000000815, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APatrolRoute, Points), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Points_MetaData), NewProp_Points_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APatrolRoute_Statics::NewProp_Root = { "Root", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APatrolRoute, Root), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Root_MetaData), NewProp_Root_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APatrolRoute_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APatrolRoute_Statics::NewProp_bLoop,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APatrolRoute_Statics::NewProp_Points_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APatrolRoute_Statics::NewProp_Points,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APatrolRoute_Statics::NewProp_Root,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APatrolRoute_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_APatrolRoute_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_PeleaMelee,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APatrolRoute_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APatrolRoute_Statics::ClassParams = {
	&APatrolRoute::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_APatrolRoute_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_APatrolRoute_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APatrolRoute_Statics::Class_MetaDataParams), Z_Construct_UClass_APatrolRoute_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APatrolRoute()
{
	if (!Z_Registration_Info_UClass_APatrolRoute.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APatrolRoute.OuterSingleton, Z_Construct_UClass_APatrolRoute_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APatrolRoute.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(APatrolRoute);
APatrolRoute::~APatrolRoute() {}
// ********** End Class APatrolRoute ***************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_PatrolRoute_h__Script_PeleaMelee_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APatrolRoute, APatrolRoute::StaticClass, TEXT("APatrolRoute"), &Z_Registration_Info_UClass_APatrolRoute, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APatrolRoute), 925390836U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_PatrolRoute_h__Script_PeleaMelee_3955009474(TEXT("/Script/PeleaMelee"),
	Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_PatrolRoute_h__Script_PeleaMelee_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_PatrolRoute_h__Script_PeleaMelee_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
