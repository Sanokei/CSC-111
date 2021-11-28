/*
Read and input file xycoordinates.txt containing the following: PersonName  X Y where the coordinates of PersonName is provided as X, Y in a 100 by 100 room
Use square root function in cmath sqrt() to calculate the shortest distance between two coordinates (Remember the Pythagorean Theorem?)
Write a program tracing.cpp that should load the xycoordinates.txt file into an 3 parallel arrays consisting of person[ ], x[ ], y[ ].  You can use either subscript notation or pointer arithmetic to access the data in the arrays.  Optionally, you can use an struct array if you want to read-ahead about the next module. (10 points bonus).
The program should use the arrays to calculate the distance between every pair in the room.
The program should use a function call that returns the distance.  If the distance is less than 6 feet, report the case giving the names and the calculated distance in a cout statement:  
Example:  Apple and Barry is 4 feet apart and violating COVID-19 social distancing guidelines.
*/

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <ios>
#include "name.cpp"
using namespace std;

int main(){
    vector<string> Person;
    vector<int> X;
    vector<int> Y;
	string Entry;
	int Count = 0;
	int XCount = 0;
	int YCount = 0;
	int Index = 0;
    int Distance = 0;
	ifstream File;
	File.open("xycoordinates.txt");
	if (File.is_open()){
        //use getline to read in the file
        while (getline(File, Entry)){
            stringstream ss(Entry);
            string item;
            vector<string> temp;
            //spit at any number of white spaces
            //use regex
            while (ss >> item){    
                temp.push_back(item);
            }
            Person.push_back(temp[0]);
            X.push_back(stoi(temp[1]));
            Y.push_back(stoi(temp[2]));
            cout<<Person[Count]<<endl;
            Count++;
            XCount++;
			YCount++;
        }
		File.close();
	}
    else{
        cout << "Error opening file" << endl;
    }

    //find every pair of people
    for (int i = 0; i < XCount; i++){
        for (int j = 0; j < YCount; j++){
            Distance = sqrt(pow(X[i] - X[j], 2) + pow(Y[i] - Y[j], 2));
            if (Distance < 6 && i != j){
                cout << Person[i] << " and " << Person[j] << " is " << Distance << " feet apart and violating COVID-19 social distancing guidelines." << endl;
            }
        }
    }
    name();
    return 0;
}