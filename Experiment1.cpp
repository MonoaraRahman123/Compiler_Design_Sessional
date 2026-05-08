#include <bits/stdc++.h>
using namespace std;

// Global sets
set<string> keywords =
{
    "auto","break","case","char","const","continue",
    "default","do","double","else","enum","extern",
    "float","for","goto","if","int","long",
    "register","return","short","signed","sizeof",
    "static","struct","switch","typedef","union",
    "unsigned","void","volatile","while"
};

set<string> kw, id, con;
set<char> op, sp;

// ---------------- Remove comments ----------------
string removeComments(string input)
{
    string res = "";

    for (int i = 0; i < input.length(); i++)
    {

        string comment ="";
        if (i + 1 < input.length() && input[i] == '/' && input[i+1] == '/')
        {
            i += 2;
            comment+="//";
            while (i < input.length() && input[i] != '\n')
            {
                comment+= input[i];
                i++;
            }
        }

        // /* */
        else if (i + 1 < input.length() && input[i] == '/' && input[i+1] == '*')
        {
            comment+="/*";
            i+=2;
            while (i + 1 < input.length() &&
                    !(input[i] == '*' && input[i+1] == '/'))
            {
                comment+= input[i];
                i++;
            }
            i += 2;
            comment+="*/";
        }
        if(comment != "")res+= comment+"\n";
    }
    return res;
}

void analyze(string input)
{

    for (int i = 0; i < input.length(); i++)
    {

        // Identifier / Keyword
        if (isalpha(input[i]) || input[i] == '_')
        {
            string word = "";

            while (i < input.length() &&
                    (isalnum(input[i]) || input[i] == '_'))
            {
                word += input[i];
                i++;
            }
            i--;

            if (keywords.count(word)) kw.insert(word);
            else id.insert(word);
        }

        // Constant
        else if (isdigit(input[i]) ||
                 (input[i] == '-' && isdigit(input[i+1])))
        {

            string num = "";

            if (input[i] == '-')
            {
                num += input[i];
                i++;
            }

            while (i < input.length() && isdigit(input[i]))
            {
                num += input[i];
                i++;
            }
            i--;

            con.insert(num);
        }

        // Operator
        else if (input[i]=='+' || input[i]=='-' || input[i]=='*' ||
                 input[i]=='/' || input[i]=='=' || input[i]=='>' ||
                 input[i]=='<')
        {
            op.insert(input[i]);
        }

        // Special symbols
        else if (input[i]==';' || input[i]==',' || input[i]=='(' ||
                 input[i]==')' || input[i]=='{' || input[i]=='}')
        {
            sp.insert(input[i]);
        }
    }
}

void printResult()
{
    cout << "\nKeywords: ";
    for (auto x : kw) cout << x << " ";

    cout << "\nIdentifiers: ";
    for (auto x : id) cout << x << " ";

    cout << "\nConstants: ";
    for (auto x : con) cout << x << " ";

    cout << "\nOperators: ";
    for (auto x : op) cout << x << " ";

    cout << "\nSpecial Symbols: ";
    for (auto x : sp) cout << x << " ";

    cout << endl;
}

int main()
{
    string line, input = "";

    cout << "Enter program ($ to stop):\n";

    while (getline(cin, line))
    {
        if (line == "$") break;
        input += line + '\n';
    }

    string comment = removeComments(input);
    analyze(input);
    printResult();
    cout<<"Comments:\n";
    cout<<comment;


    return 0;
}




