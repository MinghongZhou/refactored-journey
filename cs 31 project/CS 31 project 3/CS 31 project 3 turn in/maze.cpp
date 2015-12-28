
#include "grid.h"
#include <iostream>
#include <string>
#include <cctype>
using namespace std;



bool isRouteWellFormed(string route);

int navigateSegment(int r, int c, char dir, int maxSteps);

int navigateRoute(int sr, int sc, int er, int ec, string route, int& nsteps);

int main()
{
    setSize(3,4);
    setWall(1,4);
    setWall(2,2);
    setWall(3,2);
    if (isRouteWellFormed("n2e1"))
        cout << "Passed test 1: isRouteWellFormed(\"n2e1\")" << endl;
    if (!isRouteWellFormed("e1x"))
        cout << "Passed test 2: !isRouteWellFormed(\"e1x\")" << endl;
    if (navigateSegment(3, 1, 'N', 2) == 2)
        cout << "Passed test 3: navigateSegment(3, 1, 'N', 2)" << endl;
    int len;
    len = -999;  // so we can detect whether navigateRoute sets len
    if (navigateRoute(3,1, 3,4, "N2eE01n0s2e1", len) == 0  &&  len == 7)
        cout << "Passed test 4: navigateRoute(3,1, 3,4, \"N2eE01n0s2e1\", len)" << endl;
    len = -999;  // so we can detect whether navigateRoute sets len
    if (navigateRoute(3,1, 3,4, "e1x", len) == 2  &&  len == -999)
        cout << "Passed test 5: navigateRoute(3,1, 3,4, \"e1x\", len)" << endl;
}



bool isRouteWellFormed(string route)

{
    // test whether or not the first character is digit
    if (isdigit(route[0]))
        return false;
    // visit every single character of the string
    else for (int i = 0 ; i != route.size() ; i++ )
    {
        // test whether string contains charcters that are neither digits nor letters
        if (!isalpha(route[i]) && !isdigit(route[i]))
            return false;
        // test whether string contains invalid letters for direction
        else if (isalpha(route[i]))
        {if (route[i] != 'N' && route[i] != 'E' && route[i] != 'S' && route[i] != 'W' && route[i] != 'n' && route[i] != 'e' && route[i] != 's' && route[i] != 'w' )
            return false;
            // test whether string contains movement more than two digits
        else if (isdigit(route[i+1]) && isdigit(route[i+2]) && isdigit(route[i+3]))
            return false;
        }
    }
    return true;
}


int navigateSegment(int r, int c, char dir, int maxSteps)
{
    // if the input is invalid, return -1
    if ( r > getRows() || c > getCols()|| isWall(r,c)|| maxSteps < 0 || (dir != 'N' && dir != 'n' && dir != 'S' && dir != 's' && dir != 'W' && dir != 'w' && dir != 'E' && dir != 'e' ) )
        return -1;
    
    else
    {
        char lowerDir = tolower(dir);
        int Steps = 0;
        
        // test the case where direction is north
        if (lowerDir == 'n')
        {for (int i = 0; i != maxSteps; i++)
            if ((r - i - 1) >= 1 && !isWall (r - i - 1, c))
                Steps ++;
            else
                return Steps;
        }
        
        // test the case where direction is south
        if (lowerDir == 's')
        {for (int i = 0; i != maxSteps; i++)
            if ((r + i + 1) <= getRows() && !isWall (r + i + 1, c))
                Steps ++;
            else
                return Steps;
        }
        
        // test the case where direction is west
        if (lowerDir == 'w')
        {for (int i = 0; i != maxSteps; i++)
            if ((c - i - 1) >= 1 && !isWall (r, c - i - 1))
                Steps ++;
            else
                return Steps;
        }
        
        // test the case where direction is east
        if (lowerDir == 'e')
        {for (int i = 0; i != maxSteps; i++)
            if ((c + i + 1) <= getCols() && !isWall (r, c + i + 1))
                Steps ++;
            else
                return Steps;
        }
        
        // if the robot does not hit a wall or invalid grid, program return the maxSteps
    } return maxSteps;
    
}



int navigateRoute(int sr, int sc, int er, int ec, string route, int& nsteps)
{
    // If (sr,sc) or (er,ec) are not valid empty grid positions or if route is not syntactically valid, the function returns 2 and leaves nsteps unchanged.
    
    int maxSteps = 0; // steps taken in one movement
    int r = sr;
    int c = sc;
    
    if (isRouteWellFormed(route) && sr <= getRows() && sc <= getCols() && !isWall(sr,sc) && er <= getRows() && ec <= getCols() && !isWall(er,ec))
    {
        nsteps = 0;
        for (int k = 0; k != route.size(); k++)
          {
            
            if (isalpha(route[k]))
            {
                int numberOfDigits = 0;
                // check how many digits there are after the letter
                {if (!isdigit(route[k + 1]))
                    numberOfDigits = 0;
                    
                else if (isdigit(route[k + 2]))
                    numberOfDigits = 2;
                    
                else numberOfDigits = 1;
                    
                }
                // convert digits to maxSteps
                switch (numberOfDigits)
                {
                    case 1:
                        maxSteps = route[k + 1] - '0';
                        break;
                    case 2:
                        maxSteps = (route[k + 1] - '0') * 10 + (route[k + 2] - '0');
                        break;
                    default: maxSteps = 1;
                        break;
                }
                 // add steps in one movement to total steps taken. If the robot runs into a wall, set nsteps to the steps taken before hitting the wall and end the program.
                
                if (maxSteps == navigateSegment(r, c, route[k], maxSteps) )
                    nsteps += navigateSegment(r, c, route[k], maxSteps);
                else
                {nsteps += navigateSegment(r, c, route[k], maxSteps);
                    return 3;
                }

                // move the robot to new starting position
                    if ( route[k] == 'n' || route[k] == 'N')
                        r -= navigateSegment(r, c, route[k], maxSteps);
                    if ( route[k] == 's' || route[k] == 'S')
                        r += navigateSegment(r, c, route[k], maxSteps);
                    if ( route[k] == 'e' || route[k] == 'E')
                        c += navigateSegment(r, c, route[k], maxSteps);
                    if ( route[k] == 'w' || route[k] == 'W')
                        c -= navigateSegment(r, c, route[k], maxSteps);
             
            }
              
        }// check wether the robot ends up at the designated end point.
            if (r != er || c != ec)
                return 1;
        // if route is complete, end the program.
       else
           return 0;
    }
    // if route is invalid end the program.
    else return 2;
    
}

