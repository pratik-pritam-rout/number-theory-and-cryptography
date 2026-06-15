#include<bits/stdc++.h>
using namespace std;

void toLower(string &text){
    for(int i = 0; i < text.size(); i++){
        if(text[i] == ' '){
            continue;
        }
        if(text[i] >= 'A' && text[i] <= 'Z'){
            text[i] += 32;
        }
    }
}

int inv(int a){
    for(int x = 1; x < 26; x++){
        if((((a % 26) * (x % 26))) % 26 == 1){
            return x;
        }
    }
    return 0;
}

int main(){
    string plaintext;
    string ciphertext = "";
    int key[2][2];

    cout << "Enter plaintext : ";
    getline(cin,plaintext);

    cout << "Enter key : " << endl;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cin >> key[i][j];
        }
    }

    toLower(plaintext);
    cout << "plaintext : " << plaintext << endl;
    if(plaintext.size() % 2 == 1){
        plaintext += 'x';
    }

    for (int i = 0; i < plaintext.size(); i += 2){
        int x1 = plaintext[i] - 'a';
        int x2 = plaintext[i + 1] - 'a';

        int y1 = (x1 * key[0][0] + x2 * key[1][0]) % 26;
        int y2 = (x1 * key[0][1] + x2 * key[1][1]) % 26;

        ciphertext += 'a' + y1;
        ciphertext += 'a' + y2;

    }

    cout << "Ciphertext : " << ciphertext << endl;

    string decrypted_text = "";
    int det_k = key[0][0] * key[1][1] - key[1][0] * key[0][1];
    det_k = (det_k % 26 + 26) % 26;
    int det_k_inv = inv(det_k);
    if(det_k_inv == 0){
        cout << "Ivalid key not invertible" << endl;
        exit(0);
    }
    int adj_k[2][2];
    //for adj_k
    adj_k[0][0] = key[1][1];
    adj_k[0][1] = -key[0][1];
    adj_k[1][0] = -key[1][0];
    adj_k[1][1] = key[0][0];
    
    

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            adj_k[i][j] = (adj_k[i][j] % 26 + 26) % 26;
        }
    }

    int inv_k[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            inv_k[i][j] = ((adj_k[i][j] * det_k_inv) % 26 + 26) % 26;
        }
    }

    for (int i = 0; i < ciphertext.size(); i += 2){
        int x1 = ciphertext[i] - 'a';
        int x2 = ciphertext[i + 1] - 'a';

        int y1 = (x1 * inv_k[0][0] + x2 * inv_k[1][0]) % 26;
        int y2 = (x1 * inv_k[0][1] + x2 * inv_k[1][1]) % 26;

        decrypted_text += y1 + 'a';
        decrypted_text += y2 + 'a';

    }

    cout << "Decrypted text : " << decrypted_text << endl;

    return 0;
}