#include <bits/stdc++.h>
using namespace std;

int phi(int n) {
    int result = n;
    cout << "Initial n = " << n << ", result = " << result << endl;

    int original_n = n; // store original for display

    // Check all numbers from 2 up to sqrt(n)
    for (int p = 2; p * p <= n; p++) {
        // If p divides n, it is a prime factor
        if (n % p == 0) {
            // Remove all powers of p from n
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }

    // If n is still > 1, it means n itself is a prime factor
    if (n > 1) {
        result -= result / n;
    }

    cout << "\nphi(" << original_n << ") = " << result << endl;
    return result;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    phi(n);

    return 0;
}
