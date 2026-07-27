#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    int searchRoll, rollNo;
    string name;
    float marks, newMarks;
    bool found = false;

    // Open file for both reading and writing
    fstream file("students.txt", ios::in | ios::out);

    // Check if file opened successfully
    if (!file.is_open())
    {
        cout << "Error: File not found!" << endl;
        return 1;
    }

    // Take input from user
    cout << "Enter Roll No to update: ";
    cin >> searchRoll;

    cout << "Enter New Marks: ";
    cin >> newMarks;

    // Search for the record
    while (file >> rollNo >> name >> marks)
    {
        if (rollNo == searchRoll)
        {
            // Move pointer back to overwrite marks
            streampos pos = file.tellg();
            pos -= 7;          // Reserved width for marks field
            file.seekp(pos);

            file << setw(6) << left << newMarks;

            found = true;
            break;
        }
    }

    // Close file
    file.close();

    // Display result
    if (found)
        cout << "\nRecord updated successfully." << endl;
    else
        cout << "\nRoll No not found." << endl;

    return 0;
}
