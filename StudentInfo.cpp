//*******************************************************************************************************
// Features custom data structures (structs), menu-driven interface design, and efficient record searching/editing.
//*******************************************************************************************************

#include <iostream>
#include<cstring>
#include<string>
using namespace std;

//************************************************************

const int NAME_SIZE = 81;
const int SIZE = 10;

//************************************************************

struct Students{
    char name[NAME_SIZE];
    int ID;
    double grade;
};

//************************************************************

void editStudent(Students students[], int size);
void viewStudent(const Students students[], int size);
void countStudent(const Students students[], int size);

//************************************************************

int main() {
    Students students[SIZE];
    const string line(60, '*');
    int option = 0;
    
    for(int i = 0; i < SIZE; i++)
    {
        strcpy(students[i].name, "-");
        students[i].ID = 0;
        students[i].grade = 0;
    }
    while(option != 4)
    {
        cout << line << endl;
        cout << "1)     Edit a Student" << endl;
        cout << "2)     View Student Info" << endl;
        cout << "3)     Display a Count of How Many Students are in the List" << endl;
        cout << "4)     Quit!" << endl;
        
        cout << "Please choose one of the options: ";
        cin >> option;
    
        while(option < 0 || option > 4)
        {
            cout << "Please choose an option between 1 to 4 ";
            cin >> option;
        }

        if(option == 1)
            editStudent(students, SIZE);
        else if(option == 2)
            viewStudent(students, SIZE);
        else if(option == 3)
            countStudent(students, SIZE);
    }
    
    cout << "Finished!" << endl;
    
    return 0;
}

//************************************************************

void editStudent(Students students[], int size)
{
    int index;
    
    cout << endl;
    cout << "Please enter an index: ";
    cin >> index;
    
    while(index < 0 || index >= size)
    {
        cout << "Please enter a valid index between 0 and 9";
        cin >> index;
    }
    
    cin.ignore();
    
    cout << "Please enter a name: ";
    cin.getline(students[index].name, NAME_SIZE);
    
    cout << "Please enter an ID: ";
    cin >> students[index].ID;
    
    cout << "Please enter a grade: ";
    cin >> students[index].grade;
    
    cout << endl;
}

//************************************************************

void viewStudent(const Students students[], int size)
{
    int index;
    
    cout << endl;
    cout << "Please enter an index: ";
    cin >> index;
    
    while(index < 0 || index >= size)
    {
        cout << "Please enter a valid index between 0 and 9";
        cin >> index;
    }
    
    while(strcmp(students[index].name, "-") == 0)
    {
        cout << "There is no student in that index, please re-enter: ";
        cin >> index;
    }
    
    cout << students[index].ID << ". "
    << students[index].name << " "
    << students[index].grade << endl;
}

//************************************************************

void countStudent(const Students students[], int size)
{
    int count = 0;
    
    for(int i = 0; i < size; i++)
    {
        if(strcmp(students[i].name, "-") != 0)
        {
            count ++;
        }
    }
    
    cout << endl;
    cout << "There are " << count << " students" << endl;
}

//************************************************************

/*
 ************************************************************
 1)     Edit a Student
 2)     View Student Info
 3)     Display a Count of How Many Students are in the List
 4)     Quit!
 Please choose one of the options: 5
 Please choose an option between 1 to 4 1

 Please enter an index: 1
 Please enter a name: John
 Please enter an ID: 1234
 Please enter a grade: 97

 ************************************************************
 1)     Edit a Student
 2)     View Student Info
 3)     Display a Count of How Many Students are in the List
 4)     Quit!
 Please choose one of the options: 2

 Please enter an index: 1
 1234. John 97
 ************************************************************
 1)     Edit a Student
 2)     View Student Info
 3)     Display a Count of How Many Students are in the List
 4)     Quit!
 Please choose one of the options: 2

 Please enter an index: 0
 There is no student in that index, please re-enter: 1
 1234. John 97
 ************************************************************
 1)     Edit a Student
 2)     View Student Info
 3)     Display a Count of How Many Students are in the List
 4)     Quit!
 Please choose one of the options: 3

 There are 1 students
 ************************************************************
 1)     Edit a Student
 2)     View Student Info
 3)     Display a Count of How Many Students are in the List
 4)     Quit!
 Please choose one of the options: 1

 Please enter an index: 4
 Please enter a name: Jane
 Please enter an ID: 234
 Please enter a grade: 59

 ************************************************************
 1)     Edit a Student
 2)     View Student Info
 3)     Display a Count of How Many Students are in the List
 4)     Quit!
 Please choose one of the options: 3

 There are 2 students
 ************************************************************
 1)     Edit a Student
 2)     View Student Info
 3)     Display a Count of How Many Students are in the List
 4)     Quit!
 Please choose one of the options: 4
 Finished!
 Program ended with exit code: 0
*/
