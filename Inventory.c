#include "Inventory.h"

void SetIteminSlot(Item item, Slot slot)
{
	slot.item = item;
}

void SetInventorySize(int slot_number)
{
	inventory_size = slot_number;
}
void SetItemInSlot(Item* item,int slot_id,int item_id,Slot* slot){
    slot[slot_id].item = item[item_id];
}
Slot* CreateInventory(Create_Inventory_Func* create_inventory)
{
	
	return (create_inventory)();
}

