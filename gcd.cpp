#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int main(){
    int a, b;
    cout << "Enter a : " ;
    cin >> a;
    cout << "Enter b : ";
    cin >> b;
    int ans;
    if(a > b){
        ans = gcd(a, b);
    }
    else{
        ans = gcd(b, a);
    }
    cout << "GCD of " << a << " and " << b << " : " << ans << endl;
    return 0;
}