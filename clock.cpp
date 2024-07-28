//Name: Zackery Spears
//Date: 7/18/24
//Project One
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;


//Function to make the clock border 
void displayClockBorder() {
    string stars;
    int i;

    //Prints the * to create a var to store stars
    for(i = 0; i < 25; ++i){
        stars += "*";
    }
    cout << stars;

    //Prints the space for the border over 24 hour 
    for(i = 0; i < 5; ++i){
        cout << " ";
    }
    //Prints the * for the border over 12 hour 
    cout << stars << endl;

}

//Function to print clock and converts 24 hour clock into 12 hour clock
void displayClock(int hours, int minutes, int seconds) {
    int hourConversion;
    int minConversion;
    int secConversion;
    string morningOrNight = "AM";
    int i;

    //Titles of the Clocks
    cout << "*";
    //Loops over to get space 
    for(i = 0; i < 5; ++i) {
        cout << " ";
    }
    cout << "12-Hour Clock     *";
    cout << right << setw(6) << '*';
    //Loops over to get space 
    for(i = 0; i < 5; ++i) {
        cout << " ";
    }
    cout << "24-Hour Clock"; 
    //Loops over to get space 
    for(i = 0; i < 5; ++i) {
        cout << " ";
    }
    cout << "*" << endl;

    //Converts a 24 clock to a 12 hour clock that use AM and PM
    if(hours == 0) {
        hourConversion = 12;
    }
    else if(hours == 12) {
        hourConversion = hours;
        morningOrNight = "PM";
    }
    else if(hours > 12) {
        hourConversion = hours - 12;
        morningOrNight = "PM";
    }
    else {
        hourConversion = hours;
    }

    //Prints out the hours for 12 hour clock
    cout << "*";
    cout << fixed << setw(5) <<' ';
    cout << setw(2) << setfill('0') << hourConversion << " : ";
    //Print out the minutes for 12 hour clock
    cout << setw(2) << setfill('0') << minutes << " : ";
    //Print out the seconds for 12 hour clock
    cout << setw(2) << setfill('0') << seconds;
    //Print out pm or am for 12 hour clock
    cout << " " << morningOrNight;
    cout << "\t*";
    //Print out the hours for 24 hour clock
    //Loops over to get space
    for(i = 0; i < 5; ++i) {
        cout << " ";
    }
    //Postion the *
    cout << right << setfill(' ');
    cout << right << setw(1) << "*";
    //Print out the minutes for 12 hour clock
    cout << right << setfill(' ');
    cout << right << setw(5) << "";
    cout << setw(2) << setfill('0') << hours << " : " ;
    //Print out the minutes for 24 hour clock
    cout << setw(2) << setfill('0') << minutes << " : ";
    //Print out the seconds for 24 hour clock
    cout << setw(2) << setfill('0') << seconds;
    //Postion the *
    cout << right << setfill(' ');
    cout << right << setw(7) << "*" << endl;
}

//Function to print menu
void printMenu(){
    //Var stores menu border
    string stars;
    int i;

    //Print out and postions Make a Choice
    cout << endl;
    cout << right << setfill(' ');
    cout << right << setw(18) << "Make a Choice" << endl;
    //Prints menu border
    for(i = 0; i < 25; ++i) {
        stars += "*";
    }
    cout << stars << endl;

    //First Menu option
    cout << "* 1-Add One Hour";
    cout << right << setfill(' ');
    cout << right << setw(9) << "*" << endl;

    //Second Menu option
    cout << "* 2-Add One Minute";
    cout << right << setfill(' ');
    cout << right << setw(7) << "*" << endl;

    //Third Menu option
    cout << "* 3-Add One Second";
    cout << right << setfill(' ');
    cout << right << setw(7) << "*" << endl;

    //Fourth Menu option
    cout << "* 4-Exit Program";
    cout << right << setfill(' ');
    cout << right << setw(9) << "*" << endl;

    //Print out stars for bottom of menu border
    cout << stars << endl;
}

//Function to check users menu option selection and validates it
void userInputCheck (int& userInput,  int& addHour, int& addMin, int& addSec) {
    //Checks if the user input is valid and checks if only ints are entered
    if(!(cin >> userInput)){
        cin.clear();
        //This make sures non-numerical values are ignored
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        userInput = 0;
    }

    //Uses a switch statement to check user choice
    switch(userInput) {
        //First case adds a hour if the current is less than 23 and if not resets it back 00
        case 1:
            if(addHour < 23) {
                addHour += 1;
                break;
            }
            else {
                addHour = 00;
                break;
            }
        //Second case adds a Min if the current is less than 59 and if not resets it back 00
        case 2:
            if(addMin < 59) {
                addMin += 1;
                break;
            }
            else {
                addMin = 00;
                addHour += 1;
                break;
            }
        //Third case adds a second if the current is less than 59 and if not resets it back 00
        case 3:
             if(addSec < 59) {
                addSec += 1;
                break;
            }
            else {
                if(addSec == 59 && addMin == 59){
                    addHour += 1;
                    addMin = 00;
                    addSec = 00;
                    break;
                } else {
                    addMin += 1;
                    addSec = 00;
                }
                break;
            } 
        //Fourth case breaks out of the while loop if user types 4
        case 4:
            cout << "Good Bye" << endl;
            break;
        //Default checks if user type invalid choice. 
        default:
            cout << endl;
            cout << "Invalid choice. Please enter a number between 1-4" << endl;
            cout << endl;
            cin.clear();
            break;
    }
}


//Main Function 
int main () {
    int userHourInput = 0;
    int userMinutesInput = 0;
    int userSecondsInput = 0;
    int userMenuInput = 0;
    
    
    
    //Use a while loop to keep checking until user enters the correct info 
    while(true) {
        cout << "Enter Military Hour (0-23):" << endl;
        if(!(cin >> userHourInput)){
        cin.clear();
        //This make sures non-numerical values are ignored
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        userHourInput = 0;
        cout << "Invalid try again. ";
        } else {
            break;
        }
    }
     //Use a while loop to keep checking until user enters the correct info 
    while(true) { 
        cout << "Enter Minutes (0-59):" << endl;
        if(!(cin >> userMinutesInput)){
        cin.clear();
        //This make sures non-numerical values are ignored
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        userMinutesInput = 0;
        cout << "Invalid try again. ";
        } else {
            break;
        }
    }
     //Use a while loop to keep checking until user enters the correct info 
    while (true) {
       cout << "Enter Seconds (0-59)" << endl;
        if(!(cin >> userSecondsInput)){
        cin.clear();
        //This make sures non-numerical values are ignored
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        userSecondsInput = 0;
        cout << "Invalid try again. ";
        } else {
            break;
        }       
    }

    
    //This while loops through the program
    while (userMenuInput != 4) {

    //Display clocks border
    displayClockBorder();
    //Display current user input on the clock
    displayClock(userHourInput,userMinutesInput,userSecondsInput);
    //Display clocks border
    displayClockBorder();
    //Prints user the menu
    printMenu();
    //Checks user choice while validating it. As well as updates the clock 
    userInputCheck (userMenuInput, userHourInput, userMinutesInput, userSecondsInput);
    
    }
    return 0;
}