#include <string.h>
#include <stdint.h>
#include "base-conv.h"

char char_to_digit(char chr) {
    return (chr-'0') < 10 ? (chr-'0') : (chr-'A'+10);
}

char digit_to_char(char digit) {
    return (digit < 10) ? '0'+digit : 'A' + (digit-10);
}

int parse_number(const char *string, unsigned char base, uint64_t  *out) {
    int pos = 0;
    uint64_t number =0;
    do {
        number *= base;

        unsigned int digit = char_to_digit(string[pos++]);
        if(digit >= base) return -1; 
        number += digit; 
    } while(string[pos]);

    *out = number;
    return 0; 
}


char* serialize_number(uint64_t number, unsigned char base, char *buf) { 
    int pos=65, digit=0;
    buf[pos] = 0;
    do {
        buf[--pos] = digit_to_char(number % base); 
        number /= base;
    } while(number);

    return buf+pos;
}
