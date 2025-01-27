#include <stdio.h>
#include <string.h>

void main() {
  char input[50], stuffed[100] = "01111110"; // Start with the flag sequence
  int i, count = 0;

  printf("Enter the bit string: ");
  scanf("%s", input);

  for (i = 0; i < strlen(input); i++) {
    // Add each bit to the stuffed output
    strncat(stuffed, &input[i], 1); // remember strncat() 

    // Check if the current bit is '1' and count consecutive '1's
    if (input[i] == '1') {
      count++;
      // If five consecutive '1's are found, stuff a '0'
      if (count == 5) {
        strcat(stuffed, "0"); // and here strcat()!
        count = 0; // Reset count after stuffing
      }
    } else {
      count = 0; // Reset count if the bit is not '1'
    }
  }

  strcat(stuffed, "01111110"); // Add the ending flag sequence

  printf("After stuffing: %s\n", stuffed);
}
