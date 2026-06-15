#include<bits/stdc++.h>
using namespace std;

int main(){
    string plaintext;
    int depth;
    cout << "Enter plaintext : ";
    getline(cin, plaintext);

    cout << "Enter depth : ";
    cin >> depth;
    string ciphertext="";

    vector<string> rails(depth);

    int row = 0;
    int dir = 0;

    for(int i = 0; i < plaintext.size(); i++){
        char ch = plaintext[i];
        if(ch == ' '){
            continue;
        }
        rails[row] += ch;

        if(row == 0){
            dir = 1;
        }
        else if(row == depth - 1){
            dir = -1;
        }
        
        row += dir;
    }

    for(int i = 0; i < rails.size(); i++){
        ciphertext += rails[i];
    }

    cout << "Ciphertext : " << ciphertext << endl;

    //decryption part
    row = 0;
    dir = 0;
    vector<int> rail_len(depth, 0);
    for(int i = 0; i < ciphertext.size(); i++){
        rail_len[row]++;
        if(row == 0){
            dir = 1;
        }
        if(row == depth - 1){
            dir = -1;
        }
        row += dir;
    }

    row = 0;
    dir = 0;
    int index = 0;
    vector<string> newrails(depth);
    for(int i = 0; i < depth; i++){
        string temp = "";
        for(int j = 0; j < rail_len[i]; j++){
            temp += ciphertext[index];
            index++;
        }
        newrails[i] += temp; 
    }

    string decrypted_text ="";
    row = 0;
    dir = 0;
    vector<int> railPos(depth, 0);
    for(int i = 0; i < ciphertext.size(); i++){
        decrypted_text += newrails[row][railPos[row]++];

        if(row == 0) dir = 1;
        else if(row == depth - 1) dir = -1;
        row += dir;
    }

    cout << "decrypted text : " << decrypted_text << endl;

    return 0;
}