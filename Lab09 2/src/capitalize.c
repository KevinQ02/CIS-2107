#include "string_functions.h"
#include <ctype.h>  

void capitalize(char *s) {
    int new_word = 1;
    while (*s) {
        if (isalpha((unsigned char)*s)) {
            *s = new_word ? toupper((unsigned char)*s) : tolower((unsigned char)*s);
            new_word = 0;
        } else {
            new_word = 1;
        }
        s++;
    }
}
