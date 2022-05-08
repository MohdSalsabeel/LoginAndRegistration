#include<iostream>
#include<ctime>
#include<time.h>
using namespace std;

int main(){
    time_t now=time(0);
    tm *ltm=localtime(&now);
    int h,m,s;
    h=ltm->tm_hour;
    m=ltm->tm_min;
    s=ltm->tm_sec;

    //int a=srand();
    srand(time(0));
    int a=rand()%100;
    cout<<a<<endl;
    string b,p,q,r;
    p=to_string(h);
    q=to_string(m);
    r=to_string(s);
    b=p+":"+q+":"+r;
    //b.push_back(h);
    //b.push_back(colon);
    //b.push_back(m);
    //b.push_back(colon);
    //b.push_back(s);
    cout<<b<<endl;
    cout<<h<<":"<<m<<":"<<s<<endl;
    return 0;
}
