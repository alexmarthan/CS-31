#include "BruinCard.h"

BruinCard::BruinCard(){ // initialize variables in constructor
    mBoughtAMealPlan = false;
    
    hasEatenBreakfast = false;
    hasEatenLunch = false;
    hasEatenDinner = false;
    hasEatenBrunch = false;
    
    howManyMealsLeft = 0;
}

void BruinCard::purchaseMealPlan(MealPlan plan){ // function is used when someone buys a mealplan
    mBoughtAMealPlan = true;
    mPlan = plan; // the mealplan that is inputted is put in the class' private member variable
}

bool BruinCard::hasPurchasedMealPlan(){
    return mBoughtAMealPlan; // returns true if purchased, false if did not purchase
}


plan BruinCard::getPlan(){ // getter function
    return mPlan.getPlan(); // returns private member variable of MealPlan class
}

bool BruinCard::eat(meal m){ // function is used to represent the action of swiping
    bool returnValue = false;
    if (hasPurchasedMealPlan()){ // person has to have bought a mealplan for a swipe to work
        switch (mPlan.getPlan()){
            case PREMIER11:
            case PREMIER14:
            case PREMIER19:
                if (howManyMealsLeft > 0 ){ // if mealplan is premier, only condition is that there are meals left
                    howManyMealsLeft--;
                    returnValue = true;
                }
                break;
            case REGULAR11:
            case REGULAR14:
            case REGULAR19:
                if (howManyMealsLeft > 0){ // regular plan must have meals left in the week
                    if (m == BREAKFAST && hasEatenBreakfast == false){ // can only eat once during a meal period
                        returnValue = true;
                        howManyMealsLeft--;
                        hasEatenBreakfast = true;
                    }
                    if (m == LUNCH && hasEatenLunch == false){
                        returnValue = true;
                        howManyMealsLeft--;
                        hasEatenLunch = true;

                    }
                    if (m == DINNER && hasEatenDinner == false){
                        returnValue = true;
                        howManyMealsLeft--;
                        hasEatenDinner = true;

                    }
                    if (m == WEEKENDBRUNCH && hasEatenBrunch == false){
                        returnValue = true;
                        howManyMealsLeft--;
                        hasEatenBrunch = true;
                    }
                }
                break;
            default:
                returnValue = false;
            }
    }
    return returnValue; // returns true if you're allowed to swipe, false if not
}

void BruinCard::startQuarter(){ // initializer function - sets number of meals based on your purchased mealplan
    
    switch (mPlan.getPlan()){
        case REGULAR11:
        case PREMIER11:
            howManyMealsLeft = 11*11;
            break;
        case REGULAR14:
        case PREMIER14:
            howManyMealsLeft = 11*14;
            break;
        case REGULAR19:
        case PREMIER19:
            howManyMealsLeft = 11*19;
            break;
        default:
            howManyMealsLeft = 0;
    }
}

void BruinCard::newWeek(){ // resets the number of meals left per week for regular plan owners
    switch (mPlan.getPlan()){
        case REGULAR11:
            howManyMealsLeft = 11;
            break;

        case REGULAR14:
            howManyMealsLeft = 14;
            break;

        case REGULAR19:
            howManyMealsLeft = 19;
            break;
        default:
            break;
    }
    // the following section resets all values to false at the start of a new week
    hasEatenBreakfast = false;
    hasEatenLunch = false;
    hasEatenDinner = false;
    hasEatenBrunch = false;
}
void BruinCard::newDay(){ // resets all values to false at the start of a new day
    hasEatenBreakfast = false;
    hasEatenLunch = false;
    hasEatenDinner = false;
    hasEatenBrunch = false;
}

int BruinCard::mealsLeftThisWeek(){ // returns the number of meals left this week
    int returnValue = howManyMealsLeft;
    return returnValue;
}
