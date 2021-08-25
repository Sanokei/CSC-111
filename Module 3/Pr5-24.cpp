// This program lets the user enter a filename.
#include <iostream>
#include <string>
#include <fstream>
#include "name.cpp"
using namespace std;

int main()
{
   ifstream inputFile;
   string filename;
   int number;

   // Get the filename from the user.
   cout << "Enter the filename: ";
   cin >> filename;

   // Open the file.
   inputFile.open(filename);

   // If the file successfully opened, process it.
   if (inputFile)
   {
      // Read the numbers from the file and
      // display them.
      while (inputFile >> number)
      {
         cout << number << endl;
      }

      // Close the file.
      inputFile.close();
   }
   else
   {
	   // Display an error message.
	   cout << "Error opening the file.\n";
   }
   name();
   return 0;
}