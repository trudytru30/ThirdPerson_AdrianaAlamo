// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PeleaMeleGameInstance.h"

#ifdef PELEA_MELE_PeleaMeleGameInstance_generated_h
#error "PeleaMeleGameInstance.generated.h already included, missing '#pragma once' in PeleaMeleGameInstance.h"
#endif
#define PELEA_MELE_PeleaMeleGameInstance_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UPeleaMeleGameInstance ***************************************************
PELEA_MELE_API UClass* Z_Construct_UClass_UPeleaMeleGameInstance_NoRegister();

#define FID_Pelea_Mele_Source_Pelea_Mele_Public_PeleaMeleGameInstance_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPeleaMeleGameInstance(); \
	friend struct Z_Construct_UClass_UPeleaMeleGameInstance_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PELEA_MELE_API UClass* Z_Construct_UClass_UPeleaMeleGameInstance_NoRegister(); \
public: \
	DECLARE_CLASS2(UPeleaMeleGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/Pelea_Mele"), Z_Construct_UClass_UPeleaMeleGameInstance_NoRegister) \
	DECLARE_SERIALIZER(UPeleaMeleGameInstance)


#define FID_Pelea_Mele_Source_Pelea_Mele_Public_PeleaMeleGameInstance_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPeleaMeleGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UPeleaMeleGameInstance(UPeleaMeleGameInstance&&) = delete; \
	UPeleaMeleGameInstance(const UPeleaMeleGameInstance&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPeleaMeleGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPeleaMeleGameInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPeleaMeleGameInstance) \
	NO_API virtual ~UPeleaMeleGameInstance();


#define FID_Pelea_Mele_Source_Pelea_Mele_Public_PeleaMeleGameInstance_h_12_PROLOG
#define FID_Pelea_Mele_Source_Pelea_Mele_Public_PeleaMeleGameInstance_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Pelea_Mele_Source_Pelea_Mele_Public_PeleaMeleGameInstance_h_15_INCLASS_NO_PURE_DECLS \
	FID_Pelea_Mele_Source_Pelea_Mele_Public_PeleaMeleGameInstance_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UPeleaMeleGameInstance;

// ********** End Class UPeleaMeleGameInstance *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Pelea_Mele_Source_Pelea_Mele_Public_PeleaMeleGameInstance_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
