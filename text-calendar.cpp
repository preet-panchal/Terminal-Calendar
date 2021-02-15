//Preet Panchal
//100707094
//CSCI1060U - LAB04
//CRN:43916
//October 18, 2020

//listing all necessary libraries 
#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <cstdio>
#include <string>
#include <cmath>

using namespace std; 

//declaration of month-printing function
void printMonth(int month,int year);
//declaration of year-printing function
void printYear(int year);
//declaration of leap-year checker function
bool leapYear(int year);
//declaration of function for first day of month
int firstDay(int year, int month);

//global variables months and totalDays to be used in multiple functions
//blank space for assigning each positive integer to appropriate month
string monthList[] = {" ", "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", 
                    "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

//total days in each month in same order as listed above ^^
int totalDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {

    cout << endl;
    while (true) {
        int userMonth, userYear;
        string userInput;

        //user input for month or year calendar
        cout << "Would you like a 'month' or 'year' calender? ";
        cin >> userInput;

        //if user wants a month calender for a specific year
        if (userInput == "month") {
            cout << "Enter the year: ";
            cin >> userYear;

            cout << "Enter the month as a positive integer (ie. January = 1): ";
            cin >> userMonth;

            printMonth(userMonth, userYear);
            break;
        }

        //if user wants a year calender
        else if (userInput=="year") {
            cout << "Enter the year: ";
            cin >> userYear;
            printYear(userYear);
            break;

        }

        //if user enters an invalid input, ask again
        else {
            cout << "Invalid input. Please try again! " << endl; 
            cout << endl; 
        }
    }

    return 0;
}

//function definitions
//prints the month with all appropriate spacing and values
void printMonth(int month,int year) {

    //outputs calendar outline
    cout << endl; 
    cout << monthList[month] << " " << year << endl;
    cout << endl;
    cout << " S   M  Tu   W  Th   F   S" << endl;

    //to check if year is a leap-year or not
    //leapBool = 1 IFF it is a leap-year
    int leapBool = 0; 
    if ((leapYear(year) == true) && (month == 2)) {
        leapBool = 1;
    }
    //special cases of Jan 13 and Feb 14
    int specialMonth = month;
    int specialYear = year;

    if (month == 1) {
        specialMonth = 13;
        specialYear = year - 1;
    }
    if (month == 2) {
        specialMonth = 14;
        specialYear = year - 1;
    }

    //dayOne represents first day of the month
    int dayOne = firstDay(specialYear, specialMonth);
    if (dayOne == 0) {
        dayOne = 7;
    }

    //numDays gives total days for each month and +1 if it is leap-year
    int numDays = totalDays[month] + leapBool; 

    //counts 7 days before ending the week when outputing
    int SIZE = numDays + (dayOne - 1);
    int day = 1;
    int count = 0; 
    int calendar[SIZE];

    //null values for the days of the month that do not belong in the beginning
    //all values starting from day 1 are added into the calendar
    for (int i = 0; i < SIZE; i++) {
        if (i < (dayOne-1)) {
            calendar[i] = 0;
        }
        else {
            calendar[i] = day;
            day++;
        }
    }

    //printing calendar with appropriate spacing
    for (int i = 0; i < SIZE; i++) {
        if(calendar[i] == 0) {
            cout << "    ";
            count ++;
        }
        else {
            if (calendar[i] < 10) {
                cout << " " << calendar[i] << "  ";
                count ++;

                //reset count value to '0' once 7 days are completed
                if (count == 7) {
                    cout << endl;
                    count = 0;
                }
            }
            else {
                cout << calendar[i] << "  ";
                count++;
                if (count == 7) {
                    cout << endl;
                    count = 0;
                }
            }
        }
    }
    cout << endl; 
    return;
}

//prints all months of the year using the printMonth function above
void printYear(int year) {

    //loops 12 times for each month
    for (int i = 1; i < 13; i++) {
        printMonth(i, year);
    }
    return;
}

//Function which returns True if leap year based on the 3 given cases
bool leapYear(int year) {

    //if both year is divisible by 4 evenly and not 100 then true
    if ((year%4 == 0) && (year%100 != 0)) {
        return true;
    }
    //if year is both evenly divisble by 100 and 400 and 4 then true
    else if ((year%400 == 0) && (year%100 == 0) && (year%4 == 0)) {
        return true;
    }
    //if both cases above are false then return false
    else {
        return false;
    }
}

//to check what day is the beginning of the month
int firstDay(int year, int month) {

    //equation helps output which day the first date of month is on
    int d = ((1 + 2*month + (3*(month+1)/5) + year + (year/4) - (year/100) + (year/400) + 2)%7);
    return d;
}