#include <iostream>
#include <fstream>

#include "proj2-arrayFunctions.h"

using namespace std;

int main() {

    ifstream infile;

    infile.open("arrays.txt");
    if (!infile.is_open()) {
        cerr << "Error opening file" << endl;
    }

    int count = 1;
    while (!infile.eof()) {
        int size;
        infile >> size;

        int* arr = new int[size];
        for (int i = 0; i < size; i++) {
            infile >> arr[i];
        }

        bubbleSort(arr, size);
        cout << "Max of array " << count << " : " << largestValue(arr, size) << endl;
        cout << "Min of array " << count << " : " << smallestValue(arr, size) << endl;
        cout << "Average of array " << count << " : " << averageValue(arr, size) << endl;
        cout << "Median of array " << count << " : " << medianValue(arr, size) << endl;
        cout << endl;

        delete[] arr;
        ++count;
    }

    infile.close();

    return 0;
}
