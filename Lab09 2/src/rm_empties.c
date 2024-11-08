#include "string_functions.h"
#include <stdlib.h>  

void rm_empties(char **words) {
    char **src = words, **dst = words;
    while (*src) {
        if (**src != '\0') {
            *dst++ = *src;
        }
        src++;
    }
    *dst = NULL; 
}
