#include "string_functions.h"

int all_letters(char *s) {
    while (*s) {
        if (!((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))) {
            return 0;
        }
        s++;
    }
    return 1;
}
