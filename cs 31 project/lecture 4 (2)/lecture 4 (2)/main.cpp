#include <iostream>
#include <string>
using namespace std;

int main ()
{
    cout << "what is your name? ";
    string personsName;
    getline(cin, personsName); // input source (cin), name of the string variable. Can not be used on int or double

    cout << "How old are you? ";
    int age;
    cin >> age;
    cin. ignore(10000, '\n'); // needed becuase after reading a number, the next thing we will read is a string using       getline
    
    cout << "what is your quest? ";
    string quest;
    getline(cin, quest);
    
    cout << "Hello, brave " << personsName << "!" << endl;
    cout << "You want " << quest << endl;
    cout << "if you live, next year you will be " << age << endl;
}


