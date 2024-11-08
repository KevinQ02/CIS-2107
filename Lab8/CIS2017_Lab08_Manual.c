/*
 * Name:	Guillermo K Quiroz
 * Section:	003 
 * Lab:  	CIS2107_Lab08_Manual 
 * Goal: 	To design and implement functions taking pointers as arguments 
			to process characters and strings.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions prototypes
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[]);
void endsWithed(char *string[]);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series);

    //test for endsWithed
    endsWithed(series);

}

// 1.(Displaying Strings in Uppercase and Lowercase) 
void * upperLower (const char * s) {
        char upper[100], lower[100];
    int i = 0;
    while (s[i]) {
        upper[i] = toupper(s[i]);
        lower[i] = tolower(s[i]);
        i++;
    }
    upper[i] = '\0'; 
    lower[i] = '\0';
    printf("%s\n%s\n", upper, lower);
}

// 2.(Converting Strings to Integers for Calculations) 
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4) {
return atoi(s1) + atoi(s2) + atoi(s3) + atoi(s4);
}

//3.(Converting Strings to Floating Point for Calculations) 
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4) {
    return atof(s1) + atof(s2) + atof(s3) + atof(s4);
}


//4.(Comparing Strings) 
void compareStr(const char *s1, const char *s2) {
        int result = strcmp(s1, s2);
    if (result < 0) printf("%s is less than %s\n", s1, s2);
    else if (result > 0) printf("%s is greater than %s\n", s1, s2);
    else printf("%s is equal to %s\n", s1, s2);
}

//5.(Comparing Portions of Strings) 
void comparePartialStr(const char *s1, const char *s2, int n) {
       int result = strncmp(s1, s2, n);
    if (result < 0) printf("Comparison of first %d chars: %s is less than %s\n", n, s1, s2);
    else if (result > 0) printf("Comparison of first %d chars: %s is greater than %s\n", n, s1, s2);
    else printf("Comparison of first %d chars: %s is equal to %s\n", n, s1, s2);
}


//6.(Random Sentences) 
void randomize(void) {
    char* article[] = {"the", "a", "one", "some", "any"};
    char* noun[] = {"boy", "girl", "dog", "town", "car"};
    char* verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char* preposition[] = {"to", "from", "over", "under", "on"};
    char sentence[100];

    for(int i = 0; i < 20; i++) {
        sprintf(sentence, "%s %s %s %s %s %s.",
                article[rand() % 5],
                noun[rand() % 5],
                verb[rand() % 5],
                preposition[rand() % 5],
                article[rand() % 5],
                noun[rand() % 5]);
        sentence[0] = toupper(sentence[0]);
        printf("%s\n", sentence);
    }
}

//7.(Tokenizing Telephone Numbers) 
int tokenizeTelNum(char *num) {
    char *token;
    char *rest = num;
    char areaCode[4];
    char phoneNumber[8];

    token = strtok_r(rest, " ()-", &rest);
    strcpy(areaCode, token);

    token = strtok_r(NULL, " ()-", &rest);
    strcpy(phoneNumber, token);
    strcat(phoneNumber, strtok_r(NULL, " ()-", &rest));

    printf("%s %s\n", areaCode, phoneNumber);
    return 0; 
}


//8.(Displaying a Sentence with Its Words Reversed) 
void reverse(char *text) {
    char *token;
    char *rest = text;
    char *words[100];
    int wordCount = 0;

    while ((token = strtok_r(rest, " ", &rest))) {
        words[wordCount++] = token;
    }

    for (int i = wordCount - 1; i >= 0; i--) {
        printf("%s ", words[i]);
    }
    printf("\n");
}


//9.(Counting the Occurrences of a Substring) 
int countSubstr (char * line, char * sub) {
    int count = 0;
    char *tmp = line;
    while((tmp = strstr(tmp, sub)) != NULL) {
        count++;
        tmp++;
    }
    return count;
}

//10.(Counting the Occurrences of a Character) 
int countChar (char *line, char c) {
    int count = 0;
    while(*line) {
        if (*line == c) count++;
        line++;
    }
    return count;
}


//11.(Counting the Letters of the Alphabet in a String) 
void countAlpha(char *string) {
    int counts[26] = {0};
    for (char *p = string; *p; p++) {
        if (isalpha(*p)) {
            counts[tolower(*p) - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("%c | %d\n", 'a' + i, counts[i]);
    }
}


//12.(Counting the Number of Words in a String) 
int countWords(char *string) {
    int count = 0;
    char *token;
    char *rest = string;

    while ((token = strtok_r(rest, " ", &rest))) {
        count++;
    }
    return count;
}

//13.(Strings Starting with "b") 
void startsWithB(char *string[]) {
    for (int i = 0; string[i] != NULL; i++) {
        if (tolower(string[i][0]) == 'b') {
            printf("%s ", string[i]);
        }
    }
    printf("\n");
}

//14.(Strings Ending with "ed") 
void endsWithed(char *string[]) {
    for (int i = 0; string[i] != NULL; i++) {
        int len = strlen(string[i]);
        if (len >= 2 && string[i][len-2] == 'e' && string[i][len-1] == 'd') {
            printf("%s ", string[i]);
        }
    }
    printf("\n");
}