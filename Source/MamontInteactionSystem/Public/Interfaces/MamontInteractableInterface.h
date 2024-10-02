// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MamontInteractableInterface.generated.h"

UINTERFACE(MinimalAPI)
class UMamontInteractableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MAMONTINTEACTIONSYSTEM_API IMamontInteractableInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Mamont Interaction Interface")
	void Interact(AActor* InInstigator);

};
