#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 50

int CheckForNotDirected(int n, int A[N][N]) {
    for (int i = 0; i < n; ++i) {
        if (A[i][i]) {
            printf("Graph is not simple");
            exit();
        }
        for (int j = 0; j < n; j++) {
            if (A[i][j] != A[j][i]) {
                printf("Graph is not correct (symmetry)");
                exit();
            }
            /*
            if (A[i][j] != 0 && A[i][j] != 1) {
                printf("Graph is not correct (value)");
                exit();
            }*/
        }
    }
}


int BFS(int n, int G[N][N]) {

    int queue[N] = { 0 }, count = 0, current = 0, number = 0;
    char vertexes[N] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

    printf("BFS Method: \n");
    // We perform the operation outside the loop for the first vertex.
    printf("%c %d a\n", vertexes[0], number + 1);
    for (int k = 0; k < n; ++k) {
        G[k][0] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[current][j]) {

                number++;
                queue[number] = j;

                // We write it down.
                printf("%c %d ", vertexes[j], number + 1);
                for (int k = count; k < number + 1; k++) {
                    printf("%c", vertexes[queue[k]]);
                }
                printf("\n");

                // We zero out the column of the vertex we've already entered
                for (int k = 0; k < n; ++k) {
                    G[k][j] = 0;
                }
            }
        }
        // The next vertex.
        count++;
        current = queue[count];

        // Recording the exit from the first vertex.
        printf("- - ");
        for (int k = count; k < number + 1; k++) {
            printf("%c", vertexes[queue[k]]);
        }
        printf("\n");
    }
}


int main() {
    int G[N][N], n;

    printf("Enter the size of graph ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter G[%d][%d] ", i, j);
            scanf("%d", &G[i][j]);
        }
    }

    CheckForNotDirected(n, G);
    BFS(n, G);

}