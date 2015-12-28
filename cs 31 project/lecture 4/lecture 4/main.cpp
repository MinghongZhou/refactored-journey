

#include <iostream>
using namespace std;

int main()
{
    cout << "How many hours did you work? ";
    double hoursworked;
    cin >> hoursworked;
    cout << "You entered the value " << hoursworked << endl;

    cout << "What is your hourly rate of pay? ";
    double payRate;
    cin >> payRate;
    
    double amtEarned = hoursworked * payRate;
    
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "you earned $" << amtEarned << endl;
    cout << "$" << (0.10 * amtEarned) << " will be withheld." << endl;
}
