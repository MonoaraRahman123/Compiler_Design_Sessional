#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> symTable;

// 🔹 Insert
void insert() {
    string name, type;
    cout << "Enter identifier name: ";
    cin >> name;
    cout << "Enter type: ";
    cin >> type;

    if (symTable.count(name))
        cout << "Already exists!\n";
    else {
        symTable[name] = type;
        cout << "Inserted successfully.\n";
    }
}

// 🔹 Update
void update() {
    string name, type;
    cout << "Enter identifier to update: ";
    cin >> name;

    if (symTable.count(name)) {
        cout << "Enter new type: ";
        cin >> type;
        symTable[name] = type;
        cout << "Updated successfully.\n";
    } else {
        cout << "Not found!\n";
    }
}

// 🔹 Delete
void deleteEntry() {
    string name;
    cout << "Enter identifier to delete: ";
    cin >> name;

    if (symTable.erase(name))
        cout << "Deleted successfully.\n";
    else
        cout << "Not found!\n";
}

// 🔹 Search
void search() {
    string name;
    cout << "Enter identifier to search: ";
    cin >> name;

    if (symTable.count(name))
        cout << "Found! Type = " << symTable[name] << endl;
    else
        cout << "Not found!\n";
}

// 🔹 Display
void display() {
    cout << "\nSymbol Table:\n";
    cout << "Name\tType\n";

    for (auto &x : symTable)
        cout << x.first << "\t" << x.second << endl;
}

// 🔹 Main Menu
int main() {
    int choice;

    while (true) {
        cout << "\n--- Symbol Table Menu ---\n";
        cout << "1.Insert  2.Update  3.Delete  4.Search  5.Display  6.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) insert();
        else if (choice == 2) update();
        else if (choice == 3) deleteEntry();
        else if (choice == 4) search();
        else if (choice == 5) display();
        else if (choice == 6) break;
        else cout << "Invalid choice!\n";
    }

    return 0;
}
