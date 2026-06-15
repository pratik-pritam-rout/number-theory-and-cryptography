#include<bits/stdc++.h>
using namespace std;

void toLower(string &text){
    for(int i = 0; i < text.size(); i++){
        if(text[i] >= 'A' && text[i] <= 'Z'){
            text[i] = text[i] + 32;
        }
    }
}

int main(){
    string plaintext;
    string ciphertext = "";
    string key;

    cout << "Enter plaintext : ";
    getline(cin, plaintext);

    cout << "Enter key : ";
    getline(cin, key);

    toLower(plaintext);
    toLower(key);

    // cout << "plaintext : " << plaintext << endl;
    

    string fullkey="";
    
    int j = 0;
    // extend the key to match plaintext length
    for(int i = 0; i < plaintext.size(); i++){
        if(plaintext[i] == ' '){
            fullkey += ' ';
        }
        else{
            fullkey += key[j % key.size()];
            j++;
        }
    }

    cout << "fullkey : " << fullkey << endl;

    for(int i = 0; i < plaintext.size(); i++){ //encryption
        if(plaintext[i] == ' '){
            ciphertext += ' ';
            continue;
        }
        ciphertext += (((plaintext[i] - 'a') + (fullkey[i] - 'a')) % 26) + 'a';
    }
    cout << "Ciphertext : " << ciphertext << endl;

    string decrypted_text = "";

    for(int i = 0; i < plaintext.size(); i++){ //encryption
        if(ciphertext[i] == ' '){
            decrypted_text += ' ';
            continue;
        }
        decrypted_text += ((((ciphertext[i] - 'a') - (fullkey[i] - 'a')) + 26) % 26) + 'a';
    }
    cout << "Decrypted text : " << decrypted_text << endl;


    return 0;
}