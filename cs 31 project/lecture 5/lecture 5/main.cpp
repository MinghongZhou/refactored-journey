

#include <iostream>
using namespace std;

int main()
{
    const double PAYRATE_THRESHOLD = 12.00;
    const double HIGH_WITHHOLDING_RATE = 0.10;
    const double LOW_WITHHODING_RATE = 0.05;
    
    
    
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
    
    double withholdingRate;
    
    if (payRate >= PAYRATE_THRESHOLD)
        withholdingRate = HIGH_WITHHOLDING_RATE;
    else
        withholdingRate = LOW_WITHHODING_RATE;
    
    
    if(payRate >= 12.00)
        withholdingRate = 0.10;
    else
        withholdingRate = 0.05;
        cout << "$" << (withholdingRate * amtEarned) << "will be withheld." << endl;
}
