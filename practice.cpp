#include <bits/stdc++.h>
using namespace std;

void phi(int n){
    int original_n = n;
    int result = n;
    int p = 0;
    for(p = 2; p * p <= n; p++){
        if(n % p == 0){
            while(n % p == 0){
                n = n / p;
            }
            result -= result/p; 
        }
    }
    if(n > 1){
        result -= result/n;
    }
    cout << "Phi : " << result << endl; 
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    phi(n);

    return 0;
}
