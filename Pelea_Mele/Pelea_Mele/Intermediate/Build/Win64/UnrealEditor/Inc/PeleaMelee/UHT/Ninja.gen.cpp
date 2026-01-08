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
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPawnNoiseEmitterComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
MOTIONWARPING_API UClass* Z_Construct_UClass_UMotionWarpingComponent_NoRegister();
NIAGARA_API UClass* Z_Construct_UClass_UNiagaraSystem_NoRegister();
PELEAMELEE_API UClass* Z_Construct_UClass_ANinja();
PELEAMELEE_API UClass* Z_Construct_UClass_ANinja_NoRegister();
PELEAMELEE_API UClass* Z_Construct_UClass_UHealthComponent_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_PeleaMelee();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ANinja Function ApplyGameOverPause ***************************************
struct Z_Construct_UFunction_ANinja_ApplyGameOverPause_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANinja_ApplyGameOverPause_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ANinja, nullptr, "ApplyGameOverPause", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANinja_ApplyGameOverPause_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANinja_ApplyGameOverPause_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ANinja_ApplyGameOverPause()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANinja_ApplyGameOverPause_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANinja::execApplyGameOverPause)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ApplyGameOverPause();
	P_NATIVE_END;
}
// ********** End Class ANinja Function ApplyGameOverPause *****************************************

// ********** Begin Class ANinja Function Death ****************************************************
struct Z_Construct_UFunction_ANinja_Death_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "GameOver" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Game Over\n" },
#endif
		{ "ModuleRelativePath", "Public/Ninja.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Game Over" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANinja_Death_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ANinja, nullptr, "Death", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANinja_Death_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANinja_Death_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ANinja_Death()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANinja_Death_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANinja::execDeath)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Death();
	P_NATIVE_END;
}
// ********** End Class ANinja Function Death ******************************************************

// ********** Begin Class ANinja Function LanzarHumo ***********************************************
struct Z_Construct_UFunction_ANinja_LanzarHumo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Combat|Smoke" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------- Bomba de humo ----------\n" },
#endif
		{ "ModuleRelativePath", "Public/Ninja.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "---------- Bomba de humo ----------" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANinja_LanzarHumo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ANinja, nullptr, "LanzarHumo", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANinja_LanzarHumo_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANinja_LanzarHumo_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_ANinja_LanzarHumo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANinja_LanzarHumo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANinja::execLanzarHumo)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LanzarHumo();
	P_NATIVE_END;
}
// ********** End Class ANinja Function LanzarHumo *************************************************

