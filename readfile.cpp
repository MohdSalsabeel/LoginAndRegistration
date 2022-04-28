#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream db;
    db.open("test.txt",ios::in);

    ofstream new_db;
    new_db.open("newtest.txt",ios::out);

    string a,b,c;
    while(db>>a>>b>>c){
        if(c=="Sal"){
            string word;
            cout<<"Enter the new word: "<<endl;
            cin>>word;
            c=word;
            while(db>>a>>b>>c){
                new_db<<a<<" "<<b<<" "<<c<<endl;
            }
        }
    }

    db.close();
    new_db.close();

    remove("test.txt");
    rename("newtest.txt","test.txt");

    return 0;
}
