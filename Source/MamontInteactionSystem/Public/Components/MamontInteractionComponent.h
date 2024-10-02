// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MamontInteractionComponent.generated.h"


UCLASS( ClassGroup=(MamontInteractionSystem), meta=(BlueprintSpawnableComponent) )
class MAMONTINTEACTIONSYSTEM_API UMamontInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	explicit UMamontInteractionComponent(const FObjectInitializer& InInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable)
	void InteractOnOverlap();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Interaction")
	TSubclassOf<AActor> OverlapedActorsClass;
		
};