#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<bits/stdc++.h>
using std::ios;
using std::cerr;
using std::setprecision;
using namespace std;

class User
{
   public:
    string user_id;
    string password;
    string pin;
    string imei_no;
     int location;
    int mobile_no;
    //string security_phrase;
    int time;


};

/*
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
*/

string encrypt(string input)
{
    string result = "";
    int offset=9;
    for (int i = 0; i < input.length(); ++i)
    {
        // For capital letters
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            result += (char) (input[i] - 'A' + offset) % ('Z' - 'A') + 'A';
            continue;
        }

        // For non-capital
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            result += (char) (input[i] - 'a' + offset) % ('z' - 'a') + 'a';
            continue;
        }

        if (input[i] >= '0' && input[i] <= '9')
        {
            char ch = (input[i] - 2 + offset) -20;
            //result += (input[i] - 2 + offset) % 9;
            result += ch;
            continue;
        }

        // For others
        result += input[i];
    }

    return result;
}


class LoginPage : public User
{

    public:
    void login(User *lobj){
        string login_user_id;
        string login_password;
        cout<<"Enter login user id: "<<endl;
        cin>>login_user_id;
        cout<<"Enter login password: "<<endl;
        cin>>login_password;
        cout<<encrypt(login_password)<<endl;
        if(login_user_id==lobj[0].user_id && encrypt(login_password)==lobj[0].password){
            cout<<"Successful"<<endl;
            cout<<endl;
            cout<<"Gone to Second step verification "<<endl;
        }
        else{
            cout<<"Unsuccessful"<<endl;
        }
    }


};


class TwoStepVerification : public User
{
    string pin_number;
public:
    void correct_pin(User *pobj){
        cout<<"Enter pin number in two minutes: "<<endl;
        cin>>pin_number;

        if(encrypt(pin_number)==pobj[0].pin){
            cout<<"corrent pin number"<<endl;
            cout<<endl;
            cout<<"Gone to Third Step Verification "<<endl;
        }else{
            cout<<"Incorrect pin number"<<endl;
        }
    }
};


class ThirdStepVerfication : public User
{
    string verfiy_imei_number;
    int verify_current_location;
    int verify_previous_location;
    int verify_mobile_no;
public:
    void correct_third_step(User *thirdverifyobj){
        cout<<"Enter imei number for verification: "<<endl;
        cin>>verfiy_imei_number;

        cout<<"Enter current location: "<<endl;
        cin>>verify_current_location;

        cout<<"Enter previous location where you have login last time"<<endl;
        cin>>verify_previous_location;

        cout<<"Enter mobile number: "<<endl;
        cin>>verify_mobile_no;

        if(encrypt(verfiy_imei_number)==thirdverifyobj[0].imei_no && verify_previous_location==thirdverifyobj[0].location && verify_mobile_no==thirdverifyobj[0].mobile_no){
            thirdverifyobj[0].location=verify_current_location;

            char current_location_character=(char)verify_current_location;
            char previous_location_character=(char)verify_previous_location;
            char mobile_number_character=(char)verify_mobile_no;

            string token=verfiy_imei_number+current_location_character+previous_location_character+mobile_number_character;
            cout<<token<<endl;
            cout<<"Write same token character: "<<endl;
            //cout<<"Enter token input: "<<endl;
            string token_character;
            cin>>token_character;
            if(token==token_character){
                cout<<"Successful third step"<<endl;
            }else{
                cout<<"Wrong token number"<<endl;
            }

        }else{
            cout<<"Unsuccessful third step"<<endl;
        }

    }
};



int main(){
    User obj[1];

    obj[0].user_id="xy97";

    obj[0].password=encrypt("khan345");
    obj[0].pin=encrypt("6789");
    obj[0].imei_no=encrypt("rtyu78");
    obj[0].location=23;
    obj[0].mobile_no=89341;
    obj[0].time=10;

    cout<<endl;

    ofstream databaseFile("databaseRecord.txt",ios::out);

    databaseFile<<obj[0].user_id<<" "<<obj[0].password<<" "<<obj[0].pin<<" "<<obj[0].imei_no<<" "<<obj[0].location<<" "<<obj[0].mobile_no<<" "<<obj[0].time<<endl;

    databaseFile.close();

    cout<<obj[0].user_id<<endl;
    cout<<obj[0].password<<endl;
    cout<<obj[0].pin<<endl;
    cout<<obj[0].imei_no<<endl;
    cout<<obj[0].location<<endl;
    cout<<obj[0].mobile_no<<endl;
    cout<<obj[0].time<<endl;

    LoginPage login_page_obj;
    login_page_obj.login(obj);


    TwoStepVerification pin_obj;
    pin_obj.correct_pin(obj);

    ThirdStepVerfication third_step_verification_obj;
    third_step_verification_obj.correct_third_step(obj);

    cout<<obj[0].user_id<<endl;
    cout<<obj[0].password<<endl;
    cout<<obj[0].pin<<endl;
    cout<<obj[0].imei_no<<endl;
    cout<<obj[0].location<<endl;
    cout<<obj[0].mobile_no<<endl;
    cout<<obj[0].time<<endl;

    return 0;
}
