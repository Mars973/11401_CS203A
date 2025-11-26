#include <stdio.h>
#include <stdint.h>
#include "hash_fn.h"

int myHashInt(int key, int m) {
    uint32_t h = (uint32_t)key;
    h = h * 2654435769u; // Knuth multiplicative hash
    return h % m;
}

int myHashString(const char* str, int m) {
    uint64_t sum = 0;
    const uint64_t P = 131;

    for (const char* p = str; *p; p++) {
        sum = sum * P + (unsigned char)(*p);
    }

    sum = sum * 11400714819323198485ULL; // 64-bit Knuth multiplicative
    return (int)(sum % m);
}
