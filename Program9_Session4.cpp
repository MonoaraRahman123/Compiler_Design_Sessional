#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    vector<string> code;
    stack<char> st;

    cout << "Enter Program ($ to stop):\n";

    while (getline(cin, line)) {
        if (line == "$") break;
        code.push_back(line);
    }

    bool hasIf = false;

    for (int i = 0; i < code.size(); i++) {
        string s = code[i];

        // Duplicate token check
        if (s.find("int int") != -1 ||
            s.find("float float") != -1 ||
            s.find("double double") != -1) {
            cout << "Duplicate token at line " << i + 1 << endl;
        }

        // Missing semicolon check
        if (s.find("=") != -1 &&
            s.find(";") == -1 &&
            s.find("{") == -1 &&
            s.find("}") == -1) {
            cout << "Missing ; at line " << i + 1 << endl;
        }

        // if / else check
        if (s.find("if") != -1)
            hasIf = true;

        if (s.find("else") != -1) {
            if (!hasIf)
                cout << "Unmatched else at line " << i + 1 << endl;
            else
                hasIf = false;
        }

        // Bracket check
        for (char c : s) {
            if (c == '{')
                st.push('{');

            else if (c == '}') {
                if (st.empty())
                    cout << "Misplaced } at line " << i + 1 << endl;
                else
                    st.pop();
            }
        }
    }

    while (!st.empty()) {
        cout << "Unmatched { found" << endl;
        st.pop();
    }

    return 0;
}
