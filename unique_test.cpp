#include<iostream>
#include<string>
#include<fstream>
#include<math.h>
using namespace std;

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

class User
{
   public:
    string user_name;
    string email_id;
    string user_id;
    string password;
    string pin;
    string imei_no;
    int location;
    string mobile_no;
    int time;

};

/*
class check: public User
{
    bool check_unique(){
        string user_name1;
            string email_id1;
            string user_id1;
            string password1;
            string pin1;
            string imei_no1;
            int location1;
            string mobile_no1;
            int time1;
        ifstream database_file;
        database_file.open("databaseRecordtest.txt",ios::in);
        while(database_file>>user_name1>>mobile_no1>>user_id1>>email_id1){
            if(unique_user_id==user_id1){
                        //cout<<"Please write different name and mobile no"<<endl;
                        //break;
                return true;
            }
            if(obj.mobile_no==mobile_no1){
                        //cout<<"Mobile number must be different"<<endl;
                        //break;
                return true;
            }
            if(obj.email_id==email_id1){
                        //cout<<"Email id must be different"<<endl;
                        //break;
                return true;
            }
                    //cout<<user_name1<<endl;
        }
    return false;
    }
};
*/


int main(){
    User obj;
    loop:
    cout<<"1. Registration"<<endl;
    cout<<"2. Login"<<endl;
    cout<<"3. Forget Password"<<endl;

    int choice;
    cout<<"Enter the choice: "<<endl;
    cin>>choice;




    switch(choice){

        case 1:{

            string user_name1;
            string mobile_no1;
            string user_id1;
            string email_id1;
            string password1;
            string pin1;
            string imei_no1;
            int location1;
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

            cout<<"Enter the email id:"<<endl;
            cin>>obj.email_id;

            //cout<<three_mobile_word<<endl;
            string unique_user_id=three_user_word+three_mobile_word;

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
                database_file<<obj.user_name<<" ";
                database_file<<obj.mobile_no<<" ";
                database_file<<three_user_word+three_mobile_word<<" ";


                database_file<<obj.email_id<<" ";
                database_file<<obj.password<<" ";
                database_file<<obj.pin<<" ";
                database_file<<obj.imei_no<<" ";
                database_file<<obj.location<<" ";
                database_file<<obj.time<<" ";
                database_file<<endl;

                database_file.close();

            //}







            goto loop;





        }
    }

    return 0;
}
