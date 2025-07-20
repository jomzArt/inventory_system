#include <stdio.h>

#include "../include/helpers.h"

void add_border(int widths[], int len)
{
    printf("+");
    for (int col = 0; col < len; col++)
    {
        for (int i = 0; i < widths[col] + COL_SPACING; i++)
            putchar('-');
        printf("+");
    }
    printf("\n");
}

void display_item(Item *item)
{
    //  For dynamic padding
    char *header[] = {"ITEM NAME", "QUANTITY", "VALUE"};
    int widths[] = {strlen(header[0]), strlen(header[1]), strlen(header[2])};
    int widths_len = sizeof(widths) / sizeof(widths[0]);

    int name_len = strlen(item->name);
    int quantity_len = num_length(item->quantity);
    int value_len = num_length(item->value);

    if (name_len > widths[0])
        widths[0] = name_len;
    if (quantity_len > widths[1])
        widths[1] = quantity_len;
    if (value_len > widths[2])
        widths[2] = value_len;

    // Draw top border
    add_border(widths, widths_len);

    // Draw header
    for (int i = 0; i < widths_len; i++)
    {
        if (i == 0)
            printf("| %-*s ", widths[i], header[i]);
        else
            printf("| %*s ", widths[i], header[i]);
    }
    printf("|\n");

    // Draw bottom header border
    add_border(widths, widths_len);

    // Draw item
    printf("| %-*s ", widths[0], item->name);
    printf("| %*i ", widths[1], item->quantity);
    printf("| %*i ", widths[2], item->value);
    printf("|\n");

    // Draw bottom border
    add_border(widths, widths_len);
}

void display_inventory(Inventory *inventory)
{
    if (inventory->count == 0)
    {
        printf("------Inventory is empty------\n");
        return;
    }

    // For dynamic padding
    char *header[] = {"ITEM NAME", "QUANTITY", "VALUE"};
    int widths[] = {strlen(header[0]), strlen(header[1]), strlen(header[2])};
    int widths_len = sizeof(widths) / sizeof(widths[0]);

    for (int i = 0; i < inventory->count; i++)
    {
        int name_len = strlen(inventory->item[i].name);
        int quantity_len = num_length(inventory->item[i].quantity);
        int value_len = num_length(inventory->item[i].value);

        if (name_len > widths[0])
            widths[0] = name_len;
        if (quantity_len > widths[1])
            widths[1] = quantity_len;
        if (value_len > widths[2])
            widths[2] = value_len;
    }

    // Draw top border
    add_border(widths, widths_len);

    // Draw header
    for (int i = 0; i < widths_len; i++)
    {
        if (i == 0)
            printf("| %-*s ", widths[i], header[i]);
        else
            printf("| %*s ", widths[i], header[i]);
    }
    printf("|\n");

    // Draw header bottom border
    add_border(widths, widths_len);

    // Draw inventory Items
    for (int item = 0; item < inventory->count; item++)
    {
        printf("| %-*s ", widths[0], inventory->item[item].name);
        printf("| %*i ", widths[1], inventory->item[item].quantity);
        printf("| %*i ", widths[2], inventory->item[item].value);
        printf("|\n");
    }

    if (inventory->count > 0)
    {
        // Draw bottom border
        add_border(widths, widths_len);
    }
}