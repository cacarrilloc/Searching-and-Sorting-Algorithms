/********************************************************
 ** Author: Carlos Carrillo                             *
 ** Date:   11/11/2015                                  *
 ** Description: This program is designed to sort a set *
 *  of values from a .txt file using the selection sort *
 *  algorithm; as well as sorting a set of values taken *
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
void displayVector(vector<double>);
void selectionSort(vector<double> &);

/*******************************************************
 *                       main                          *
 * The main calls the necessary functions to perform   *
 * the desired action.                                 *
 ******************************************************/

int main()
{
    cout << "\n**WELCOME TO THE SELECTION SORT METHOD!**"<<endl;
    
    // Input file variables
    std::ofstream userFile3;
    std::string filename3;
    
    //Prompt the user to open and provide a filename for the input file
    cout << "\nEnter a FILENAME for the file to be sorted: "<<endl;
    cout<<"DO NOT ENTER SPACES (use undescore '_' instead): ";
    std::getline(cin, filename3);
    filename3 += ".txt";
    userFile3.open(filename3.c_str());
    
    //Prompt the user to input numeric values in random order
    double values;
    cout <<"\n1) Enter as many numeric values as you want in ANY order."<<endl;
    cout <<"2) Press ENTER after each value."<<endl;
    cout <<"3) Type 'EXIT' when you are DONE.\n"<<endl;
    cin>>values;
    
    // Loop to input values inte the input file
    do
    {
        userFile3<<values<<endl;
        
    }while(cin>>values);
    
    userFile3.close();
    
    // Open the input file and transfer its values to a vector
    std::ifstream userFile4(filename3.c_str());
    std::istream_iterator<double> start(userFile4), end;
    std::vector<double> sortVector(start, end);
    
    // Display the unsorted values from the file
    cout << "\nTHE UNSORTED VALUES FROM THE INPUT FILE ARE:\n";
    displayVector(sortVector);
    
    // Sort the values
    selectionSort(sortVector);
    
    // Transfer the sorted values to a new file called 'outputSorted.txt'
    std::ofstream outputFile("outputSorted.txt");
    std::copy(sortVector.begin(), sortVector.end(),std::ostream_iterator<double>(outputFile," "));
    outputFile.close();
    
    // Display the sorted values
    cout << "\nTHE SORTED VALUES ARE:\n";
    displayVector(sortVector);
    cout <<endl;
    
    // Note to remind the user that the values are also in the output file
    cout <<"NOTE: You can also see the sorted values in"<<endl;
    cout <<"      the output file called 'outputSorted.txt'.\n"<<endl;
    
    return 0;
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






