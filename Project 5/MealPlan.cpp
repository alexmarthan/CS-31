#include "MealPlan.h"
#include "Enums.h"

MealPlan::MealPlan(){} // i have to initialize constructor?

void MealPlan::pickPlan(plan p){ // setter function
    mPlan = p; // input a mealplan, and makes the class variable mPlan be that plan
}

plan MealPlan::getPlan(){ // getter function
    return mPlan; // returns the private member variable mPlan
}

double MealPlan::cost(){ // function returns the cost of the mealplan you have purchased
    double returnValue;
    switch (mPlan){ // switch statement going through all possible meal plan options, and associating that option to a price
        case REGULAR11:
            returnValue = 4646.64;
            break;
            
        case REGULAR14:
            returnValue = 5107.20;
            break;
            
        case REGULAR19:
            returnValue = 5278.20;
            break;
            
        case PREMIER11:
            returnValue = 5018.28;
            break;
            
        case PREMIER14:
            returnValue = 5570.04;
            break;
            
        case PREMIER19:
            returnValue = 5898.20;
            break;
    }
    return returnValue; // return the price associated to the mealplan you bought
}

int MealPlan::mealsEachWeek(){ // returns the number of meals you get per week depending on your plan
    int returnValue;
    switch (mPlan){ // switch statement associating mealplans to an int number representing the nb of meals per week
        case REGULAR11:
        case PREMIER11:
            returnValue = 11;
            break;
        case REGULAR14:
        case PREMIER14:
            returnValue = 14;
            break;
        case REGULAR19:
        case PREMIER19:
            returnValue = 19;
            break;
    }
    return returnValue;
}

bool MealPlan::unusedMealsCarryOver(){ // returns true if premier mealplan, false if regular mealplan
    bool returnValue;
    switch (mPlan){ // switch statement associating regular to false, and premier to true
        case REGULAR11:
        case REGULAR14:
        case REGULAR19:
            returnValue = false;
            break;
        case PREMIER11:
        case PREMIER14:
        case PREMIER19:
            returnValue = true;
            break;
    }
    return returnValue; // returns boolean value
}
