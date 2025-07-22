#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX_ITEM 100
#define MAX_LEN_NAME 50

typedef struct
{
    char name[MAX_LEN_NAME];
    int quantity;
    int value;
}
Item;

typedef struct
{
    Item item[MAX_ITEM];
    int count;
}
Inventory;

#endif