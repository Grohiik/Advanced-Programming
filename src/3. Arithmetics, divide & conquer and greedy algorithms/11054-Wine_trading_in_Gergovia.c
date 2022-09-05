/*
https://onlinejudge.org/external/110/11054.pdf
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int inhabitants;
    scanf("%d", &inhabitants);
    while (inhabitants) {
        int needs_to_be_moved = 0;
        long long total_work = 0;
        int current_house_request;
        while (inhabitants--) {
            scanf("%d", &current_house_request);
            needs_to_be_moved += current_house_request;
            total_work += abs(needs_to_be_moved);
        }
        scanf("%d", &inhabitants);
    }
}