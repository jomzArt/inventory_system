#ifndef HELPERS_H
#define HELPERS_H

#include <stdbool.h>
#include <windows.h>

#include "inventory.h"

#define COL_SPACING 2

typedef int (*char_compare)(const char *, const char *);
typedef int (*int_compare)(const int, const int);

// For saving/loading data
void export_to_csv(Inventory *inventory);
void load_from_file(Inventory *inventory);
void save_to_file(Inventory *inventory);

// Inventory logic
bool delete_item(Inventory *inventory, Item *item, int item_index);
int search_item(Inventory *inventory);
void add_new_item(Inventory *inventory);
void edit_item(Inventory *inventory, Item *item);

// Filter inventory
int name_asc(const char *a, const char *b);
int name_desc(const char *a, const char *b);
int quantity_asc(const int a, const int b);
int quantity_desc(const int a, const int b);
int value_asc(const int a, const int b);
int value_desc(const int a, const int b);

void filter_name(Inventory *inventory, char_compare cmp);
void filter_quantity(Inventory *inventory, int_compare cmp);
void filter_value(Inventory *inventory, int_compare cmp);

// Graphics
void add_border(int widths[], int len);
void display_inventory(Inventory *inventory);
void display_item(Item *item);

// Utility
BOOL WINAPI handle_ctrl_c(DWORD signal);
int ask_for_number(char *prompt, int min, int max);
int is_answer_true(char *prompt);
int num_length(int num);
void flush_input();
void prompt_enter();
void set_cursor_position(int x, int y);
void show_cursor(bool visible);
void swap_items(Item *a, Item *b);

#endif