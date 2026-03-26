//*******************************************************************************************************
// Showcases dynamic memory allocation using the new operator, pointer-based array navigation, and sorting algorithms.		
//*******************************************************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

//*****************************************************************************************************

int * getData (int size);
int getAverage(const int * ptr, int
size);
void displayForward(const int * ptr, int
size);
int getMax(const int * ptr, int size);
void displayBackward(const int * ptr, int
size);
void swap(int *a, int *b);
void bubbleSort(int *ptr, int size);

//*****************************************************************************************************

int main()
{
    const int SIZE = 16;
    int * ptr = nullptr;
    int max = 0;
    int avg= 0;
    
    ptr = getData(SIZE);
    
    avg = getAverage(ptr, SIZE);
    max = getMax(ptr, SIZE);
    
    cout << "display forward:" << endl;
    displayForward(ptr, SIZE);
    cout << endl;
    cout << "display backwards:" << endl;
    displayBackward(ptr, SIZE);
    cout << endl;
    cout << "average is: " << avg << endl;
    cout << "max is: " << max << endl;
    bubbleSort(ptr, SIZE);
    cout << "after sorting, display forward:" << endl;
    displayForward(ptr, SIZE);
    cout << endl;
    cout << "after sorting, display backwards: " << endl;
    displayBackward(ptr, SIZE);
    cout << endl;

    return 0;
}

//*****************************************************************************************************

int * getData (int size)
{
    int * pCity = nullptr;
    pCity = new int[size];
    for(int i = 0; i < size; i++)
    {
        cout << "Enter population for city " << i + 1 << ": ";
        cin >> *(pCity + i);
    }
    return pCity;
}

//*****************************************************************************************************

int getAverage(const int * ptr, int
size)
{
    double sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += *ptr;
        ptr++;
    }
    
    return static_cast<int>(sum/size);
}

//*****************************************************************************************************

void displayForward(const int * ptr, int
size)
{
    int count = 1;
    for(int i = 0; i < size; i++)
    {
        cout << left << setw(10) << *(ptr + i) << " ";
        
        if(count % 4 == 0)
        {
            cout << endl;
        }
        count ++;
    }
}

//*****************************************************************************************************

int getMax(const int * ptr, int size)
{
    int max = *ptr;
    for(int i = 1; i < size; i++)
    {
        if(*(ptr + i) > max)
        {
            max = *(ptr + i);
        }
    }
    return max;
}

//*****************************************************************************************************

void displayBackward(const int * ptr, int
size)
{
    int count = 1;
    for(int i = size - 1; i >=0; i--)
    {
        cout << left << setw(10) << *(ptr + i) << " ";
        
        if(count % 4 == 0)
        {
            cout << endl;
        }
        count ++;
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

void bubbleSort(int *ptr, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(*(ptr + j) > *(ptr + j + 1))
            {
                swap((ptr + j), (ptr + j + 1));
            }
        }
    }
}

//*****************************************************************************************************

/*Enter population for city 1: 860090
Enter population for city 2: 2704958
Enter population for city 3: 855164
Enter population for city 4: 264488
Enter population for city 5: 672795
Enter population for city 6: 481420
Enter population for city 7: 446970
Enter population for city 8: 595047
Enter population for city 9: 298800
Enter population for city 10: 413651
Enter population for city 11: 388072
Enter population for city 12: 389902
Enter population for city 13: 311404
Enter population for city 14: 302398
Enter population for city 15: 280364
Enter population for city 16: 279789
display forward:
860090     2704958    855164     264488     
672795     481420     446970     595047     
298800     413651     388072     389902     
311404     302398     280364     279789     

display backwards:
279789     280364     302398     311404     
389902     388072     413651     298800     
595047     446970     481420     672795     
264488     855164     2704958    860090     

average is: 596582
max is: 2704958
after sorting, display forward:
264488     279789     280364     298800     
302398     311404     388072     389902     
413651     446970     481420     595047     
672795     855164     860090     2704958    

after sorting, display backwards: 
2704958    860090     855164     672795     
595047     481420     446970     413651     
389902     388072     311404     302398     
298800     280364     279789     264488     



...Program finished with exit code 0
Press ENTER to exit console. /*
