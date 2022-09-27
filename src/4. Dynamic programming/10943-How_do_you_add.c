/*
https://onlinejudge.org/external/109/10943.pdf
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    long long precalculate[101][101] = {0};

    for (int i = 0; i < 101; ++i)
        precalculate[i][1] = 1;

    for (int i = 0; i < 101; ++i)
        for (int j = 1; j < 101; ++j)

            for (int k = 0; k <= i; ++k)
                precalculate[i][j] =
                    (precalculate[i][j] + precalculate[i - k][j - 1]) % 1000000;

    int K, N;
    while (scanf("%d%d", &N, &K) && N) {
        printf("%d\n", precalculate[N][K]);
    }
    return 0;
}