// Copyrighted by DevotedKoi


#include "AttributeSetBase.h"
#include "CharacterBase.h"

UAttributeSetBase::UAttributeSetBase() : Health(100.0f), MaxHealth(100.0f), Mana(100.0f), MaxMana(100.0f), Strength(0.0f), Defense(0.0f)
{

}

void UAttributeSetBase::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	/**
	 * Health Attribute has been altered; Clamp the health and broadcast it.
	 */
	if( Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Health)) )
	{

	}

	/**
	 * Mana Attribute has been altered; Clamp the mana and broadcast it.
	 */
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Mana)))
	{

	}

	/**
	 * Strength Attribute has been altered; broadcast it.
	 */
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Strength)))
	{

	}

	/**
	 * Defense Attribute has been altered; broadcast it.
	 */
	if (Data.EvaluatedData.Attribute.GetUProperty() == FindFieldChecked<UProperty>(UAttributeSetBase::StaticClass(), GET_MEMBER_NAME_CHECKED(UAttributeSetBase, Defense)))
	{

	}
}
