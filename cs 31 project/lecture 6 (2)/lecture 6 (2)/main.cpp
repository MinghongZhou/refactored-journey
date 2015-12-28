
#include <iostream>
# include <string>
using namespace std;

int main()
{
    cout << "How many times do you want to be greeted?";
    int nTimes;
    cin >> nTimes;
    
    int k = 0;
    while (k < nTimes)
    {
        cout << "Hello" << endl;
        k = k + 1;
    }

}
