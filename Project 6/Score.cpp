//
//  Score.cpp
//

#include "Score.h"
#include <stdexcept>

namespace cs31
{

// setup a default score - all WRONG ANSWER's
Score::Score()
{
    for( int i = 0; i < REQUIREDLENGTH; i++ )
    {
        array[ i ] = WRONG;
    }
}

// TODO comparing the played move to the answer move,
//      build the ANSWER array of this Score
Score::Score(Move move, Move answer)
{
    // Array keeps track of the answer pieces that have already been matched
    bool matched[REQUIREDLENGTH] = {false, false, false, false};

    // checking for pieces in the correct position (RIGHT)
    for (int i = 0; i < REQUIREDLENGTH; i++) {
        if (move.getPiece(i).getColor() == answer.getPiece(i).getColor()) {
            array[i] = RIGHT;
            matched[i] = true; // Mark the answer piece as matched
        } else {
            array[i] = WRONG; // Assume it's wrong until we find a matching color
        }
    }

    // Next, look for color matches in other positions (MAYBE)
    for (int i = 0; i < REQUIREDLENGTH; i++) {
        if (array[i] == WRONG) { // Only look for MAYBE matches for pieces that are not RIGHT
            for (int j = 0; j < REQUIREDLENGTH; j++) {
                if (move.getPiece(i).getColor() == answer.getPiece(j).getColor() && !matched[j]) {
                    matched[j] = true; // Mark the answer piece as matched
                    array[i] = MAYBE; // Found a matching color in a different position
                    break;
                }
            }
        }
    }
}


// trivial getter but throw logic_error if the index is out of range
ANSWER Score::getAnswer( int i )
{
    if (i >= 0 && i < REQUIREDLENGTH)
        return( array[ i ] );
    else
        throw std::logic_error( "invalid i value" );
}

// stringify this Score
std::string Score::to_string() const
{
    std::string s = "";
    int mCount = 0;
    int rCount = 0;
    for (int i = 0; i < REQUIREDLENGTH; i++)
    {
        switch( array[i] )
        {
            case WRONG:
                // wrongs should not be printed at all
                s += "_";
                break;
            case RIGHT:
                rCount++;
                s += "R";
                break;
            case MAYBE:
                mCount++;
                s += "M";
                break;
        }
    }
    return( s );
}

// TODO is the ANSWER array all RIGHT ANSWER's?
bool Score::isExactMatch() const  // // // // // // // // POT DONE
{
    
    bool returnValue(true); // set as true
    
    for (int i = 0; i < REQUIREDLENGTH; i++){
        if (array[i] != RIGHT){ // if one of the values in the array is not right, then your move does not match the answer
            returnValue = false; // is not exact match
            break; // stop iterating through loop if you find one value that doesn't match
        }
    }
    return( returnValue );
}

}
