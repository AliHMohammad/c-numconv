#ifndef NUMCONV2_H
#define NUMCONV2_H

int dec_to_int(char str[]);
int bin_to_int(char str[]);
int hex_to_int(char str[]);
int oct_to_int(char str[]);

void int_to_dec(int num, char str[]);
void int_to_hex(int num, char str[]);
void int_to_oct(int num, char str[]);
void int_to_bin(int num, char str[]);

// Helpers

int is_digit(char c);
int is_bin_digit(char c);
int is_hex_digit(char c);
int is_oct_digit(char c);

void reverse_string(char *startPos, char *str);

#endif // NUMCONV2_H
