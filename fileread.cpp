#include<iostream>
#include<fstream>
using namespace std;

struct student
{
    int id;
    char name[25];
    char name1[25];
};

int main(){
    loop:
    student s;
    int a,b;
    cin>>a;
    switch(a)
    {
    case 1:{
        cout<<"Enter the id:"<<endl;
        cin>>s.id;
        cout<<"Enter the first name:"<<endl;
        cin>>s.name;
        cout<<"Enter the last name:"<<endl;
        cin>>s.name1;

        ofstream sdata;
        sdata.open("student.txt",ios::app);
        sdata<<endl;
        sdata<<s.id<<endl;
        sdata<<s.name<<endl;
        sdata<<s.name1<<endl;
        sdata<<endl;
        sdata.close();
        goto loop;
        break;
    }
    case 2:{
        ifstream tdata;
        tdata.open("student.txt",ios::in);

        tdata>>s.id;
        tdata>>s.name;
        tdata>>s.name1;

        while(!tdata.eof()){
            cout<<"Student Id:"<<s.id<<endl;
            cout<<"Student name:"<<s.name<<endl;
            cout<<"Student last name:"<<s.name1<<endl;

            tdata>>s.id;
            tdata>>s.name;
            tdata>>s.name1;
        }

        tdata.close();
        goto loop;
        break;
    }
    case 3:{
        cout<<"\n\tEnter ID of student want to delete record: ";
        cin>>b;
        ifstream d;
        d.open("student.txt");
        ofstream e;
        e.open("new.txt");

        d>>s.id;
        d>>s.name;
        d>>s.name1;

        while(!d.eof()){
            if(s.id!=b){
                e<<endl;
                e<<s.id<<endl;
                e<<s.name<<endl;
                e<<s.name1<<endl;
            }else{
                cout<<"Record deleted"<<endl;
            }

            d>>s.id;
            d>>s.name;
            d>>s.name1;

        }
        e.close();
        d.close();

        if(remove("student.txt")!=0){
            cout<<"Not remove"<<endl;
        }
        else{
            cout<<"ok"<<endl;
        }

        if(rename("new.txt","student.txt")!=0){
            cout<<"not rename"<<endl;
        }
        else{
            cout<<"ok rename"<<endl;
        }

        goto loop;
        break;
    }
    case 4:{
        int g;
        char h[25],j[25];
        cout<<"\n\tEnter ID ";
        cin>>b;

        ifstream d;
        d.open("student.txt");
        ofstream e;
        e.open("new.txt");

        d>>s.id;
        d>>s.name;
        d>>s.name1;

        while(!d.eof()){
            if(s.id!=b){
                e<<endl;
                e<<s.id<<endl;
                e<<s.name<<endl;
                e<<s.name1<<endl;
            }else{
                cout<<"\n\tEnter new id:";
                cin>>g;
                cout<<"\n\tEnter first name:";
                cin>>h;
                cout<<"\n\tEnter last name:";
                cin>>j;

                cout<<endl;
                e<<g<<endl;
                e<<h<<endl;
                e<<j<<endl;
            }

            d>>s.id;
            d>>s.name;
            d>>s.name1;

        }
        e.close();
        d.close();

        if(remove("student.txt")!=0){
            cout<<"Not remove"<<endl;
        }
        else{
            cout<<"ok"<<endl;
        }

        if(rename("new.txt","student.txt")!=0){
            cout<<"not rename"<<endl;
        }
        else{
            cout<<"ok rename"<<endl;
        }

        goto loop;

        break;
    }
    }
    return 0;
}

