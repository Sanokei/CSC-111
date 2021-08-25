#include <iostream>
#include <string>
#include <string.h>
#include "name.cpp"
using namespace std;

int main(){
    string lastname;
    double km;

    cout<<"Name: ";cin>>lastname;
    int time[2];
    cout<<"Time: ";
    for(int i=0;i<2;i++){
        cin>>time[i];
    }
    cout<<"It is now "<<time[0]<<":"<<time[1]<<endl;

    cout<<"What is the distance between Jupiter and Saturn on December 21, 2020 in km?";
    cin>>km;

    cout<<"Jupiter and Saturn were ";
    cout<<km/1.609;
    cout<<"  miles apart on December 21, 2020."<<endl;
    
    cout << name() << endl;
    return 0;
}