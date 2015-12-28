
#include "grid.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;



bool isRouteWellFormed(string route);

int navigateSegment(int r, int c, char dir, int maxSteps);

int navigateRoute(int sr, int sc, int er, int ec, string route, int& nsteps);

void makemaze()
{
    //   123456789012
    // 1 ............
    // 2 ......*.....
    // 3 ............
    // 4 ..*.........
    // 5 ......*.....
    
    setSize(5,12);
    setWall(4,3);
    setWall(2,7);
    setWall(5,7);
}

void testone(int n)
{
    int ns = 0;
    switch (n)
    {
        default: {
            cout << "Bad argument" << endl;
        } break; case  1: {
            assert(isRouteWellFormed(""));
        } break; case  2: {
            assert(!isRouteWellFormed("x"));
        } break; case  3: {
            assert(!isRouteWellFormed("3"));
        } break; case  4: {
            assert(!isRouteWellFormed("@"));
        } break; case  5: {
            assert(!isRouteWellFormed("x1"));
        } break; case  6: {
            assert(!isRouteWellFormed("12"));
        } break; case  7: {
            assert(isRouteWellFormed("E03"));
        } break; case  8: {
            assert(!isRouteWellFormed("E003"));
        } break; case  9: {
            assert(!isRouteWellFormed("n1#"));
        } break; case 10: {
            assert(isRouteWellFormed("W"));
        } break; case 11: {
            assert(isRouteWellFormed("e2"));
        } break; case 12: {
            assert(isRouteWellFormed("N10"));
        } break; case 13: {
            assert(isRouteWellFormed("n98"));
        } break; case 14: {
            assert(isRouteWellFormed("SW"));
        } break; case 15: {
            assert(isRouteWellFormed("S1W"));
        } break; case 16: {
            assert(isRouteWellFormed("SW1"));
        } break; case 17: {
            assert(isRouteWellFormed("S1W2"));
        } break; case 18: {
            assert(isRouteWellFormed("s12w3"));
        } break; case 19: {
            assert(isRouteWellFormed("n1e12"));
        } break; case 20: {
            assert(isRouteWellFormed("n12e12"));
        } break; case 21: {
            assert(isRouteWellFormed("n1e12s"));
        } break; case 22: {
            assert(!isRouteWellFormed("n12n12x"));
        } break; case 23: {
            assert(!isRouteWellFormed("n12n12x1"));
        } break; case 24: {
            assert(!isRouteWellFormed("n12e12sx"));
        } break; case 25: {
            makemaze();
            assert(navigateSegment(0,4,'S',2) == -1);
        } break; case 26: {
            makemaze();
            assert(navigateSegment(6,4,'N',2) == -1);
        } break; case 27: {
            makemaze();
            assert(navigateSegment(3,0,'E',2) == -1);
        } break; case 28: {
            makemaze();
            assert(navigateSegment(3,13,'W',2) == -1);
        } break; case 29: {
            makemaze();
            assert(navigateSegment(4,3,'E',2) == -1);
        } break; case 30: {
            makemaze();
            assert(navigateSegment(3,4,'E',-1) <= 0);
        } break; case 31: {
            makemaze();
            assert(navigateSegment(3,4,'E',0) == 0);
        } break; case 32: {
            makemaze();
            assert(navigateSegment(3,4,'e',2) == 2);
        } break; case 33: {
            makemaze();
            assert(navigateSegment(1,3,'s',2) == 2);
        } break; case 34: {
            makemaze();
            assert(navigateSegment(1,3,'w',2) == 2);
        } break; case 35: {
            makemaze();
            assert(navigateSegment(3,7,'n',0) == 0);
        } break; case 36: {
            makemaze();
            assert(navigateSegment(3,7,'E',2) == 2);
        } break; case 37: {
            makemaze();
            assert(navigateSegment(3,6,'S',2) == 2);
        } break; case 38: {
            makemaze();
            assert(navigateSegment(3,6,'N',2) == 2);
        } break; case 39: {
            makemaze();
            assert(navigateSegment(2,3,'S',3) == 1);
        } break; case 40: {
            makemaze();
            assert(navigateSegment(2,8,'W',3) == 0);
        } break; case 41: {
            makemaze();
            assert(navigateSegment(4,7,'N',2) == 1);
        } break; case 42: {
            makemaze();
            assert(navigateSegment(2,3,'E',8) == 3);
        } break; case 43: {
            makemaze();
            assert(navigateSegment(4,5,'W',8) == 1);
        } break; case 44: {
            makemaze();
            assert(navigateSegment(3,4,'W',4) == 3);
        } break; case 45: {
            makemaze();
            assert(navigateSegment(3,4,'e',10) == 8);
        } break; case 46: {
            makemaze();
            assert(navigateSegment(3,4,'S',3) == 2);
        } break; case 47: {
            makemaze();
            assert(navigateSegment(3,4,'N',4) == 2);
        } break; case 48: {
            makemaze();
            assert(navigateRoute(0,4,1,4,"s",ns) == 2);
        } break; case 49: {
            makemaze();
            assert(navigateRoute(1,13,1,12,"w",ns) == 2);
        } break; case 50: {
            makemaze();
            assert(navigateRoute(5,2,6,2,"s",ns) == 2);
        } break; case 51: {
            makemaze();
            assert(navigateRoute(2,7,2,6,"w",ns) == 2);
        } break; case 52: {
            makemaze();
            assert(navigateRoute(3,4,2,4,"?",ns) == 2);
        } break; case 53: {
            makemaze();
            assert(navigateRoute(2,6,2,7,"E",ns) == 2);
        } break; case 54: {
            makemaze();
            ns = 999;
            navigateRoute(2,6,2,7,"E",ns);
            assert(ns == 999);
        } break; case 55: {
            makemaze();
            assert(navigateRoute(4,7,1,7,"n3",ns) == 3  &&  ns == 1);
        } break; case 56: {
            makemaze();
            assert(navigateRoute(4,6,2,8,"n2e2",ns) == 3  &&  ns == 2);
        } break; case 57: {
            makemaze();
            assert(navigateRoute(4,5,2,8,"n2e3",ns) == 3  &&  ns == 3);
        } break; case 58: {
            makemaze();
            assert(navigateRoute(3,11,4,5,"e2sw3",ns) == 3  &&  ns == 1);
        } break; case 59: {
            makemaze();
            assert(navigateRoute(5,11,4,5,"N2E2SW3",ns) == 3  &&  ns == 3);
        } break; case 60: {
            makemaze();
            assert(navigateRoute(4,4,4,4,"EW2",ns) == 3  &&  ns == 2);
        } break; case 61: {
            makemaze();
            assert(navigateRoute(4,5,5,4,"s2",ns) == 3  &&  ns == 1);
        } break; case 62: {
            makemaze();
            ns = 999;
            navigateRoute(4,5,5,4,"s2",ns);
            assert(ns == 1);
        } break; case 63: {
            makemaze();
            assert(navigateRoute(5,3,5,4,"",ns) == 1  &&  ns == 0);
        } break; case 64: {
            makemaze();
            assert(navigateRoute(5,3,5,3,"",ns) == 0  &&  ns == 0);
        } break; case 65: {
            makemaze();
            assert(navigateRoute(2,1,2,4,"E3",ns) == 0  &&  ns == 3);
        } break; case 66: {
            makemaze();
            assert(navigateRoute(2,1,2,3,"E3",ns) == 1  &&  ns == 3);
        } break; case 67: {
            makemaze();
            assert(navigateRoute(2,1,2,5,"E3",ns) == 1  &&  ns == 3);
        } break; case 68: {
            makemaze();
            assert(navigateRoute(5,3,5,3,"E",ns) == 1  &&  ns == 1);
        } break; case 69: {
            makemaze();
            ns = 999;
            navigateRoute(5,3,5,3,"E",ns);
            assert(ns == 1);
        } break; case 70: {
            makemaze();
            assert(navigateRoute(5,3,2,8,"E2NE3N2",ns) == 0  &&  ns == 8);
        } break; case 71: {
            makemaze();
            assert(navigateRoute(5,3,2,8,"E2NE3N3",ns) == 1  &&  ns == 9);
        }
    }
}

int main()
{
    cout << "Enter test number: ";
    int n;
    cin >> n;
    testone(n);
    cout << "Passed!" << endl;
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

