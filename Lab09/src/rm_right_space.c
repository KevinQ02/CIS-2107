#include "string_functions.h"

void rm_right_space(char *s) {
    char *end = s + strlen(s) - 1;
    while (end > s && (*end == ' ' || *end == '\t' || *end == '\n')) end--;
    *(end + 1) = '\0';
}
