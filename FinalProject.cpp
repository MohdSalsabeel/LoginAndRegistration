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
    string user_name;
    string email_id;
    string user_id;
    string password;
    string pin;
    string imei_no;
    float location;
    
    string mobile_no;
    int time;

};



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
    string login(){

        ifstream database_file;
        database_file.open("databaseRecordtest.txt",ios::in);
        string word;

        ofstream new_database_file;
        new_database_file.open("newDatabaseRecordtest.txt",ios::out);

        string login_user_id;
        string login_password;
        int login_time;
        //cout<<lobj[0].user_id<<"Hello"<<endl;
        //cout<<lobj[0].password<<"World"<<endl;
        cout<<"Enter login user id: "<<endl;
        cin>>login_user_id;
        cout<<"Enter login password: "<<endl;
        cin>>login_password;
        cout<<"Enter login time: "<<endl;
        cin>>login_time;

        //cout<<encrypt(login_password)<<endl;

        while(database_file>>user_name>>mobile_no>>user_id>>email_id>>password>>pin>>imei_no>>location>>time){

            if(encrypt(login_user_id)==user_id && encrypt(login_password)==password){
                //cout<<"Successfully "<<endl;
                time=login_time;
                new_database_file<< user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;
                while(database_file>>user_name>>mobile_no>>user_id>>email_id>>password>>pin>>imei_no>>location>>time){
                    new_database_file<< user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;
                }
                return "Successful";
            }


        }
        return "False";
    };


};


class ForgetPassword : public User
{
    public:

    void forget(){

        ifstream database_file;
        database_file.open("databaseRecordtest.txt",ios::in);
        //string word;

        ofstream new_database_file;
        new_database_file.open("newDatabaseRecordtest.txt",ios::out);

        string pins;
        int times;
        cout<<"Enter the pin "<<endl;
        cin>>pins;
        cout<<"Enter the last time "<<endl;
        cin>>times;



        while(database_file>>user_name>>mobile_no>>user_id>>email_id>>password>>pin>>imei_no>>location>>time){
            if(encrypt(pins)==pin && encrypt(to_string(times))==to_string(time)){
                string new_password;
                cout<<"Enter the new password"<<endl;
                cin>>new_password;
                password=new_password;
                new_database_file<< user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;
                while(database_file>>user_name>>mobile_no>>user_id>>email_id>>password>>pin>>imei_no>>location>>time){
                    new_database_file<< user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;
                }

                cout<<"Successfully "<<endl;

            }
        }

    }
};


class TwoStepVerification : public User
{
    string pin_number;
public:
    string correct_pin(){

        ifstream database_file;
        database_file.open("databaseRecordtest.txt",ios::in);

        cout<<"Enter pin number in two minutes: "<<endl;
        cin>>pin_number;


        while(database_file>>user_name>>mobile_no>>user_id>>email_id>>password>>pin>>imei_no>>location>>time){
            if(encrypt(pin_number)==pin){
                //cout<<"Successfully "<<endl;
                return "Successful";

            }
        }
        return "False";
    }
};


