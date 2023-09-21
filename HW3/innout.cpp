#include <iostream>
#include <string>
#include <ctype.h>
#include <math.h>
#include <cassert>

using namespace std;

// alex's functions

int numberz(string orders, size_t& index){
     
    int quantity(0);
    int returnvalue(-1);
    while (index < orders.size() && orders.at(index) >= '0' && orders.at(index) <= '9'){
        int digit = orders.at(index) - '0';
        quantity = quantity * 10 + digit;
        index++;
    }
    if (quantity != 0){
        returnvalue = quantity;
    }
    return returnvalue;
}

bool IsACategory(string orders,size_t position){
    char Array[6] = {'1','2','3','C','V','S'};
    int index = 0;
    int counter = 0;
    int retvalue = false;
    while (index < 6){
        if(position < orders.size()){
            if (orders.at(position) == Array[index]){
                counter++;
            }
        }
        index++;
        
    }
    if (counter > 0){
        retvalue = true;
    }
    else {
        retvalue = false;
    }
    
    return retvalue;
}

int countingReps(const string& orders){
    int countingReps = 0;
    for (size_t index = 0; index < orders.size(); index++){
        if (orders.at(index) == '_'){
            countingReps++;
        }
    }
    return countingReps;
}

//NECESSARY FUNCTIONS

bool isValidOrderString(const string orders){
    
    bool retvalue = true;
    size_t position = 0;
    
    int countingRepsVar = countingReps(orders);
    int TotalQuantity = 0;
    
    for (int i = 0; i <= countingRepsVar; i++){ // loops only as many times as there are '_'
        if (orders.size()>0){
            if (orders.at(orders.size() - 1) == '_'){ // if the last one is '_' then no point in starting for loop
                retvalue = false;
                break;
            }
        }
        
        int value = numberz(orders,position);
        if (value == -1 || value >= 50){
            retvalue = false;
        }
        // making sure that the total quantity isn't superior to 50
        TotalQuantity += value;
        if (TotalQuantity >= 50){
            retvalue = false;
        }
        bool Colon = true;
        
        if (position < orders.size()){
            Colon = orders.at(position) == ':';
        }

        if (not Colon){
            return false;
        }

        position ++;
        
        bool Category = IsACategory(orders,position);
        
        if (Category == false){
            retvalue = false;
        }
        
        if (orders.size() > position){ // may need to do orders.size() -1
            position++;
        }
        
        if ( orders.size() > position && orders.at(position) != '_'){ // may need to do orders.size() -1
            retvalue = false;
        }
        position++;
    }
    return retvalue;
}

int howManyCombos(const string orders, int whichCombo){
    if (isValidOrderString(orders) == false || whichCombo > 4 || whichCombo < 0){
        return -1;
    }
    
    int countingRepsVar = countingReps(orders);
    
    size_t position = 0;
    int TotalQuantity(0);
    for (int i = 0; i <= countingRepsVar; i++){
        
        int quantity = numberz(orders,position);
        position++; // this is to skip the colon symbol
    
        if (position < orders.size()){ // here to make sure I don't go out of bounds
            int ItemCategory = orders.at(position) - '0';
            if (ItemCategory == whichCombo){
                TotalQuantity += quantity;
            }
        }
        position += 2; //to see next quantity
    }
   
    return TotalQuantity;
}

