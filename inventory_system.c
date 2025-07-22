#include <conio.h>
#include <stdio.h>
#include <windows.h>

#include "include/helpers.h"

// Inventory
void inventory_manager();
void item_manager(Inventory *inventory, int item_index);
void filter_inventory(Inventory *inventory);

int main() {
    SetConsoleCtrlHandler(handle_ctrl_c, TRUE);
    system("cls");
    inventory_manager();
}

void inventory_manager() {
    Inventory inventory = {0};

    load_from_file(&inventory);

    int cursor_y = 0;
    char *cursor[] = {" <--\n", "    \n"};
    int options = 4;

    // Menu
    while (true) {
        set_cursor_position(0, 0);
        show_cursor(false);

        display_inventory(&inventory);

        printf("+----------------------------+\n");
        printf("|    Inventory Manager       |\n");
        printf("+----------------------------+\n");

        printf("| Add Item                   |");

        // Add cursor
        if (cursor_y == 0)
            printf("%s", cursor[0]);
        else
            printf("%s", cursor[1]);

        printf("| Search Item                |");

        // Add cursor
        if (cursor_y == 1)
            printf("%s", cursor[0]);
        else
            printf("%s", cursor[1]);

        printf("| Filter Inventory           |");

        // Add cursor
        if (cursor_y == 2)
            printf("%s", cursor[0]);
        else
            printf("%s", cursor[1]);

        printf("| Exit                       |");

        // Add cursors
        if (cursor_y == 3)
            printf("%s", cursor[0]);
        else
            printf("%s", cursor[1]);

        printf("+----------------------------+\n");

        printf("Select Options");

        if (_kbhit()) {
            int key = _getch();

            if (key == 0 || key == 224) {
                key = _getch();
                switch (key) {
                    case 72: // up
                        cursor_y = (cursor_y + options - 1) % options;
                        break;
                    case 80: // down
                        cursor_y = (cursor_y + 1) % options;
                        break;
                }
            }
            else if (key == '\r') {  // enter key
                show_cursor(true);
                switch (cursor_y) {
                    case 0:
                        add_new_item(&inventory);
                        break;
                    case 1:
                        int item_index = search_item(&inventory);
                        if (item_index == -1) {
                            system("cls");
                            printf("No Item Found\n");
                            prompt_enter();
                        }
                        else {
                            item_manager(&inventory, item_index);
                        }
                        break;
                    case 2:
                        filter_inventory(&inventory);
                        break;
                    case 3:
                        system("cls");
                        save_to_file(&inventory);
                        export_to_csv(&inventory);
                        exit(0);
                }
            }
        }
        Sleep(60);
    }
}

void item_manager(Inventory *inventory, int item_index) {
    Item *item = &inventory->item[item_index];

    while (true) {
        system("cls");
        display_item(item);

        printf("+---------------------+\n");
        printf("| 1. Edit Item        |\n");
        printf("| 2. Delete Item      |\n");
        printf("| 3. Back             |\n");
        printf("+---------------------+\n");
        int choice = ask_for_number("Select Options ", 1, 3);

        switch (choice) {
            case 1:
                edit_item(inventory, item);
                break;
            case 2:
                if (delete_item(inventory, item, item_index)) return;
                break;
            case 3:
                system("cls");
                return;
        }
    }
}

void filter_inventory(Inventory *inventory) {
    if (inventory->count == 0) {
        printf("Inventory is empty\n");

        prompt_enter();
        return;
    }

    system("cls");

    display_inventory(inventory);

    printf("+--------------------------------+\n");
    printf("| 1. Filter by name (A-Z)        |\n");
    printf("| 2. Filter by name (Z-A)        |\n");
    printf("| 3. Filter by quantity (ASC)    |\n");
    printf("| 4. Filter by quantity (DESC)   |\n");
    printf("| 5. Filter by value (ASC)       |\n");
    printf("| 6. Filter by value (DESC)      |\n");
    printf("+--------------------------------+\n");
    int choice = ask_for_number("Select Option: ", 1, 6);

    switch (choice) {
        case 1:
            filter_name_asc(inventory);
            break;
        case 2:
            filter_name_desc(inventory);
            break;
        case 3:
            filter_quantity_asc(inventory);
            break;
        case 4:
            filter_quantity_desc(inventory);
            break;
        case 5:
            filter_value_asc(inventory);
            break;
        case 6:
            filter_value_desc(inventory);
    }

    system("cls");
}