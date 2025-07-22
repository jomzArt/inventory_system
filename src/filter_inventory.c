#include "../include/helpers.h"

void filter_quantity_asc(Inventory *inventory) {
    for (int i = 0; i < inventory->count; i++) {
        bool is_swap = false;
        for (int j = 0; j < inventory->count - (i + 1); j++) {
            if (inventory->item[j].quantity > inventory->item[j + 1].quantity) {
                // swap
                Item temp = inventory->item[j];
                inventory->item[j] = inventory->item[j + 1];
                inventory->item[j + 1] = temp;

                is_swap = true;
            }
        }
        if (!is_swap) {
            return;
        }
    }
}

void filter_quantity_desc(Inventory *inventory) {
        for (int i = 0; i < inventory->count; i++) {
        bool is_swap = false;
        for (int j = 0; j < inventory->count - (i + 1); j++) {
            if (inventory->item[j].quantity < inventory->item[j + 1].quantity) {
                // swap
                Item temp = inventory->item[j];
                inventory->item[j] = inventory->item[j + 1];
                inventory->item[j + 1] = temp;

                is_swap = true;
            }
        }
        if (!is_swap) {
            return;
        }
    }
}

void filter_value_asc(Inventory *inventory) {
    for (int i = 0; i < inventory->count; i++) {
        bool is_swap = false;
        for (int j = 0; j < inventory->count - (i + 1); j++) {
            if (inventory->item[j].value > inventory->item[j + 1].value) {
                // swap
                Item temp = inventory->item[j];
                inventory->item[j] = inventory->item[j + 1];
                inventory->item[j + 1] = temp;

                is_swap = true;
            }
        }
        if (!is_swap) {
            return;
        }
    }
}

void filter_value_desc(Inventory *inventory) {
    for (int i = 0; i < inventory->count; i++) {
        bool is_swap = false;
        for (int j = 0; j < inventory->count - (i + 1); j++) {
            if (inventory->item[j].value < inventory->item[j + 1].value) {
                // swap
                Item temp = inventory->item[j];
                inventory->item[j] = inventory->item[j + 1];
                inventory->item[j + 1] = temp;

                is_swap = true;
            }
        }
        if (!is_swap) {
            return;
        }
    }
}

void filter_name_asc(Inventory *inventory) {
    for (int i = 0; i < inventory->count; i++) {
        bool is_swap = false;
        for (int j = 0; j < inventory->count - (i + 1); j++) {
            // check and compare each character
            for (int k = 0; k < MAX_LEN_NAME; k++) {
                if (inventory->item[j].name[k] > inventory->item[j + 1].name[k]) {
                    Item temp = inventory->item[j];
                    inventory->item[j] = inventory->item[j + 1];
                    inventory->item[j + 1] = temp;

                    is_swap = true;
                    break;
                } else if (inventory->item[j].name[k] == inventory->item[j + 1].name[k]) {
                    continue;
                }
                break;
            }
        }
        if (!is_swap) {
            return;
        }
    }
}

void filter_name_desc(Inventory *inventory) {
    for (int i = 0; i < inventory->count; i++) {
        bool is_swap = false;
        for (int j = 0; j < inventory->count - (i + 1); j++) {
            // check and compare each character
            for (int k = 0; k < MAX_LEN_NAME; k++) {
                if (inventory->item[j].name[k] < inventory->item[j + 1].name[k]) {
                    Item temp = inventory->item[j];
                    inventory->item[j] = inventory->item[j + 1];
                    inventory->item[j + 1] = temp;

                    is_swap = true;
                    break;
                } else if (inventory->item[j].name[k] == inventory->item[j + 1].name[k]) {
                    continue;
                }
                break;
            }
        }
        if (!is_swap) {
            return;
        }
    }
}