// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PeleaMeleeGameInstance.h"

#ifdef PELEAMELEE_PeleaMeleeGameInstance_generated_h
#error "PeleaMeleeGameInstance.generated.h already included, missing '#pragma once' in PeleaMeleeGameInstance.h"
#endif
#define PELEAMELEE_PeleaMeleeGameInstance_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPeleaMeleeGameInstance **************************************************
PELEAMELEE_API UClass* Z_Construct_UClass_UPeleaMeleeGameInstance_NoRegister();

#define FID_Pelea_Mele_Source_PeleaMelee_Public_PeleaMeleeGameInstance_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPeleaMeleeGameInstance(); \
	friend struct Z_Construct_UClass_UPeleaMeleeGameInstance_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PELEAMELEE_API UClass* Z_Construct_UClass_UPeleaMeleeGameInstance_NoRegister(); \
public: \
	DECLARE_CLASS2(UPeleaMeleeGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/PeleaMelee"), Z_Construct_UClass_UPeleaMeleeGameInstance_NoRegister) \
	DECLARE_SERIALIZER(UPeleaMeleeGameInstance)


#define FID_Pelea_Mele_Source_PeleaMelee_Public_PeleaMeleeGameInstance_h_10_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPeleaMeleeGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPeleaMeleeGameInstance(UPeleaMeleeGameInstance&&) = delete; \
	UPeleaMeleeGameInstance(const UPeleaMeleeGameInstance&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPeleaMeleeGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPeleaMeleeGameInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPeleaMeleeGameInstance) \
	NO_API virtual ~UPeleaMeleeGameInstance();


#define FID_Pelea_Mele_Source_PeleaMelee_Public_PeleaMeleeGameInstance_h_7_PROLOG
#define FID_Pelea_Mele_Source_PeleaMelee_Public_PeleaMeleeGameInstance_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Pelea_Mele_Source_PeleaMelee_Public_PeleaMeleeGameInstance_h_10_INCLASS_NO_PURE_DECLS \
	FID_Pelea_Mele_Source_PeleaMelee_Public_PeleaMeleeGameInstance_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPeleaMeleeGameInstance;

// ********** End Class UPeleaMeleeGameInstance ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Pelea_Mele_Source_PeleaMelee_Public_PeleaMeleeGameInstance_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
