/*
https://onlinejudge.org/external/103/10307.pdf
*/

#include <stdio.h>
#include <stdlib.h>

int bfs() { return 0; }

void init_matrix(char **matrix, int width, int height) {
    matrix = (char **)realloc(matrix, height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        matrix[i] = (char *)realloc(matrix[i], width * sizeof(char));
    }
}

int read_maze(char **matrix, int width, int height, int *start, int **end) {
    int alien_counter = 0;
    for (int i = 0; i < height; i++) {
        scanf("%s", matrix[i]);
        for (int ii = 0; ii < width; ii++) {
            if (matrix[i][ii] == 'S') {
                start[0] = i;
                start[1] = ii;
            } else if (matrix[i][ii] == 'A') {
                end[alien_counter][0] = i;
                end[alien_counter++][1] = ii;
            }
        }
    }
}

int main() {
    int cases;
    scanf("%d", &cases);
    int width, height;
    char **maze;
    while (cases--) {
        scanf("%d%d", &width, &height);
        int start[2];
        int end[50][2];

        init_matrix(maze, width, height);
        int alien_counter = read_maze(maze, width, height, start, end);
        printf("%d %d", start[0], start[1]);
    }

    for (int i = 0; i < height; i++) {
        free(maze[i]);
    }
    free(maze);
}