#include<iostream>
using namespace std;

char encrypt(char ch, int k){
    if(ch >= 'A' && ch <= 'Z'){
        ch = ch + 32;
    }
    char newChar = (((ch - 'a') + k) % 26) + 'a'; 
    return newChar;
}

char decrypt(char ch, int k){
    // if(ch >= 'A' && ch <= 'Z'){
    //     ch = ch + 32;
    // }
    char newChar = (((ch - 'a') - k + 26) % 26) + 'a'; 
    return newChar;
}

int main(){
    string plaintext;
    string ciphertext = "";
    string decrypted_text = "";
    int k;
    cout << "Enter the plaintext : ";
    getline(cin, plaintext); //reads full string including spaces

    // cout << "Plaintext : " << plaintext << endl;
    cout << "Enter the value of k (shift) : ";
    cin >> k;

    for(int i = 0; i < plaintext.size(); i++){
        if(plaintext[i] != ' '){
            char ch = plaintext[i];
            char encrypted_char = encrypt(ch, k);
            ciphertext += encrypted_char;
        }
        else if(plaintext[i] == ' '){
            ciphertext += ' ';
        }
        
    }

    cout << "Ciphertext : " << ciphertext << endl;

    cout << "Decrypted Text : ";
    for(int i = 0; i < ciphertext.size(); i++){
        if(ciphertext[i] != ' '){
            char ch = ciphertext[i];
            char decrypted_char = decrypt(ch, k);
            decrypted_text += decrypted_char;
        }
        else if(ciphertext[i] == ' '){
            decrypted_text += ' ';
        }
        
    }

    cout << decrypted_text << endl; 

    return 0;
}