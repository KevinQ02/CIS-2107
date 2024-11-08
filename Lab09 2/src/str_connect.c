#include "string_functions.h"
#include <stdlib.h>
#include <string.h>

char *str_connect(char **strs, int n, char sep) {
    if (n <= 0) return NULL;

    int total_length = 0;
    for (int i = 0; i < n; i++) {
        total_length += strlen(strs[i]);
        if (i < n - 1) total_length++; 
    }

    char *result = malloc(total_length + 1);
    if (!result) return NULL;

    char *p = result;
    for (int i = 0; i < n; i++) {
        strcpy(p, strs[i]);
        p += strlen(strs[i]);
        if (i < n - 1) *p++ = sep;
    }
    *p = '\0';
    return result;
}
