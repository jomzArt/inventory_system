#include <conio.h>
#include <stdio.h>
#include <string.h>

#include "../include/helpers.h"

int num_length(int num) {
    int num_len = 0;
    if (num == 0)
        return 1;

    if (num < 0) {
        num_len++;
        num *= -1;
    }
    while (num) {
        num_len++;
        num /= 10;
    }
    return num_len;
}

int is_answer_true(char *prompt) {
    char answer[50];
    while (1) {
        printf("%s", prompt);

        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = '\0';

        if (strcasecmp(answer, "n") == 0 || strcasecmp(answer, "no") == 0)
            return 0;
        else if (strcasecmp(answer, "y") == 0 || strcasecmp(answer, "yes") == 0)
            return 1;
    }
}

int ask_for_number(char *prompt, int min, int max) {
    char number[10];
    int num = 0;
    while (1) {
        printf("%s", prompt);
        fgets(number, sizeof(number), stdin);
        if (sscanf(number, "%i", &num) != 1)
            continue;

        if (num >= min && num <= max) {
            return num;
        }
    }
}

void swap_items(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void show_cursor(bool visible) {
    HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor_info;
    GetConsoleCursorInfo(h_console, &cursor_info);
    cursor_info.bVisible = visible;
    SetConsoleCursorInfo(h_console, &cursor_info);
}

void set_cursor_position(int x, int y) {
    COORD coords;

    coords.X = x;
    coords.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);
}

void prompt_enter() {
    printf("\nPress enter to continue\n");

    while (GetAsyncKeyState(VK_RETURN) & 0x8000)
        Sleep(10);
    while (!(GetAsyncKeyState(VK_RETURN) & 0x8000))
        Sleep(10);

    Sleep(150);
    flush_input();
}

void flush_input() {
    while (_kbhit()) _getch();
}

BOOL WINAPI handle_ctrl_c(DWORD signal) {
    if (signal == CTRL_C_EVENT) {
        system("cls");
        printf("Program terminated by Ctrl+C\n");
        exit(0);
    }
    return FALSE;
}