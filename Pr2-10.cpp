// This program has variables of several of the integer types.
#include <iostream>
#include "name.cpp"
using namespace std;

int main()
{
   int checking;
   unsigned int miles;
   long diameter;

   checking = -20;
   miles = 4276;
   diameter = 100000;
   cout << "We have made a long journey of " << miles;
   cout << " miles.\n";
   cout << "Our checking account balance is " << checking;
   cout << "\nThe galaxy is about " << diameter;
   cout << " light years in diameter.\n";
   cout << name() << endl;
   return 0;
}