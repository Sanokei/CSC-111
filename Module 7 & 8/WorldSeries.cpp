/*
Write a program that displays the contents of the Teams.txt file on the screen and prompts the user to enter the name of one of the teams.  The program should then display the number of times that team has won the World Series in the time period from 1903 to 2020.

In the program, 2 arrays are needed:  TeamList array and Winners array.  

TeamList array will contain the entries in Teams.txt.

Winners array will contain the entries in WorldSeriesWinners.txt.

Use a search algorithm to validate if the entry from the user is in the team list.

Use a loop to count which years that team won the World Series, list the years in the output and the number of World Series wins.

Add logic to loop for an additional search or exit the program.
*/
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <ios>
#include "name.cpp"
using namespace std;

int main(){
    vector<string> TeamList;
    vector<string> Winners;
	string TeamEntry;
	int TeamCount = 0;
	int WinCount = 0;
	int TeamIndex = 0;
    int NumOfWinCounter = 0;
	ifstream TeamFile;
	ifstream WinFile;
	TeamFile.open("Teams.txt");
	WinFile.open("WorldSeriesWinners.txt");
	if (TeamFile.is_open() && WinFile.is_open()){
        //use getline to read in the file
        while (getline(TeamFile, TeamEntry)){
            TeamList.push_back(TeamEntry);
            cout<<TeamList[TeamCount]<<endl;
            TeamCount++;
        }
		while (getline(WinFile, TeamEntry)){
            Winners.push_back(TeamEntry);
			WinCount++;
		}
		TeamFile.close();
		WinFile.close();
	}
    else{
        cout << "Error opening file" << endl;
    }
    do{
        cout << "Enter the name of a team: ";
        getline(cin, TeamEntry);
        //find if the team is in the list
        for (int i = 0; i < TeamCount; i++){
            if (TeamEntry == TeamList[i]){
                TeamIndex = i;
                break;
            }
        }
    }while (TeamIndex == -1);
    //loop through the winners vector and count the number of times the team won the World Series
    for (int i = 0; i < WinCount; i++){
        if (TeamEntry == Winners[i]){
            NumOfWinCounter++;
        }
    }
    cout << "The team " << TeamEntry << " won the World Series " << NumOfWinCounter << " times." << endl;
    name();
    return 0;
}