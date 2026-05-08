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
    int i = 0;

    while (i < input.length())
    {

        if (i + 1 < input.length() && input[i] == '/' && input[i + 1] == '/')
        {
            i += 2;
            string comments = "";
            while (i < input.length() && input[i] != '\n')
            {
                comments+=input[i];
                i++;
            }
            cout<<comments<<endl<<" This is a single line comment\n";
        }

        // 🔹 Multi-line comment /* ... */
        else if (i + 1 < input.length() && input[i] == '/' && input[i + 1] == '*')
        {
            i += 2;
            string comments="";
            while (i + 1 < input.length() && !(input[i] == '*' && input[i + 1] == '/'))
            {
                comments+=input[i];
                i++;
            }
            cout<<comments<<endl<<" This is a Multi-line comment\n";
            i += 2; // skip closing */
        }
        i++;

    }

    return 0;
}
