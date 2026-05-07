#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

string names[MAX_SIZE];
int scores[MAX_SIZE];
int count = 0;

void loadData() {
    ifstream inFile;
    inFile.open("data.txt");
    
    if (!inFile) {
        cout << "no file found" << endl;
        return;
    }
    
    while (inFile >> names[count] >> scores[count]) {
        count++;
        if (count == MAX_SIZE)
            break;
    }
    
    inFile.close();
}

void displayData() {
    cout << "Name" << "     " << "Score" << endl;
    cout << "-------------------" << endl;
    
    for (int i = 0; i < count; i++) {
        cout << names[i] << "     " << scores[i] << endl;
    }
}

void addEntry() {
    string n;
    int s;
    
    if (count >= MAX_SIZE) {
        cout << "cant add more" << endl;
    }
    
    cout << "enter name: ";
    cin >> n;
    cout << "enter score: ";
    cin >> s;
    
    names[count] = n;
    scores[count] = s;
    count++;
}

void searchEntry() {
    string search;
    cout << "enter name: ";
    cin >> search;
    
    for (int i = 0; i < count; i++) {
        if (names[i] == search) {
            cout << names[i] << " " << scores[i] << endl;
            return;
        }
    }
    cout << "not found" << endl;
}

void saveData(string names[], int scores[], int count) {
    ofstream outFile;
    outFile.open("data.txt");
    
    for (int i = 0; i < count; i++) {
        outFile << names[i] << " " << scores[i] << endl;
    }
    
    outFile.close();
}

int main() {
    loadData();
    
    int choice;
    
    while (true) {
        cout << "\n1. View Data" << endl;
        cout << "2. Add Entry" << endl;
        cout << "3. Search Entry" << endl;
        cout << "4. Save Data" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        
        if (choice == 1) {
            displayData();
        }
        else if (choice == 2) {
            addEntry();
        }
        else if (choice == 3) {
            searchEntry();
        }
        else if (choice == 4) {
            saveData(names, scores, count);
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "invalid" << endl;
        }
    }
    
    return 0;
}