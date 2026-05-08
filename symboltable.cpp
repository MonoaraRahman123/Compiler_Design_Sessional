#include <bits/stdc++.h>
using namespace std;

// Symbol structure
struct Symbol {
    string name, type;
    int scope, line;
    string value;
    bool initialized;
};

// Symbol Table global state
map<int, vector<Symbol>> table;
int currentScope = 0;

void insertSymbol(string name, string type, int line) {
    // Check current scope for duplicates
    for (auto& s : table[currentScope]) {
        if (s.name == name) {
            cout << "Error: '" << name << "' already exists in scope " << currentScope << endl;
            return;
        }
    }
    Symbol s = {name, type, currentScope, line, "", false};
    table[currentScope].push_back(s);
    cout << "Inserted: " << name << " (" << type << ") at scope " << currentScope << endl;
}

Symbol* lookupSymbol(string name) {
    for (int i = currentScope; i >= 0; i--) {
        for (auto& s : table[i]) {
            if (s.name == name) return &s;
        }
    }
    return nullptr;
}

void deleteSymbol(string name) {
    auto& symbols = table[currentScope];
    for (auto it = symbols.begin(); it != symbols.end(); it++) {
        if (it->name == name) {
            cout << "Deleted: " << name << " from scope " << currentScope << endl;
            symbols.erase(it);
            return;
        }
    }
    cout << "Error: '" << name << "' not found in scope " << currentScope << endl;
}

void updateSymbol(string name, string value) {
    Symbol* s = lookupSymbol(name);
    if (s) {
        s->value = value;
        s->initialized = true;
        cout << "Updated: " << name << " = " << value << endl;
    } else {
        cout << "Error: '" << name << "' not found" << endl;
    }
}

void enterScope() {
    currentScope++;
    cout << "Entered scope " << currentScope << endl;
}

void exitScope() {
    if (currentScope > 0) {
        cout << "Exited scope " << currentScope << endl;
        table.erase(currentScope);
        currentScope--;
    } else {
        cout << "Error: Cannot exit global scope" << endl;
    }
}

void displayTable() {
    cout << "\nSymbol Table:" << endl;
    cout << "Name\t\tType\t\tScope" << endl;
    cout << "----\t\t----\t\t-----" << endl;
    for (auto& scope : table) {
        for (auto& s : scope.second) {
            cout << s.name << "\t\t" << s.type << "\t\t" << s.scope << endl;
        }
    }
}

void displayMenu() {
    cout << "\n========================================" << endl;
    cout << "   SYMBOL TABLE MANAGEMENT SYSTEM" << endl;
    cout << "========================================" << endl;
    cout << "1. Insert Symbol" << endl;
    cout << "2. Lookup Symbol" << endl;
    cout << "3. Delete Symbol" << endl;
    cout << "4. Display Symbol Table" << endl;
    cout << "5. Quit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice (1-5): ";
}

int main() {
    int choice;

    // Auto-load symbols from input.txt
    ifstream inputFile("input.txt");
    if (inputFile.is_open()) {
        cout << "Loading symbols from input.txt..." << endl;
        string name, type;
        int line;
        while (inputFile >> name >> type >> line) {
            insertSymbol(name, type, line);
        }
        inputFile.close();
        cout << "Loading complete!\n" << endl;
    } else {
        cout << "Note: input.txt not found. Starting with empty symbol table.\n" << endl;
    }

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear input buffer

        switch (choice) {
            case 1: {
                string name, type;
                int line;
                cout << "Enter symbol name: ";
                cin >> name;
                cout << "Enter symbol type: ";
                cin >> type;
                cout << "Enter line number: ";
                cin >> line;
                insertSymbol(name, type, line);
                break;
            }
            case 2: {
                string name;
                cout << "Enter symbol name to lookup: ";
                cin >> name;
                Symbol* s = lookupSymbol(name);
                if (s) {
                    cout << "\n--- Found ---" << endl;
                    cout << "Name: " << s->name << endl;
                    cout << "Type: " << s->type << endl;
                    cout << "Scope: " << s->scope << endl;
                } else {
                    cout << "Not found: " << name << endl;
                }
                break;
            }
            case 3: {
                string name;
                cout << "Enter symbol name to delete: ";
                cin >> name;
                deleteSymbol(name);
                break;
            }
            case 4: {
                displayTable();
                break;
            }
            case 5: {
                cout << "Thank you for using Symbol Table Manager. Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice! Please enter a number between 1 and 5." << endl;
            }
        }
    }

    return 0;
}
