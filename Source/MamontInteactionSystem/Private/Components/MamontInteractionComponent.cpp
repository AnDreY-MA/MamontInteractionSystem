// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/MamontInteractionComponent.h"
#include "Interfaces/MamontInteractableInterface.h"

UMamontInteractionComponent::UMamontInteractionComponent(const FObjectInitializer& InInitializer) :
	Super(InInitializer), OverlapedActorsClass(AActor::StaticClass())
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UMamontInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UMamontInteractionComponent::InteractOnOverlap()
{
	TSet<AActor*> OverlappedActors;
	GetOwner()->GetOverlappingActors(OverlappedActors, OverlapedActorsClass);
	if (OverlappedActors.IsEmpty()) return;

	for (auto* Actor : OverlappedActors)
	{
		if (Actor->Implements<UMamontInteractableInterface>())
		{
			IMamontInteractableInterface::Execute_Interact(Actor, GetOwner());
		}
		else if (auto* InteractableComponent{ Actor->FindComponentByInterface<UMamontInteractableInterface>()}; InteractableComponent)
		{
			IMamontInteractableInterface::Execute_Interact(InteractableComponent, GetOwner());
		}
	}
}