#include <iostream>
#include <string>
#include <cassert>


using namespace std;

int appendToAll(string a[], int n, string value);

int lookup(const string a[], int n, string target);

int positionOfMax(const string a[], int n);

int rotateLeft(string a[], int n, int pos);

int countRuns(const string a[], int n);

int flip(string a[], int n);

int differ(const string a1[], int n1, const string a2[], int n2);

int subsequence(const string a1[], int n1, const string a2[], int n2);

int lookupAny(const string a1[], int n1, const string a2[], int n2);

int split(string a[], int n, string splitter);

int main()
{
    
    string h[7] = { "bernie", "hillary", "donald", "jeb", "", "carly", "ben" };
    assert(lookup(h, 7, "carly") == 5);
    assert(lookup(h, 7, "donald") == 2);
    assert(lookup(h, 2, "donald") == -1);
    assert(positionOfMax(h, 7) == 3);
    
    string g[4] = { "bernie", "hillary", "jeb", "carly" };
    assert(differ(h, 4, g, 4) == 2);
    assert(appendToAll(g, 4, "?") == 4 && g[0] == "bernie?" && g[3] == "carly?");
    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "jeb?" && g[3] == "hillary?");
    
    string e[4] = { "donald", "jeb", "", "carly" };
    assert(subsequence(h, 7, e, 4) == 2);
    
    string d[5] = { "hillary", "hillary", "hillary", "ben", "ben" };
    assert(countRuns(d, 5) == 2);
    
    string f[3] = { "jeb", "donald", "marco" };
    assert(lookupAny(h, 7, f, 3) == 2);
    assert(flip(f, 3) == 3 && f[0] == "marco" && f[2] == "jeb");
    
    assert(split(h, 7, "carly") == 3);
    
    cout << "All tests succeeded" << endl;}

int appendToAll(string a[], int n, string value)
{
    // if n < 0, return -1.
    if(n < 0)
        return -1;
    //go through each element and append the value string.
    else for (int k = 0; k < n; k++)
        a[k] = a[k] + value;
    return n;
    
}


int lookup(const string a[], int n, string target)
{
    if (n < 0)
        return -1;
    else
        // go through each element. If target is found, return position. If not, return -1.
    { for (int k = 0; k < n; k++)
    {if (a[k] == target)
        return k;
    }
        return -1;
    }
}

int positionOfMax(const string a[], int n)
{
    int k;
    bool largest = true;
    if (n < 0)
        return -1;
    else
    {
        // visit each item
        for (k = 0; k < n; k++)
        {
            // compare it to other items in the array
            for (int i = 0; i < n; i++)
            {
                // if this item is smaller than any item in the array, the statement that it's the largest is false
                if (a[k] < a[i])
                    largest = false;
            }
            // if this item is not the largest, move on to the next item.
            if (largest == false)
                largest = true;
            else break;
        }return k;
        
    }
}

int rotateLeft(string a[], int n, int pos)
{
    string target;
    if (n < 0 || n <= pos)
        return -1;
    else
    {
        // store the element of the target position in a new string target
        target = a[pos];
        // move everything after target position left for 1 spot
        for (int i = 0; i + pos < n - 1; i++ )
            a[pos+i] = a[pos+i+1];
        // set the last element to target
        a[n-1] = target;
    } return pos;
}

int countRuns(const string a[], int n)
{
    int count = 1;
    if (n < 0)
        return -1;
    // if we are interested in 0 items, there will be 0 sequence.
    if (n == 0)
        return 0;
    else
        for (int k = 0; k < n - 1; k++ )
        {
            // every time the two adjacent items are not equal, we have one more sequence.
            if(a[k] != a [k+1])
                count++;
        }
    return count;
}

int flip(string a[], int n)
{
    string copy;
    if (n < 0)
        return -1;
    else
        // switch the positions of the first term and the last term, then switch the positions of the second term and the second to last lerm. Keep performing this operation till we reach the elememts or element in the middle of the array.
        for (int k = 0; k < n/2; k++)
        {copy = a[k];
            a[k] = a[n-1-k];
            a[n-1-k] = copy;
        }
    return n;
}

int differ(const string a1[], int n1, const string a2[], int n2)
{
    int pos = 0;
    if (n1 < 0 || n2 < 0)
        return -1;
    else
        for (int k = 0; k < n1 && k < n2; k++)
        {if (a1[k] != a2[k])
        {pos = k;
            return pos;
        }
            
        }
    if (n1 <= n2)
        return n1;
    else return n2;
}

int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    bool match = true;
    if (n1 < 0 || n2 < 0 || n2 > n1)
        return -1;
    else
        // look for the first item that match
        for (int i = 0; i < n1; i++)
        {if (a2[0] == a1[i])
            // compare the subsequent items. If they all match, match is equal to true, otherwise false.
        {for (int k = 1; k < n2; k++)
        {if(a2[k] != a1 [i+k])
            match = false;
        }
            // if all items match return the position
            if (match == true)
                return i;
            match = true;
        }
        }
    return -1;
}

int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
    if (n1 < 0 || n2 < 0)
        return -1;
    else
        for (int k = 0; k < n1; k++)
            for (int i = 0; i < n2; i++)
                if (a1[k] == a2[i])
                    return k;
    return -1; // return -1 if we can't find the element
}

int split(string a[], int n, string splitter)
{
    
    
    int beforeSplitter = 0;
    if(n < 0)
        return -1;
    else
        // first count the number of items come before splitter
        for (int k = 0; k < n; k++)
            if (a[k] < splitter)
                beforeSplitter++;
    
    bool smallest = true;
    int pos = 0;
    string low;
    string currentItem;
    
    while (pos < n)
        // visit each item in the array
    {for  (int k = pos; k < n; k++)
    {
        // compare it to the other items to the right of it
        for (int i = k; i < n; i++ )
            // if there is any item smaller than our interested item, then it is not the smallest
        {if (a[i] < a[k])
            smallest = false;
        }
        // if the interested item is the smallest, we swap that item with the item at current position (this spot demarks the items in order from the items yet to be put in order). then we move the current position to the right for 1 spot and break out of the for loop.
        if (smallest == true)
        {low = a[k];
            currentItem = a[pos];
            a[pos] = low;
            a[k] = currentItem;
            pos ++;
            break;
        }
        smallest = true;
        
    }
    }
    // we are done with the while loop after all items are in order
    return beforeSplitter;
    
}


