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
  function hash_int(k):
    a = 2654435761          // Knuth multiplicative constant
    return (a * k) mod m
  ```
- Rationale: I chose Knuth’s multiplicative hashing because multiplying the key by a large constant produces a well-distributed set of hash values, even when the input integers are sequential or closely related.
This approach helps minimize clustering and reduces collisions compared to simply using k mod m.
It is also efficient because it only requires one multiplication and one modulo operation.
### Non-integer Keys
- Formula / pseudocode:
  ```text
  function hash_string(s):
    p = 131                 // prime base
    hash = 0
    for each character c in s:
        hash = hash * p + ord(c)
    return hash mod m
  ```
- Rationale: I use a polynomial rolling hash, which considers both the position and ASCII value of each character.
This method is widely used in hash tables and string algorithms because it spreads out similar strings effectively and reduces collisions.
Using a prime base (131) increases mixing and ensures that different strings are very unlikely to map to the same hash value.

