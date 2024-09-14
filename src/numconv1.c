#include <stdio.h>
#include "numconv1.h"

int main(int argc, char const *argv[])
{
    char bin[] = "101011010";
    printf("Hello\n");

    printf("%d\n", bin_to_int(bin));
    return 0;
}

int bin_to_int(char str[]) {
    int value = 0;

    while (*str != '\0')
    {
        value *= 2;

        if (*str == '1') {
            value += 1;
        } 
        
        str++;
    }

    return value;
}

