#include<bits/stdc++.h>
using namespace std;

bool isPrime(long long n){
	for(long long i = 2; i < n; i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

long long phi(long long n){
	if(isPrime(n)){
		return n - 1;
	}
}

int main(){
	long long n;
	cout << "Enter n : ";
	cin >> n;

	cout << "Phi(n) : " << phi(n) << endl;
	return 0;
}