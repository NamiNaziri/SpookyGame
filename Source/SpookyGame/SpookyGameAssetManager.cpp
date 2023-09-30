


#include "SpookyGameAssetManager.h"
#include "AbilitySystemGlobals.h"
void USpookyGameAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	UAbilitySystemGlobals::Get().InitGlobalData();
}
