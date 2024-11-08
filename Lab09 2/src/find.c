#include "string_functions.h"

int find(char *h, char *n) {
    char *p = h;
    int pos = 0;

    while (*p) {
        char *start = p, *sub = n;
        while (*sub && *start && *start == *sub) {
            start++;
            sub++;
        }
        if (!*sub) return pos;
        p++;
        pos++;
    }
    return -1;
}
