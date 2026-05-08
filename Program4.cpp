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

    string result = "";
    int i = 0;

    while (i < input.length())
    {

        // 🔹 Single-line comment //
        if (i + 1 < input.length() && input[i] == '/' && input[i + 1] == '/')
        {
            i += 2;
            while (i < input.length() && input[i] != '\n')
            {
                i++; // skip comment
            }
        }

        // 🔹 Multi-line comment /* ... */
        else if (i + 1 < input.length() && input[i] == '/' && input[i + 1] == '*')
        {
            i += 2;
            while (i + 1 < input.length() && !(input[i] == '*' && input[i + 1] == '/'))
            {
                i++;
            }
            i += 2; // skip closing */
        }

        // 🔹 Normal code
        else
        {
            result += input[i];
            i++;
        }
    }

    cout << "\nCode after removing comments:\n";
    cout << result;

    return 0;
}
