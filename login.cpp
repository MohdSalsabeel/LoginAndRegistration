#include<iostream>
using namespace std;

class User
{
    public:
    void registration(){
    cout<<"register"<<endl;
    }

    void login(){
        cout<<"Login"<<endl;
    }

    void forget_password(){
        cout<<"Password"<<endl;
    }
};


int main(){
    User users;
    int choice;
    do{
        cout<<"Enter 1 for Registration: "<<endl;
    cout<<"Enter 2 for Login: "<<endl;
    cout<<"Enter 3 for Forget Password: "<<endl;
    cout<<"Enter 4 Quit: "<<endl;

    cin>>choice;
        switch(choice)
        {
        case 1:
            users.registration();
            break;
        case 2:
            users.login();
            break;
        case 3:
            users.forget_password();
            break;
        case 4:
            break;
        default:
            break;
        }
        }while(choice!=4);
    return 0;
}
