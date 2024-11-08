#include "string_functions.h"
#include <ctype.h>  

int is_empty(char *s) {
    if (!s) return 1;
    while (*s) {
        if (!isspace((unsigned char)*s)) return 0;
        s++;
    }
    return 1;
}
