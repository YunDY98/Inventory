// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 * 
 */


UCLASS(Abstract,BlueprintType,Blueprintable,EditInlineNew,DefaultToInstanced)
class INVENTORY_API UItem : public UObject
{
	GENERATED_BODY() 
public:
    UItem();

    virtual class UWorld* GetWorld() const {return World;};

    UPROPERTY(Transient)
    class UWorld* World;

    //The text for using ths item.
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "Item")
    FText UseActionText;

    //The mesh to display for this items pickup
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "Item")
    class UStaticMesh* PickupMesh;

   // The Thumnail for this item
    UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Item")
    class UTexture2D* Thumnail;

    //The display name for this item in the inventory
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "Item")
    FText ItemDisplayName;


    //An optional description for the item
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "Item", meta = (MultiLine = true))
    FText ItemDescription;

    //The weight of the item
    UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "Item",meta = (ClampMin = 0.0))
    float Weight;

    //The inventory tha owns this item
    UPROPERTY()
    class UInventoryComponent* OwningInventory;

    virtual void Use(class AInventoryCharacter* Character);

    UFUNCTION(BlueprintImplementableEvent)
    void OnUse(class AInventoryCharacter* Character);

          
};
