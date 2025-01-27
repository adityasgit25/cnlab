#include<stdio.h>
#include<string.h>

#define MIN(x, y) ((x) > (y) ? y: x);

int main() {
    int incoming[20], dropped, remaining, bucketsize, outgoing;
    int current =0;
    int i=0;
    int nsec;
    
    do {
        printf("Enter the %d th second no of packets: ", (i+1));
        scanf("%d", &incoming[i]);
        i++;
        int flag;
        
        printf("1 to continue and 0 for exit: ");
        scanf("%d", &flag);
        if (flag == 0) break;
    } while(1);
    
    nsec =i;
    printf("\n Second \t outgoing \t recieved \t dropped \t remaining\n");
    for (i=0; i< nsec; i++) {
        printf("At %d second \t ", (i+1));
        outgoing = MIN(current+incoming[i], outgoing);
        int remaining = current+incoming[i] - outgoing;
        if (remaining > bucketsize) {
            current =bucketsize;
            dropped = remaining - bucketsize;
        } else {
            current = remaining;
            dropped = 0;
        }
        printf("%d \t %d \t %d \t %d \n ", outgoing, incoming[i], dropped, remaining);
    }
    
    return 0;
}