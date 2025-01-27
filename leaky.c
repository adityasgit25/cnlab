#include <stdio.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))  // Returns the smaller of two values

int main() {
    int bucket_size, output_rate, current_count = 0, dropped_packets = 0;
    int incoming_packets[100], nsec, i = 0;

    // Input the bucket size and output rate
    printf("Enter bucket size: ");
    scanf("%d", &bucket_size);

    printf("Enter output rate: ");
    scanf("%d", &output_rate);

    // Input for incoming packets for each second
    printf("Enter number of seconds and packet arrivals for each second:\n");
    do {
        printf("Second %d - Enter number of incoming packets: ", i + 1);
        scanf("%d", &incoming_packets[i]);
        i++;
        printf("Enter 1 to continue or 0 to quit: ");
        int ch;
        scanf("%d", &ch);
        if (ch == 0)
            break;
    } while (1); // Loop until the user wants to quit

    nsec = i;  // Total number of seconds for which input was given

    printf("\nSecond\tReceived\tSent\tDropped\tRemaining\n");

    // Simulation loop for each second
    for (i = 0; i < nsec; i++) {
        printf("%d\t", i + 1);  // Display the second number

        // Read the incoming packets for the current second
        int received_packets = incoming_packets[i];

        // Calculate the number of packets to send (leak) at the output rate
        int sent_packets = MIN(received_packets + current_count, output_rate);

        // Calculate remaining packets after sending
        int remaining_packets = received_packets + current_count - sent_packets;

        // Update dropped packets and current count based on bucket size
        if (remaining_packets > bucket_size) {
            dropped_packets = remaining_packets - bucket_size;
            current_count = bucket_size;
        } else {
            dropped_packets = 0;
            current_count = remaining_packets;
        }

        // Print the status for this second
        printf("%d\t%d\t%d\t%d\n", received_packets, sent_packets, dropped_packets, current_count);
    }

    return 0;
}
