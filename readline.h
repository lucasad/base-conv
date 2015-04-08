#ifndef READLINE_FALLBACK_H
#define READLINE_FALLBACK_H

#include <stdio.h>
#include <string.h>

char* readline(const char * prompt) {
    char *result = malloc(1);
    size_t n = 0;
    printf("%s", prompt);
    getline(&result, &n, stdin);
    result[strlen(result)-1] = 0;
    return result;
}

#endif /* READLINE_FALLBACK_H */
