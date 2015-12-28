

#include <iostream>
# include <string>
using namespace std;

int main()
{
    double income;
    if (income < 30000)
        cout << "Low";
    else
    {
        if (income < 80000) // don't need the condition income >= 30000. We couldn't get here if it were false
            cout << "Middle";
        else
        {
            if (income <= 200000)
                cout << "High";
            else
                cout << "very high";
        }
    }
}

