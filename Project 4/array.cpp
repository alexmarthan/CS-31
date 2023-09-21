//
//  main.cpp
//  HW4
//
//  Created by Xela Xela on 17/2/2023.

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int locateMaximum( const  string  array[ ],  int  n ){
    string ValueAtIndex, MaximumValue;
    int IndexOfMax = -1;
    
    for (int i = 0; i < n; i++){
        ValueAtIndex = array[i];
        if (ValueAtIndex > MaximumValue){
            MaximumValue = ValueAtIndex;
            IndexOfMax = i;
        }

    }
    return IndexOfMax;
}

bool hasNoDuplicates( const string array[ ], int  n ){
    bool returnVal = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; ++j){
            if (i!=j){
                if (array[i] == array[j]){
                    returnVal = 0;
                    break;
                }
            }
        }
    }
    if (n < 0){
        returnVal = 0;
    }
    return returnVal;
}


int countXPairs( const string array[ ], int  n, int x ){
    int counter = 0;
    
    for (int i = 0; i < n; i++){
        if (array[i] >= "0" && array[i] < ":" ){ // array must only contain numbers
            for (int j = 0; j < n; j++){
                if (stoi(array[i]) + stoi(array[j]) == x && (i != j)){
                    counter++;
                }
            }
        }
        else {
            break;
        }
    }
    
    int returnValue = counter/2; // everything is counted twice (for when i and j values are switched)
    if (n<=0){
        returnValue = -1;
    }
    
    return returnValue;
}

int findSecondToLastOccurrence( const string array[ ], int n, string target ){
    
    int returnValue = -1;
    
    int firstCounter(0);
    for (int index = 0; index < n; index++){ // this figures out how many "target"s we have
        if (array[index] == target){
            firstCounter++;
        }
    }
    int counter2(0);
    for (int i = 0; i < n; i++){
        if (array[i] == target){
            counter2++;
        }
        if (firstCounter > 1){
            if (counter2 == firstCounter - 1){
                returnValue = i;
                break;
            }
        }
    }
    
    return returnValue;
}

int countPunctuation( const string array[ ], int   n ){
    int punctCounter(0);
    int returnValue(-1);
    for (int index = 0; index < n; index++){
        for (size_t charIndex = 0; charIndex < array[index].size(); charIndex++){
            if ( array[index][charIndex] == '.' || array[index][charIndex] == ',' || array[index][charIndex] == '!' || array[index][charIndex] == ';' || array[index][charIndex] == '\'' || array[index][charIndex] == '-' || array[index][charIndex] == '/' || array[index][charIndex] == ':' || array[index][charIndex] == '?' || array[index][charIndex] == '"'){
                punctCounter++;
            }
        }
    }
    returnValue = punctCounter;
    
    if (n <= 0){
        returnValue = -1;
    }
    return returnValue;
}

int flipAround( string array[ ], int n ){
        
    for (int i = 0; i < (n/2); i++){ // til n/2 so that it doesnt flip it twice
        string theBeginning = array[i];
        string theEnd = array[n-i-1]; // must take off 1 to account for first arr index being 0
        array[i] = theEnd;
        array[n-i-1] = theBeginning;
    }
    int returnValue = n/2; // counting on integer division to truncate
    return returnValue;
}

int moveToEnd( string array[ ], int  n, int pos ){
    int returnValue = -1;
        if (pos < n - 1 && pos > 0){
            string rememberStringAtPos = array[pos];
            int whicheverPos = pos;
            for (int i = pos; i < n - 1 ;i++){
                array[whicheverPos] = array[whicheverPos + 1];
                whicheverPos++;
            }
            
            array[n-1] = rememberStringAtPos;
        }
        
        if (pos >= 0 && pos <= n-1){
            returnValue = pos;
        }
        
        return returnValue;
}


int main() {
    
    std::cout << "Hello everybody, enjoy my project! ";

    return 0;
}
