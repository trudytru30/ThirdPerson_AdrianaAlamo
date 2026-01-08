// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Ninja.h"

#ifdef PELEAMELEE_Ninja_generated_h
#error "Ninja.generated.h already included, missing '#pragma once' in Ninja.h"
#endif
#define PELEAMELEE_Ninja_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class UAnimMontage;

// ********** Begin Class ANinja *******************************************************************
#define FID_Pelea_Mele_Source_PeleaMelee_Public_Ninja_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnNinjaDied); \
	DECLARE_FUNCTION(execLanzarHumo); \
	DECLARE_FUNCTION(execOnAssassinationMontageEnded); \
	DECLARE_FUNCTION(execDeath); \
	DECLARE_FUNCTION(execLossHealth); \
	DECLARE_FUNCTION(execApplyGameOverPause);


PELEAMELEE_API UClass* Z_Construct_UClass_ANinja_NoRegister();

#define FID_Pelea_Mele_Source_PeleaMelee_Public_Ninja_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesANinja(); \
	friend struct Z_Construct_UClass_ANinja_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PELEAMELEE_API UClass* Z_Construct_UClass_ANinja_NoRegister(); \
public: \
	DECLARE_CLASS2(ANinja, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PeleaMelee"), Z_Construct_UClass_ANinja_NoRegister) \
	DECLARE_SERIALIZER(ANinja)


#define FID_Pelea_Mele_Source_PeleaMelee_Public_Ninja_h_24_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ANinja(ANinja&&) = delete; \
	ANinja(const ANinja&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ANinja); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ANinja); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ANinja) \
	NO_API virtual ~ANinja();


#define FID_Pelea_Mele_Source_PeleaMelee_Public_Ninja_h_21_PROLOG
#define FID_Pelea_Mele_Source_PeleaMelee_Public_Ninja_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Pelea_Mele_Source_PeleaMelee_Public_Ninja_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Pelea_Mele_Source_PeleaMelee_Public_Ninja_h_24_INCLASS_NO_PURE_DECLS \
	FID_Pelea_Mele_Source_PeleaMelee_Public_Ninja_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ANinja;

// ********** End Class ANinja *********************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Pelea_Mele_Source_PeleaMelee_Public_Ninja_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
