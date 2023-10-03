


#include "SpookyGamePlayerState.h"

#include "NavigationSystemTypes.h"
#include "SpookyGame/Character/Abilities/CharacterAbilitySystemComponent.h"
#include "SpookyGame/Character/Abilities/AttributeSet/CharacterAttributeSetBase.h"

ASpookyGamePlayerState::ASpookyGamePlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UCharacterAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UCharacterAttributeSetBase>("Attribute Set");

	
}

UAbilitySystemComponent* ASpookyGamePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ASpookyGamePlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
