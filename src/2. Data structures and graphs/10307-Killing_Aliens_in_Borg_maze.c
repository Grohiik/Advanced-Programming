/*
https://onlinejudge.org/external/103/10307.pdf
*/

#include <stdio.h>
#include <stdlib.h>

int bfs() {}

int main() {
    int cases;
    scanf("%d", &cases);
    int width, height;
    while (cases--) {
        scanf("%d%d", &width, &height);
        char **blub = (char *)malloc(sizeof(char *) * width);
        for (int i = 0; i < width; i++) {
            blub[i] = (char *)malloc(sizeof(char) * height);
        }

        for (int i = 0; i < height; i++) {
            for (int ii = 0; ii < width; ii++) {
                scanf("%c", &blub[i][ii]);
            }
        }
    }
}