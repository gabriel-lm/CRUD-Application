#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

void addPerson();
void getAll();
void searchID();
void deleteP();

int main()
{
    int choice;

    do{

    cout<<"1 - Add person\n";
    cout<<"2 - Get all\n";
    cout<<"3 - Search ID\n";
    cout<<"4 - Edit\n";
    cout<<"5 - Delete\n";
    cout<<"6 - Exit\n";
    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice){
        case 1:
            addPerson();
            break;
        case 2:
            getAll();
            break;
        case 3:
            searchID();
            break;
        case 4:
            break;
        case 5:
            deleteP();
            break;
        case 6:
            exit(0);
        }
    } while (1);
    return 0;
}

void addPerson()
{
    string p_id, p_name, p_age;

    ofstream plist("person.txt",ios::app);

    cout<<"\t\t\t Person";
    cout<<"\nEnter person ID: ";
    cin>>p_id;
    plist << p_id;
    cout<<"\nEnter person name: ";
    cin>>p_name;
    plist << p_name;
    cout<<"\n\nEnter person age: ";
    cin>>p_age;
    plist << p_age <<"\n";

    plist.close();
}

void getAll()
{
    ifstream plist("person.txt");
    string prs;

    if (plist.is_open())
    while (!plist.eof()){
        getline(plist, prs);
        cout << prs << "\n";
    }
    else cout<<"file not open\n";
    plist.close();
}

void searchID()
{
    ifstream plist("person.txt");
    string p_id, line;

    cout << "Enter ID to search: ";
    cin >> p_id; cout <<"\n";

    if (plist.is_open())
    while (!plist.eof()){
            getline(plist, line);
        if (line.find(p_id) != string::npos){
            cout << line << "\n";
            break;
        }
    }
    else cout << "File didn't open!\n";
    plist.close();
}

void deleteP()
{
    ifstream plist("person.txt");
    ofstream newplist ("temp.txt");

    string p_id, line;
    bool foud = false;

    cout << "Enter the ID of person to delete: ";
    cin >> p_id; cout << "\n";

    if (plist.is_open())
    while (!plist.eof()){
           getline(plist, line);
        if (line.find(p_id) !=string::npos && !foud){
            line.replace(line.find(p_id), line.length(), "\b");
            foud = true;
        }
        newplist << line << "\n";
    }
    else cout << "File couldn't open!\n";

    plist.close();
    newplist.close();

    remove("person.txt");
    rename("temp.txt", "person.txt");
}
