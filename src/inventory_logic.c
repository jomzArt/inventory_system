#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/helpers.h"

void add_new_item(Inventory *inventory) {
    system("cls");
    if (inventory->count >= MAX_ITEM) {
        printf("Inventory full!\n");

        prompt_enter();
        return;
    }

    printf("Add New Item\n");

    Item new_item;
    printf("\n");
    printf("Enter Item: ");
    fgets(new_item.name, MAX_LEN_NAME, stdin);
    new_item.name[strcspn(new_item.name, "\n")] = '\0';

    new_item.quantity = ask_for_number("Enter Quantity: ", 1, INT_MAX);

    new_item.value = ask_for_number("Enter Value: ", 1, INT_MAX);

    inventory->item[inventory->count++] = new_item;

    printf("\nItem added successfully\n");
    prompt_enter();
}

int search_item(Inventory *inventory) {
    system("cls");

    display_inventory(inventory);

    char search[MAX_LEN_NAME];
    printf("Search Item: ");

    fgets(search, MAX_LEN_NAME, stdin);
    search[strcspn(search, "\n")] = '\0';

    for (int i = 0; i < inventory->count; i++) {
        if (strcasecmp(search, inventory->item[i].name) == 0)
        {
            return i;
        }
    }
    
    return -1;
}

void edit_item(Inventory *inventory, Item *item) {
    while (1) {
        system("cls");
        display_item(item);

        printf("+----------------------+\n");
        printf("| 1. Edit Name         |\n");
        printf("| 2. Edit Quantity     |\n");
        printf("| 3. Edit Value        |\n");
        printf("| 4. Back              |\n");
        printf("+----------------------+\n");
        int choice = ask_for_number("Select Options ", 1, 4);

        system("cls");
        switch (choice) {
            case 1:
                printf("Enter new name: ");
                fgets(item->name, MAX_LEN_NAME, stdin);
                item->name[strcspn(item->name, "\n")] = '\0';
                printf("\nItem updated successfully");
                prompt_enter();
                break;
            case 2:
                item->quantity = ask_for_number("Enter new quantity: ", 0, INT_MAX);
                printf("\nItem updated successfully");
                prompt_enter();
                break;
            case 3:
                item->value = ask_for_number("Enter new value: ", 0, INT_MAX);
                printf("\nItem updated successfully");
                prompt_enter();
                break;
            case 4:
                return;
        }
    }
}

bool delete_item(Inventory *inventory, Item *item, int item_index) {
    while (1) {
        if (is_answer_true("Do you really want to delete this item?y/n ")) {
            for (int i = item_index; i < inventory->count - 1; i++) {
                inventory->item[i] = inventory->item[i + 1];
            }
            inventory->count--;

            system("cls");
            printf("\nItem deleted successfully");
            prompt_enter();
            return true;
        }
        else {
            return false;
        }
    }
}