#include <stdio.h>

#define SIZE 100

// Provided char functions

// Returns : 1 if `c` is a lowercase letter
//         : 0 otherwise.
int is_lowercase(char c) {
    return 'a' <= c && c <= 'z';
}

// Returns : 1 if `c` is an uppercase letter
//         : 0 otherwise.
int is_uppercase(char c) {
    return 'A' <= c && c <= 'Z';
}

// Returns : 1 if `c` is a letter
//         : 0 otherwise.
int is_letter(char c) {
    return is_lowercase(c) || is_uppercase(c);
}

// Returns : `c` converted to lowercase, if it was an uppercase letter
//         : `c` unmodified, otherwise
char to_lowercase(char c) {
    if (is_uppercase(c)) {
        return c - 'A' + 'a';
    }
    return c;
}

// Returns : `c` converted to uppercase, if it was a lowercase letter
//         : `c` unmodified, otherwise
char to_uppercase(char c) {
    if (is_lowercase(c)) {
        return c - 'a' + 'A';
    }
    return c;
}

// Returns : 1 if `c` is an uppercase or lowercase vowel
//         : 0 otherwise.
int is_vowel(char c) {
    char lower_c = to_lowercase(c);
    return lower_c == 'a' 
        || lower_c == 'e'
        || lower_c == 'i' 
        || lower_c == 'o' 
        || lower_c == 'u';
}

// Functions to implement:

// 1.
// returns the number of lowercase letters in `char string[]`
int count_lowercase(char string[]) {
    int count = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (is_lowercase(string[i])) {
            count++;
        }
    }
    return count;
}

// 2.
// modifies `char string[]` by converting all its vowels to uppercase
void make_vowels_uppercase(char string[]) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (is_vowel(string[i])) {
            string[i] = to_uppercase(string[i]);
        }
    }
}

// 3..
// shortens a string so that it ends after the first word
// e.g. "This is a sentence" should turn into:
//      "This"
// 
// (hint. what defines when a string ends?)
void delete_following_words(char string[]) {
    int is_deleted = 0;
    for (int i = 0; string[i] != '\0' && is_deleted == 0; i++) {
        if (string[i] == ' ') {
            string[i] = '\0';
            is_deleted = 1;
        }
    }
}

int main(void) {

    char string[SIZE] = "Hello World!";

    printf("Testing count_lowercase():\n");
    printf("Original string: %s\n", string);
    printf("Result: %d\n", count_lowercase(string));

    printf("Testing make_vowels_uppercase():\n");
    printf("Original string: %s\n", string);
    make_vowels_uppercase(string);
    printf("Result: %s\n", string);

    printf("Testing delete_following_words():\n");
    printf("Original string: %s\n", string);
    delete_following_words(string);
    printf("Result: %s\n", string);

    return 0;
}