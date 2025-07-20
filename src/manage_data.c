#include <stdio.h.>

#include "../include/helpers.h"

#define INVENTORY_FILE "data/inventory.txt"
#define INVENTORY_FILE_CSV "data/inventory.csv"

void export_to_csv(Inventory *inventory)
{
    FILE *file = fopen(INVENTORY_FILE_CSV, "w");
    if (file == NULL)
    {
        printf("Failed to export inventory");
        return;
    }

    fprintf(file, "Item Name,Quantity,Value\n");
    for (int i = 0; i < inventory->count; i++)
    {
        fprintf(file, "\"%s\",%i,%i\n",
                inventory->item[i].name,
                inventory->item[i].quantity,
                inventory->item[i].value);
    }

    fclose(file);
}

void load_from_file(Inventory *inventory)
{
    // Make sure file exist
    FILE *temp_file = fopen(INVENTORY_FILE, "a");
    if (temp_file == NULL)
    {
        printf("Error: couldn't load file\n");
        exit(1);
    }
    fclose(temp_file);

    FILE *file = fopen(INVENTORY_FILE, "r");
    if (file == NULL)
    {
        printf("Error: couldn't load file\n");
        exit(1);
    }

    Item item;

    while (fscanf(file, "%49[^|]|%i|%i\n", item.name, &item.quantity, &item.value) == 3)
    {
        inventory->item[inventory->count++] = item;
        if (inventory->count >= MAX_ITEM)
            break;
        printf("code reach here\n");
    }

    fclose(file);
}

void save_to_file(Inventory *inventory)
{
    FILE *file = fopen(INVENTORY_FILE, "w");
    if (file == NULL)
    {
        printf("Error: couldn't save file\n");
        exit(1);
    }

    for (int i = 0; i < inventory->count; i++)
    {
        fprintf(file, "%s|", inventory->item[i].name);
        fprintf(file, "%i|", inventory->item[i].quantity);
        fprintf(file, "%i\n", inventory->item[i].value);
    }

    fclose(file);
}