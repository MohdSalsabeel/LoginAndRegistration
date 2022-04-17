#include<iostream>
using namespace std;

void encryption(char message[], int key){
    char ch;
    int i;
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch > 'z'){
            ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
            }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch > 'Z'){
            ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
            }
    }
    cout << "Encrypted message: " << message<<endl;
};


void decryption(char message[], int dekey)
{
    char ch;
    int i;
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - dekey;
            if(ch < 'a'){
            ch = ch + 'z' - 'a' + 1;
        }
        message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - dekey;
            if(ch > 'a'){
            ch = ch + 'Z' - 'A' + 1;
        }
        message[i] = ch;
        }
    }
    cout << "Decrypted message: " << message<<endl;
};


int main(){

    char message[100];
    int  key;
    cout << "Enter a message to encrypt: ";
    cin.getline(message, 100);
    cout << "Enter key: ";
    cin >> key;

    encryption(message,key);

    int dekey;
    cout<<"Enter key to decrypt the message"<<endl;
    cin>>dekey;
    decryption(message,dekey);

    return 0;
}
