#include "string_functions.h"
#include <stdlib.h>
#include <string.h>

char **str_chop_all(char *s, char c) {
    int count = 1;
    for (char *p = s; *p; p++) {
        if (*p == c) count++;
    }

    char **result = malloc((count + 1) * sizeof(char *));
    if (!result) return NULL;

    int i = 0;
    char *next = strtok(s, &c);
    while (next) {
        result[i++] = next;
        next = strtok(NULL, &c);
    }
    result[i] = NULL;
    return result;
}
