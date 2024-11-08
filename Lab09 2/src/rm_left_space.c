#include "string_functions.h"

void rm_left_space(char *s) {
    char *start = s;
    while (*s && (*s == ' ' || *s == '\t' || *s == '\n')) s++;
    while (*s) *start++ = *s++;
    *start = '\0';
}
