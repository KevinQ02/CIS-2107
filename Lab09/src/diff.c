#include "string_functions.h"

int diff(char *s1, char *s2) {
    int differences = 0;
    while (*s1 || *s2) {
        if (*s1 != *s2) differences++;
        if (*s1) s1++;
        if (*s2) s2++;
    }
    return differences;
}
