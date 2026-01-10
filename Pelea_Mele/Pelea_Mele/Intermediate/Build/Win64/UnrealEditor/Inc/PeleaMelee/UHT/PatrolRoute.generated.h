// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PatrolRoute.h"

#ifdef PELEAMELEE_PatrolRoute_generated_h
#error "PatrolRoute.generated.h already included, missing '#pragma once' in PatrolRoute.h"
#endif
#define PELEAMELEE_PatrolRoute_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

class ATargetPoint;

// ********** Begin Class APatrolRoute *************************************************************
#define FID_Pelea_Mele_Source_PeleaMelee_Public_PatrolRoute_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetNearestIndex); \
	DECLARE_FUNCTION(execGetPoint); \
	DECLARE_FUNCTION(execNumPoints);


PELEAMELEE_API UClass* Z_Construct_UClass_APatrolRoute_NoRegister();

#define FID_Pelea_Mele_Source_PeleaMelee_Public_PatrolRoute_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPatrolRoute(); \
	friend struct Z_Construct_UClass_APatrolRoute_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend PELEAMELEE_API UClass* Z_Construct_UClass_APatrolRoute_NoRegister(); \
public: \
	DECLARE_CLASS2(APatrolRoute, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PeleaMelee"), Z_Construct_UClass_APatrolRoute_NoRegister) \
	DECLARE_SERIALIZER(APatrolRoute)


#define FID_Pelea_Mele_Source_PeleaMelee_Public_PatrolRoute_h_14_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	APatrolRoute(APatrolRoute&&) = delete; \
	APatrolRoute(const APatrolRoute&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APatrolRoute); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APatrolRoute); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APatrolRoute) \
	NO_API virtual ~APatrolRoute();


#define FID_Pelea_Mele_Source_PeleaMelee_Public_PatrolRoute_h_11_PROLOG
#define FID_Pelea_Mele_Source_PeleaMelee_Public_PatrolRoute_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Pelea_Mele_Source_PeleaMelee_Public_PatrolRoute_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Pelea_Mele_Source_PeleaMelee_Public_PatrolRoute_h_14_INCLASS_NO_PURE_DECLS \
	FID_Pelea_Mele_Source_PeleaMelee_Public_PatrolRoute_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class APatrolRoute;

// ********** End Class APatrolRoute ***************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Pelea_Mele_Source_PeleaMelee_Public_PatrolRoute_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
