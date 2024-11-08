#include "string_functions.h"

void shorten(char *s, int new_len) {
    if (new_len < 0) return;
    if (s[new_len] != '\0') s[new_len] = '\0';
}
