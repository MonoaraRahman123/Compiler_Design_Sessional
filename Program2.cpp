#include <bits/stdc++.h>
using namespace std;

int main() {
    string line, input = "";

    cout << "Enter program ($ to stop):\n";

    while (getline(cin, line)) {
        if (line == "$") break;
        input += line + '\n';
    }


    set<string> constants;

    for (int i = 0; i < input.length(); i++) {

        // If starts with letter or _
        if (isdigit(input[i]) || (input[i] == '-' && i+1<input.length()&& isdigit(input[i+1]))) {
            string num = "";
            if(input[i]=='-'){
                num+="-";
                i++;
            }

            // Build full word
            while (i < input.length() &&( (isdigit(input[i])) || input[i]=='.')) {
                num += input[i];
                i++;
            }
            i--;

           constants.insert(num);
        }
    }

    // Output
    cout << "\nConstants are:\n";
    for (auto id : constants) {
        cout << id << endl;
    }

    return 0;
}
