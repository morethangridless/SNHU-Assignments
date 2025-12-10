// CS210 Project Three - Corner Grocer Item Tracker
// Fully functional, cross-platform, creates frequency.dat automatically

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstdlib>      // for system("cls") / system("clear")
#include <limits>       // for numeric_limits in input validation
using namespace std;

// ========================================
// Cross-platform screen clearing
// ========================================
void clearScreen() {
#ifdef _WIN32
    system("cls");      // Windows (Visual Studio)
#else
    system("clear");    // Mac and Linux
#endif
}

// ========================================
// GroceryTracker Class - Core logic
// ========================================
class GroceryTracker {
private:
    map<string, int> itemFrequency;                    // Stores item count
    const string inputFile = "CS210_Project_Three_Input_File.txt";
    const string backupFile = "frequency.dat";

    // Reads the input file and populates the map
    void loadData() {
        ifstream inFile(inputFile);
        string item;

        if (!inFile) {
            cout << "Error: Could not open " << inputFile << endl;
            return;
        }

        while (getline(inFile, item)) {
            if (!item.empty()) {
                itemFrequency[item]++;                  // Increment count for this item
            }
        }
        inFile.close();
    }

    // Creates/overwrites frequency.dat with current data
    void saveToBackupFile() const {
        ofstream outFile(backupFile);
        if (!outFile) {
            cout << "Error: Could not create " << backupFile << endl;
            return;
        }
        for (const auto& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << endl;
        }
        outFile.close();
    }

public:
    // Constructor automatically loads data and creates backup file on startup
    GroceryTracker() {
        loadData();
        saveToBackupFile();
    }

    // Returns how many times an item appears (0 if not found)
    int getItemFrequency(const string& item) const {
        auto it = itemFrequency.find(item);
        return (it != itemFrequency.end()) ? it->second : 0;
    }

    // Menu Option 2: Print all items and frequencies
    void printAllFrequencies() const {
        cout << "\nItem Frequency List:\n";
        cout << "========================\n";
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
        cout << endl;
    }

    // Menu Option 3: Print histogram with asterisks
    void printHistogram() const {
        cout << "\nItem Frequency Histogram:\n";
        cout << "=========================\n";
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
        cout << endl;
    }
};

// ========================================
// Display main menu
// ========================================
void displayMenu() {
    cout << "=== Corner Grocer Item Tracker ===\n";
    cout << "1. Search for an item\n";
    cout << "2. Display frequency of all items\n";
    cout << "3. Display histogram\n";
    cout << "4. Exit\n";
    cout << "Enter your choice (1-4): ";
}

// ========================================
// Main program loop
// ========================================
int main() {
    GroceryTracker tracker;        // Loads file and creates frequency.dat immediately

    int choice;
    string searchItem;

    while (true) {
        clearScreen();
        displayMenu();

        // Validate menu input
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid choice. Please select 1-4.\n";
            cout << "Press Enter to continue...";
            cin.get();
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer

        switch (choice) {
        case 1:   // Search for specific item
            cout << "\nEnter item name: ";
            getline(cin, searchItem);
            if (searchItem.empty()) {
                cout << "\nNo item entered.\n";
            }
            else {
                int freq = tracker.getItemFrequency(searchItem);
                cout << "\n" << searchItem << " appears " << freq
                    << (freq == 1 ? " time" : " times") << " today.\n";
            }
            cout << "\nPress Enter to return to menu...";
            cin.get();
            break;

        case 2:   // List all items
            tracker.printAllFrequencies();
            cout << "Press Enter to return to menu...";
            cin.get();
            break;

        case 3:   // Show histogram
            tracker.printHistogram();
            cout << "Press Enter to return to menu...";
            cin.get();
            break;

        case 4:   // Exit
            clearScreen();
            cout << "Thank you for using Corner Grocer Tracker. Goodbye!\n";
            return 0;

        default:
            cout << "\nInvalid choice. Please select 1-4.\n";
            cout << "Press Enter to continue...";
            cin.get();
        }
    }

    return 0;
}