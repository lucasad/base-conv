#ifndef BASE_CONV_H
#define BASE_CONV_H
#include <stdint.h>

int parse_number(const char *string, unsigned char base, uint64_t *number); 
char* serialize_number(uint64_t number, unsigned char base, char *buf); 

char char_to_digit(char chr); 
char digit_to_char(char digit); 
#endif /* BASE_CONV_H */
