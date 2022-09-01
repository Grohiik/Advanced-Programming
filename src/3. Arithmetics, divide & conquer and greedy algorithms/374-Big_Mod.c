#include <stdio.h>
#include <stdlib.h>

int big_mod(int base, int power, int mod) {
    if (mod == 1) return 0;

    base %= mod;
    int result = 1;

    while (power) {
        if (power & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        power >>= 1;
    }

    return result;
}

int main(void) {
    char *line = NULL;
    size_t len = 0;

    int B = 1;
    int P = 0;
    int M = 0;

    while (!feof(stdin)) {
        getline(&line, &len, stdin);
        B = atoi(line);

        getline(&line, &len, stdin);
        P = atoi(line);

        getline(&line, &len, stdin);
        M = atoi(line);

        printf("%d\n", big_mod(B, P, M));
        getline(&line, &len, stdin);
    }

    free(line);
    return 0;
}
