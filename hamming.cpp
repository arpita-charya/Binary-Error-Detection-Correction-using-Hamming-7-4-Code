#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate parity bits
vector<int> calculateParityBits(vector<int> data) {
    vector<int> codeword(7, 0);
    codeword[2] = data[0];
    codeword[4] = data[1];
    codeword[5] = data[2];
    codeword[6] = data[3];

    // Parity bit 1 (position 1)
    codeword[0] = codeword[2] ^ codeword[4] ^ codeword[6];

    // Parity bit 2 (position 2)
    codeword[1] = codeword[2] ^ codeword[5] ^ codeword[6];

    // Parity bit 3 (position 4)
    codeword[3] = codeword[4] ^ codeword[5] ^ codeword[6];

    return codeword;
}

// Function to detect and correct errors
int detectAndCorrectError(vector<int> &codeword) {
    int p1 = codeword[0] ^ codeword[2] ^ codeword[4] ^ codeword[6];
    int p2 = codeword[1] ^ codeword[2] ^ codeword[5] ^ codeword[6];
    int p3 = codeword[3] ^ codeword[4] ^ codeword[5] ^ codeword[6];

    int errorPosition = p1 + p2 * 2 + p3 * 4;

    if (errorPosition != 0) {
        cout << "Error detected at position: " << errorPosition << endl;
        codeword[errorPosition - 1] ^= 1; // Correct the error
    } else {
        cout << "No error detected." << endl;
    }

    return errorPosition;
}

int main() {
    vector<int> data = {1, 0, 1, 0}; // Example 4-bit data
    vector<int> codeword = calculateParityBits(data);

    cout << "Generated Codeword: ";
    for (int bit : codeword) {
        cout << bit;
    }
    cout << endl;

    // Simulate an error
    codeword[3] ^= 1; // Introduce an error at position 4
    cout << "Codeword with error: ";
    for (int bit : codeword) {
        cout << bit;
    }
    cout << endl;

    detectAndCorrectError(codeword);

    cout << "Corrected Codeword: ";
    for (int bit : codeword) {
        cout << bit;
    }
    cout << endl;

    return 0;
}
