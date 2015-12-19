/********************************************************
 ** Author: Carlos Carrillo                             *
 ** Date:   11/11/2015                                  *
 ** Description: This program is designed to search for *
 *  target value from different a .txt files. using the *
 *  binary search algorithm.                            *
 *******************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

//Function prototypes
void selectionSort(vector<double> &);
double seachBinary(vector<double> &, double &);
void displayVector(vector<double>);

/*******************************************************
 *                       main                          *
 * The main calls the necessary functions to perform   *
 * the desired action.                                 *
 ******************************************************/

int main()
{
    cout << "\n**WELCOME TO THE BINARY SEARCH METHOD!**"<<endl;

    // Input file variables
    std::ofstream userFile5;
    std::string filename5;
    
    //Prompt the user to open and provide a filename for the input file
    cout << "\nEnter a FILENAME for the file you want to use to perform the search: "<<endl;
    cout<<"DO NOT ENTER SPACES (use undescore '_' instead): ";
    std::getline(cin, filename5);
    filename5 += ".txt";
    userFile5.open(filename5.c_str());
    
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
        userFile5<<values<<endl;
        
    }while(cin>>values);
    
    userFile5.close();
    
    // Open the input file and transfer its values to a vector
    std::ifstream userFile6(filename5.c_str());
    std::istream_iterator<double> start(userFile6), end;
    std::vector<double> binaryVector(start, end);
    
    // Sort the values in the file
    selectionSort(binaryVector);
    cout<<endl;
    
    // Display the sorted values on the console for user's reference
    cout << "THE SORTED VALUES BEFORE THE BINARY SEARCH ARE:\n";
    displayVector(binaryVector);
    cout <<endl;
    
    // Transfer the sorted values to the same input file
    std::ofstream outputFile(filename5.c_str());
    std::copy(binaryVector.begin(), binaryVector.end(),std::ostream_iterator<double>(outputFile," "));
    outputFile.close();
    
    // Re-open the input file and transfer the now sorted values to a new vector
    std::ifstream userFile(filename5.c_str());
    std::istream_iterator<double> start1(userFile), end1;
    std::vector<double> binaryVector2(start1, end1);
    
    // Call the function to search for the desired value
    double searchResult;
    searchResult = seachBinary(binaryVector2, value);
    
    // If seachLinear returned -1, the value/number has not been found
    if (searchResult == -1)
     {
        cout <<"\nSorry, "<<value<<" has NOT been found!\n"<<endl;
     }
    
    else
     {
        // print the position of the value/number being searched.
        cout <<value<<" WAS FOUND IN POSITION #"<<(searchResult+1)<< ".\n"<<endl;
     }

    return 0;
}

/******************************************************************
 *                         seachBinary                            *
 * This function performs a binary search on an vector of doubles *
 * whose values are stored in ascending order. The array is       *
 * searched for the number stored in the value parameter. If the  *
 * number is found, its array subscript is returned. Otherwise,   *
 * -1 is returned.                                                *
 *****************************************************************/
double seachBinary(vector<double> &binary, double &number)
{
    int first = 0, // First array element
    last = binary.size() - 1, // Last array element
    middle, // Midpoint of search
    position = -1; // Position of search value
    bool found = false; // Flag
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2; // Calculate midpoint
        
        if (binary[middle] == number) // If value is found at mid
        {
            found = true;
            position = middle;
        }
        
        else if (binary[middle] > number) // If value is in lower half
        {
            last = middle - 1;
        }
        
        else
        {
            first = middle + 1; // If value is in upper half
        }
    }
    
    return position;
}

/*************************************************************
 *                      selectionSort                        *
 * This function performs an ascending-order selection sort  *
 * on array. The parameter size holds the number of elements *
 * in the vector.                                            *
 ************************************************************/
void selectionSort(vector<double> &numbers)
{
    double startScan;
    double minIndex;
    double minValue;
    
    for (startScan = 0; startScan < (numbers.size() - 1); startScan++)
    {
        minIndex = startScan;
        minValue = numbers[startScan];
        
        for(int index = startScan + 1; index < numbers.size(); index++)
        {
            if (numbers[index] < minValue)
            {
                minValue = numbers[index];
                minIndex = index;
            }
        }
        
        numbers[minIndex] = numbers[startScan];
        numbers[startScan] = minValue;
    }
}

/*************************************************************
 *                      displayVector                        *
 * This function displays the contents of numbers, a vector  *
 * of doubles.                                               *
 *************************************************************/
void displayVector(vector<double> numbers)
{
    for (unsigned count = 0; count < numbers.size(); count++)
    {
        cout << numbers[count] << " ";
        cout << endl;
    }
}








