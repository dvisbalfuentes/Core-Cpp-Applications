//*******************************************************************************************************
//
//        This program reads and copies text from one file to another one.
//
//
//*******************************************************************************************************

#include <iostream>
#include<fstream>
#include<cctype>
#include<string>
#include<cstring>
using namespace std;

//*****************************************************************************************************

int getChoice();
void handleMenu(ifstream & fin);
void displayFirstFive(ifstream & fin);
void displayLastFive(ifstream & fin);
int count(ifstream & fin);
void copyToFile(ifstream & fin , ofstream & fout);
void search(ifstream & fin);

//*****************************************************************************************************

int main() {
    ifstream fin;
    fin.open("names.txt");
    if(!fin)
    {
        cout << "File cannot be opened.";
        return 0;
    }
    handleMenu(fin);
    
    fin.close();
    return 0;
}

//*****************************************************************************************************

int getChoice()
{
    int option;
    const int DISPLAY_FIRST_FIVE = 1;
    const int QUIT = 6;
    do{
        cout << string(40, '*') << endl;
        cout << "1. Display first five names" << endl;
        cout << "2. Display last five names" << endl;
        cout << "3. Count the number of names" << endl;
        cout << "4. Copy names to names_copy.txt" << endl;
        cout << "5. Search for a name" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter you choice: ";
        cin >> option;
        if(option > QUIT || option < DISPLAY_FIRST_FIVE)
        {
            cout << "Try again" << endl;
        }
    }while(option > QUIT || option < DISPLAY_FIRST_FIVE);
    return option;
}

//*****************************************************************************************************

void handleMenu(ifstream & fin)
{
    int choice;
    const int DISPLAY_FIRST_FIVE = 1;
    const int DISPLAY_LAST_FIVE = 2;
    const int COUNT_NO_OF_NAME = 3;
    const int COPY_NAMES = 4;
    const int SEARCH_NAME = 5;
    const int QUIT = 6;
    ofstream fout;
    do{
        choice = getChoice();
        if(choice == DISPLAY_FIRST_FIVE)
            displayFirstFive(fin);
        else if(choice == DISPLAY_LAST_FIVE)
            displayLastFive(fin);
        else if(choice == COUNT_NO_OF_NAME)
            cout << "There are " << count(fin) << " names." << endl;
        else if(choice == COPY_NAMES)
        {
            fout.open("names_copy.txt");
            copyToFile(fin, fout);
            fout.close();
            cout << "Done!" << endl;
        }
        else if(choice == SEARCH_NAME)
        {
            cin.ignore();
            search(fin);
        }
    }while(choice != QUIT);
    if(choice == QUIT)
        cout << "Over!" << endl;
}

//*****************************************************************************************************

void displayFirstFive(ifstream & fin)
{
    fin.clear();
    fin.seekg(0L, ios::beg);
    char name[81];
    for(int i = 0; i < 5; i++)
    {
        fin.getline(name, 81);
        cout << i+1 << ": " << name << endl;
    }
}

//*****************************************************************************************************

void displayLastFive(ifstream & fin)
{
    fin.clear();
    fin.seekg(0L, ios::beg);
    int total = count(fin);
    fin.clear();
    fin.seekg(0L, ios::beg);
    char name[81];
    int start = total - 5;
    if(start < 0)
        start = 0;
    for(int i = 0; i < start; i++)
    {
        fin.getline(name, 81);
    }
    for(int i = start; i < total; i++)
    {
        fin.getline(name, 81);
        cout << i + 1 << ": " << name << endl;
    }
}

//*****************************************************************************************************

int count(ifstream & fin)
{
    fin.clear();
    fin.seekg(0L, ios::beg);
    char name[81];
    int sum = 0;
    while(fin.getline(name, 81))
    {
        sum++;
    }
    return sum;
}

//*****************************************************************************************************

void copyToFile(ifstream & fin , ofstream & fout)
{
    fin.clear();
    fin.seekg(0L, ios::beg);
    char name[81];
    while (fin.getline(name, 81))
    {
        fout << name << endl;
    }
}

//*****************************************************************************************************

void search(ifstream & fin)
{
    fin.clear();
    fin.seekg(0L, ios::beg);
    char name[81];
    char target[81];
    bool found = false;
    int line = 1;
    cout << "Enter a name so I can search for it: ";
    cin.get(target, 81);
    while(fin.getline(name, 81))
    {
        if(strcmp(name, target) == 0)
        {
            cout << "Found on line " << line << endl;
            found = true;
        }
        line++;
    }
    if(found == false)
        cout << "Not found" << endl;
}

//*****************************************************************************************************

/*
 ****************************************
 1. Display first five names
 2. Display last five names
 3. Count the number of names
 4. Copy names to names_copy.txt
 5. Search for a name
 6. Quit
 Enter you choice: 1
 1: Woodrow Holloway
 2: Andy Rodgers
 3: Jean Barker
 4: Lynda Hernandez
 5: Carol Diaz
 ****************************************
 1. Display first five names
 2. Display last five names
 3. Count the number of names
 4. Copy names to names_copy.txt
 5. Search for a name
 6. Quit
 Enter you choice: 2
 46: Emily Santos
 47: Cynthia Burton
 48: Noah Moreno
 49: Glenn Barnes
 50: Nancy Hicks
 ****************************************
 1. Display first five names
 2. Display last five names
 3. Count the number of names
 4. Copy names to names_copy.txt
 5. Search for a name
 6. Quit
 Enter you choice: 3
 There are 50 names.
 ****************************************
 1. Display first five names
 2. Display last five names
 3. Count the number of names
 4. Copy names to names_copy.txt
 5. Search for a name
 6. Quit
 Enter you choice: 4
 Done!
 ****************************************
 1. Display first five names
 2. Display last five names
 3. Count the number of names
 4. Copy names to names_copy.txt
 5. Search for a name
 6. Quit
 Enter you choice: 5
 Enter a name so I can search for it: Carol Diaz
 Found on line 5
 ****************************************
 1. Display first five names
 2. Display last five names
 3. Count the number of names
 4. Copy names to names_copy.txt
 5. Search for a name
 6. Quit
 Enter you choice: 5
 Enter a name so I can search for it: John Doe
 Not found
 ****************************************
 1. Display first five names
 2. Display last five names
 3. Count the number of names
 4. Copy names to names_copy.txt
 5. Search for a name
 6. Quit
 Enter you choice: 6
 Over!
 Program ended with exit code: 0
 */
