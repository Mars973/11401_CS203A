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

