#include<stdio.h>
#define INFINITY 99
#define START_NODE 2

void dijkstra(int cost[10][10], int n);

int main() {
    int cost[10][10], i, j, n;

    // Input the number of vertices and the cost matrix
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Run Dijkstra's algorithm
    dijkstra(cost, n);
    return 0;
}

void dijkstra(int cost[10][10], int n) {
    int distance[10], pred[10], visited[10];
    int count = 1, mindistance, nextnode, i, j;

    // Initialize arrays
    for (i = 0; i < n; i++) {
        distance[i] = cost[START_NODE][i]; // Initial distances from the start node
        pred[i] = START_NODE;              // Initial predecessors
        visited[i] = 0;                    // Mark all nodes as unvisited
    }
    distance[START_NODE] = 0;  // Distance to the start node is 0
    visited[START_NODE] = 1;   // Mark the start node as visited

    // Main loop of Dijkstra's algorithm
    while (count < n - 1) {
        mindistance = INFINITY;

        // Find the unvisited node with the smallest distance
        for (i = 0; i < n; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;  // Mark the selected node as visited

        // Update distances of the neighbors of the selected node
        for (i = 0; i < n; i++) {
            if (!visited[i] && mindistance + cost[nextnode][i] < distance[i]) {
                distance[i] = mindistance + cost[nextnode][i];
                pred[i] = nextnode;  // Update the predecessor -------------------------------------
            }
        }
        count++;  // Increment the count
    }

    // Print the shortest paths
    for (i = 0; i < n; i++) {
        if (i != START_NODE) {
            printf("\nDistance to node %d = %d", i, distance[i]);
            printf("\nPath = %d", i);
            j = i;
            while (j != START_NODE) {
                j = pred[j];
                printf("<-%d", j);
            }
            printf("\n");
        }
    }
}
