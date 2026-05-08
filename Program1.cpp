#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line, input = "";

    cout << "Enter program ($ to stop):\n";

    while (getline(cin, line))
    {
        if (line == "$") break;
        input += line + '\n';
    }

    // Keywords
    set<string> keywords =
    {
        "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long",
        "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while"
    };

    set<string> identifiers;

    for (int i = 0; i < input.length(); i++)
    {

        // If starts with letter or _
        if (isalpha(input[i]) || input[i] == '_')
        {
            string word = "";

            // Build full word
            while (i < input.length() && (isalnum(input[i]) || input[i] == '_'))
            {
                word += input[i];
                i++;
            }
            i--;

            // Check not keyword
            if (!keywords.count(word))
            {
                identifiers.insert(word);
            }
        }
    }

    // Output
    cout << "\nIdentifiers are:\n";
    for (auto id : identifiers)
    {
        cout << id << endl;
    }

    return 0;
}
