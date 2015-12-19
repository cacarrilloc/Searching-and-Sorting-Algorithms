/********************************************************
 ** Author: Carlos Carrillo                             *
 ** Date:   11/11/2015                                  *
 ** Description: This program is designed to search for *
 *  target value from different a .txt files. using the *
 *  linear search algorithm.                            *
 *******************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

//Function prototype
double seachLinear(vector<double> &, double &);

/*******************************************************
 *                       main                          *
 * The main calls the necessary functions to perform   *
 * the desired action.                                 *
 ******************************************************/

int main()
{
    cout << "\n**WELCOME TO THE LINEAR SEARCH METHOD!**"<<endl;
    
    // Input file variables
    std::ofstream userFile;
    std::string filename;
    
    //Prompt the user to open and provide a filename for the input file
    cout << "\nEnter a FILENAME for the file you want to use to perform the search: "<<endl;
    cout<<"DO NOT ENTER SPACES (use undescore '_' instead): ";
    std::getline(cin, filename);
    filename += ".txt";
    userFile.open(filename.c_str());
    
    //Prompt the user to input the value to be searched
    double value;
    cout << "\nEnter the number to be searched: ";
    cin>>value;
    
    //Prompt the user to input numeric values in random order (including the chosen value)
    double values;
    cout <<"\n1) Enter as many numeric values as you want (Include the number you chose)."<<endl;
    cout <<"2) Enter the chosen number at any position you want (beginning, middle, end)."<<endl;
    cout <<"3) Press ENTER after each value."<<endl;
    cout <<"4) Type 'EXIT' when you are DONE.\n"<<endl;
    cin>>values;
    
    // Loop to input values inte the input file
    do
    {
        userFile<<values<<endl;
        
    }while(cin>>values);
    
    userFile.close();
    
    // Open the input file and transfer its values to a vector
    std::ifstream userFile2(filename.c_str());
    std::istream_iterator<double> start(userFile2), end;
    std::vector<double> linearVector(start, end);
    
    // Call the function to search for the desired value
    double searchResult;
    searchResult = seachLinear(linearVector, value);
    
    // If seachLinear returned -1, the value/number has not been found
    if (searchResult == -1)
    {
        cout <<"\nSorry, "<<value<<" has NOT been found!\n"<<endl;
    }
    
    else
    {
        // print the position of the value/number being searched.
        cout <<"\n"<<value<<" WAS FOUND IN POSITION #"<<(searchResult + 1)<< ".\n"<<endl;
    }

    return 0;
}

/****************************************************************
 *                        searchLinear                          *
 * This function performs a linear search on an double vector.  *
 * The function searchs for the number stored in value. If the  *
 * number is found, its array subscript is returned. Otherwise, *
 * -1 is returned.                                              *
 ***************************************************************/

double seachLinear(vector<double> &linear, double &number)
{
    int index = 0; // Used as a subscript to search the vector
    int position = -1; // Used to record position of search value
    bool found = false; // Flag to indicate if the value was found
    
    while (index < linear.size() && !found)
    {
        if (linear.at(index) == number) // If the value is found
        {
            found = true; // Set the flag
            position = index; // Record the value's subscript
        }
        
        index++; // Go to the next element
    }
    
    return position; // Return the position, or -1
}





