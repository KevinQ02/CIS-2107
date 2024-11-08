#include "string_functions.h"

void take_last(char *s, int n) {
    int len = strlen(s);
    if (n < len) {
        memmove(s, s + len - n, n);
        s[n] = '\0';
    }
}
