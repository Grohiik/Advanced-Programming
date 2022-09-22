/*
https://onlinejudge.org/external/103/10307.pdf
*/

#include <stdio.h>
#include <stdlib.h>

int bfs() { return 0; }

int main() {
    int cases;
    scanf("%d", &cases);
    int width, height;
    while (cases--) {
        scanf("%d%d", &width, &height);
        int start[2];
        int end[50][2];
        int alien_counter = 0;
        char **blub = (char *)malloc(sizeof(char *) * width);
        for (int i = 0; i < width; i++) {
            blub[i] = (char *)malloc(sizeof(char) * height);
        }

        for (int i = 0; i < height; i++) {
            scanf("%s", &blub[i]);
            for (int ii = 0; ii < width; ii++) {
                if (blub[i][ii] == 'S') {
                    start[0] = i;
                    start[1] = ii;
                } else if (blub[i][ii] == 'A') {
                    end[alien_counter][0] = i;
                    end[alien_counter++][1] = ii;
                }
            }
        }
        printf("%d %d", start[0], start[1]);
    }
}