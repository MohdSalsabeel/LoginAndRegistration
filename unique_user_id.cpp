#include<iostream>
#include<set>
using namespace std;

int main(){
    set<string> user;
    string st;

    set<string>::iterator unique_user;

    for(int i=0;i<5;i++){
        cin>>st;
        for(unique_user=user.begin();unique_user!=user.end();++unique_user){
            if(st==*unique_user)
            {
                cout<<"Already this user id is present"<<endl;
                cout<<"Please enter other user id"<<endl;
                break;
            }
        }

        user.insert(st);
    }


    //for(itr=user.begin();itr!=user.end();++itr){
    //    cout<<*itr<<" ";
    //}

    return 0;
}
