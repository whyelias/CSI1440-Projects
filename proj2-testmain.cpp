#include "proj2-arrayFunctions.h"
#include <iostream>
#include <sstream>

using namespace std;

int main() {

    // Psuedo File
    stringstream ss;
    ss << "5" << endl;
    ss << "1 2 3 4 5" << endl;
    ss << "4" << endl;
    ss << "10 2 32 14" << endl;
    ss << "3" << endl;
    ss << "23 41 2";

    // Reads size and array contents until end of ss is reached
    int count = 1;
    while (!ss.eof()) {
        int size;
        ss >> size;

        int* arr = new int[size];
        for (int i = 0; i < size; i++) {
            ss >> arr[i];
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


    return 0;
}
