# Binary Error Detection & Correction using Hamming(7,4) Code

This project implements the **Hamming(7,4)** code for single-bit error detection and correction in C++.

### Hamming(7,4) Code Overview:
4 data bits + 3 parity bits = 7-bit codeword

Parity bits are placed at positions 1, 2, and 4.

The code can detect and correct single-bit errors.



### How It Works
- **4 data bits** + **3 parity bits** = **7-bit codeword**.
- The code can detect and correct single-bit errors.

### Usage
1. Compile and run the `hamming.cpp` file.
2. The program will generate a codeword, simulate an error, and correct it.

### Example
Input Data: `1 0 1 0`  
Generated Codeword: `1 0 1 0 1 0 0`  
Codeword with Error: `1 0 1 1 1 0 0`  
Corrected Codeword: `1 0 1 0 1 0 0`
