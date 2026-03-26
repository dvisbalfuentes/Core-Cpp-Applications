//*******************************************************************************************************
// Demonstrates advanced C-string processing, pointer arithmetic, and manual array manipulation without standard library helpers.
//*******************************************************************************************************

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

//****************************************************************************************************

void convertToUpper(char * str);
void findAndRemove(char* str);
void appendAy(char* str);
void swap(char *a, char *b);
void reverse(char * str);
void convertPigLatin(char * str);
bool isQuitMessage(const char* str);
bool containsIG(const char* str);
void appendLength(char* str, int lenBeforeDigits);

//****************************************************************************************************

int main()
{
    const int SIZE = 181;
    char *str = new char[SIZE];

    convertPigLatin(str);

    delete[] str;
    str = nullptr;

    return 0;
}

//****************************************************************************************************

void convertToUpper(char * str)
{
    while (*str != '\0')
    {
        *str = static_cast<char>(toupper(static_cast<unsigned char>(*str)));
        str++;
    }
}

//****************************************************************************************************

void findAndRemove(char* str)
{
    while (*str != '\0')
    {
        char c1 = static_cast<char>(toupper(static_cast<unsigned char>(*str)));
        char c2 = static_cast<char>(toupper(static_cast<unsigned char>(*(str + 1))));

        if (c1 == 'I' && c2 == 'G')
        {
            *str = '\0';
            return;
        }
        str++;
    }
}

//****************************************************************************************************

void appendAy(char* str)
{
    while (*str != '\0')
    {
        str++;
    }
    *str = 'a';
    *(str + 1) = 'y';
    *(str + 2) = '\0';
}

//****************************************************************************************************

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

//****************************************************************************************************

void reverse(char * str)
{
    char *start = str;
    char *end = str;

    while (*end != '\0')
    {
        end++;
    }

    if (end > start)
    {
        end--;
    }

    while (start < end)
    {
        swap(start, end);
        start++;
        end--;
    }
}

//****************************************************************************************************

bool isQuitMessage(const char* str)
{
    const char* p = str;

    if (*p == '\0') return false;

    char q = static_cast<char>(toupper(static_cast<unsigned char>(*p))); p++;
    char u = static_cast<char>(toupper(static_cast<unsigned char>(*p))); p++;
    char i = static_cast<char>(toupper(static_cast<unsigned char>(*p))); p++;
    char t = static_cast<char>(toupper(static_cast<unsigned char>(*p))); p++;

    return (q == 'Q' && u == 'U' && i == 'I' && t == 'T' && *p == '\0');
}

//****************************************************************************************************

bool containsIG(const char* str)
{
    const char* p = str;
    while (*p != '\0')
    {
        char c1 = static_cast<char>(toupper(static_cast<unsigned char>(*p)));
        char c2 = static_cast<char>(toupper(static_cast<unsigned char>(*(p + 1))));
        if (c1 == 'I' && c2 == 'G')
        {
            return true;
        }
        p++;
    }
    return false;
}

//****************************************************************************************************

void appendLength(char* str, int lenBeforeDigits)
{
    char* endPtr = str;
    while (*endPtr != '\0')
    {
        endPtr++;
    }

    if (lenBeforeDigits >= 100)
    {
        *endPtr = static_cast<char>((lenBeforeDigits / 100) + '0'); endPtr++;
        *endPtr = static_cast<char>(((lenBeforeDigits / 10) % 10) + '0'); endPtr++;
        *endPtr = static_cast<char>((lenBeforeDigits % 10) + '0'); endPtr++;
    }
    else if (lenBeforeDigits >= 10)
    {
        *endPtr = static_cast<char>((lenBeforeDigits / 10) + '0'); endPtr++;
        *endPtr = static_cast<char>((lenBeforeDigits % 10) + '0'); endPtr++;
    }
    else
    {
        *endPtr = static_cast<char>(lenBeforeDigits + '0'); endPtr++;
    }

    *endPtr = '\0';
}

//****************************************************************************************************

void convertPigLatin(char * str)
{
    const int SIZE = 181;

    while (true)
    {
        cout << "Enter a string, enter quit to stop the process ";
        cin.getline(str, SIZE);

        if (isQuitMessage(str))
        {
            cout << "Quit!" << endl;
            return;
        }

        convertToUpper(str);
        findAndRemove(str);
        appendAy(str);
        reverse(str);

        int lenBeforeDigits = static_cast<int>(strlen(str));
        appendLength(str, lenBeforeDigits);

        cout << str << endl;
    }
    cout << endl;
}

//****************************************************************************************************


/* 
Enter a string, enter quit to stop the process night
yaN3
Enter a string, enter quit to stop the process niGHT
yaN3
Enter a string, enter quit to stop the process no ig here
ya ON5
Enter a string, enter quit to stop the process no i-g here
yaEREH G-I ON13
Enter a string, enter quit to stop the process First they ignore you, then they laugh at you, then they fight you, then you win.
ya YEHT TSRIF13
Enter a string, enter quit to stop the process then they fight you, then you win.
yaF YEHT NEHT13
Enter a string, enter quit to stop the process over
yaREVO6
Enter a string, enter quit to stop the process quit
Quit!
*/
