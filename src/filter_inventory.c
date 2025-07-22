#include "../include/helpers.h"

int name_asc(const char *a, const char *b) { return strcasecmp(a, b); }
int name_desc(const char *a, const char *b) { return strcasecmp(b, a); }
int quantity_asc(const int a, const int b) { return a - b; }
int quantity_desc(const int a, const int b) { return b - a; }
int value_asc(const int a, const int b) { return a - b; }
int value_desc(const int a, const int b) { return b - a; }

void filter_quantity(Inventory *inventory, int_compare cmp) {
    for (int i = 0; i < inventory->count; i++) {
        bool is_swap = false;
        for (int j = 0; j < inventory->count - (i + 1); j++) {
            if (cmp(inventory->item[j].quantity, inventory->item[j + 1].quantity) > 0) {
                swap_items(&inventory->item[j], &inventory->item[j + 1]);

                is_swap = true;
            }
        }
        if (!is_swap) {
            return;
        }
    }
}

void filter_value(Inventory *inventory, int_compare cmp) {
    for (int i = 0; i < inventory->count; i++) {
        bool is_swap = false;
        for (int j = 0; j < inventory->count - (i + 1); j++) {
            if (cmp(inventory->item[j].value, inventory->item[j + 1].value) > 0) {
                swap_items(&inventory->item[j], &inventory->item[j + 1]);

                is_swap = true;
            }
        }
        if (!is_swap) {
            return;
        }
    }
}

void filter_name(Inventory *inventory, char_compare cmp) {
    for (int i = 0; i < inventory->count; i++) {
        bool is_swap = false;
        for (int j = 0; j < inventory->count - (i + 1); j++) {
            if (cmp(inventory->item[j].name, inventory->item[j + 1].name) > 0) {
                swap_items(&inventory->item[j], &inventory->item[j + 1]);

                is_swap = true;
            }
        }
        if (!is_swap) {
            return;
        }
    }
}