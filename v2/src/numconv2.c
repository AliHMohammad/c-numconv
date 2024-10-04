#include <stdio.h>
#include "numconv2.h"


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
        value <<= 4; // Shifter til venstre med 4 bits (2^4)
        char c = *str;

        if (c > 0x39) { // Hvis a-f/A-F
            c -= 7;
        }

        value += c & 0b1111; // AND med 15
        str++;
    }

    return value;
}

void int_to_hex(int num, char *str) {
    int remain = num;
    char *start = str;  // Start position
    
    // From right to left
    do {
        int digit = remain & 0xF; // Få de første fire bits (15) med AND masking 

        if (digit < 10) {
            *str = digit | 0b00110000;  // OR med asci 48
        } else {
            *str = (0x41 & 0xF0) | (digit - 9); 
        }

        str++;
        remain >>= 4; // Shifter til højre med 4 bits (2^4)
    } while (remain > 0);
    
    *str = '\0';
    reverse_string(start, str);
}

int bin_to_int(char *str) {
    int value = 0;

    while (is_bin_digit(*str))
    {
        value <<= 1;

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
        remain >>= 1;
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

