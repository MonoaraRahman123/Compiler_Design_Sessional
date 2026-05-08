#include <iostream>
using namespace std;

int main()
{
    string line, input = "";

    cout << "Enter program ($ to stop):\n";

    // Read input
    while (getline(cin, line))
    {
        if (line == "$") break;
        input += line + '\n';
    }

    string comments = "";
    int i = 0;

    while (i < input.length())
    {

        if (i + 1 < input.length() && input[i] == '/' && input[i + 1] == '/')
        {
            i += 2;
            while (i < input.length() && input[i] != '\n')
            {
                if(isalpha(input[i]))comments+=input[i];
                i++;
            }
        }

        // 🔹 Multi-line comment /* ... */
        else if (i + 1 < input.length() && input[i] == '/' && input[i + 1] == '*')
        {
            i += 2;
            while (i + 1 < input.length() && !(input[i] == '*' && input[i + 1] == '/'))
            {
                if(isalpha(input[i]))comments+=input[i];
                i++;
            }
            i += 2; // skip closing
        }
        i++;

    }

    cout << "\nLetters in comment:\n";
    cout << comments.length();

    return 0;
}
