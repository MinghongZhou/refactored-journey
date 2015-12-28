#include <iostream>
#include <cstring>
#include <cctype>
#include "utilities.h"
using namespace std;

const int MAX_WORDS = 10000;

const int MAX_WORD_LEN = 6;

int manageOneRound (const char words[][MAX_WORD_LEN + 1], int nWords, int wordnum);

int rocks (const char words[], char probeWord[]);

int pebbles (const char words[], char probeWord[]);


int main()
{
    int numOfTriesInOneRound = 0;
    int totalNumOfTries = 0;
    int minimum = 10000;
    int maximum = 0;
    double average = 0;
    // declare an array to hold the words
    char wordList[MAX_WORDS][MAX_WORD_LEN + 1];
    // actual number of the words
    int nWords = loadWords(wordList, 10000);
    // if no word is loaded, cout the message and terminate the program
    if (nWords < 1)
        {
            cout << "No words were loaded, so I can't play the game."<< endl;
            return -1;
        }
    
    // ask user the number of rounds
    cout << "How many rounds do you want to play? " ;
    int numOfRounds;
    cin >> numOfRounds;
    cin. ignore(10000, '\n');
    int numOfRoundsHavePlayed = 0;
    // make sure the number of Rounds is positive
    if (numOfRounds <= 0)
        {
            cout << "The number of rounds must be positive." << endl;
            return -1;
        
        }
   
    for (; ;)
        {
            // after the user play the number of rounds intended to play, end the program
            if (numOfRoundsHavePlayed == numOfRounds)
                break;
            
            int randomNum = randInt(0, nWords - 1);
            int wordLenth = strlen (wordList[randomNum]);
            cout << "\n";
                                    //cerr << wordList[randomNum]<< endl;//
            cout << "Round " << numOfRoundsHavePlayed + 1 << endl;
            cout << "The secret word is " << wordLenth<< " letters long."<< endl;
            
            numOfTriesInOneRound = manageOneRound (wordList, nWords, randomNum);
            totalNumOfTries+= numOfTriesInOneRound;
            
            
            if (numOfTriesInOneRound != 1)
                cout << "You got it in " << numOfTriesInOneRound << " tries." << endl;
            if (numOfTriesInOneRound == 1)
                cout << "You got it in 1 try." << endl;
            
            
            if (numOfTriesInOneRound > maximum)
                maximum = numOfTriesInOneRound;
            
            if (numOfTriesInOneRound < minimum)
                minimum = numOfTriesInOneRound;
            
            average = static_cast<double>(totalNumOfTries)/ (numOfRoundsHavePlayed + 1);
            cout. setf (ios::fixed);
            cout.precision(2);
            // tell player the statistics of each round and move on to the next round
            cout << "Average: " << average << ", minimum: " << minimum<<", maximum: "<< maximum<< endl;
            numOfRoundsHavePlayed ++;
            
            
        }
    
}


int manageOneRound (const char words[][MAX_WORD_LEN + 1], int nWords, int wordnum)
{
    if (nWords <= 0 || wordnum < 0 || wordnum >= nWords)
        return -1;
    
    
    char probeWord[100];
    
    bool inTheArray = false;
    bool validWord = true;
    
    int numOfTrys = 1;
    
    for (;;)
    {
        // let the player input the probe word
        cout << "Probe word: ";
        cin.getline(probeWord,100);
     
        // if the player guess the correct word, break the loop
        if (strcmp(probeWord, words[wordnum]) == 0)
            break;
        
    
       // if the probe word is not a word of 4 to 6 lower case letters, notify player the error
        for (int i = 0; probeWord[i] != '\0'; i++)
            {
                if (islower(probeWord[i]) == false)
                    validWord = false;
            }
        
        if (validWord == false || strlen(probeWord) > 6 || strlen(probeWord) < 4)
            {
            cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
            validWord = true;
            continue;
            }
        
        
        // if the word is not in the list, notify the player
        for (int k = 0; k != 10000; k++)
            {
                    if (strcmp (probeWord, words[k]) == 0)
                        inTheArray = true;
            }
        
        // tell player number of rocks and pebbles
        if (inTheArray == true)
            {
                cout << "Rocks: " << rocks( words[wordnum], probeWord ) << ", Pebbles: " << pebbles(words[wordnum], probeWord)<< endl;
                numOfTrys ++;
                inTheArray = false;
            }
        else
            cout << "I don't know that word." << endl;
    }
    return numOfTrys;
}



int rocks (const char words[], char probeWord[])
{
    int rocks = 0;
    for (int k = 0; words[k] != '\0' && probeWord[k] != '\0'; k++)
        if (words[k] == probeWord[k])
            rocks ++;
    return rocks;
    
}


int pebbles (const char words[], char probeWord[])
{
    int  pebbles = 0;
    char remainderOfWords[MAX_WORD_LEN + 1] = "";
    char remainderOfProbeWord[MAX_WORD_LEN + 1] ="";
    int  pos = 0;
    
    // creat a new c string that contains the letter from probe word that are not involved in rocks
    for (int k = 0;probeWord[k] != '\0'; k++ )
        if (words[k] != probeWord[k])
            {
                remainderOfProbeWord[pos] = probeWord[k];
                pos ++;
            }
    
    pos = 0;
    // creat a new c string that contains the letter from words that are not involved in rocks

    for (int x = 0; words[x] != '\0'; x++ )
        if (words[x] != probeWord[x])
        {
            remainderOfWords[pos] = words[x];
            pos ++;
        }

    
    // count the number of same letters. Every time we find a letter that is contained in both words and probe word, we set it to 0 in words and 1 in probe word, so that we won't count them again.
        for (int i = 0; remainderOfProbeWord[i] != '\0'; i++)
        {
                for (int a = 0; remainderOfWords[a] != '\0'; a++)
                {
                    if (remainderOfProbeWord[i] == remainderOfWords[a])
                    {
                        pebbles++;
                        remainderOfWords[a] = '0';
                        remainderOfProbeWord [i] = '1';
                    }
                }
        }

    
    return pebbles;
}
