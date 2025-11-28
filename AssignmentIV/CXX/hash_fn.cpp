#include <cstdint>
#include <string>
#include "hash_fn.hpp"

// 整數雜湊（Knuth multiplicative hash）
int myHashInt(int key, int m) {
    std::uint32_t h = static_cast<std::uint32_t>(key);
    h = h * 2654435769u;  // Knuth multiplicative constant
    return h % m;
}

// 字串雜湊（Polynomial rolling hash + 64-bit Knuth multiplicative）
int myHashString(const std::string& str, int m) {
    std::uint64_t sum = 0;
    const std::uint64_t P = 131;

    for (unsigned char c : str) {
        sum = sum * P + c;
    }

    sum = sum * 11400714819323198485ULL;
    return static_cast<int>(sum % m);
}
