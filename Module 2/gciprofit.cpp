#include <iostream>
using namespace std;

int main(){
    //const variables for multiplying the cost of crates and material
    const double COST_PER_CUBIC_FOOT = 0.23; //This represents the cost to build a crate, per cubic foot.
    const double CHARGE_PER_CUBIC_FEET = 0.5; //This represents the amount charged for a crate, per cubic foot.

    //initialized variables used in script
    double length,width,height,volume,cost,charge,profit;

    //input 
    cout<<"Length: ";cin>>length;
    cout<<"Width: ";cin>>width;
    cout<<"Height: ";cin>>height;

    //math
    volume = length * width * height;
    cost = COST_PER_CUBIC_FOOT * volume;
    charge = CHARGE_PER_CUBIC_FEET * volume;
    profit = charge - cost;

    //output the results
    cout<<"Volume: "<<volume<<endl;
    cout<<"Cost: "<<cost<<endl;
    cout<<"Customer price: "<<charge<<endl;
    cout<<"Profit of any crate GCI builds: "<<profit<<endl;

    return 0;
}