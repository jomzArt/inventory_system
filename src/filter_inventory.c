#include "../include/helpers.h"

void filter_quantity_asc(Inventory *inventory) {
    for (int i = 0; i < inventory->count; i++) {
        bool is_swap = false;
        for (int j = 0; j < inventory->count - (i + 1); j++) {
            if (inventory->item[j].quantity > inventory->item[j + 1].quantity) {
                swap_items(&inventory->item[j], &inventory->item[j + 1]);

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
                swap_items(&inventory->item[j], &inventory->item[j + 1]);

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
                swap_items(&inventory->item[j], &inventory->item[j + 1]);

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
                swap_items(&inventory->item[j], &inventory->item[j + 1]);

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
            if (strcasecmp(inventory->item[j].name, inventory->item[j + 1].name) > 0) {
                swap_items(&inventory->item[j], &inventory->item[j + 1]);

                is_swap = true;
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
            if (strcasecmp(inventory->item[j].name, inventory->item[j + 1].name) < 0) {
                swap_items(&inventory->item[j], &inventory->item[j + 1]);

                is_swap = true;
            }
        }
        if (!is_swap) {
            return;
        }
    }
}