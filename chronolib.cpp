#include<chrono>
#include<iostream>
using namespace std;

/*

A precision neutral library for time and date
std::chrono::system_clock: current time according to the system - is not steady
std::chrono::steady_clock: goes at the uniform rate
std::chrono::high_resolution_clock: provide smallest possible tick point

std::chrono::duration<>: REPRESENT TIME DURATION
  2 hours (a number and a unit)
  duration<int,ratio<1,1>> // number of second in int

*/


int main(){

    /*
    std::ratio<2,10> r;
    cout<<r.num<<"/"<<r.den<<endl;

    cout<<chrono::system_clock::period::num<<"/"<<chrono::system_clock::period::den<<endl;
    */

    chrono::system_clock::time_point tp=chrono::system_clock::now();
    cout<<tp.time_since_epoch().count()<<endl;
    tp=tp + chrono::seconds(2);
    cout<<tp.time_since_epoch().count()<<endl;


    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    cout<<"I am Khan"<<endl;
    chrono::steady_clock::time_point ends = chrono::steady_clock::now();

    chrono::steady_clock::duration d = ends-start;
    //cout<<d<<endl;

    if(d==chrono::steady_clock::duration::zero()){
        cout<<"No time elapsed"<<endl;
    }
    cout<<chrono::duration_cast<chrono::microseconds>(d).count()<<endl;

    return 0;
}
