
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Units sent: ";
    int unitsSent;
    cin >> unitsSent;
    cin.ignore(10000, '\n'); // ask the user to input units sent
   
    cout << "Title: ";
    string title;
    getline(cin, title); // ask the user to input title
    
    cout << "Base price: ";
    double basePrice;
    cin >> basePrice;
    cin. ignore(10000, '\n'); // ask the user to input base price
    
    
    cout << "Premium item? (y/n): ";
    string yesOrNo;
    getline(cin, yesOrNo); // ask the user to input y/n
    
    cout << "---" << endl;
    
    cout.setf(ios::fixed);
    cout.precision(2);
    
    double amtEarned;
    
    if(unitsSent < 0 || title == "" || basePrice < 0 || (yesOrNo != "y" && yesOrNo != "n"))
    {if(unitsSent < 0)
        cout << "The number of units sent must be nonnegative." << endl;
    else
         {if(title == "")
        cout << "You must enter a title." << endl;
    else
              {if(basePrice < 0)
        cout << "The base price must be nonnegative." << endl;
    else
                 {if (yesOrNo != "y" && yesOrNo != "n")
        cout << "You must enter y or n." << endl;
                 }
              }
         }
    } // cases in which incorrect inputs have been given to the operating system
    
    else
     {
        {if(unitsSent <= 400)
          {amtEarned = 0.09 * basePrice * unitsSent;
            cout << title << " earned $" << amtEarned << " in royalties." << endl;
          }
        } // when the units sent is less or equal to 400
        
        
        {if(unitsSent > 400 && unitsSent <= 1200)
          {if(yesOrNo == "n")
             {amtEarned = (36 + (unitsSent - 400) * 0.13 ) * basePrice;
            cout << title << " earned $" << amtEarned << " in royalties." << endl;
             }
        else
            {amtEarned = (36 + (unitsSent - 400) * 0.16 ) * basePrice;
            cout << title << " earned $" << amtEarned << " in royalties." << endl;
            }
            
          }
        } // when the units sent is greater than 400 and less or equal to 1200
        
        
        {if(unitsSent > 1200)
          {if(yesOrNo == "n")
              {amtEarned = (140 + (unitsSent - 1200) * 0.14) * basePrice;
               cout << title << " earned $" << amtEarned << " in royalties." << endl;
              }
        else
            {amtEarned = (164 + (unitsSent - 1200) * 0.14) * basePrice;
            cout << title << " earned $" << amtEarned << " in royalties." << endl;
            }
            
          }
        } // when the units sent is greater than 1200
     }
   
    }
  