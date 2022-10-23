 // Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"
#include "InventoryCharacter.h"
#include "InventoryComponent.h"

void UFoodItem::Use(class AInventoryCharacter* Character)
{
     if(Character)
     {
         Character->Health += HealthToHeal;
         
         if(OwningInventory)
         {
             OwningInventory->RemoveItem(this);
         }
     }
}
