#include "string_functions.h"
#include <ctype.h>  

int ends_with_ignore_case(char *s, char *suff) {
    int slen = strlen(s);
    int sufflen = strlen(suff);
    if (sufflen > slen) return 0;
    s += slen - sufflen;
    while (*suff) {
        if (tolower((unsigned char)*s++) != tolower((unsigned char)*suff++)) return 0;
    }
    return 1;
}

