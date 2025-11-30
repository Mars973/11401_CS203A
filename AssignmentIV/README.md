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
## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

### Manual Compilation (if needed)
- Command for C:
  ```bash
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
  ```

### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./hash_function
  ```
  or
  ```bash
  ./hash_function_cpp
  ```

  ### Result Snapshot
- Example output for integers:
  ```
  === Hash Function Observation (C Version) ===

  === Table Size m = 10 ===
Key     Index
-----------------
21      7
22      0
23      3
24      2
25      5
26      8
27      7
28      0
29      9
30      2
51      3
52      6
53      5
54      8
55      7
56      0
57      3
58      2
59      5
60      8

=== Table Size m = 11 ===
Key     Index
-----------------
21      0
22      3
23      6
24      2
25      5
26      8
27      4
28      7
29      3
30      6
51      2
52      5
53      1
54      4
55      0
56      3
57      6
58      2
59      5
60      8

=== Table Size m = 37 ===
Key     Index
-----------------
21      15
22      18
23      21
24      31
25      34
26      0
27      10
28      13
29      23
30      26
51      34
52      0
53      10
54      13
55      23
56      26
57      29
58      2
59      5
60      8  

=== String Hash (m = 10) ===
Key     Index
-----------------
cat     8
dog     2
bat     9
cow     3
ant     3
owl     4
bee     0
hen     3
pig     0
fox     9

=== String Hash (m = 11) ===
Key     Index
-----------------
cat     5
dog     0
bat     9
cow     6
ant     10
owl     0
bee     8
hen     8
pig     4
fox     6

=== String Hash (m = 37) ===
Key     Index
-----------------
cat     6
dog     9
bat     2
cow     21
ant     18
owl     14
bee     24
hen     34
pig     10
fox     11
  ```
=== Hash Function Observation (C++ Version) ===

=== Table Size m = 10 ===
Key     Index
-----------------
21      7
22      0
23      3
24      2
25      5
26      8
27      7
28      0
29      9
30      2
51      3
52      6
53      5
54      8
55      7
56      0
57      3
58      2
59      5
60      8

=== Table Size m = 11 ===
Key     Index
-----------------
21      0
22      3
23      6
24      2
25      5
26      8
27      4
28      7
29      3
30      6
51      2
52      5
53      1
54      4
55      0
56      3
57      6
58      2
59      5
60      8

=== Table Size m = 37 ===
Key     Index
-----------------
21      15
22      18
23      21
24      31
25      34
26      0
27      10
28      13
29      23
30      26
51      34
52      0
53      10
54      13
55      23
56      26
57      29
58      2
59      5
60      8

=== String Hash (m = 10) ===
Key     Index
-----------------
cat     8
dog     2
bat     9
cow     3
ant     3
owl     4
bee     0
hen     3
pig     0
fox     9

=== String Hash (m = 11) ===
Key     Index
-----------------
cat     5
dog     0
bat     9
cow     6
ant     10
owl     0
bee     8
hen     8
pig     4
fox     6

=== String Hash (m = 37) ===
Key     Index
-----------------
cat     6
dog     9
bat     2
cow     21
ant     18
owl     14
bee     24
hen     34
pig     10
fox     11
  ```

- Observations: 
Integer Keys:
- The C and C++ versions produce identical outputs.
- Small table size (m=10) shows noticeable repeated collisions and high periodicity.
- Prime table sizes (m=11 and m=37) provide a more uniform distribution, with significantly fewer collisions.

String Keys:
- The C and C++ versions produce identical outputs.
- Small table sizes still exhibit collisions (e.g., "ant", "pig"), while the large table (m=37) has a more uniform distribution.  

- Example output for integers:
  ```
  Hash table (m=10): [7, 0, 3, 2, 5, 8, 7, 0, 9, 2, 3, 6, 5, 8, 7, 0, 3, 2, 5, 8]
Hash table (m=11): [0, 3, 6, 2, 5, 8, 4, 7, 3, 6, 2, 5, 1, 4, 0, 3, 6, 2, 5, 8]
Hash table (m=37): [15, 18, 21, 31, 34, 0, 10, 13, 23, 26, 34, 0, 10, 13, 23, 26, 29, 2, 5, 8]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"] -> [8, 2, 9, 3, 3, 4, 0, 3, 0, 9]
Hash table (m=11): ["cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"] -> [5, 0, 9, 6, 10, 0, 8, 8, 4, 6]
Hash table (m=37): ["cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"] -> [6, 9, 2, 21, 18, 14, 24, 34, 10, 11]
  ```
- Observations: 
- Prime table sizes (m=11 and m=37) give more uniform distribution for both integers and strings.
- Non-prime or small table sizes (m=10) show noticeable collisions and repeated indices.  

## Analysis
- Effect of Table Size (m):
The experiments show that the choice of table size plays a major role in how evenly values are spread. When the table size is prime (such as 11 or 37), the hash results are more dispersed and avoid repeating cycles. Non-prime table sizes, especially small ones like 10, tend to generate noticeable patterns that increase the chance of collisions.

- Distribution Behavior:
For integer keys, the Knuth multiplicative hash works reliably, but modulo with a non-prime value can cause key clusters to recur. For string keys, the combination of polynomial rolling and a 64-bit mixing constant gives a stronger spread, but smaller table sizes still restrict the overall uniformity.

- Optimization Notes:
Choosing a larger prime for the table size consistently improves distribution quality. The current hashing methods already perform well, but they benefit significantly from operating within a prime-sized hash table.bution.

## Reflection
1. Crafting a hash function involves understanding how arithmetic operations and table size interact. Even a well-designed hash function can produce suboptimal results if paired with a poorly chosen table size.
2. The experiments highlight that prime table sizes help break cyclic patterns, allowing both integer and string keys to distribute more evenly.
3. The combination of multiplicative hashing for integers and polynomial hashing for strings proved effective and stable across both C and C++ implementations, demonstrating reliable, predictable behavior in different languages.
4. Overall, the design produces consistent and well-balanced hash outputs, especially when supported by an appropriate table size.



