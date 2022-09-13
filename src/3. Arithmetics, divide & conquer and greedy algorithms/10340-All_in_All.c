/*
https://onlinejudge.org/external/103/10340.pdf
*/
#include <stdio.h>
#include <string.h>

int main() {
    char unencoded[1000000];
    char encoded[1000000];
    int i, j, counter;
    while (scanf("%s %s", unencoded, encoded) && !feof(stdin)) {
        j = 0;
        counter = 0;
        for (i = 0; i < strlen(unencoded); i++) {
            for (; j < strlen(encoded); j++) {
                if (unencoded[i] == encoded[j]) {
                    counter++;
                    j++;
                    break;
                }
            }
        }
        if (counter >= strlen(unencoded)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}