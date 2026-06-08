#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Ninja.generated.h"

class UHealthComponent;
class UUserWidget;
class USoundBase;
class UInputAction;
class UInputMappingContext;
class UCameraComponent;
class UImage;
class UPawnNoiseEmitterComponent;
class UAnimMontage;
class UNiagaraSystem;
class UMotionWarpingComponent;
struct FInputActionValue;

UCLASS()
class PELEAMELEE_API ANinja : public ACharacter
{
	GENERATED_BODY()

public:
	ANinja();

protected:

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UFUNCTION()
	void ApplyGameOverPause();

	// Fire (Enhanced Input)
	void OnNinjaFireTriggered(const FInputActionValue& Value);
	void OnNinjaFireCompleted(const FInputActionValue& Value);

	// Look (Enhanced Input)
	void OnNinjaLookTriggered(const FInputActionValue& Value);

	// Move (Enhanced Input)
	void OnNinjaMoveTriggered(const FInputActionValue& Value);

	// Sneak (Enhanced Input)
	void OnNinjaSneakTriggered(const FInputActionValue& Value);
	void OnNinjaSneakCompleted(const FInputActionValue& Value);

	// Attack (Enhanced Input)
	void OnNinjaAttackStarted(const FInputActionValue& Value);

	// Helpers UI/Trace
	void SetCrossHairVisible(bool bVisible);
	void SetCrossHairTint(const FLinearColor& Tint);
	
	// Helpers Attack
	void DoAssassinationAttack();
	void TryGetVictimTargetTransform(FTransform& OutTransform, bool& bOutHasTransform) const;

	//Aim Helpers
	void SetAiming(bool bNewAiming);
	void UpdateAimFromCrosshair(float DeltaTime);
	void UpdateAimOffsetFromMouse();
	bool GetCrosshairScreenPointPx(FVector2D& OutPx);

	//Damage
	void ApplyShurikenDamageToTarget();

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
	UCameraComponent* Camera = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera")
	USpringArmComponent* SpringArm;

	// Inventario
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory|Ammo")
	int32 ShurikensCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory|Ammo")
	int32 BombCount = 0;

	// Vida
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	UHealthComponent* HealthComp = nullptr;
	
	UFUNCTION(BlueprintCallable, Category="Stats")
	void LossHealth(float HealthToLoss);

	// Game Over
	UFUNCTION(BlueprintCallable, Category="GameOver")
	void Death();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GameOver")
	TSubclassOf<UUserWidget> GameOverMenuWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GameOver")
	USoundBase* DeathSound = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GameOver")
	float GameOverDelaySeconds = 0.4f;

	// ---------- BeginPlay: Input Mapping + HUD ----------

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	UInputMappingContext* NinjaMappingContext = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	int32 NinjaMappingPriority = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI")
	TSubclassOf<UUserWidget> HUDWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UI")
	int32 HUDZOrder = 0;

	// ---------- Input (Enhanced) ----------

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	UInputAction* NinjaFireAction = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	UInputAction* NinjaLookAction = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	UInputAction* NinjaMoveAction = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	UInputAction* NinjaSneakAction = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	UInputAction* NinjaAttackAction = nullptr;

	// ---------- Sneak ----------

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	bool bSneaking = false;

	// ---------- Ruido al moverse ----------

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|Noise")
	UPawnNoiseEmitterComponent* PawnNoiseEmitter = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI|Noise")
	float MoveNoiseLoudness = 0.2f;

	// ---------- Ataque básico / Asesinato ----------

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Attack")
	bool bCanAttack = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Attack")
	bool bAttacking = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Attack")
	AActor* Victim = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat|Attack")
	UMotionWarpingComponent* MotionWarping = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat|Attack")
	UAnimMontage* AssassinMontage = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat|Attack")
	UAnimMontage* VictimAssassinatedMontage = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat|Attack")
	FName VictimWarpTargetName = TEXT("Victim");
	
	UPROPERTY()
	AActor* AssassinationVictim = nullptr;

	UFUNCTION()
	void OnAssassinationMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	// ---------- Bomba de humo ----------

	UFUNCTION(BlueprintCallable, Category="Combat|Smoke")
	void LanzarHumo();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	bool bThrowBomb = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat|Smoke")
	UNiagaraSystem* SmokeSystem = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Combat|Smoke")
	FVector SmokeSystemScale = FVector(0.2f, 0.2f, 0.2f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Smoke")
	float SmokeBombRadius = 500.f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Smoke")
	float SmokeBombDuration = 4.0f;

	FTimerHandle SmokeBombThrowResetHandle;
	

	// ---------- Ataque con Shuriken ----------
	
	// HUD creado en BeginPlay (equivalente a la variable "HUD" del BP)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UI")
	UUserWidget* IHUD = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UI")
	UImage* CrossHair = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UI")
	FLinearColor CrossHairColorBase = FLinearColor::White;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UI")
	FLinearColor CrossHairColorOverEnemy = FLinearColor::Red;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Aim")
	bool bIsAiming = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Shuriken")
	float ShurikenTraceDistance = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat|Shuriken")
	float ShurikenDamage = 50.0f;

	UPROPERTY(EditAnywhere, Category="Aim")
	float AimSensitivity = 10.0f;

	UPROPERTY(EditAnywhere, Category="Aim")
	float AimTurnSpeed = 12.0f;

	UPROPERTY(EditAnywhere, Category="Aim")
	FVector2D CrossHairSizeUMG = FVector2D(32.f, 32.f);


private:
	UPROPERTY()
	UUserWidget* GameOverMenuWidget = nullptr;

	UFUNCTION()
	void OnNinjaDied();
	FTimerHandle GameOverDelayHandle;
	bool bDeathTriggered = false;

	UPROPERTY()
	AActor* TargetEnemy = nullptr;

	FVector2D AimOffsetUMG = FVector2D::ZeroVector;
};
