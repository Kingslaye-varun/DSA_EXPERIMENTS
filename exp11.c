#include <stdio.h>
#include <stdlib.h>

#define SIZE 10  // Max size of the graph

int adjMatrix[SIZE][SIZE];  // Adjacency matrix
int visited[SIZE];          // Array to keep track of visited vertices

// Function to perform BFS
void bfs(int start, int n) {
    int queue[SIZE], front = 0, rear = 0;
    int current;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front < rear) {
        current = queue[front++]; // Dequeue
        printf("%d ", current + 1); // Print with +1 to match user input

        for (int i = 0; i < n; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                queue[rear++] = i; // Enqueue
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Function to perform DFS
void dfs(int vertex, int n) {
    printf("%d ", vertex + 1); // Print with +1 to match user input
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

// Function to reset the visited array
void resetVisited(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
}

int main() {
    int n, choice, start;

    // Input number of vertices
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    do {
        // Menu-driven options
        printf("\nGraph Traversal Menu:\n");
        printf("1. BFS\n");
        printf("2. DFS\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // BFS Traversal
                resetVisited(n);
                printf("Enter the starting vertex for BFS (1 to %d): ", n);
                scanf("%d", &start);
                bfs(start - 1, n); // Convert to 0-index
                break;

            case 2:
                // DFS Traversal
                resetVisited(n);
                printf("Enter the starting vertex for DFS (1 to %d): ", n);
                scanf("%d", &start);
                printf("DFS Traversal: ");
                dfs(start - 1, n); // Convert to 0-index
                printf("\n");
                break;

            case 3:
                // Exit the program
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
