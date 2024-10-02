// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Interfaces/MamontInteractableInterface.h"
#include "MamontBoxInteractableComponent.generated.h"

class UWidgetComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteracted, AActor*, InInstigator);

UCLASS(ClassGroup = (MamontInteractionSystem), meta = (BlueprintSpawnableComponent))
class MAMONTINTEACTIONSYSTEM_API UMamontBoxInteractableComponent : public UBoxComponent, public IMamontInteractableInterface
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Interact_Implementation(AActor* InInstigator) override;

	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FOnInteracted OnInteracted;

private:
	UFUNCTION()
	void OnOverlaped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlaped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction", meta = (AllowPrivateAccess = "true"))
	TWeakObjectPtr<UWidgetComponent> InteractionButton;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction", meta = (AllowPrivateAccess = "true"))
	bool bShowButton{ true };

};