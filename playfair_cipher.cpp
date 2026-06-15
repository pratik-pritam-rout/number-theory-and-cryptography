#include<bits/stdc++.h>
using namespace std;

pair<int,int> findPosition(char arr[5][5], char ch){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(arr[i][j] == ch){
                return {i,j};
            }
        }
    }
}

int main(){
    char arr[5][5];

    string key;
    cout << "Enter key : ";
    cin >> key;
    bool seen[26] = {false};

    //first i am convert the key to lowercase letters and making every 'J' to 'I'
    for(int i = 0; i < key.size(); i++){
        char ch = key[i];
        if(ch >= 'A' && ch <= 'Z'){
            key[i] = ch + 32;
        }

        if(key[i] == 'j'){
            key[i] = 'i';
        }

    }

    string clean = "";

    for(int i = 0; i < key.size(); i++){ //removing duplicates from the key here
        if(seen[key[i] - 'a'] == false){
            clean += key[i];
            seen[key[i] - 'a'] = true;
        }
    }

    //now i am adding alphabets from a-z except j 
    for(int i = 0; i < 26; i++){
        char ch = i + 'a';
        if(ch == 'j'){
            continue;
        }

        if(seen[ch - 'a'] == false){
            clean += ch;
            seen[ch - 'a'] = true;
        }
    }
    int k = 0;
    //now building the matrix
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            arr[i][j] = clean[k];
            k++;
        }
    }

    cout << "Matrix : " << endl;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    string plaintext;
    cin.ignore(); // <-- add this line!
    cout << "Enter plaintext : ";
    getline(cin, plaintext);

    string prepared = "";
    //now i will make the plaintext to lowercase, convert j to i and also remove spaces
    for(int i = 0; i < plaintext.size(); i++){
        char ch = plaintext[i];
        if(ch == ' '){
            continue;
        }

        if(ch == 'J' or ch == 'j'){
            ch = 'i';
        }

        if(ch >= 'A' && ch <= 'Z'){
            ch = ch + 32;
        }

        prepared += ch;
    }

    vector<pair<char, char>>pairs;

    for(int i = 0; i < prepared.size(); i++){
        char first = prepared[i];
        char second;

        if(i + 1 < prepared.size()){
            if(first !=  prepared[i + 1]){ //different letters
                second = prepared[i + 1];
                i++; //skip the next letter since its already used in second
            }
            else{
                second = 'x'; //same letter
            }
        }
        else{ //last character
            second = 'x';
        }

        pairs.push_back({first, second});
    }

    cout << "diagram : ";
    for(int i = 0; i < pairs.size(); i++){
        cout << pairs[i].first << pairs[i].second << "\t";
    }
    cout << endl;
    
    string ciphertext = "";

    for(int i = 0; i < pairs.size(); i++){
        char a = pairs[i].first;
        char b = pairs[i].second;

        pair<int,int> a_pos = findPosition(arr, a);
        pair<int,int> b_pos = findPosition(arr, b);

        int rowa = a_pos.first;
        int cola = a_pos.second;
        int rowb = b_pos.first;
        int colb = b_pos.second;

        //same row rule
        if(rowa == rowb){
            ciphertext += arr[rowa][(cola + 1) % 5];
            ciphertext += arr[rowb][(colb + 1) % 5];
        }
        else if(cola == colb){
            ciphertext += arr[(rowa + 1) % 5][cola];
            ciphertext += arr[(rowb + 1) % 5][colb];
        }
        else{
            ciphertext += arr[rowa][colb];
            ciphertext += arr[rowb][cola];
        }
    }

    cout << "Ciphertext : " << ciphertext << endl;


    // now adding decryption
    string decrypted_text = "";

    vector<pair<char, char>>pairs2;
    for(int i = 0; i < ciphertext.size(); i++){
        int first = ciphertext[i];
        int second;
        if(i + 1 < ciphertext.size()){
            if(ciphertext[i + 1] != ciphertext[i]){
                second = ciphertext[i + 1]; 
                i++;
            }
            else if(ciphertext[i] == ciphertext[i + 1]){
                second = 'x';
            }
        }
        else{
            second = 'x';
        }

        pairs2.push_back({first, second});
    }


    for(int i = 0; i < pairs2.size(); i++){
        char a = pairs2[i].first;
        char b = pairs2[i].second;

        pair<int,int> a_pos = findPosition(arr, a); //<row, col> of first char
        pair<int,int> b_pos = findPosition(arr, b); //<row, col> of second char

        int rowa = a_pos.first;
        int cola = a_pos.second;
        int rowb = b_pos.first;
        int colb = b_pos.second;

        //same row rule
        if(rowa == rowb){
            decrypted_text += arr[rowa][(cola + 4) % 5];
            decrypted_text += arr[rowb][(colb + 4) % 5];
        }
        else if(cola == colb){
            decrypted_text += arr[(rowa + 4) % 5][cola];
            decrypted_text += arr[(rowb + 4) % 5][colb];
        }
        else{
            decrypted_text += arr[rowa][colb];
            decrypted_text += arr[rowb][cola];
        }
    }

    cout << "Decrypted text : " << decrypted_text << endl;

    return 0;
}