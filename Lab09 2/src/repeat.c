#include "string_functions.h"
#include <stdlib.h>
#include <string.h>

char *repeat(char *s, int x, char sep) {
    if (s == NULL || x <= 0) return NULL;  

    int len = strlen(s);
    int total_length = x * len + (x - 1);  
    char *result = malloc(total_length + 1);  
    if (!result) return NULL; 

    char *ptr = result;
    for (int i = 0; i < x; i++) {
        strcpy(ptr, s);  
        ptr += len;  
        if (i < x - 1) {  
            *ptr = sep;
            ptr++;
        }
    }
    *ptr = '\0';  
    return result;
}
