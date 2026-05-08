#include <bits/stdc++.h>
using namespace std;

// X -> bbX | bcX | ε
string X()
{
    int choice = rand() % 3;

    if (choice == 0) return "bb" + X();
    else if (choice == 1) return "bc" + X();
    else return "";   // ε
}

// A -> aXd
string A()
{
    return "a" + X() + "d";
}

int main()
{

    srand(time(0));
    string result = A();

    cout << "Generated String: " << result << endl;

    return 0;
}
