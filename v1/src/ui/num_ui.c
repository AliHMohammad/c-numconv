#include <stdio.h>
#include "num_ui.h"
#include "numconv1.h"

int main(int argc, char const *argv[])
{
    show_welcome();

    while (1)
    {
        char input[255];
        show_menu();

        scanf(" %c", input);

        if (*input == 'x'){
            break;
        }

        char type[255];
        char value[255];
        char result[255];

        if (*input == 'd'){
            show_dec_menu();
            scanf(" %c", type);

            if (*type == 'x'){
                continue;
            }

            if (*type == 'a') {
                int v = get_int_value();
                int_to_dec(v, result);
                printf("\nResult is %s\n", result);
            } else if (*type == 'b') {
                get_string_value(value);
                int final = dec_to_int(value);
                printf("\nResult is %d\n", final);
            }


        }  else if (*input == 'b') {
            show_bin_menu();
            scanf(" %c", type);

            if (*type == 'x'){
                continue;
            }

            if (*type == 'a') {
                int v = get_int_value();
                int_to_bin(v, result);
                printf("\nResult is %s\n", result);
            } else if (*type == 'b') {
                get_string_value(value);
                int final = bin_to_int(value);
                printf("\nResult is %d\n", final);
            }

        } else if (*input == 'h') {
            show_hex_menu();
            scanf(" %c", type);

            if (*type == 'x'){
                continue;
            }

            if (*type == 'a') {
                int v = get_int_value();
                int_to_hex(v, result);
                printf("\nResult is %s\n", result);
            } else if (*type == 'b') {
                get_string_value(value);
                int final = hex_to_int(value);
                printf("\nResult is %d\n", final);
            }
 
        } else if (*input == 'o') {
            show_octo_menu();
            scanf(" %c", type);

            if (*type == 'x'){
                continue;
            }

            if (*type == 'a') {
                int v = get_int_value();
                int_to_oct(v, result);
                printf("\nResult is %s\n", result);
            } else if (*type == 'b') {
                get_string_value(value);
                int final = oct_to_int(value);
                printf("\nResult is %d\n", final);
            }

        }

    }
    

    return 0;
}


void show_welcome() {
    puts("Welcome to Ali's Converter");
    puts("========================");
}

void show_menu() {
    puts("\nI want to convert:");
    puts("d) To/from decimals");
    puts("b) To/from binary");
    puts("h) To/from hexidecimals");
    puts("o) To/from octodecimals");
    puts("x) Exit");
}

void show_bin_menu() {
    puts("\nI want to convert:");
    puts("a) To binary");
    puts("b) From binary");
    puts("x) Exit");
}

void show_octo_menu() {
    puts("\nI want to convert:");
    puts("a) To octodecimals");
    puts("b) From octodecimals");
    puts("x) Exit");
}

void show_hex_menu() {
    puts("\nI want to convert:");
    puts("a) To hexidecimals");
    puts("b) From hexidecimals");
    puts("x) Exit");
}

void show_dec_menu() {
    puts("\nI want to convert:");
    puts("a) To decimals");
    puts("b) From decimals");
    puts("x) Exit");
}


void get_string_value(char *str) {
    printf("\nEnter value: ");
    scanf("%s", str);
}

int get_int_value() {
    printf("\nEnter value:");
    int val;
    scanf("%d", &val);
    return val;
}
