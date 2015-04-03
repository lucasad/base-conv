#ifndef READLINE_FALLBACK_H
#define READLINE_FALLBACK_H

#include <stdio.h>

char* readline(const char * prompt) {
    char *result;
    printf("%s", prompt);
    scanf("%ms", &result); 
    return result;
}

#endif /* READLINE_FALLBACK_H */
