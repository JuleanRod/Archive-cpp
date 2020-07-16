#include <iostream>
using namespace std;

//functions
void displayNumbers(int[], int);
void selectionSort(int[], int);
void bubbleSort(int[], int);

//main starts here
int main()
{

    int numbers1[8] = {7, 2, 3, 8, 4, 5, 6, 1};
    int numbers2[8]= {7, 2, 3, 8, 4, 5, 6, 1};
    
    cout << "Bubble Sort\n";
    cout << "The unsorted values are: ";
    
    displayNumbers(numbers1, 8);
    bubbleSort(numbers1, 8);
    cout << "  " << endl;

    cout << "The sorted values are: ";
    displayNumbers(numbers1, 8);
    cout << "\nSelection Sort\n";
    cout << "The unsorted values are: ";
    displayNumbers(numbers2, 8);
    selectionSort(numbers2, 8);
    cout << " " << endl;
    cout << "The sorted values are: ";
    displayNumbers(numbers1, 8);

    return 0;
}//main ends here

//selectionsort function
void selectionSort(int numbers[], int arraySize) {

    int startScan, minValue, minIndex, x=1;

    for (startScan = 0; startScan < arraySize - 1; startScan++) {
        minValue = numbers[startScan];
        minIndex = startScan;

        for (int index = startScan + 1; index < arraySize; index++) {

            if (numbers[index] < minValue) {

                minValue = numbers[index];
                minIndex = index;
            }
        }

        numbers[minIndex] = numbers[startScan];

        numbers[startScan] = minValue;
        cout << " sort pass #" << x << " : "; x++;

        displayNumbers(numbers, arraySize);
    }
}
//display of numbers function
void displayNumbers(int numbers[], int arraySize) {

    for (int counter = 0; counter < arraySize; counter++) {
        cout << numbers[counter] << "  ";
    }
    cout << endl;
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
//bubble sort function
void bubbleSort(int numbers[], int n)
{
    int x = 1;
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {

        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                swap(&numbers[j], &numbers[j + 1]);
                swapped = true;

                cout << " sort pass #" << x << " : ";
                x++;
                displayNumbers(numbers, n);
            }
        }

        if (swapped == false)
            break;
    }
} 
