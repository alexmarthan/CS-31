//
//  main.cpp
//  HW2
//
//  Created by Xela Xela on 18/1/2023.

#include <iostream>
#include <string>
using namespace std;
int main() {
    
    string movieName, Actors, thumbsUp, thumbsDown; // creating string variables
    int similarTheme, ActorsInt, Taste, thumbsUpInt, thumbsDownInt; // creating integer variables
    
    
    // asking for the movie name section
    cout << "What movie is to be rated ";
    getline(cin, movieName);

    // asking if you like similar themes section
    cout << "On a scale of 1-10, how much do you like movies with a similar theme? ";
    cin >> similarTheme;
    // detect for input error
    if (similarTheme < 1 || similarTheme > 10){
        cout << "Invalid theme value!";
        return(1); // stop program if wrong input
    }
    
    //actors section
    cout << "Do you like movies starring the actor or actress that stars in this movie? ";
    cin.ignore(1000,'\n');
    getline(cin,Actors);
    // assign value based on true or false
    if (Actors == "Yes"){
        ActorsInt = 10; // Yes equivalent to 10/10
    }
    else if (Actors == "No"){
        ActorsInt = 0; // No equivalent to 0/10
    }
    
    else{ //in case of input error
        cout << "Invalid actor value!";
        return(1); // stop program if wrong input
    }
    
    // similar taste section
    cout << "On a scale of 1-10, how much do users with tastes similar to yours like this movie? ";
    cin >> Taste;
    if (Taste < 1 || Taste > 10){
        cout << "Invalid taste value!";
        return(1); // stop program if wrong input
    }
    
    
    // thumbs up section
    cout << "Have you thumbed up this movie already? ";
    cin.ignore(10000,'\n');
    getline(cin,thumbsUp);
    if (thumbsUp == "Yes"){
        thumbsUpInt = 10;
    }
    else if (thumbsUp == "No"){
        thumbsUpInt = 0;
    }
    
    else{ //in case of input error
        cout << "Invalid thumbed up value!";
        return(1);
    }

    //thumbs down section
    cout << "Have you thumbed down this movie already? ";
    getline(cin,thumbsDown);
    if (thumbsDown == "Yes"){
        thumbsDownInt = 10;
    }
    else if (thumbsDown == "No"){
        thumbsDownInt = 0;
    }
    
    else{ //in case of input error
        cout << "Invalid thumbed down value!";
        return(1); // stop program if wrong input
    }
    
    // formatting section for double variables --> want 1 digit after decimal point
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
   
    // calculation of recommendation number with weight of each variable
    float recNumber = 0.3 * similarTheme + 0.2 * ActorsInt + 0.3 * Taste + 0.2 * thumbsUpInt - 0.2 * thumbsDownInt;
    
    // final answer
    cout << "Our recommendation for you for the movie: " << movieName << " is " << recNumber;
    
    return(0);
}
