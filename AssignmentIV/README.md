# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: 邱品翔  
Email: mars35020915@gmail.com  
## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
  function myHashInt(key, m):
    h = (uint32) key
    h = h * 2654435769    // Knuth multiplicative constant
    return h mod m
  ```
- Rationale: For integer keys, I use the Knuth multiplicative hash, a well-known and efficient method for distributing integer inputs uniformly across a hash table.

The key is first converted to a 32-bit unsigned integer, then multiplied by the constant 2654435769, which is derived from the golden ratio. This constant ensures that consecutive or patterned integers (e.g., 1, 2, 3, …) are well-scattered across the hash space.

Advantages:
- Produces a uniform distribution for sequential or structured integers
- Fast (uses only multiplication and modulo operations)
- Reduces clustering and improves overall hash table performance
The final step applies h % m to map the hashed value into the table size m.
### Non-integer Keys
- Formula / pseudocode:
  ```text
  function myHashString(str, m):
    sum = 0
    P = 131                        // polynomial rolling base
    
    for each character c in str:
        sum = sum * P + ASCII(c)

    sum = sum * 11400714819323198485   // 64-bit Knuth multiplicative constant
    return sum mod m
  ```
- Rationale: For string keys, I use a combination of Polynomial Rolling Hash and a 64-bit Knuth multiplicative constant.

The polynomial hash treats the string as a base-P polynomial:
- sum = sum * 131 + c  
Using P = 131 is a widely adopted choice because it provides good dispersion for ASCII and UTF-8 characters.
The hash accumulates in a 64-bit unsigned integer, which allows support for long strings and naturally incorporates overflow to increase randomness.

After computing the rolling hash, I multiply the result by:
```text
  11400714819323198485ULL
  ```
This is the 64-bit version of Knuth’s multiplicative constant.
This additional mixing step improves the hash by:
- Further randomizing high and low bits
- Reducing multi-pattern collisions common in polynomial hashing
- Improving overall uniformity in bucket distribution

This design provides:
- High hashing speed
- Low collision probability
- Strong dispersion for a wide variety of string inputs
Making it suitable for general-purpose hash tables.  
## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 1, 2, 3, 4, ...        | The pattern repeats every 10 because the table size is small. Collisions occur more frequently, and distribution is cyclic. |
| 11             | 10, 0, 1, 2, ...       | More uniform distribution. Since 11 is prime, the multiplicative hash spreads values better across the table.            |
| 37             | 20, 21, 22, 23, ...    | Near-uniform distribution. A large prime table size provides the best spread with minimal collision patterns.             |


