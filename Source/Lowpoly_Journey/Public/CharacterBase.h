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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

};
