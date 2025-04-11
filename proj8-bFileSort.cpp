#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("sortedInts", ios::in | ios::out | ios::binary);

    // If file doesn't exist, create it
    if (!file) {
        file.open("sortedInts", ios::out | ios::binary);  // Create empty file
        file.close();
        file.open("sortedInts", ios::in | ios::out | ios::binary);  // Reopen for read/write
    }

    // Ask for new integer
    int newNum;
    cout << "Enter an integer to insert into the sorted binary file: ";
    cin >> newNum;

    // Determine number of integers in the file
    file.seekg(0, ios::end);
    streampos fileSize = file.tellg();
    int numInts = fileSize / sizeof(int);

    // Edge case: empty file
    if (numInts == 0) {
        file.seekp(0, ios::beg);
        file.write(reinterpret_cast<char*>(&newNum), sizeof(int));
        cout << "Inserted into empty file." << endl;
    } else {
        // Read the last integer to check if we can append
        int lastNum;
        file.seekg((numInts - 1) * sizeof(int), ios::beg);
        file.read(reinterpret_cast<char*>(&lastNum), sizeof(int));

        if (lastNum <= newNum) {
            // Append newNum at the end
            file.seekp(0, ios::end);
            file.write(reinterpret_cast<char*>(&newNum), sizeof(int));
        } else {
            // Shift larger elements to make space
            int current;
            int i = numInts - 1;
            while (i >= 0) {
                file.seekg(i * sizeof(int), ios::beg);
                file.read(reinterpret_cast<char*>(&current), sizeof(int));

                if (current <= newNum) break;

                // Move current one position ahead
                file.seekp((i + 1) * sizeof(int), ios::beg);
                file.write(reinterpret_cast<char*>(&current), sizeof(int));
                i--;
            }

            // Write newNum in correct position
            file.seekp((i + 1) * sizeof(int), ios::beg);
            file.write(reinterpret_cast<char*>(&newNum), sizeof(int));
        }
    }

    // Display all integers in the file
    cout << "Contents of sortedInts:" << endl;
    file.seekg(0, ios::beg);
    int val;
    for (int i = 0; i <= numInts; i++) {
        file.read(reinterpret_cast<char*>(&val), sizeof(int));
        cout << val << " ";
    }
    cout << endl;

    file.close();
    return 0;
}
