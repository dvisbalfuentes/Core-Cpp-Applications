//*******************************************************************************************************
// Utilizes pointer-to-pointer parameters, array sorting (Bubble Sort), and precision-based output formatting.
//*******************************************************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

//*****************************************************************************************************

void getAllData(int * pArray, int size);
double getAverage(const int * pArray, int size);
void displayAllValue(const int * pArray, int SIZE);
void swap(int *a, int *b);
void bubbleSort(int * const pArray, const int SIZE);

//*****************************************************************************************************

int main()
{
    const int SIZE = 10;
    int quizzes[SIZE];
    int *ptr = quizzes;
    
    getAllData(ptr, SIZE);
    displayAllValue(ptr, SIZE);
    cout << endl;
    cout << "The Average Is:"; 
    cout << getAverage(ptr, SIZE) << endl;
    bubbleSort(ptr, SIZE);
    cout << "After Sort, Display All Values: ";
    displayAllValue(ptr, SIZE);

    return 0;
}

//*****************************************************************************************************

void getAllData(int * pArray, int size)
{
    const int MIN = 0;
    const int MAX = 100;
    for(int i = 0; i < size; i++)
    {
        do{
            cout << "Quiz " << i + 1 << ": ";
            cin >> *(pArray + i);
            if (*(pArray + i) < MIN || *(pArray + i) > MAX)
            {
                cout << "!!!Grades cannot be less than 0 or more than 100" << endl;
            }
        }while(*(pArray + i) < MIN || *(pArray + i) > MAX);
    }
}

//*****************************************************************************************************

double getAverage(const int * pArray, int size)
{
    double sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += *pArray;
        *pArray++;
    }
    double avg = sum/size;
    return avg;
}

//*****************************************************************************************************

void displayAllValue(const int * pArray, int SIZE)
{
    cout << fixed << setprecision(2) << endl;
    cout << "Display All Values:" << endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << left << setw(5) << pArray[i];
        if((i + 1) % 5 == 0)
        {
            cout << endl;
        }
    }
}

//*****************************************************************************************************

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//*****************************************************************************************************

void bubbleSort(int * const pArray, const int SIZE)
{
    for(int i = 0; i < SIZE - 1; i++)
    {
        for(int j = 0; j < SIZE - i - 1; j++)
        {
            if(*(pArray + j ) > *(pArray + j + 1))
            {
                swap((pArray + j ), (pArray + j + 1));
            }
        }
    }
    
}

//*****************************************************************************************************

/* 
Quiz 1: 90
Quiz 2: -9
!!!Grades cannot be less than 0 or more than 100
Quiz 2: 91
Quiz 3: 89
Quiz 4: 105
!!!Grades cannot be less than 0 or more than 100
Quiz 4: 85
Quiz 5: 78
Quiz 6: 65
Quiz 7: 64
Quiz 8: 92
Quiz 9: 75
Quiz 10: 49

Display All Values:
90   91   89   85   78   
65   64   92   75   49   

The Average Is:77.80
After Sort, Display All Values: 
Display All Values:
49   64   65   75   78   
85   89   90   91   92 
*/
