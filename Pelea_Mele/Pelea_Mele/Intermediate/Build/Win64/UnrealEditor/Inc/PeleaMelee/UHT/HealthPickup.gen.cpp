// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HealthPickup.h"
#include "Engine/HitResult.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeHealthPickup() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
PELEAMELEE_API UClass* Z_Construct_UClass_AHealthPickup();
PELEAMELEE_API UClass* Z_Construct_UClass_AHealthPickup_NoRegister();
UPackage* Z_Construct_UPackage__Script_PeleaMelee();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AHealthPickup Function OnCollisionBeginOverlap ***************************
struct Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics
{
	struct HealthPickup_eventOnCollisionBeginOverlap_Parms
	{
		UPrimitiveComponent* OverlappedComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		int32 OtherBodyIndex;
		bool bFromSweep;
		FHitResult SweepResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HealthPickup.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static void NewProp_bFromSweep_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HealthPickup_eventOnCollisionBeginOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HealthPickup_eventOnCollisionBeginOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HealthPickup_eventOnCollisionBeginOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HealthPickup_eventOnCollisionBeginOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
{
	((HealthPickup_eventOnCollisionBeginOverlap_Parms*)Obj)->bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(HealthPickup_eventOnCollisionBeginOverlap_Parms), &Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(HealthPickup_eventOnCollisionBeginOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // 267591329
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AHealthPickup, nullptr, "OnCollisionBeginOverlap", Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::PropPointers), sizeof(Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::HealthPickup_eventOnCollisionBeginOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::HealthPickup_eventOnCollisionBeginOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AHealthPickup::execOnCollisionBeginOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnCollisionBeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// ********** End Class AHealthPickup Function OnCollisionBeginOverlap *****************************

// ********** Begin Class AHealthPickup ************************************************************
void AHealthPickup::StaticRegisterNativesAHealthPickup()
{
	UClass* Class = AHealthPickup::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnCollisionBeginOverlap", &AHealthPickup::execOnCollisionBeginOverlap },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AHealthPickup;
UClass* AHealthPickup::GetPrivateStaticClass()
{
	using TClass = AHealthPickup;
	if (!Z_Registration_Info_UClass_AHealthPickup.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("HealthPickup"),
			Z_Registration_Info_UClass_AHealthPickup.InnerSingleton,
			StaticRegisterNativesAHealthPickup,
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
	return Z_Registration_Info_UClass_AHealthPickup.InnerSingleton;
}
UClass* Z_Construct_UClass_AHealthPickup_NoRegister()
{
	return AHealthPickup::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AHealthPickup_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "HealthPickup.h" },
		{ "ModuleRelativePath", "Public/HealthPickup.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Root_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HealthPickup.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Collision_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HealthPickup.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HealthPickup.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealthDelta_MetaData[] = {
		{ "Category", "Potion" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Positivo = cura, negativo = veneno/da\xc3\xb1o\n" },
#endif
		{ "ModuleRelativePath", "Public/HealthPickup.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Positivo = cura, negativo = veneno/da\xc3\xb1o" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PickupSound_MetaData[] = {
		{ "Category", "Potion" },
		{ "ModuleRelativePath", "Public/HealthPickup.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bConsumeOnlyIfApplied_MetaData[] = {
		{ "Category", "Potion" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Si no cambia la vida, no se consume\n" },
#endif
		{ "ModuleRelativePath", "Public/HealthPickup.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Si no cambia la vida, no se consume" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Root;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Collision;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HealthDelta;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PickupSound;
	static void NewProp_bConsumeOnlyIfApplied_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bConsumeOnlyIfApplied;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AHealthPickup_OnCollisionBeginOverlap, "OnCollisionBeginOverlap" }, // 684105639
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHealthPickup>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHealthPickup_Statics::NewProp_Root = { "Root", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHealthPickup, Root), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Root_MetaData), NewProp_Root_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHealthPickup_Statics::NewProp_Collision = { "Collision", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHealthPickup, Collision), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Collision_MetaData), NewProp_Collision_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHealthPickup_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHealthPickup, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mesh_MetaData), NewProp_Mesh_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AHealthPickup_Statics::NewProp_HealthDelta = { "HealthDelta", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHealthPickup, HealthDelta), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealthDelta_MetaData), NewProp_HealthDelta_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AHealthPickup_Statics::NewProp_PickupSound = { "PickupSound", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AHealthPickup, PickupSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PickupSound_MetaData), NewProp_PickupSound_MetaData) };
void Z_Construct_UClass_AHealthPickup_Statics::NewProp_bConsumeOnlyIfApplied_SetBit(void* Obj)
{
	((AHealthPickup*)Obj)->bConsumeOnlyIfApplied = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AHealthPickup_Statics::NewProp_bConsumeOnlyIfApplied = { "bConsumeOnlyIfApplied", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AHealthPickup), &Z_Construct_UClass_AHealthPickup_Statics::NewProp_bConsumeOnlyIfApplied_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bConsumeOnlyIfApplied_MetaData), NewProp_bConsumeOnlyIfApplied_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AHealthPickup_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealthPickup_Statics::NewProp_Root,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealthPickup_Statics::NewProp_Collision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealthPickup_Statics::NewProp_Mesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealthPickup_Statics::NewProp_HealthDelta,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealthPickup_Statics::NewProp_PickupSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AHealthPickup_Statics::NewProp_bConsumeOnlyIfApplied,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHealthPickup_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AHealthPickup_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_PeleaMelee,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHealthPickup_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AHealthPickup_Statics::ClassParams = {
	&AHealthPickup::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AHealthPickup_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AHealthPickup_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHealthPickup_Statics::Class_MetaDataParams), Z_Construct_UClass_AHealthPickup_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AHealthPickup()
{
	if (!Z_Registration_Info_UClass_AHealthPickup.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHealthPickup.OuterSingleton, Z_Construct_UClass_AHealthPickup_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AHealthPickup.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AHealthPickup);
AHealthPickup::~AHealthPickup() {}
// ********** End Class AHealthPickup **************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_HealthPickup_h__Script_PeleaMelee_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AHealthPickup, AHealthPickup::StaticClass, TEXT("AHealthPickup"), &Z_Registration_Info_UClass_AHealthPickup, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHealthPickup), 3379849770U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_HealthPickup_h__Script_PeleaMelee_1673853256(TEXT("/Script/PeleaMelee"),
	Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_HealthPickup_h__Script_PeleaMelee_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_HealthPickup_h__Script_PeleaMelee_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
