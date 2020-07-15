#include <iostream>
#include <iomanip>
#include <ctgmath>
#include <cmath>

using namespace std;

//functions
void sortArray(double *, int);
double getAverage(double *, int);

int main()
{
    /*variable to store user input
    for number of tests*/
    int numTests;

    /*prompt user to enter input then read
    cout << "Please enter number of test scores ";
    cout << "that will be stored:\n";*/
    cout << "How many test scores do you have? ";
    cin >> numTests;

    //dynamically allocate array large enough
    double *testScores = new double[numTests];

    //read values into array using for loop
    for(int counter = 0; counter < numTests; counter++){
        cout << "Test Score #" << counter + 1 << ": ";

        /*use pointer notation, don't forget
        to dereference first*/
        cin >> *(testScores + counter);

        //validate input
        while(*(testScores + counter) < 0){
            //print error message then prompt and read
            cout << "Value must be one or greater: ";
            cin >> *(testScores + counter);
        }
    }

    //sort array
    sortArray(testScores, numTests);

    //format output
    cout << fixed << setprecision(0);

    //display contents of array
    cout << endl;
    cout << "The numbers in set are:" << endl;
    //cout << "Sorted test scores are: \n";
    for(int counter = 0; counter < numTests; counter++){
        cout << *(testScores + counter) << " ";
    }

    //print message for average
    cout << "\nAverage Score: ";
    cout << getAverage(testScores, numTests);

   
    return 0;
}

//function to sort array
void sortArray(double *ptr, int arraySize){
    //temporary variable to help in swapping
    double temp;

    /*boolean variable that will control when
    array is done sorting*/
    bool swapped = true;

    while(swapped){
        swapped = false;

        //loop on all elements
        for(int counter = 0; counter < arraySize - 1; counter++){
            /*check if following element is greater
            than current element*/
            if(*(ptr+counter) > *(ptr+counter+1)){
                //if so, perform swap
                temp = *(ptr+counter+1);
                *(ptr+counter+1) = *(ptr+counter);
                *(ptr+counter) = temp;

                //and update boolean variable
                swapped = true;

            }//if ends here
        }//for loop ends here
    }//while loop ends here
}

//function to get average
double getAverage(double *ptr, int arraySize){
    //accumulator variable
    double total = 0;

    //loop on all values of array
    for(int counter = 0; counter < arraySize; counter++){
        total += *(ptr + counter);
    }

    //use typecast to double to
    //prevent integer division
    return (int)total/arraySize;
}
