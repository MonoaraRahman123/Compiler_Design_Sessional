#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    vector<string>input;

    cout << "Enter program ($ to stop):\n";

    // Read input
    while (getline(cin, line))
    {
        if (line == "$") break;
        input.push_back(line);
    }
    int i = 0;

    while (i < input.size())
    {
        string s= input[i];
        int j=0;
        while(s[j]==' ')j++;
        if(s[j]=='/' && (s[j+1]=='*' || s[j+1]=='/'))
        {
            cout<<"Comment in line "<<i+1<<endl;
        }
        i++;

    }

    return 0;
}
