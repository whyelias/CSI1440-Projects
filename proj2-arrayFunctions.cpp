//
// Created by Elias Tovar on 1/31/2025.
//

#include "proj2-arrayFunctions.h"

/*
 * Pre: Takes array of pointers and an integer size
 * Return: void
 * Desc: Bubble sorts array contents (Needed for other functions)
 * Post: Sorted array
 */
void bubbleSort(int *array, int size) {
    for (int pass = 0; pass < size - 1; pass++) {
        for (int i = 0; i < size - 1 - pass; i++) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

/*
 * Pre: Takes array of pointers and an integer size
 * Return: Integer
 * Desc: Takes the last index of the array as the max assuming bubble sort function was ran prior
 * Post: Returns max
 */
int largestValue(int *array, int size) {
    int max = array[size - 1];
    return max;
}

/*
 * Pre: Takes array of pointers and an integer size
 * Return: Integer
 * Desc: Takes the first index of the array as the min assuming bubble sort function was ran prior
 * Post: Returns min
 */
int smallestValue(int *array, int size) {
    int min = array[0];
    return min;
}

/*
 * Pre: Takes array of pointers and integer size
 * Return: Double
 * Desc: Adds the total value of array and divides by size
 * Post: returns average of array
 */
double averageValue(int *array, int size) {
    double totalOfValues = 0.0;
    for (int i = 0; i < size; i++) {
        totalOfValues += array[i];
    }
    double average = totalOfValues / size;
    return average;
}

/*
 * Pre: Takes array of pointers and integer size
 * Return: Integer
 * Desc: If array size is even, the function takes the lower value in between the array. If not, then it takes the middle value of the array
 * Post: Returns median
 */
int medianValue(int *array, int size) {
    int median;
    if (size % 2 == 0) {
        median = array[size / 2 - 1];
    }
    else {
        median = array[size / 2];
    }
    return median;
}
