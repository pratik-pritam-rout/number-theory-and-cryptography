#include <bits/stdc++.h>
using namespace std;

// check closure under given operation (mod n)
bool isClosed(const vector<int>& set, int mod, char op) {
    for (int a : set) {
        for (int b : set) {
            int result;
            if (op == '+') result = (a + b) % mod;
            else if (op == '*') result = (a * b) % mod;
            else return false;
            if (find(set.begin(), set.end(), result) == set.end()) {
                return false;
            }
        }
    }
    return true;
}

// check additive identity (0 must be present)
bool hasAdditiveIdentity(const vector<int>& set) {
    return find(set.begin(), set.end(), 0) != set.end();
}

// check additive inverse exists for all
bool hasAdditiveInverses(const vector<int>& set, int mod) {
    for (int a : set) {
        bool found = false;
        for (int b : set) {
            if ((a + b) % mod == 0) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

// distributivity check
bool isDistributive(const vector<int>& set, int mod) {
    for (int a : set)
        for (int b : set)
            for (int c : set) {
                int left1 = (a * (b + c)) % mod;
                int right1 = ((a * b) + (a * c)) % mod;
                if (left1 != right1) return false;

                int left2 = ((a + b) * c) % mod;
                int right2 = ((a * c) + (b * c)) % mod;
                if (left2 != right2) return false;
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
    bool hasId = hasAdditiveIdentity(set);
    bool hasInv = hasAdditiveInverses(set, mod);
    bool distr = isDistributive(set, mod);

    if (closedAdd && closedMul && hasId && hasInv && distr)
        cout << "The given set forms a RING under modulo " << mod << endl;
    else
        cout << "The given set does NOT form a ring." << endl;
}
