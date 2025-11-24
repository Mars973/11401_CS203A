#include <stdio.h>
#include <stdint.h>

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

int main() {
    int intKeys[] = {21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                     51, 52, 53, 54, 55, 56, 57, 58, 59, 60};
    const char* strKeys[] = {"cat", "dog", "bat", "cow", "ant", "owl",
                             "bee", "hen", "pig", "fox"};
    int tableSizes[] = {10, 11, 37};

    int nInt = sizeof(intKeys) / sizeof(intKeys[0]);
    int nStr = sizeof(strKeys) / sizeof(strKeys[0]);
    int nSize = sizeof(tableSizes) / sizeof(tableSizes[0]);

    for (int t = 0; t < nSize; t++) {
        int m = tableSizes[t];
        printf("=== Hash Table Size: %d ===\n", m);

        printf("Integer hash results:\n");
        for (int i = 0; i < nInt; i++) {
            printf("%d -> %d  ", intKeys[i], myHashInt(intKeys[i], m));
        }
        printf("\n");

        printf("String hash results:\n");
        for (int i = 0; i < nStr; i++) {
            printf("%s -> %d  ", strKeys[i], myHashString(strKeys[i], m));
        }
        printf("\n\n");
    }

    return 0;
}