// ********** Begin Class ANinja Function LossHealth ***********************************************
struct Z_Construct_UFunction_ANinja_LossHealth_Statics
{
	struct Ninja_eventLossHealth_Parms
	{
		float HealthToLoss;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stats" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HealthToLoss;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ANinja_LossHealth_Statics::NewProp_HealthToLoss = { "HealthToLoss", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Ninja_eventLossHealth_Parms, HealthToLoss), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANinja_LossHealth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANinja_LossHealth_Statics::NewProp_HealthToLoss,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANinja_LossHealth_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANinja_LossHealth_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ANinja, nullptr, "LossHealth", Z_Construct_UFunction_ANinja_LossHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANinja_LossHealth_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANinja_LossHealth_Statics::Ninja_eventLossHealth_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANinja_LossHealth_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANinja_LossHealth_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ANinja_LossHealth_Statics::Ninja_eventLossHealth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANinja_LossHealth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANinja_LossHealth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANinja::execLossHealth)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_HealthToLoss);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LossHealth(Z_Param_HealthToLoss);
	P_NATIVE_END;
}
// ********** End Class ANinja Function LossHealth *************************************************

// ********** Begin Class ANinja Function OnAssassinationMontageEnded ******************************
struct Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded_Statics
{
	struct Ninja_eventOnAssassinationMontageEnded_Parms
	{
		UAnimMontage* Montage;
		bool bInterrupted;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Montage;
	static void NewProp_bInterrupted_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInterrupted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded_Statics::NewProp_Montage = { "Montage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Ninja_eventOnAssassinationMontageEnded_Parms, Montage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded_Statics::NewProp_bInterrupted_SetBit(void* Obj)
{
	((Ninja_eventOnAssassinationMontageEnded_Parms*)Obj)->bInterrupted = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded_Statics::NewProp_bInterrupted = { "bInterrupted", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Ninja_eventOnAssassinationMontageEnded_Parms), &Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded_Statics::NewProp_bInterrupted_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded_Statics::NewProp_Montage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded_Statics::NewProp_bInterrupted,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_ANinja, nullptr, "OnAssassinationMontageEnded", Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded_Statics::PropPointers), sizeof(Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded_Statics::Ninja_eventOnAssassinationMontageEnded_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded_Statics::Function_MetaDataParams), Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded_Statics::Ninja_eventOnAssassinationMontageEnded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ANinja::execOnAssassinationMontageEnded)
{
	P_GET_OBJECT(UAnimMontage,Z_Param_Montage);
	P_GET_UBOOL(Z_Param_bInterrupted);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAssassinationMontageEnded(Z_Param_Montage,Z_Param_bInterrupted);
	P_NATIVE_END;
}
// ********** End Class ANinja Function OnAssassinationMontageEnded ********************************

// ********** Begin Class ANinja *******************************************************************
void ANinja::StaticRegisterNativesANinja()
{
	UClass* Class = ANinja::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ApplyGameOverPause", &ANinja::execApplyGameOverPause },
		{ "Death", &ANinja::execDeath },
		{ "LanzarHumo", &ANinja::execLanzarHumo },
		{ "LossHealth", &ANinja::execLossHealth },
		{ "OnAssassinationMontageEnded", &ANinja::execOnAssassinationMontageEnded },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShurikensCount_MetaData[] = {
		{ "Category", "Inventory|Ammo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Inventario\n" },
#endif
		{ "ModuleRelativePath", "Public/Ninja.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Inventario" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BombCount_MetaData[] = {
		{ "Category", "Inventory|Ammo" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HealthComp_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Vida\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Vida" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameOverMenuWidgetClass_MetaData[] = {
		{ "Category", "GameOver" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeathSound_MetaData[] = {
		{ "Category", "GameOver" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameOverDelaySeconds_MetaData[] = {
		{ "Category", "GameOver" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NinjaMappingContext_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------- BeginPlay: Input Mapping + HUD ----------\n" },
#endif
		{ "ModuleRelativePath", "Public/Ninja.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "---------- BeginPlay: Input Mapping + HUD ----------" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NinjaMappingPriority_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HUDWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HUDZOrder_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NinjaFireAction_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------- Input (Enhanced) ----------\n" },
#endif
		{ "ModuleRelativePath", "Public/Ninja.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "---------- Input (Enhanced) ----------" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NinjaLookAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NinjaMoveAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NinjaSneakAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NinjaAttackAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSneaking_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------- Sneak ----------\n" },
#endif
		{ "ModuleRelativePath", "Public/Ninja.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "---------- Sneak ----------" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PawnNoiseEmitter_MetaData[] = {
		{ "Category", "AI|Noise" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------- Ruido al moverse ----------\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "---------- Ruido al moverse ----------" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveNoiseLoudness_MetaData[] = {
		{ "Category", "AI|Noise" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanAttack_MetaData[] = {
		{ "Category", "Combat|Attack" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------- Ataque b\xc3\xa1sico / Asesinato ----------\n" },
#endif
		{ "ModuleRelativePath", "Public/Ninja.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "---------- Ataque b\xc3\xa1sico / Asesinato ----------" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAttacking_MetaData[] = {
		{ "Category", "Combat|Attack" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Victim_MetaData[] = {
		{ "Category", "Combat|Attack" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MotionWarping_MetaData[] = {
		{ "Category", "Combat|Attack" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssassinMontage_MetaData[] = {
		{ "Category", "Combat|Attack" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VictimAssassinatedMontage_MetaData[] = {
		{ "Category", "Combat|Attack" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VictimWarpTargetName_MetaData[] = {
		{ "Category", "Combat|Attack" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssassinationVictim_MetaData[] = {
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bThrowBomb_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SmokeSystem_MetaData[] = {
		{ "Category", "Combat|Smoke" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SmokeSystemScale_MetaData[] = {
		{ "Category", "Combat|Smoke" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IHUD_MetaData[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// HUD creado en BeginPlay (equivalente a la variable \"HUD\" del BP)\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "HUD creado en BeginPlay (equivalente a la variable \"HUD\" del BP)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CrossHair_MetaData[] = {
		{ "Category", "UI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CrossHairColorBase_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CrossHairColorOverEnemy_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsAiming_MetaData[] = {
		{ "Category", "Aim" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShurikenTraceDistance_MetaData[] = {
		{ "Category", "Combat|Shuriken" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShurikenDamage_MetaData[] = {
		{ "Category", "Combat|Shuriken" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimSensitivity_MetaData[] = {
		{ "Category", "Aim" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AimTurnSpeed_MetaData[] = {
		{ "Category", "Aim" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CrossHairSizeUMG_MetaData[] = {
		{ "Category", "Aim" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GameOverMenuWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetEnemy_MetaData[] = {
		{ "ModuleRelativePath", "Public/Ninja.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ShurikensCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BombCount;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HealthComp;
	static const UECodeGen_Private::FClassPropertyParams NewProp_GameOverMenuWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DeathSound;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_GameOverDelaySeconds;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NinjaMappingContext;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NinjaMappingPriority;
	static const UECodeGen_Private::FClassPropertyParams NewProp_HUDWidgetClass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_HUDZOrder;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NinjaFireAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NinjaLookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NinjaMoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NinjaSneakAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NinjaAttackAction;
	static void NewProp_bSneaking_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSneaking;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PawnNoiseEmitter;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MoveNoiseLoudness;
	static void NewProp_bCanAttack_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanAttack;
	static void NewProp_bAttacking_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAttacking;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Victim;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MotionWarping;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AssassinMontage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VictimAssassinatedMontage;
	static const UECodeGen_Private::FNamePropertyParams NewProp_VictimWarpTargetName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AssassinationVictim;
	static void NewProp_bThrowBomb_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bThrowBomb;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SmokeSystem;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SmokeSystemScale;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IHUD;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CrossHair;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CrossHairColorBase;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CrossHairColorOverEnemy;
	static void NewProp_bIsAiming_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAiming;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShurikenTraceDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShurikenDamage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimSensitivity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AimTurnSpeed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CrossHairSizeUMG;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GameOverMenuWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetEnemy;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ANinja_ApplyGameOverPause, "ApplyGameOverPause" }, // 1468760044
		{ &Z_Construct_UFunction_ANinja_Death, "Death" }, // 1416673002
		{ &Z_Construct_UFunction_ANinja_LanzarHumo, "LanzarHumo" }, // 836473133
		{ &Z_Construct_UFunction_ANinja_LossHealth, "LossHealth" }, // 3800991766
		{ &Z_Construct_UFunction_ANinja_OnAssassinationMontageEnded, "OnAssassinationMontageEnded" }, // 3364487320
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANinja>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArm_MetaData), NewProp_SpringArm_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_ShurikensCount = { "ShurikensCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, ShurikensCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShurikensCount_MetaData), NewProp_ShurikensCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_BombCount = { "BombCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, BombCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BombCount_MetaData), NewProp_BombCount_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_HealthComp = { "HealthComp", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, HealthComp), Z_Construct_UClass_UHealthComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HealthComp_MetaData), NewProp_HealthComp_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_GameOverMenuWidgetClass = { "GameOverMenuWidgetClass", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, GameOverMenuWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameOverMenuWidgetClass_MetaData), NewProp_GameOverMenuWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_DeathSound = { "DeathSound", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, DeathSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeathSound_MetaData), NewProp_DeathSound_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_GameOverDelaySeconds = { "GameOverDelaySeconds", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, GameOverDelaySeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameOverDelaySeconds_MetaData), NewProp_GameOverDelaySeconds_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_NinjaMappingContext = { "NinjaMappingContext", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, NinjaMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NinjaMappingContext_MetaData), NewProp_NinjaMappingContext_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_NinjaMappingPriority = { "NinjaMappingPriority", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, NinjaMappingPriority), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NinjaMappingPriority_MetaData), NewProp_NinjaMappingPriority_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_HUDWidgetClass = { "HUDWidgetClass", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, HUDWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HUDWidgetClass_MetaData), NewProp_HUDWidgetClass_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_HUDZOrder = { "HUDZOrder", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, HUDZOrder), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HUDZOrder_MetaData), NewProp_HUDZOrder_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_NinjaFireAction = { "NinjaFireAction", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, NinjaFireAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NinjaFireAction_MetaData), NewProp_NinjaFireAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_NinjaLookAction = { "NinjaLookAction", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, NinjaLookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NinjaLookAction_MetaData), NewProp_NinjaLookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_NinjaMoveAction = { "NinjaMoveAction", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, NinjaMoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NinjaMoveAction_MetaData), NewProp_NinjaMoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_NinjaSneakAction = { "NinjaSneakAction", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, NinjaSneakAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NinjaSneakAction_MetaData), NewProp_NinjaSneakAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_NinjaAttackAction = { "NinjaAttackAction", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, NinjaAttackAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NinjaAttackAction_MetaData), NewProp_NinjaAttackAction_MetaData) };
void Z_Construct_UClass_ANinja_Statics::NewProp_bSneaking_SetBit(void* Obj)
{
	((ANinja*)Obj)->bSneaking = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_bSneaking = { "bSneaking", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ANinja), &Z_Construct_UClass_ANinja_Statics::NewProp_bSneaking_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSneaking_MetaData), NewProp_bSneaking_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_PawnNoiseEmitter = { "PawnNoiseEmitter", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, PawnNoiseEmitter), Z_Construct_UClass_UPawnNoiseEmitterComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PawnNoiseEmitter_MetaData), NewProp_PawnNoiseEmitter_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_MoveNoiseLoudness = { "MoveNoiseLoudness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, MoveNoiseLoudness), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveNoiseLoudness_MetaData), NewProp_MoveNoiseLoudness_MetaData) };
void Z_Construct_UClass_ANinja_Statics::NewProp_bCanAttack_SetBit(void* Obj)
{
	((ANinja*)Obj)->bCanAttack = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_bCanAttack = { "bCanAttack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ANinja), &Z_Construct_UClass_ANinja_Statics::NewProp_bCanAttack_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanAttack_MetaData), NewProp_bCanAttack_MetaData) };
void Z_Construct_UClass_ANinja_Statics::NewProp_bAttacking_SetBit(void* Obj)
{
	((ANinja*)Obj)->bAttacking = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_bAttacking = { "bAttacking", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ANinja), &Z_Construct_UClass_ANinja_Statics::NewProp_bAttacking_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAttacking_MetaData), NewProp_bAttacking_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_Victim = { "Victim", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, Victim), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Victim_MetaData), NewProp_Victim_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_MotionWarping = { "MotionWarping", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, MotionWarping), Z_Construct_UClass_UMotionWarpingComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MotionWarping_MetaData), NewProp_MotionWarping_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_AssassinMontage = { "AssassinMontage", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, AssassinMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssassinMontage_MetaData), NewProp_AssassinMontage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_VictimAssassinatedMontage = { "VictimAssassinatedMontage", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, VictimAssassinatedMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VictimAssassinatedMontage_MetaData), NewProp_VictimAssassinatedMontage_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_VictimWarpTargetName = { "VictimWarpTargetName", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, VictimWarpTargetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VictimWarpTargetName_MetaData), NewProp_VictimWarpTargetName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_AssassinationVictim = { "AssassinationVictim", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, AssassinationVictim), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssassinationVictim_MetaData), NewProp_AssassinationVictim_MetaData) };
void Z_Construct_UClass_ANinja_Statics::NewProp_bThrowBomb_SetBit(void* Obj)
{
	((ANinja*)Obj)->bThrowBomb = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_bThrowBomb = { "bThrowBomb", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ANinja), &Z_Construct_UClass_ANinja_Statics::NewProp_bThrowBomb_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bThrowBomb_MetaData), NewProp_bThrowBomb_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_SmokeSystem = { "SmokeSystem", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, SmokeSystem), Z_Construct_UClass_UNiagaraSystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SmokeSystem_MetaData), NewProp_SmokeSystem_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_SmokeSystemScale = { "SmokeSystemScale", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, SmokeSystemScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SmokeSystemScale_MetaData), NewProp_SmokeSystemScale_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_IHUD = { "IHUD", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, IHUD), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IHUD_MetaData), NewProp_IHUD_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_CrossHair = { "CrossHair", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, CrossHair), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CrossHair_MetaData), NewProp_CrossHair_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_CrossHairColorBase = { "CrossHairColorBase", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, CrossHairColorBase), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CrossHairColorBase_MetaData), NewProp_CrossHairColorBase_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_CrossHairColorOverEnemy = { "CrossHairColorOverEnemy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, CrossHairColorOverEnemy), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CrossHairColorOverEnemy_MetaData), NewProp_CrossHairColorOverEnemy_MetaData) };
void Z_Construct_UClass_ANinja_Statics::NewProp_bIsAiming_SetBit(void* Obj)
{
	((ANinja*)Obj)->bIsAiming = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_bIsAiming = { "bIsAiming", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ANinja), &Z_Construct_UClass_ANinja_Statics::NewProp_bIsAiming_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsAiming_MetaData), NewProp_bIsAiming_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_ShurikenTraceDistance = { "ShurikenTraceDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, ShurikenTraceDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShurikenTraceDistance_MetaData), NewProp_ShurikenTraceDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_ShurikenDamage = { "ShurikenDamage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, ShurikenDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShurikenDamage_MetaData), NewProp_ShurikenDamage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_AimSensitivity = { "AimSensitivity", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, AimSensitivity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimSensitivity_MetaData), NewProp_AimSensitivity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_AimTurnSpeed = { "AimTurnSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, AimTurnSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AimTurnSpeed_MetaData), NewProp_AimTurnSpeed_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_CrossHairSizeUMG = { "CrossHairSizeUMG", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, CrossHairSizeUMG), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CrossHairSizeUMG_MetaData), NewProp_CrossHairSizeUMG_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_GameOverMenuWidget = { "GameOverMenuWidget", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, GameOverMenuWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GameOverMenuWidget_MetaData), NewProp_GameOverMenuWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ANinja_Statics::NewProp_TargetEnemy = { "TargetEnemy", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ANinja, TargetEnemy), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetEnemy_MetaData), NewProp_TargetEnemy_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ANinja_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_Camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_SpringArm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_ShurikensCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_BombCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_HealthComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_GameOverMenuWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_DeathSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_GameOverDelaySeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_NinjaMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_NinjaMappingPriority,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_HUDWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_HUDZOrder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_NinjaFireAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_NinjaLookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_NinjaMoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_NinjaSneakAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_NinjaAttackAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_bSneaking,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_PawnNoiseEmitter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_MoveNoiseLoudness,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_bCanAttack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_bAttacking,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_Victim,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_MotionWarping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_AssassinMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_VictimAssassinatedMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_VictimWarpTargetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_AssassinationVictim,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_bThrowBomb,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_SmokeSystem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_SmokeSystemScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_IHUD,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_CrossHair,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_CrossHairColorBase,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_CrossHairColorOverEnemy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_bIsAiming,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_ShurikenTraceDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_ShurikenDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_AimSensitivity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_AimTurnSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_CrossHairSizeUMG,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_GameOverMenuWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ANinja_Statics::NewProp_TargetEnemy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANinja_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ANinja_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_PeleaMelee,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ANinja_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ANinja_Statics::ClassParams = {
	&ANinja::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ANinja_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
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
struct Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_Ninja_h__Script_PeleaMelee_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ANinja, ANinja::StaticClass, TEXT("ANinja"), &Z_Registration_Info_UClass_ANinja, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANinja), 1903653084U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_Ninja_h__Script_PeleaMelee_987740575(TEXT("/Script/PeleaMelee"),
	Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_Ninja_h__Script_PeleaMelee_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Pelea_Mele_Source_PeleaMelee_Public_Ninja_h__Script_PeleaMelee_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
