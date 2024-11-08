#include "string_functions.h"
#include <stdlib.h>

char *dedup(char *s) {
    char *result = malloc(strlen(s) + 1);
    if (!result) return NULL;
    char *p = result, *end = result;
    while (*s) {
        char *temp = result;
        int found = 0;
        while (temp < end) {
            if (*temp == *s) { found = 1; break; }
            temp++;
        }
        if (!found) *end++ = *s;
        s++;
    }
    *end = '\0';
    return result;
}
