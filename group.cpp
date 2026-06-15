#include<bits/stdc++.h>
using namespace std;

bool checkClosure(vector<int> &set, int mod){
    for(int i = 0; i < set.size(); i++){
        for(int j = 0; j < set.size(); j++){
            int result = (set[i] + set[j]) % mod;
            bool found = false;
            for(int k = 0; k < set.size(); k++){
                if(set[k] == result){
                    found = true;
                    break;
                }
            }
            if(found == false){
                return false;
            }
        }
    }
    return true;
    
}

bool checkAssociativity(vector<int> &set, int mod){
    for(int i = 0; i < set.size(); i++){
        for(int j = 0; j < set.size(); j++){
            for(int k = 0; k < set.size(); k++){
                int left = (((set[i] + set[j]) % mod) + set[k]) % mod;
                int right = (set[i] + (set[j] + set[k]) % mod) % mod;
                if(left != right){
                    cout << "Associativity Fails" << endl;
                    return false;
                }
            }
        }
    }
    return true;
}

bool checkIdentity(vector<int> &set, int mod, int &Id_ele){
    
    for(int i = 0; i < set.size(); i++){
        int e = set[i];
        bool isIdentity = true;
        for(int j = 0; j < set.size(); j++){
            int a = set[j];
            if(((a + e) % mod != a) && ((e + a) % mod != a)){
                isIdentity = false;
                break;
            }
        }
        if(isIdentity){
            Id_ele = e;
            return true;
        }

    }
    
    cout << "No identity element found" << endl;
    return false;
}

bool checkInverse(vector<int> &set, int mod, int &e){
    for(int i = 0; i < set.size(); i++){
        int a = set[i];
        bool hasInverse = false;
        for(int j = 0; j < set.size(); j++){
            int b = set[j];

            if(((a + b) % mod == e) && ((b + a) % mod == e)){
                hasInverse = true;
                break;
            }
        }
        if(hasInverse == false){
            cout << "No Inverse exist for a number" << endl;
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> set(n);
    cout << "Enter elements : " << endl;
    for(int i = 0; i < n; i++){
        cin >> set[i];
        // cout << endl;
    }

    int mod;
    int maxi = INT_MIN;
    for(int i = 0; i < set.size(); i++){
        maxi = max(maxi, set[i]);
    }
    mod = maxi + 1;
    bool closure = checkClosure(set, mod);
    
    bool associative = checkAssociativity(set, mod);
    int Id_ele;
    bool id = checkIdentity(set, mod, Id_ele);

    bool inv = checkInverse(set, mod, Id_ele);

    if(closure && associative && id && inv){
        cout << "Yes given set of elements form a group" << endl;
    }
    else{
        cout << "Does not form a group" << endl;
    }
    return 0;
}