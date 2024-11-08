#include "string_functions.h"
#include <ctype.h>  
int strcmp_ign_case(char *s1, char *s2) {
    while (*s1 && *s2 && tolower((unsigned char)*s1) == tolower((unsigned char)*s2)) {
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}
