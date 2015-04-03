#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>

#include "base-conv.h"

#define ever (;;) 

int prompt_number(const char *prompt, unsigned int *number, unsigned int base);

int main(int argc, char **argv) {
    unsigned int from=0, to=0;

    for ever {
        unsigned int number;
        char buf[65];
        char *converted;

        while(from < 2) {
            if(prompt_number("From: ", &from, 10)) {
                from = 0;
                fputs("You must give a number", stderr);
            } else if(from < 2) fputs("You must give a number greater than two\n", stderr);
        }
        while(to < 2) {
            if(prompt_number("To: ", &to, 10)) {
                to = 0;
                fputs("You must give a number", stderr);
            } else if(to < 2) fputs("You must give a number greater than two\n", stderr);
        }

        printf("Converting from base-%d to base-%d\n", from, to);

        if(prompt_number("Number: ", &number, from)) {
            fputs("You must enter a valid number in that base (case-sensitive… A is 10, a is 42\n",stderr);
            fflush(stderr);
        }

        if((converted=serialize_number(number, (unsigned char) to, buf))) {
            puts(converted);
        } else {
            fputs("Could not convert the number", stderr);
        }

    }

    return 0;
}

int prompt_number(const char *prompt, unsigned int *number, unsigned int base) {
    char *string = readline(prompt);
    if(string == NULL) {return -1; }; 
    if(parse_number(string, base, number)) {
        free(string);
        return -1;
    };

    free(string);
    return 0;
}
