#include <iostream>
using namespace std;

int main()
{
    string  input ;

    cout << "Enter a string:\n";
    cin>>input;
    if(input[0]=='/' && input[1]=='/')
    {
        cout<<"This is a comment";
    }
    else
    {
        cout<<"This is not a comment";
    }

    return 0;
}
