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
    set<string> key =
    {
        "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long",
        "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while"
    };
    set<string> identifiers;
    set<string> keywords;

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
            if (!key.count(word))
            {
                identifiers.insert(word);
            }
            else
            {
                keywords.insert(word);
            }
        }
    }

    // Output
    cout << "\nIdentifiers are:\n";
    for (auto id : identifiers)
    {
        cout << id << endl;
    }

    cout<<"\nKeywords are:\n";

    for(auto keys : keywords)
    {
        cout<< keys <<endl;
    }

    return 0;
}
