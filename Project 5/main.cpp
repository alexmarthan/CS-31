//
//  main.cpp
//  HW5
//
//  Created by Xela Xela on 26/2/2023.
//

#include <iostream>
#include "Enums.h"
#include "MealPlan.h"
#include "BruinCard.h"

using namespace std;

int main() {
    //MealPlan m;
    //BruinCard b;
    
    BruinCard c;
    MealPlan m;
    m.pickPlan( PREMIER14 );
    c.purchaseMealPlan( m );
    c.startQuarter();  // Premier plans get all their meals at the start of each quarter
    assert( c.mealsLeftThisWeek() == 11*14 );
    c.newWeek();
    assert( c.eat( BREAKFAST ) );   // using one meal on the plan
    assert( c.eat( BREAKFAST ) );   // Premier plans can use multiple meals at the same sitting
    assert( c.mealsLeftThisWeek() == 11*14 - 2 ); // testing for adjustment of nb of meals left
    c.newDay();
    assert( c.mealsLeftThisWeek() == 11*14 - 2 );
    c.newWeek();
    assert( c.mealsLeftThisWeek() == 11*14 - 2 );
    assert( std::to_string( m.cost() ) == "5570.040000" );

    BruinCard d;
    MealPlan n;
    n.pickPlan( REGULAR19 );
    d.purchaseMealPlan( n );
    d.startQuarter();
    d.newWeek();
    assert( d.mealsLeftThisWeek() == 19 );  // Regular plans get their meals at the start of each week
    assert( d.eat( BREAKFAST ) );
    assert( d.eat( BREAKFAST ) == false );          // Regular plans cannot dine twice at the same meal
    assert( d.mealsLeftThisWeek() == 18 );
    d.newDay();
    assert( d.eat( BREAKFAST ) );
    assert( d.mealsLeftThisWeek() == 17 );
    d.newWeek();
    assert( d.mealsLeftThisWeek() == 19 );  // Regular plans lose any meals leftover at the start of the new week
    assert( std::to_string( n.cost() ) == "5278.200000" );

    BruinCard e;
    e.startQuarter();
    e.newWeek();
    // without a meal plan, BruinCards cannot be used for meals
    assert( e.eat( BREAKFAST ) == false );
    assert( e.mealsLeftThisWeek() == 0 );
    e.newDay();
    assert( e.eat( LUNCH ) == false );
    assert( e.eat( DINNER ) == false );
    assert( e.eat( WEEKENDBRUNCH ) == false );
    
    
    return 0;
}
