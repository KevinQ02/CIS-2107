#include "string_functions.h"
#include <string.h>  

char *ptr_to(char *h, char *n) {
    if (h == NULL || n == NULL) return NULL;  
    char *start = h;
    char *pattern = n;
    while (*start) {
        char *current = start;
        pattern = n;
        while (*current && *pattern && *current == *pattern) {
            current++;
            pattern++;
        }
        if (*pattern == '\0') {
            return start;
        }
        start++;
    }
    return NULL; 
}
