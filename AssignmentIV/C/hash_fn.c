/* knuth_test.c
   gcc -std=c23 -O2 -Wall -Wextra -o knuth_test knuth_test.c
*/

#include <stdio.h>
#include <stdint.h>

#define KNUTH_A 2654435761u

uint32_t hash_int_knuth(int k, uint32_t m) {
    uint64_t prod = (uint64_t)k * (uint64_t)KNUTH_A;
    return (uint32_t)(prod % m);
}

int main() {
    int data[] = {
        21,22,23,24,25,26,27,28,29,30,
        51,52,53,54,55,56,57,58,59,60
    };
    int n = sizeof(data) / sizeof(data[0]);

    uint32_t ms[] = {10, 11, 37};

    for (int i = 0; i < 3; i++) {
        uint32_t m = ms[i];

        printf("\n====================================\n");
        printf("   Testing Knuth Hash (mod %u)\n", m);
        printf("====================================\n");
        printf(" key   ->  hash\n");
        printf("------------------------------------\n");

        for (int j = 0; j < n; j++) {
            uint32_t h = hash_int_knuth(data[j], m);
            printf("%4d  ->  %u\n", data[j], h);
        }
    }

    return 0;
}

