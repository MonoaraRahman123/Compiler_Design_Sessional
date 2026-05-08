#include<bits/stdc++.h>
using namespace std;

unordered_map<string,string>SymTable;

string name,type;

void Insert()
{
    cout<<"Enter the name to insert:\n";
    cin>>name;
    cout<<"Enter type:\n";
    cin>>type;
    if(SymTable.count(name))
        cout<<"Already exits:\n";
    else
    {
        SymTable[name]=type;
        cout<<"Successfully inserted\n";
    }
}

void Update()
{
    cout<<"Enter the name to update:\n";
    cin>>name;
    if(SymTable.count(name))
    {
        cout<<"Enter New type:\n";
        cin>>type;
        SymTable[name]=type;
        cout<<"Updated successfully\n";
    }
    else
    {
        cout<<"Not Found\n";
    }
}

void Delete()
{
    cout<<"Enter the name to delete:\n";
    cin>>name;
    if(SymTable.erase(name))
        cout<<"Successfully deleted\n";
    else
    {
        cout<<"Not Found\n";
    }
}

void Search()
{
    cout<<"Enter the name to search:\n";
    cin>>name;
    if(SymTable.count(name))
        cout<<"Found\n";
    else
    {
        cout<<"Not Found\n";
    }
}

void Display()
{
    cout<<"Symbol Table\n";
    cout<<"Name\tType\n";
    for(auto &x: SymTable)
        cout<<x.first<<"\t"<<x.second<<endl;
}

int main()
{
    int choice;
    while(true)
    {
        cout<<"---Symbol Table Construction---\n";
        cout<<"1.Insert 2.Update 3.Delete 4.Search 5.Display 6.Exit\n";
        cout<<"Enter the number of choice: \n";
        cin>>choice;
        if(choice==1) Insert();
        else if(choice==2) Update();
        else if(choice==3) Delete();
        else if(choice==4) Search();
        else if(choice==5) Display();
        else break;
    }
}

