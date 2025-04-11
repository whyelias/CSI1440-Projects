// createBinaryFile.cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("sortedInts", ios::binary | ios::trunc);

    if (!outFile) {
        cerr << "Error creating file." << endl;
        return 1;
    }

    // Add some sorted integers to the file for testing
    int sortedNums[] = {5, 10, 15, 20, 25};
    for (int num : sortedNums) {
        outFile.write(reinterpret_cast<char*>(&num), sizeof(int));
    }

    outFile.close();
    cout << "Binary file 'sortedInts' created with initial sorted values." << endl;

    return 0;
}
