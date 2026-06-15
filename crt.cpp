#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

bool checkCoprime(int a, int b){
    if(b > a){
        int temp = a;
        a = b;
        b = temp;
        
    }
    if(gcd(a,b) == 1){
        return true;
    }
    return false;
}

int modInv(int a, int m){
    int x = 1;
    for(x = 1; x < m; x++){
        if(((a % m) * (x % m)) % m == 1){
            return x;
        }
    }
    return 0; //no inverse exist
}

int main(){

    int result = 0;

    int n; //total number of equations
    cout << "Enter total number of equations : " << endl;
    cin >> n;

    vector<int> a(n), m(n);

    cout << "Enter values of a : (a1, a2, a3....) : ";
    for(int i = 0; i < n; i++){
        cin >> a[i]; 
    }

    cout << "Enter values of m : (m1, m2, m3....) : ";
    for(int i = 0; i < n; i++){
        cin >> m[i]; 
    }

    for(int i = 0; i < n; i++){
        cout << "X = " << a[i] << "(" << " mod " << m[i] << ")" << endl;
    }

    //checking if the mods are coprimes
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            bool isCoprime = checkCoprime(m[i], m[j]);
            if(isCoprime == false){
                cout << "Moduli not coprime" << endl;
                return 0;
            }
        }
    }

    cout << "All are coprime : " << endl;
    int M = 1;
    for(int i = 0; i < m.size(); i++){
        M *= m[i];
    }
    vector<int> M_sub(n);
    for(int i =0 ; i< m.size(); i++){
        M_sub[i] = M / m[i];
    }

    vector<int> M_subInv(n);
    for(int i = 0; i < n; i++){
        M_subInv[i] = modInv(M_sub[i], m[i]);
        result += a[i]*M_sub[i]*M_subInv[i];
    }
    result = result % M;
    cout << "X : " << result << endl; 

    

    return 0;
}