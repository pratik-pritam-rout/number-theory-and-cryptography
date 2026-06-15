int gcdExtended(int a, int b, int &x, int &y) {
    if (b == 0) {     // base case changed
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = gcdExtended(b, a % b, x1, y1);

    // update x and y using the returned values
    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}



int modInverse(int a, int m) {
    int x, y;
    int g = gcdExtended(a, m, x, y);
    if (g != 1)
        return -1; // inverse doesn’t exist if not coprime
    else {
        // x might be negative, so normalize it
        return (x % m + m) % m;
    }
}
