// Copyrighted by DevotedKoi


#include "CharacterBase.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComp = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("Ability System Component"));
	AttributeSetComp = CreateDefaultSubobject<UAttributeSetBase>(TEXT("AttributeSet Component"));
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	AttributeSetComp->OnHealthChange.AddDynamic(this, &ACharacterBase::OnHealthChanged);
	AttributeSetComp->OnManaChange.AddDynamic(this, &ACharacterBase::OnManaChanged);
	AttributeSetComp->OnStrengthChange.AddDynamic(this, &ACharacterBase::OnStrengthChanged);
	AttributeSetComp->OnDefenseChange.AddDynamic(this, &ACharacterBase::OnDefenseChanged);
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacterBase::AcquireAbility(TSubclassOf<UGameplayAbility> AbilityToAcquire)
{
	if (AbilitySystemComp)
	{
		if (HasAuthority() && AbilityToAcquire)
		{
			FGameplayAbilitySpecDef SpecDef = FGameplayAbilitySpecDef();
			SpecDef.Ability = AbilityToAcquire;
			FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(SpecDef, 1);
			AbilitySystemComp->GiveAbility(AbilitySpec);
		}

		AbilitySystemComp->InitAbilityActorInfo(this, this);
	}
}

void ACharacterBase::OnHealthChanged(float CurrentHealth, float MaxHealth)
{

	BP_OnHealthChanged(CurrentHealth, MaxHealth);
}

void ACharacterBase::OnManaChanged(float CurrentMana, float MaxMana)
{

	BP_OnManaChanged(CurrentMana, MaxMana);
}

void ACharacterBase::OnStrengthChanged(float StrengthValue)
{

	BP_OnStrengthChanged(StrengthValue);
}

void ACharacterBase::OnDefenseChanged(float DefenseValue)
{
	
	BP_OnDefenseChanged(DefenseValue);
}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

