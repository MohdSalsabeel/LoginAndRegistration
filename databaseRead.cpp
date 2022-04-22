#include<iostream>
#include<fstream>
using namespace std;

int main(){

    string user_id;
    string password;
    string pin;
    string imei_no;
    int location;
    int mobile_no;
    int time;

    ifstream database_file;
    database_file.open("databaseRecord.txt",ios::in);
    string word;

    ofstream new_database_file;
    new_database_file.open("newDatabaseRecord.txt",ios::out);

    // while(!database_file.eof()){
    //     database_file>>word;
    //     if(word=="23"){
    //         string new_word="789";
    //         //database_file.fi
    //         word=new_word;
    //         //cout<<"Replace "<<endl;
    //         //break;
    //     }
    //     new_database_file<<word<<" ";
    //     cout<<word<<" ";
    //     cout<<endl;
    //     new_database_file<<endl;
    // }

    while(database_file >> user_id >> password >> pin >> imei_no >> location >> mobile_no >> time){
        if(location==23){
            int new_location=100;
            location=new_location;
        }

        new_database_file<< user_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< mobile_no <<" "<< time <<endl;
        cout<< user_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< mobile_no <<" "<< time <<endl;
    }

    remove("databaseRecord.txt");
    rename("newDatabaseRecord.txt","databaseRecord.txt");

    database_file.close();
    new_database_file.close();

    return 0;
}
