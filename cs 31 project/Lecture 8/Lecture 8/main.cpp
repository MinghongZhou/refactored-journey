#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isValidPhoneNumber(string pn);
string digitsOf(string s);

int main()
{
       cout << "Enter a phone number: ";
    string phone;
    getline(cin, phone);
    if( isValidPhoneNumber(phone))
        cout << "The digits in the number are " << digitsOf (phone) << endl;
    else
        cout << "A phone number must have 10 digits." << endl;
}

bool isValidphoneNumber(string pn)
{
    int numberOfDigits = 0;
    for (int k = 0; k != pn.size(); k++)
    {
        if (isdigit(pn[k]))
            numberOfDigits++;
    }
    return   numberOfDigits == 10;  // if the function is not void, make sure every execution hit the bottom with a return
}

string digitsOf (string s)
{
    string  digitsOnly = "";
    for (int k = 0; k != s.size(); k++)
    {
        if(isdigit(s[k]))
            digitsOnly += s[k]; // take the current value of the digitsOnly string and add one charachter befre put it          back to the original string
    }
    return digitsOnly;
}