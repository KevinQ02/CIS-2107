#include <stdio.h>
#include <stdlib.h>
#include "string_functions.h"

int main() {
    // Test all_letters
    printf("All letters ('HelloWorld'): %d\n", all_letters("HelloWorld"));
    printf("All letters ('He11o World'): %d\n", all_letters("He11o World"));

    // Test num_in_range
    printf("Num in range ('Yellow', 'f', 'm'): %d\n", num_in_range("Yellow", 'f', 'm'));

    // Test diff
    printf("Diff ('Book', 'Back'): %d\n", diff("Book", "Back"));

    // Test shorten
    char string1[] = "Hello World";
    shorten(string1, 5);
    printf("Shorten ('Hello World', 5): %s\n", string1);
    char string2[] = "Hello World";
    shorten(string2, 20);
    printf("Shorten ('Hello World', 20): %s\n", string2);

    // Test len_diff
    printf("Len diff ('Philadelphia', 'Hello'): %d\n", len_diff("Philadelphia", "Hello"));

    // Test rm_left_space
    char string3[] = "     Hello";
    rm_left_space(string3);
    printf("Remove left space ('     Hello'): '%s'\n", string3);

    // Test rm_right_space
    char string4[] = "Hello     ";
    rm_right_space(string4);
    printf("Remove right space ('Hello     '): '%s'\n", string4);

    // Test rm_space
    char string5[] = " Hello     ";
    rm_space(string5);
    printf("Remove space (' Hello     '): '%s'\n", string5);

    // Test find
    printf("Find ('Hello', 'l'): %d\n", find("Hello", "l"));
    printf("Find ('Hello', 'q'): %d\n", find("Hello", "q"));

    // Test ptr_to
    printf("Ptr to ('Hello', 'l'): %s\n", ptr_to("Hello", "l"));
    printf("Ptr to ('Hello', 'q'): %s\n", ptr_to("Hello", "q") ? ptr_to("Hello", "q") : "NULL");

    // Test is_empty
    printf("Is empty (' '): %d\n", is_empty(" "));
    printf("Is empty ('Hello'): %d\n", is_empty("Hello"));

    // Test str_zip
    char *zipped = str_zip("Temple", "Hello");
    printf("Str zip ('Temple', 'Hello'): %s\n", zipped);
    free(zipped); // Don't forget to free the memory!

    // Test capitalize
    char string6[] = "hello world";
    capitalize(string6);
    printf("Capitalize ('hello world'): %s\n", string6);

    // Test strcmp_ign_case
    printf("Strcmp ign case ('hello', 'goodbye'): %d\n", strcmp_ign_case("hello", "goodbye"));
    printf("Strcmp ign case ('Hello', 'hello'): %d\n", strcmp_ign_case("Hello", "hello"));

    // Test take_last
    char string7[] = "hello";
    take_last(string7, 3);
    printf("Take last ('hello', 3): %s\n", string7);

    // Test dedup
    char *deduped = dedup("hello");
    printf("Dedup ('hello'): %s\n", deduped);
    free(deduped);

    // Test pad
    char *padded = pad("hello", 6);
    printf("Pad ('hello', 6): '%s'\n", padded);
    free(padded);

    // Test ends_with_ignore_case
    printf("Ends with ignore case ('Coding', 'ing'): %d\n", ends_with_ignore_case("Coding", "ing"));
    printf("Ends with ignore case ('Coding', 'ed'): %d\n", ends_with_ignore_case("Coding", "ed"));

    // Test repeat
    char *repeated = repeat("hello", 3, '-');
    printf("Repeat ('hello', 3, '-'): %s\n", repeated);
    free(repeated);

    // Test replace
    char *replaced = replace("Steph is the X", "X", "best");
    printf("Replace ('Steph is the X', 'X', 'best'): %s\n", replaced);
    free(replaced);

    // Test str_connect
    char *strings[] = {"Hello", "world", "Hello", "world", NULL}; 
    char *connected = str_connect(strings, 4, '-');
    if (connected != NULL) {
        printf("Str connect (4 strings with '-'): %s\n", connected);
        free(connected); 
    } else {
        printf("Failed to connect strings.\n");
    }


    // Test rm_empties
    char *words[] = {"Hello", "World", "", "", "Steph", NULL};
    rm_empties(words);
    printf("Remove empties: ");
    for (int i = 0; words[i] != NULL; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    // Test str_chop_all
    char chop_string[] = "Hello/world/hello/world";
    char **chopped = str_chop_all(chop_string, '/');
    printf("Str chop all ('Hello/world/hello/world', '/'): ");
    for (int i = 0; chopped[i] != NULL; i++) {
        printf("%s ", chopped[i]);
    }
    printf("\n");
    free(chopped); // Assume dynamic allocation in str_chop_all

    return 0;
}
