#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

class User
{
   public:
    string user_id;
    string password;
    int pin;
    string imei_no;
    int location;
    int mobile_no;
    //string security_phrase;
    int time;


};

string encrypt(string msg)
{
    long int pt, ct, key = 78, k, len, i, m[100], n, temp[100], en[100];
    i = 0;
    len = msg.size();
    while (i != len)
    {
        pt = m[i];
        pt = pt - 96;
        k = 1;
        for (int j = 0; j < key; j++)
        {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    string encry="";
    //cout << "\nTHE ENCRYPTED MESSAGE IS\n";
    for (i = 0; en[i] != -1; i++){
        //printf("%c", en[i]);
        //char en[]=(char)
        char che=en[i];
        encry=encry+che;
        //cout<<che;
    }
    return encry;

};


void login(User lobj){
    string login_user_id;
    string login_password;
    cout<<"Enter login user id: "<<endl;
    cin>>login_user_id;
    cout<<"Enter login password: "<<endl;
    cin>>login_password;
    cout<<encrypt(login_password)<<endl;
    if(login_user_id==lobj.user_id && encrypt(login_password)==lobj.password){
        cout<<"Successful"<<endl;
    }
    else{
        cout<<"Unsuccessful"<<endl;
    }
}





int main(){
    User obj;

    obj.user_id="xy97";

    obj.password=encrypt("khan");
    obj.pin=6789;
    obj.imei_no="rtyu78";
    obj.location=23;
    obj.mobile_no=89341;
    obj.time=10;

    cout<<endl;
    cout<<obj.user_id<<endl;
    cout<<obj.password<<endl;
    cout<<obj.pin<<endl;
    cout<<obj.imei_no<<endl;
    cout<<obj.location<<endl;
    cout<<obj.mobile_no<<endl;
    cout<<obj.time<<endl;

    login(obj);

    return 0;
}
