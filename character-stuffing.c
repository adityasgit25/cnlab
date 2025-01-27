#include <stdio.h>
#include <string.h>

void main() {
    char input[30], stuffed[500], startDelimiter, endDelimiter;
    int i, j = 0;

    printf("Enter the characters to be stuffed: ");
    scanf("%s", input);

    printf("Enter the starting delimiter character: ");
    scanf(" %c", &startDelimiter); // remember to give a space before %c

    printf("Enter the ending delimiter character: ");
    scanf(" %c", &endDelimiter); // remember to give a space before %c

    stuffed[j++] = startDelimiter;  // Add starting delimiter

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == startDelimiter || input[i] == endDelimiter) {
            stuffed[j++] = startDelimiter;  // Add escape character
        }
        stuffed[j++] = input[i];  // Add the current character
    }

    stuffed[j++] = endDelimiter;  // Add ending delimiter
    stuffed[j] = '\0';            // Null-terminate the string

    printf("After stuffing: %s\n", stuffed);
}
