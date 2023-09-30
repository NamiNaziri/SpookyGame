

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "SpookyGameAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class SPOOKYGAME_API USpookyGameAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	virtual void StartInitialLoading() override;
};
