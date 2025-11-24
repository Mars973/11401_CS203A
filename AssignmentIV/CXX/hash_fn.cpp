// knuth_test.cpp
// g++ -std=c++23 -O2 -Wall -Wextra -o knuth_test_cpp knuth_test.cpp

#include <bits/stdc++.h>
using namespace std;

static constexpr uint32_t KNUTH_A = 2654435761u;

uint32_t hash_int_knuth(int k, uint32_t m) {
    uint64_t prod = static_cast<uint64_t>(k) * KNUTH_A;
    return static_cast<uint32_t>(prod % m);
}

int main() {
    vector<int> data = {
        21,22,23,24,25,26,27,28,29,30,
        51,52,53,54,55,56,57,58,59,60
    };

    vector<uint32_t> ms = {10, 11, 37};

    for (uint32_t m : ms) {
        cout << "\n====================================\n";
        cout << "   Testing Knuth Hash (mod " << m << ")\n";
        cout << "====================================\n";
        cout << " key   ->  hash\n";
        cout << "------------------------------------\n";

        for (int k : data) {
            uint32_t h = hash_int_knuth(k, m);
            cout << setw(4) << k << "  ->  " << h << "\n";
        }
    }
    return 0;
}
