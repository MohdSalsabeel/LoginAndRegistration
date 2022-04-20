#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<bits/stdc++.h>
using std::ios;
using std::cerr;
//using std::setprecision;
using namespace std;

class User
{
   public:
    // static string user_id;
    // static string password;
    // static string pin;
    // static string imei_no;
    // static int location;
    // static int mobile_no;
    // //string security_phrase;
    // static int time;

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


string read_database(string name) {
   fstream file;

   string filename="databaseRecord.txt";
   string word;

   file.open(filename.c_str());
   while(file >> word) { //take word and print
        if(word==name){
            return word;
        }
      //cout << word << endl;
   }
   file.close();
}


class LoginPage : public User
{

    public:
    string login(User *lobj){
        string login_user_id;
        string login_password;
        //cout<<lobj[0].user_id<<"Hello"<<endl;
        //cout<<lobj[0].password<<"World"<<endl;
        cout<<"Enter login user id: "<<endl;
        cin>>login_user_id;
        cout<<"Enter login password: "<<endl;
        cin>>login_password;
        //cout<<encrypt(login_password)<<endl;
        for(int i=0;i<5;i++){
            if(login_user_id==read_database(login_user_id) && encrypt(login_password)==read_database(login_password)){
                return "Successful";
                break;
                //cout<<"Successful"<<endl;
                //cout<<endl;
                //cout<<"Gone to Second step verification "<<endl;
            }
            // if(login_user_id!=lobj[0].user_id && encrypt(login_password)!=lobj[0].password){

            //     //cout<<"Unsuccessful"<<endl;
            //     return "Unsuccessful";

            // }
            // else{
            //     return "Unsuccessful";
            // }
        }
    };


};


class TwoStepVerification : public User
{
    string pin_number;
public:
    string correct_pin(User *pobj){
        cout<<"Enter pin number in two minutes: "<<endl;
        cin>>pin_number;

        for(int i=0;i<5;i++){
            if(encrypt(pin_number)==pobj[i].pin){
                return "Successful";
                break;
                // cout<<"corrent pin number"<<endl;
                // cout<<endl;
                // cout<<"Gone to Third Step Verification "<<endl;
            }
            // else{
            //     //cout<<"Incorrect pin number"<<endl;
            //     return "Unsuccessful";
            // }
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

        for(int i=0;i<5;i++){
            if(encrypt(verfiy_imei_number)==thirdverifyobj[i].imei_no && verify_previous_location==thirdverifyobj[i].location && verify_mobile_no==thirdverifyobj[i].mobile_no){
                thirdverifyobj[i].location=verify_current_location;

                char current_location_character=(char)verify_current_location;
                char previous_location_character=(char)verify_previous_location;
                char mobile_number_character=(char)verify_mobile_no;

                string token=verfiy_imei_number+current_location_character+previous_location_character+mobile_number_character;
                cout<<"Token is generated "<<endl;
                cout<<token<<endl;
                cout<<endl;
                cout<<"Write same token character: "<<endl;
                //cout<<"Enter token input: "<<endl;
                string token_character;
                cin>>token_character;
                if(token==token_character){
                    cout<<"Successful third step"<<endl;
                    break;
                }else{
                    cout<<"Wrong token number"<<endl;
                    break;
                }

            }
            // else{
            //     cout<<"Unsuccessful third step"<<endl;
            //     break;
            // }
        }

    }
};


// string User::user_id="0";
// string User::password="0";
// string User::pin="0";
// string User::imei_no="0";
// int User::location=0;
// int User::mobile_no=0;
// int User::time=0;

int main(){
    User obj[5];

    cout<<"1. Registration"<<endl;
    cout<<"2. Login"<<endl;
    cout<<"3. Forget Password"<<endl;

    int choice;
    cout<<"Enter the choice: "<<endl;
    cin>>choice;

    switch(choice){

        case 1:{

            // User::user_id = "xy97";
            // User::password = encrypt("khan345");
            // User::pin = encrypt("6789");
            // User::imei_no = encrypt("rtyu78");
            // User::location = 23;
            // User::mobile_no = 89341;
            // User::time = 10;
            //User obj[2];
            obj[0].user_id="xy97";
            obj[0].password=encrypt("khan345");
            obj[0].pin=encrypt("6789");
            obj[0].imei_no=encrypt("rtyu78");
            obj[0].location=23;
            obj[0].mobile_no=89341;
            obj[0].time=10;

            obj[1].user_id="abc12";
            obj[1].password=encrypt("khan123");
            obj[1].pin=encrypt("1234");
            obj[1].imei_no=encrypt("edf78");
            obj[1].location=29;
            obj[1].mobile_no=34513;
            obj[1].time=12;

            obj[2].user_id="fgh12";
            obj[2].password=encrypt("jad456");
            obj[2].pin=encrypt("8910");
            obj[2].imei_no=encrypt("klm99");
            obj[2].location=35;
            obj[2].mobile_no=10000;
            obj[2].time=54;

            obj[3].user_id="pqrs1";
            obj[3].password=encrypt("khan345");
            obj[3].pin=encrypt("0988");
            obj[3].imei_no=encrypt("yuzx89");
            obj[3].location=89;
            obj[3].mobile_no=45678;
            obj[3].time=67;

            obj[4].user_id="klmn89";
            obj[4].password=encrypt("sal456");
            obj[4].pin=encrypt("5613");
            obj[4].imei_no=encrypt("7845");
            obj[4].location=90;
            obj[4].mobile_no=87654;
            obj[4].time=95;

            LoginPage login_page_obj;
        }
        case 2:{
            //User obj[2];
            LoginPage login_page_obj;
            //login_page_obj.login(obj);

            if(login_page_obj.login(obj)=="Successful"){
                cout<<endl;
                cout<<"Gone to Second Step Verification"<<endl;
                TwoStepVerification pin_obj;
                //pin_obj.correct_pin(obj);

                if(pin_obj.correct_pin(obj)=="Successful"){
                    cout<<endl;
                    cout<<"Go to Third Step Verification"<<endl;
                    ThirdStepVerfication third_step_verification_obj;
                    third_step_verification_obj.correct_third_step(obj);
                }else{
                    cout<<"Wrong pin number"<<endl;

                }
            }
            else{
                cout<<"UnSuccessful"<<endl;
            }
            break;
        }
        default:
            cout<<"Enter the correct choice"<<endl;



    }

    // obj[0].user_id="xy97";

    // obj[0].password=encrypt("khan345");
    // obj[0].pin=encrypt("6789");
    // obj[0].imei_no=encrypt("rtyu78");
    // obj[0].location=23;
    // obj[0].mobile_no=89341;
    // obj[0].time=10;

    cout<<endl;

    ofstream databaseFile("databaseRecord.txt",ios::out);

    databaseFile<<obj[0].user_id<<" "<<obj[0].password<<" "<<obj[0].pin<<" "<<obj[0].imei_no<<" "<<obj[0].location<<" "<<obj[0].mobile_no<<" "<<obj[0].time<<endl;
    databaseFile<<obj[1].user_id<<" "<<obj[1].password<<" "<<obj[1].pin<<" "<<obj[1].imei_no<<" "<<obj[1].location<<" "<<obj[1].mobile_no<<" "<<obj[1].time<<endl;
    databaseFile<<obj[2].user_id<<" "<<obj[2].password<<" "<<obj[2].pin<<" "<<obj[2].imei_no<<" "<<obj[2].location<<" "<<obj[2].mobile_no<<" "<<obj[2].time<<endl;
    databaseFile<<obj[3].user_id<<" "<<obj[3].password<<" "<<obj[3].pin<<" "<<obj[3].imei_no<<" "<<obj[3].location<<" "<<obj[3].mobile_no<<" "<<obj[3].time<<endl;
    databaseFile<<obj[4].user_id<<" "<<obj[4].password<<" "<<obj[4].pin<<" "<<obj[4].imei_no<<" "<<obj[4].location<<" "<<obj[4].mobile_no<<" "<<obj[4].time<<endl;

    databaseFile.close();

    // cout<<obj[0].user_id<<endl;
    // cout<<obj[0].password<<endl;
    // cout<<obj[0].pin<<endl;
    // cout<<obj[0].imei_no<<endl;
    // cout<<obj[0].location<<endl;
    // cout<<obj[0].mobile_no<<endl;
    // cout<<obj[0].time<<endl;

    // LoginPage login_page_obj;
    // login_page_obj.login(obj);


    // TwoStepVerification pin_obj;
    // pin_obj.correct_pin(obj);

    // ThirdStepVerfication third_step_verification_obj;
    // third_step_verification_obj.correct_third_step(obj);

    // cout<<obj[0].user_id<<endl;
    // cout<<obj[0].password<<endl;
    // cout<<obj[0].pin<<endl;
    // cout<<obj[0].imei_no<<endl;
    // cout<<obj[0].location<<endl;
    // cout<<obj[0].mobile_no<<endl;
    // cout<<obj[0].time<<endl;

    return 0;
}
