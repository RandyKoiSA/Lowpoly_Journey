// Copyrighted by DevotedKoi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Abilities/GameplayAbility.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "AttributeSetBase.h"
#include "CharacterBase.generated.h"

UCLASS()
class LOWPOLY_JOURNEY_API ACharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterBase")
	UAbilitySystemComponent* AbilitySystemComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterBase")
	UAttributeSetBase* AttributeSetComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AcquireAbility(TSubclassOf<UGameplayAbility> AbilityToAcquire);

	UFUNCTION()
	void OnHealthChanged(float CurrentHealth, float MaxHealth);

	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterBase", meta = (DisplayName = "OnHealthChanged"))
	void BP_OnHealthChanged(float CurrentHealth, float MaxHealth);

	UFUNCTION()
	void OnManaChanged(float CurrentMana, float MaxMana);

	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterBase", meta = (DisplayName = "OnManaChanged"))
	void BP_OnManaChanged(float CurrentMana, float MaxMana);

	UFUNCTION()
	void OnStrengthChanged(float StrengthValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterBase", meta = (DisplayName = "OnStrengthChanged"))
	void BP_OnStrengthChanged(float StrengthValue);

	UFUNCTION()
	void OnDefenseChanged(float DefenseValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "CharacterBase", meta = (DisplayName = "OnDefenseChanged"))
	void BP_OnDefenseChanged(float DefenseValue);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

};
