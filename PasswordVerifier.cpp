//*******************************************************************************************************
//Implements complex boolean logic, character-level string parsing, and robust input validation loops.
//*******************************************************************************************************

#include <iostream>
#include<string>

using namespace std;

//*****************************************************************************************************

void getInput(string & password);
bool checkLength(string password);
bool checkCase(string password);
bool checkDigit(string password);
bool checkAlpha(string password);
bool checkSymbol(string password);
bool checkWhiteSpace(string password);

//*****************************************************************************************************

int main()
{
    string password;
    bool isValid;
    do{
        cout << "****************************************************" << endl;
        getInput(password);
        bool passLen = checkLength(password);
        bool passCase = checkCase(password);
        bool passDigit = checkDigit(password);
        bool passAlpha = checkAlpha(password);
        bool passSymbol = checkSymbol(password);
        bool passSpace = checkWhiteSpace(password);
        if(passLen == true && passCase == true && passDigit == true && passAlpha == true && passSymbol == true && passSpace == true)
        {
            isValid = true;
        }
        else
        {
            isValid = false;
        }
        cout << endl;
    }while(isValid == false);
    
    cout << "You have successfully entered a password" << endl;
    cout << "The password you've entered is: " << password << endl;
    
    return 0;
}

//*****************************************************************************************************

void getInput(string & password)
{
    cout << "Please enter a valid password:" << endl;
    getline(cin, password);
}

//*****************************************************************************************************

bool checkLength(string password)
{
    const int MIN_LENGTH = 8;
    const int MAX_LENGTH = 20;
    int len = password.length();
    if(len < MIN_LENGTH)
    {
        cout << "!!!Error!!! Input is too short" << endl;
        return false;
    }
    else if(len > MAX_LENGTH)
    {
        cout << "!!!Error!!! Input is too long" << endl;
        return false;
    }
    else
    return true;
}

//*****************************************************************************************************

bool checkCase(string password)
{
    bool hasUpper = false;
    bool hasLower = false;
    for(int i = 0; i < password.length(); i++)
    {
        if (isupper(password[i]))
        {
            hasUpper = true;
        }
        if (islower(password[i]))
        {
            hasLower = true;
        }
    }
    
    if(hasUpper == false)
    {
        cout << "!!!Error!!! Input doesn't contain an upper case letter" << endl;
    }
    if(hasLower == false)
    {
        cout << "!!!Error!!! Input doesn't contain a lower case letter" << endl;
    }
    if(hasUpper == true && hasLower == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//*****************************************************************************************************

bool checkDigit(string password)
{
    bool hasDigit = false;
    for(int i = 0; i < password.length(); i++)
    {
        if(isdigit(password[i]))
        {
            hasDigit = true;

        }
    }
    if(hasDigit == false)
    {
        cout << "!!!Error!!! Input doesn't contain a digit" << endl;
        return false;
    }
    return true;
}

//*****************************************************************************************************

bool checkAlpha(string password)
{
    bool hasAlpha = false;
    for(int i = 0; i < password.length(); i++)
    {
        if(isalpha(password[i]))
        {
            hasAlpha = true;
        }
    }
    if(hasAlpha == false)
    {
        cout << "!!!Error!!! Input doesn't contain an alphabet" << endl;
        return false;
    }
    return true;
}

//*****************************************************************************************************

bool checkSymbol(string password)
{
    bool hasSymb = false;
    for(int i = 0; i < password.length(); i++)
    {
        if(!isalnum(password[i]))
        {
            hasSymb = true;
        }
    }
    if(hasSymb == false)
    {
        cout << "!!!Error!!! The password doesn't contain at least one symbol" << endl;
        return false;
    }
    return true;
}

//*****************************************************************************************************

bool checkWhiteSpace(string password)
{
    bool hasSpace = false;
    for(int i = 0; i < password.length(); i++)
    {
        if(isspace(password[i]))
        {
            hasSpace = true;
        }
    }
        if(hasSpace == true)
        {
            cout << "!!!Error!!! Input cannot contain a white space" << endl;
            return false;
        }
        return true;
}

//*****************************************************************************************************

/* ****************************************************
Please enter a valid password:
123
!!!Error!!! Input is too short
!!!Error!!! Input doesn't contain an upper case letter
!!!Error!!! Input doesn't contain a lower case letter
!!!Error!!! Input doesn't contain an alphabet
!!!Error!!! The password doesn't contain at least one symbol

****************************************************
Please enter a valid password:
password
!!!Error!!! Input doesn't contain an upper case letter
!!!Error!!! Input doesn't contain a digit
!!!Error!!! The password doesn't contain at least one symbol

****************************************************
Please enter a valid password:
password1
!!!Error!!! Input doesn't contain an upper case letter
!!!Error!!! The password doesn't contain at least one symbol

****************************************************
Please enter a valid password:
Password1
!!!Error!!! The password doesn't contain at least one symbol

****************************************************
Please enter a valid password:
Password 1
!!!Error!!! Input cannot contain a white space

****************************************************
Please enter a valid password:
Password1#

You have successfully entered a password
The password you've entered is: Password1#


...Program finished with exit code 0
Press ENTER to exit console. /*
