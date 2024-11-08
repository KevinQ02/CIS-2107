#include "string_functions.h"
#include <stdlib.h>

char *pad(char *s, int d) {
    int len = strlen(s);
    int new_len = (len % d == 0) ? len : len + (d - (len % d));
    char *result = malloc(new_len + 1);
    if (!result) return NULL;
    strcpy(result, s);
    for (int i = len; i < new_len; i++) result[i] = ' ';
    result[new_len] = '\0';
    return result;
}
