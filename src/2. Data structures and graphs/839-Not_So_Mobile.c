/*
https://onlinejudge.org/external/8/839.pdf
*/

#include <stdio.h>
#include <stdlib.h>

int mobile() {
    int wl, dl, wr, dr;
    scanf("%d%d%d%d", &wl, &dl, &wr, &dr);

    if (wl == 0) wl = mobile();
    if (wr == 0) wr = mobile();

    if ((wl * dl) != (wr * dr)) {
        return 0;
    } else {
        return wl + wr;
    }
}

int main() {
    int num_tests;
    scanf("%d", &num_tests);

    while (num_tests--) {
        scanf("", NULL);
        if (mobile()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

        if (num_tests) {
            printf("\n");
        }
    }
}