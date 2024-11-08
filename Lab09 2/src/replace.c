#include "string_functions.h"
#include <stdlib.h>
#include <string.h>

char *replace(char *s, char *pat, char *rep) {
    int s_len = strlen(s), pat_len = strlen(pat), rep_len = strlen(rep);
    int count = 0;

    for (char *p = s; (p = strstr(p, pat)); p += pat_len) {
        count++;
    }

    int new_length = s_len + count * (rep_len - pat_len);
    char *result = malloc(new_length + 1);
    if (!result) return NULL;

    char *src = s, *dst = result;
    while (*src) {
        if (strstr(src, pat) == src) {
            strcpy(dst, rep);
            dst += rep_len;
            src += pat_len;
        } else {
            *dst++ = *src++;
        }
    }
    *dst = '\0';
    return result;
}
