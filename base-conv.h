#ifndef BASE_CONV_H
#define BASE_CANV_H

int parse_number(const char *string, unsigned char base, unsigned *number); 
char* serialize_number(unsigned int number, unsigned char base, char *buf); 

char char_to_digit(char chr); 
char digit_to_char(char digit); 
#endif /* BASE_CONV_H */
