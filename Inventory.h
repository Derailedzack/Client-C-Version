#pragma once

typedef void (Item_Use_func)();
typedef void (Item_OnRemoval)();

typedef struct Item
{

	const char* name;
	const char* image_path;
	int func_id;
	int id;
	Item_Use_func* use_func;
	
	
}Item;

typedef struct Slot
{
	Item item;
	int slot_index;
}Slot;
int inventory_size;
typedef Slot* (Create_Inventory_Func)();

void SetIteminSlot(Item item, Slot slot);
void SetItemInSlot(Item* item,int slot_id,int item_id,Slot* slot);
void SetInventorySize(int slot_number);
Item GetItemFromName(const char* item_name);
Item GetItemFromID(int item_id);
Slot GetSlotFromItem();
Slot GetSlotFromSlotIndex();


Slot* CreateInventory(Create_Inventory_Func* create_inventory);
