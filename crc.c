#include <stdio.h>
#include <string.h>

char t[30], cs[30], g[10]; // Data, checksum, generating polynomial
int a, i, j, N; // Data length, loop variables, polynomial length

// XOR operation for CRC calculation
void xor1() {
    for (j = 1; j < N; j++) {
        cs[j] = (cs[j] == g[j]) ? '0' : '1'; // XOR operation
    }
}

// CRC calculation
void crc() {
    for (i = 0; i < N; i++) {
        cs[i] = t[i]; // Copy data into checksum array
    }

    do {
        if (cs[0] == '1') { // If the most significant bit is 1
            xor1(); // Perform XOR with the generating polynomial
        }

        // Shift the bits left
        for (j = 0; j < N - 1; j++) {
            cs[j] = cs[j + 1];
        }
        cs[j] = t[i++]; // Add the next bit of the data

    } while (i < a + N - 1); // Continue until all data is processed
}

int main() {
    printf("Enter data (binary): ");
    scanf("%s", t); // User inputs the data to be transmitted

    printf("Enter the generating polynomial (binary): ");
    scanf("%s", g); // User inputs the generating polynomial

    N = strlen(g); // Length of the generating polynomial
    a = strlen(t); // Length of the data

    // Append zeros to data
    for (i = a; i < a + N - 1; i++) {
        t[i] = '0'; // Append zeros
    }
    t[i] = '\0'; // Null terminate the string

    printf("Modified data (with appended zeros): %s\n", t);

    // Perform CRC and get the checksum
    crc();
    for (i = a; i < a + N - 1; i++) {
        t[i] = cs[i - a]; // Append the checksum to the data
    }
    t[i] = '\0'; // Null terminate the transmitted data

    printf("Transmitted codeword (data + checksum): %s\n", t);

    // Simulate receiving data and checking for errors
    printf("Enter received message (binary): ");
    scanf("%s", t);

    // Recalculate CRC on received data
    crc();
    for (i = 0; i < N - 1 && cs[i] != '1'; i++);

    if (i < N - 1) {
        printf("Error detected in the received data.\n");
    } else {
        printf("No error detected in the received data.\n");
    }

    return 0;
}
