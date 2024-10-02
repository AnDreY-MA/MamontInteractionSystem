// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/MamontBoxInteractableComponent.h"

#include "Components/WidgetComponent.h"

void UMamontBoxInteractableComponent::BeginPlay()
{
	if (bShowButton)
	{
		InteractionButton = GetOwner()->FindComponentByClass<UWidgetComponent>();

		OnComponentBeginOverlap.AddDynamic(this, &UMamontBoxInteractableComponent::OnOverlaped);
		OnComponentEndOverlap.AddDynamic(this, &UMamontBoxInteractableComponent::OnEndOverlaped);
	}

}

void UMamontBoxInteractableComponent::Interact_Implementation(AActor* InInstigator)
{
	if (OnInteracted.IsBound())
	{
		OnInteracted.Broadcast(InInstigator);
	}

}

void UMamontBoxInteractableComponent::OnOverlaped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!InteractionButton.IsValid() || !bShowButton || OtherActor == GetOwner()) return;

	InteractionButton->SetVisibility(true);

}

void UMamontBoxInteractableComponent::OnEndOverlaped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!InteractionButton.IsValid() || !bShowButton || OtherActor == GetOwner()) return;

	InteractionButton->SetVisibility(false);
}