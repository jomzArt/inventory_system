#include <stdbool.h>
#include <windows.h>

#include "inventory.h"

#define COL_SPACING 2

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
void filter_name_asc(Inventory *inventory);
void filter_name_desc(Inventory *inventory);
void filter_quantity_asc(Inventory *inventory);
void filter_quantity_desc(Inventory *inventory);
void filter_value_asc(Inventory *inventory);
void filter_value_desc(Inventory *inventory);

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