// Copyrighted by DevotedKoi

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"
#include "AttributeSetBase.generated.h"

/**
 * Macro that will create the following functions:
 * Get Attribute
 * Get/Set AttributeValue
 */
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * Create a dynamic delegate to use for attributes when change
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttributeChangeDelegate, float, CurrentAttribute, float, MaxAttribute);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSingleAttributeChangeDelegate, float, CurrentAttribute);

/**
 * Attribute Set Base
 */
UCLASS()
class LOWPOLY_JOURNEY_API UAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UAttributeSetBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Health);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, MaxHealth);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Mana);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, MaxMana);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Strength);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttributeSetBase")
	FGameplayAttributeData Defense;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Defense);

	/**
	 * Immediately after modifying an Attribute's value, this function can react to the change.
	 * This often includes clamping the final value of the Attribute, or triggering an in-game reaction to the new value,
	 * like dying when the "health" Attribute falls to zero.
	 */
	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	/**
	 * Create the delegate channels that we will be using when the attribute changes.
	 */
	FOnAttributeChangeDelegate OnHealthChange;
	FOnAttributeChangeDelegate OnManaChange;
	FOnSingleAttributeChangeDelegate OnStrengthChange;
	FOnSingleAttributeChangeDelegate OnDefenseChange;
};
