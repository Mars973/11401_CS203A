// knuth_test.cpp
// g++ -std=c++23 -O2 -Wall -Wextra -o knuth_test_cpp knuth_test.cpp

#include <bits/stdc++.h>
using namespace std;

static constexpr uint32_t KNUTH_A = 2654435761u;

uint32_t hash_int_knuth(int k, uint32_t m) {
    uint64_t prod = static_cast<uint64_t>(k) * KNUTH_A;
    return static_cast<uint32_t>(prod % m);
}