class ThirdStepVerfication : public User
{
    string verfiy_imei_number;
    float verify_current_location;
    float verify_previous_location;
    string verify_mobile_no;
public:
    void correct_third_step(){

        ifstream database_file;
        database_file.open("databaseRecordtest.txt",ios::in);

        ofstream new_database_file;
        new_database_file.open("newDatabaseRecordtest.txt",ios::out);


        cout<<"Enter imei number for verification: "<<endl;
        cin>>verfiy_imei_number;

        cout<<"Enter current location: "<<endl;
        cin>>verify_current_location;

        cout<<"Enter previous location where you have login last time"<<endl;
        cin>>verify_previous_location;

        cout<<"Enter mobile number: "<<endl;
        cin>>verify_mobile_no;


        while(database_file>>user_name>>mobile_no>>user_id>>email_id>>password>>pin>>imei_no>>location>>time){
            if(encrypt(verfiy_imei_number)==imei_no && encrypt(to_string(verify_previous_location))==to_string(location) && encrypt(verify_mobile_no)==mobile_no){
                //cout<<"Successfully"<<endl;

                location=verify_current_location;
                new_database_file<< user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;
                while(database_file>>user_name>>mobile_no>>user_id>>email_id>>password>>pin>>imei_no>>location>>time){
                    new_database_file<< user_name <<" "<< mobile_no <<" "<< user_id <<" "<< email_id <<" "<< password <<" "<< pin <<" "<< imei_no <<" "<< location <<" "<< time <<endl;
                }

                char current_location_character=(char)verify_current_location;
                char previous_location_character=(char)verify_previous_location;
                char mobile_number_character=verify_mobile_no.size();

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
        }

    }
};


int main(){
    //User obj[5];
    User obj;
    loop:
    //cout<<"**********************************************************"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"                1. Sign Up           "<<endl;
    cout<<"                2. Already Register/Sign In              "<<endl;
    cout<<"                3. Forget Password                      "<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    //cout<<"***********************************************************"<<endl;

    int choice;
    cout<<"Enter the choice: "<<endl;
    cin>>choice;


    switch(choice){

        case 1:{
            /*
            ofstream database_file;
            database_file.open("databaseRecord.txt",ios::out | ios::app);
            cout<<"Enter the user id: "<<endl;
            cin>>obj.user_id;
            database_file<<obj.user_id<<" ";
            cout<<"Enter the password: "<<endl;
            cin>>obj.password;
            database_file<<encrypt(obj.user_id)<<" ";
            cout<<"Enter the pin: "<<endl;
            cin>>obj.pin;
            database_file<<encrypt(obj.pin)<<" ";
            cout<<"Enter the imei no: "<<endl;
            cin>>obj.imei_no;
            database_file<<encrypt(obj.user_id)<<" ";
            cout<<"Enter the location: "<<endl;
            cin>>obj.location;
            database_file<<obj.location<<" ";
            cout<<"Enter the mobile no: "<<endl;
            cin>>obj.mobile_no;
            database_file<<obj.mobile_no<<" ";
            cout<<"Enter the time: "<<endl;
            cin>>obj.time;
            database_file<<obj.time<<endl;
            database_file.close();
            goto loop;
            */

            string user_name1;
            string mobile_no1;
            string user_id1;
            string email_id1;
            string password1;
            string pin1;
            string imei_no1;
            float location1;
            int time1;

            fstream database_file;
            database_file.open("databaseRecordtest.txt",ios::out | ios::app | ios::in);

            cout<<"Enter the user name:"<<endl;
            cin>>obj.user_name;
            //database_file<<obj.user_name<<" ";

            string three_user_word;
            for(int i=0;i<3;i++){
                three_user_word+=obj.user_name[i];
            }

            //cout<<three_user_word<<endl;

            cout<<"Enter the mobile number"<<endl;
            cin>>obj.mobile_no;
            //database_file<<obj.mobile_no<<" ";

            if(obj.mobile_no.size()<10){
                cout<<"Mobile number must be ten digit"<<endl;
                goto loop;
            }

            string three_mobile_word;
            for(int i=0;i<3;i++){
                three_mobile_word+=obj.mobile_no[i];
            }

            string unique_user_id=three_user_word+three_mobile_word;
            cout<<"User id is generated: "<<endl;
            cout<<unique_user_id<<endl;

            cout<<"Enter the email id:"<<endl;
            cin>>obj.email_id;

            //cout<<three_mobile_word<<endl;
            //string unique_user_id=three_user_word+three_mobile_word;

            cout<<"Enter the password:"<<endl;
            cin>>obj.password;

            if(obj.password.size()>=8){
                goto bottom1;
            }
            else{
                cout<<"Password must be greater than 8 character"<<endl;
                goto loop;
            }

            bottom1:

            cout<<"Enter the pin:"<<endl;
            cin>>obj.pin;

            if(obj.pin.size()==4){
                goto bottom2;
            }
            else{
                cout<<"Pin must be in 4 digit"<<endl;
                goto bottom1;
            }

            bottom2:

            cout<<"Enter the imei number"<<endl;
            cin>>obj.imei_no;

            cout<<"Enter the location"<<endl;
            cin>>obj.location;

            cout<<"Enter the time"<<endl;
            cin>>obj.time;

            //cout<<unique_user_id<<endl;
            database_file.close();

            database_file.open("databaseRecordtest.txt",ios::in);
            while(database_file>>user_name1>>mobile_no1>>user_id1>>email_id1>>password1>>pin1>>imei_no1>>location1>>time1){
                if(unique_user_id==user_id1){
                    cout<<"Please write different name and mobile no"<<endl;
                    goto loop;
                    break;
                }
                if(obj.mobile_no==mobile_no1){
                    cout<<"Mobile number must be different"<<endl;
                    goto loop;
                    break;
                }
                if(obj.email_id==email_id1){
                    cout<<"Email id must be different"<<endl;
                    goto loop;
                    break;
                }
                //cout<<user_name1<<endl;
            }




            //cout<<three_user_word+three_mobile_word<<endl;
            database_file.close();
            //check obj;
            //if(obj.check_unique()=="False"){
            database_file.open("databaseRecordtest.txt",ios::out | ios::app);
            database_file<<encrypt(obj.user_name)<<" ";
            database_file<<encrypt(obj.mobile_no)<<" ";
            database_file<<encrypt(three_user_word+three_mobile_word)<<" ";


            database_file<<encrypt(obj.email_id)<<" ";
            database_file<<encrypt(obj.password)<<" ";
            database_file<<encrypt(obj.pin)<<" ";
            database_file<<encrypt(obj.imei_no)<<" ";
            database_file<<encrypt(to_string(obj.location))<<" ";
            database_file<<encrypt(to_string(obj.time))<<" ";
            database_file<<endl;

            database_file.close();

            //}
            cout<<"Successfully Register "<<endl;
            goto loop;

        }
        case 2:{
            User obj[5];



            LoginPage login_page_obj;
            //login_page_obj.login();
            //cout<<login_page_obj.login(obj)<<endl;

            if(login_page_obj.login()=="Successful"){
                cout<<endl;
                cout<<"Go to Second Step Verification"<<endl;
                TwoStepVerification pin_obj;
                //pin_obj.correct_pin(obj);

                if(pin_obj.correct_pin()=="Successful"){
                    cout<<endl;
                    cout<<"Go to Third Step Verification"<<endl;
                    ThirdStepVerfication third_step_verification_obj;
                    third_step_verification_obj.correct_third_step();
                }else{
                    cout<<"Wrong pin number"<<endl;

                }
            }
            else{
                cout<<"UnSuccessful"<<endl;
            }

            break;
        }

        case 3:{
            User obj[5];


            ForgetPassword forget_password_obj;
            forget_password_obj.forget();
            //cout<<obj[0].pin<<endl;
            break;
        }

        default:
            cout<<"Enter the correct choice"<<endl;

    }


    cout<<endl;
    //cout<<obj[0].user_id<<endl;
    //cout<<obj[0].pin<<endl;

    // ofstream databaseFile("databaseRecord.txt",ios::out | ios::app );

    // databaseFile<<obj[0].user_id<<" "<<obj[0].password<<" "<<obj[0].pin<<" "<<obj[0].imei_no<<" "<<obj[0].location<<" "<<obj[0].mobile_no<<" "<<obj[0].time<<endl;
    // databaseFile<<obj[1].user_id<<" "<<obj[1].password<<" "<<obj[1].pin<<" "<<obj[1].imei_no<<" "<<obj[1].location<<" "<<obj[1].mobile_no<<" "<<obj[1].time<<endl;
    // databaseFile<<obj[2].user_id<<" "<<obj[2].password<<" "<<obj[2].pin<<" "<<obj[2].imei_no<<" "<<obj[2].location<<" "<<obj[2].mobile_no<<" "<<obj[2].time<<endl;
    // databaseFile<<obj[3].user_id<<" "<<obj[3].password<<" "<<obj[3].pin<<" "<<obj[3].imei_no<<" "<<obj[3].location<<" "<<obj[3].mobile_no<<" "<<obj[3].time<<endl;
    // databaseFile<<obj[4].user_id<<" "<<obj[4].password<<" "<<obj[4].pin<<" "<<obj[4].imei_no<<" "<<obj[4].location<<" "<<obj[4].mobile_no<<" "<<obj[4].time<<endl;

    // databaseFile.close();



    return 0;
}
