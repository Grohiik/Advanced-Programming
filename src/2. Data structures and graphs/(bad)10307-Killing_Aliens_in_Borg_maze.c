/*
https://onlinejudge.org/external/103/10307.pdf
*/

#include <stdio.h>
#include <stdlib.h>

char maze[600][600];
int nodes[50][2];

int bfs() { return 0; }

int read_maze(int width, int height) {
    int alien_counter = 0;
    for (int i = 0; i < height; i++) {
        // fgets(maze[i], width+1, stdin);
        scanf("%[^\n]%*c", maze[i]);
        for (int ii = 0; ii < width; ii++) {
            if (maze[i][ii] == 'S' || maze[i][ii] == 'A') {
                nodes[alien_counter][0] = i;
                nodes[alien_counter++][1] = ii;
            }
        }
    }
    return alien_counter;
}

int main() {
    int cases;
    scanf("%d", &cases);
    int width, height;
    while (cases--) {
        scanf("%d%d", &width, &height);
        int nodes[50][2];

        printf("%d %d\n", width, height);
        int alien_counter = read_maze(width, height);

        for (int i = 0; i < height; i++) {
            printf("%s\n", maze[i]);
        }
    }
}