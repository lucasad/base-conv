#ifndef READLINE_FALLBACK_H
#define READLINE_FALLBACK_H

#include <stdio.h>
#include <string.h>

char* readline(const char * prompt) {
    char *result = malloc(1024);
    printf("%s", prompt);
    fgets(result, 1023, stdin);
    result[strlen(result)-1] = 0;
    return result;
}

#endif /* READLINE_FALLBACK_H */
