#include <stdio.h>
#include "numconv1.h"


int dec_to_int(char *str) {
    int value = 0;
    int isNegative = 0;

    if (*str == '-') {
        str++;
        isNegative = 1;
    }

    while (is_digit(*str))
    {
        value *= 10;
        value += *str - '0';
        str++;
    }
    
    if (isNegative == 1) {
        value *= -1;
    }
    
    return value;
}

void int_to_dec(int num, char* str) {
    int remain = num;
    char *start = str;  // Start position
    do
    {
        int digit = remain % 10;
        *str = digit + '0';
        str++;
        remain /= 10;
    } while (remain > 0);

    *str = '\0';
    reverse_string(start, str);
}

int oct_to_int(char *str) {
    int value = 0;

    while (is_oct_digit(*str))
    {
        value *= 8;
        value += *str - '0';

        str++;
    }

    return value;
}

void int_to_oct(int num, char *str) {
    int remain = num;
    char *start = str;  // Start position
    
    // From right to left
    do {
        int digit = remain % 8;

        *str = digit + '0';  // 0 er asci 48

        str++;
        remain /= 8;
    } while (remain > 0);
    
    *str = '\0';
    reverse_string(start, str);
}

int hex_to_int(char *str) {
    int value = 0;

    while (is_hex_digit(*str))
    {
        value *= 16;

        if (*str >= '0' && *str <= '9') {
            value += *str - '0'; 
        } else if ((*str >= 'A' && *str <= 'F') || (*str >= 'a' && *str <= 'f') ) {
            value += *str - 'A' + 10;  // til 10-15
        }

        str++;
    }

    return value;
}

void int_to_hex(int num, char *str) {
    int remain = num;
    char *start = str;  // Start position
    
    // From right to left
    do {
        int digit = remain % 16;

        if (digit < 10) {
            *str = digit + '0';  // 0 er asci 48
        } else {
            *str = digit + 'A' - 10; // 10 til 15;
        }

        str++;
        remain /= 16;
    } while (remain > 0);
    
    *str = '\0';
    reverse_string(start, str);
}

int bin_to_int(char *str) {
    int value = 0;

    while (is_bin_digit(*str))
    {
        value *= 2;

        if (*str == '1') {
            value += 1;
        } 
        
        str++;
    }

    return value;
}

void int_to_bin(int num, char *str) {
    int remain = num;
    char *start = str;  // Start position
    
    // From right to left
    do {
        int digit = remain % 2;
        *str = digit + '0';  // 0 er asci 48
        str++;
        remain /= 2;
    } while (remain > 0);
    

    *str = '\0';
    reverse_string(start, str - 1); // -1 for ikke at få '\0' med
}

int is_bin_digit(char c) {
    return (c == '0' || c == '1') ? 1 : 0;
}

int is_hex_digit(char c) {
    return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) ? 1 : 0;
}

int is_oct_digit(char c) {
    return (c >= '0' && c <= '8') ? 1 : 0;
}

int is_digit(char c) {
    return (c >= '0' && c <= '9') ? 1 : 0;
}

void reverse_string(char *startPos, char *str) {
    // Reverse the string to correct the order
    int len = str - startPos;  // Calculate the length of the binary string
    for (int i = 0; i < len / 2; i++) {
        // Swap the characters
        char temp = startPos[i];
        startPos[i] = startPos[len - i - 1];
        startPos[len - i - 1] = temp;
    }
}

