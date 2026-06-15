#include <bits/stdc++.h>
using namespace std;

bool isClosed(const vector<int>& set, int mod, char op) {
    for (int a : set)
        for (int b : set) {
            int result = (op == '+') ? (a + b) % mod : (a * b) % mod;
            if (find(set.begin(), set.end(), result) == set.end())
                return false;
        }
    return true;
}

bool hasAdditiveIdentity(const vector<int>& set) {
    return find(set.begin(), set.end(), 0) != set.end();
}

bool hasAdditiveInverses(const vector<int>& set, int mod) {
    for (int a : set) {
        bool found = false;
        for (int b : set)
            if ((a + b) % mod == 0) { found = true; break; }
        if (!found) return false;
    }
    return true;
}

bool hasMultiplicativeIdentity(const vector<int>& set) {
    return find(set.begin(), set.end(), 1) != set.end();
}

bool hasMultiplicativeInverses(const vector<int>& set, int mod) {
    for (int a : set) {
        if (a == 0) continue;
        bool found = false;
        for (int b : set)
            if ((a * b) % mod == 1) { found = true; break; }
        if (!found) return false;
    }
    return true;
}

bool isDistributive(const vector<int>& set, int mod) {
    for (int a : set)
        for (int b : set)
            for (int c : set) {
                int left1 = (a * (b + c)) % mod;
                int right1 = ((a * b) + (a * c)) % mod;
                if (left1 != right1) return false;
            }
    return true;
}

int main() {
    int mod;
    cout << "Enter modulus n: ";
    cin >> mod;

    vector<int> set;
    cout << "Enter elements of the set (end with -1): ";
    int x;
    while (cin >> x && x != -1) set.push_back(x);

    bool closedAdd = isClosed(set, mod, '+');
    bool closedMul = isClosed(set, mod, '*');
    bool hasZero = hasAdditiveIdentity(set);
    bool hasOne = hasMultiplicativeIdentity(set);
    bool addInv = hasAdditiveInverses(set, mod);
    bool mulInv = hasMultiplicativeInverses(set, mod);
    bool distr = isDistributive(set, mod);

    if (closedAdd && closedMul && hasZero && hasOne && addInv && mulInv && distr)
        cout << "The given set forms a FIELD under modulo " << mod << endl;
    else
        cout << "The given set does NOT form a field." << endl;
}
