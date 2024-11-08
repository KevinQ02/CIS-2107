#include "string_functions.h"
#include <stdlib.h>

char *str_zip(char *s1, char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    if (!result) return NULL;
    char *p = result;
    while (*s1 && *s2) {
        *p++ = *s1++;
        *p++ = *s2++;
    }
    while (*s1) *p++ = *s1++;
    while (*s2) *p++ = *s2++;
    *p = '\0';
    return result;
}
