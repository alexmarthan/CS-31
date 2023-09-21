#ifndef mealPlan_H
#define mealPlan_H

#include "Enums.h"

class MealPlan{
private:
    plan mPlan; // member variable of type plan
public:
    MealPlan(); // class constructor
    void pickPlan(plan p); // setter function
    plan getPlan(); // getter function
    double cost(); // function returns the cost of the mealplan you have purchased
    int mealsEachWeek(); // returns the number of meals you get per week depending on your plan
    bool unusedMealsCarryOver(); // returns true if premier mealplan, false if regular mealplan
};


#endif
