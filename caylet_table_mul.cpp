#include<bits/stdc++.h>
using namespace std;

int main(){
    //Addition
    int n;
	cout << "Enter n : ";
	cin >> n;

    int arr[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = (i * j) % n;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

	return 0;
}