int howManyShakes(const string orders, string whichShake){
    
    if (isValidOrderString(orders) == false || (not(whichShake == "Chocolate" || whichShake == "Vanilla" || whichShake == "Strawberry" ))){
        return -1;
    }
    
    char whichShakeChar = whichShake.at(0); // extract Char from String
    
    int countingRepsVar = countingReps(orders);
    
    size_t position = 0;
    int TotalQuantity(0);
    for (int i = 0; i <= countingRepsVar; i++){
        
        int quantity = numberz(orders,position);
        position++; // this is to skip the colon symbol
    
        if (position < orders.size()){ // here to make sure I don't go out of bounds
            int ItemCategory = orders.at(position);
            if (ItemCategory == whichShakeChar){
                TotalQuantity += quantity;
            }
        }
        position += 2; //to see next quantity
    }
   
    return TotalQuantity;
}

 double cost(const string orders){
     
    //formatting
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    if (isValidOrderString(orders) == false){
        return -1;
    }
    int NbOfOnes = howManyCombos(orders,1);
    int NbOfTwos = howManyCombos(orders,2);
    int NbOfThrees = howManyCombos(orders,3);
    int NbOfCs = howManyShakes(orders,"Chocolate");
    int NbOfVs = howManyShakes(orders,"Vanilla");
    int NbOfSs = howManyShakes(orders,"Strawberry");
    
     double cost = NbOfOnes * (9.45) + NbOfTwos * (7.95) + NbOfThrees * (7.55) + (NbOfCs+NbOfVs+NbOfSs) * (2.85);
     
     return cost;
 }

int main(){
    //main routine
    
    
    assert(isValidOrderString("V:C") == false);
    assert(isValidOrderString("a:1") == false);
    assert(isValidOrderString("5:3") == true);
    assert(isValidOrderString("13:T") == false);
    assert(isValidOrderString("80:3") == false);
    assert(isValidOrderString("33:V") == true);
    assert(isValidOrderString("1:2_3:V") == true);
    assert(isValidOrderString("a:::") == false);
    assert(isValidOrderString("40:C_10:1") == false);
    assert(isValidOrderString("49:C_10:V_3:S") == false);
    assert(isValidOrderString("34_C") == false);
    assert(isValidOrderString("12:3C:2") == false);
    assert(isValidOrderString("12:3_C:2") == false);
    assert(isValidOrderString("12:1_79:C") == false);
    assert(isValidOrderString("12!1_1:C") == false);
    assert(isValidOrderString("12:3_12_2") == false);
    assert(isValidOrderString("12:3:12") == false);
    assert(isValidOrderString("12:3_1:C_49:V") == false);
    assert(isValidOrderString("0:V") == false);
    assert(isValidOrderString("12:3_1:C_0:V") == false);
    assert(isValidOrderString("12_3") == false);
    assert(isValidOrderString("12:3__") == false);
    assert(isValidOrderString("12:3_1:C_") == false);
    assert(isValidOrderString("2:22:1") == false);
    assert(cost("2:3") == 15.100000);
    assert(cost("4:1") == 37.800000);
    assert(cost("2:1_2:1") == 37.800000);
    assert(cost("2:2_2:1") == 34.800000);
    assert(cost("2:2_2:1_1:V") == 37.650000);
    assert(cost("1:C_1:V_36:3") == 277.500000);
    assert(cost("2:2_2:1") == 34.800000);
    assert(cost("2:22:1") == -1.0000000);
    assert(howManyCombos("23:1", 1) == 23);
    assert(howManyCombos("211:1", 1) == -1);
    assert(howManyCombos("12:2", 2) == 12);
    assert(howManyCombos("12:2", 5) == -1);
    assert(howManyCombos("12:2", -4) == -1);
    assert(howManyCombos("1:1", 3) == 0);
    assert(howManyCombos("12:2_1:3", 3) == 1);
    assert(howManyCombos("12:2_1:3_2:3", 3) == 3);
    
    assert(howManyShakes("12:2_1:3_2:3", "Chocolate") == 0);
    assert(howManyShakes("12:2_1:C_2:V", "Vanilla") == 2);
    assert(howManyShakes("12:V_1:V_2:V", "Vanilla") == 15);

    string MyOrder ;
    cout << "What do you wanna order? ";
    getline(cin,MyOrder);
    // 1:1_2:3_4_V
    
    //cout.setf(ios::boolalpha);
    //std::cout << isValidOrderString(MyOrder);
    //std::cout << cost(MyOrder);
    //std::cout << howManyCombos(MyOrder, 1);

    return(0);
}

