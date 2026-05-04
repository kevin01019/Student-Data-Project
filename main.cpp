#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int SIZE = 5;

struct Student {
    string name;
    int score;
};

void readData(Student students[], int &count) {
    ifstream inFile;
    inFile.open("data.txt");
    
    if (!inFile) {
        cout << "Unable to open file." << endl;
        return;
    }
    
    count = 0;
    while (inFile >> students[count].name >> students[count].score && count < SIZE) {
        count++;
    }
    
    inFile.close();
}

void displayAll(Student students[], int count) {
    cout << "\n--- All Students ---" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Name: " << students[i].name << " | Score: " << students[i].score << endl;
    }
}

void findHighest(Student students[], int count) {
    if (count == 0) return;
    
    int highestIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].score > students[highestIndex].score) {
            highestIndex = i;
        }
    }
    
    cout << "\nHighest Score: " << students[highestIndex].name 
         << " with " << students[highestIndex].score << endl;
}

void findLowest(Student students[], int count) {
    if (count == 0) return;
    
    int lowestIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].score < students[lowestIndex].score) {
            lowestIndex = i;
        }
    }
    
    cout << "\nLowest Score: " << students[lowestIndex].name 
         << " with " << students[lowestIndex].score << endl;
}

void calculateAverage(Student students[], int count) {
    if (count == 0) return;
    
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += students[i].score;
    }
    
    double average = static_cast<double>(total) / count;
    cout << "\nAverage Score: " << fixed << setprecision(2) << average << endl;
}

void searchByName(Student students[], int count) {
    string searchName;
    cout << "\nEnter name to search: ";
    cin >> searchName;
    
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (students[i].name == searchName) {
            cout << "Found: " << students[i].name << " | Score: " << students[i].score << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Student not found." << endl;
    }
}

int main() {
    Student students[SIZE];
    int count = 0;
    int choice;
    
    readData(students, count);
    
    if (count == 0) {
        cout << "No data found in file." << endl;
        return 1;
    }
    
    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Display all students" << endl;
        cout << "2. Find highest score" << endl;
        cout << "3. Find lowest score" << endl;
        cout << "4. Calculate average score" << endl;
        cout << "5. Search for a student" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                displayAll(students, count);
                break;
            case 2:
                findHighest(students, count);
                break;
            case 3:
                findLowest(students, count);
                break;
            case 4:
                calculateAverage(students, count);
                break;
            case 5:
                searchByName(students, count);
                break;
            case 6:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);
    
    return 0;
}