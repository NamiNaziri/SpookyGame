


#include "SpookyGameCharacterBase.h"
#include "Abilities/AttributeSet/CharacterAttributeSetBase.h"
#include "Abilities/CharacterAbilitySystemComponent.h"
#include "Player/SpookyGamePlayerState.h"

ASpookyGameCharacterBase::ASpookyGameCharacterBase(const class FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ASpookyGameCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}



UAbilitySystemComponent* ASpookyGameCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ASpookyGameCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void ASpookyGameCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the server
	InitAbilityActorInfo();
}

void ASpookyGameCharacterBase::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the client
	InitAbilityActorInfo();
}

void ASpookyGameCharacterBase::InitAbilityActorInfo()
{
	ASpookyGamePlayerState* SGPlayerState = GetPlayerState<ASpookyGamePlayerState>();
	check(SGPlayerState);

	SGPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(SGPlayerState, this);
	AbilitySystemComponent = SGPlayerState->GetAbilitySystemComponent();
	AttributeSet = SGPlayerState->GetAttributeSet();
}
