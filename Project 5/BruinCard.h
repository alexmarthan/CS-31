#ifndef BruinCard_H
#define BruinCard_H

#include "Enums.h"
#include "MealPlan.h"

class BruinCard {
    MealPlan mPlan; // object of type MealPlan (can be used to call members of the MealPlan Class)
    bool mBoughtAMealPlan;
    
    // boolean member variables below serve as memory for whether someone has eaten or not
    bool hasEatenBreakfast;
    bool hasEatenLunch;
    bool hasEatenDinner;
    bool hasEatenBrunch;
    
    int howManyMealsLeft;
public:
    BruinCard(); // class constructor
    void purchaseMealPlan(MealPlan plan); // function is used when someone buys a mealplan
    bool hasPurchasedMealPlan(); // returns true if purchased, false if did not purchase
    plan getPlan(); // getter function
    bool eat(meal m); // function represents the action of swiping - returns true if allowed, false if not
    
    void startQuarter(); // initializer function - sets number of meals based on your purchased mealplan
    void newWeek(); // resets the number of meals left per week for regular plan owners
    void newDay(); // resets all values to false at the start of a new day
    int mealsLeftThisWeek(); // returns the number of meals left this week
    
};
#endif
