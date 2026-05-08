#include <bits/stdc++.h>
using namespace std;

/*
Grammar:
S -> A
A -> aB
B -> bC | c
C -> d
*/

map<char, vector<string>> g;

bool parse(string input)
{
    stack<char> st;
    st.push('S');

    int i = 0;

    while (!st.empty())
    {
        char top = st.top();
        char look = input[i];

        st.pop();

        // terminal match
        if (!isupper(top))
        {
            if (top == look) i++;
            else return false;
        }
        else
        {
            // S -> A
            if (top == 'S') st.push('A');

            // A -> aB
            else if (top == 'A')
            {
                if (look == 'a')
                {
                    st.push('B');
                    st.push('a');
                }
                else return false;
            }

            // B -> bC | c
            else if (top == 'B')
            {
                if (look == 'b')
                {
                    st.push('C');
                    st.push('b');
                }
                else if (look == 'c')
                {
                    st.push('c');
                }
                else return false;
            }

            // C -> d
            else if (top == 'C')
            {
                if (look == 'd') st.push('d');
                else return false;
            }
        }
    }

    return i == input.size();
}

int main()
{
    string input;
    cout<<"Enter a string to test: ";
    cin>>input;

    cout << "Input: " << input << endl;

    if (parse(input))
        cout << "Accepted\n";
    else
        cout << "Rejected\n";

    return 0;
}
