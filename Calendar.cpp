/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Calendar.cpp
 * Author: Bahati Boniface
 * 
 * Created on April 25, 2017, 4:18 PM
 */

#include "Calendar.h"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Date.h"
#include "Event.h"
#include <conio.h>

Calendar::Calendar() {
}

void Calendar::Run() {

    bool run = true;

    /*****************************/
    /*          Menu system       */
    /********************************/

    while (run) {

        char op;
        string file;
        cout
                << "\nN: Show Next Month"
                << "\tP: Show Previous Month " << "\tI: Show Specific Date "
                << "\nA: Create An Event" << "\tL: List All Events"
                << "\tD: Delete An Event" << "\nS: Save All Events"
                << "\tR: Load Event" << "\tQ: Quit" << "\nInput your command ";
        cin >> op;
        if (op >= 'a' && op <= 'z')
            op += ('A' - 'a');

        switch (op) {
            case 'N':
                NextMonth();
                Draw();
                break;
            case 'P':
                PreviousMonth();
                Draw();
                break;
            case 'I':
                InputDate();
                Draw();
                break;
            case 'A':
                CreateEvent();
                break;
            case 'L':
                ListEvents();
                break;
            case 'D':
                DeleteEvent();
                break;
            case 'S':
                Save();
                break;
            case 'R':
                Load();
                break;
            case 'Q':
                run = false;
                break;
            default:
                cout << "Invalid input." << endl;
                break;
        }
    }
}

void Calendar::Draw() {
    int year = currentDate.getYear();
    int month = currentDate.getMonth();

    cout << "    " << Date::MonthNames[month - 1];
    cout << "    " << year << endl;

    cout << "**************************" << endl;


    //Print all the startingDay days Mon-Sun 
    for (int i = 0; i < sizeof Date::DayNames / sizeof Date::DayNames[0]; ++i) {
        cout << Date::DayNames[i] << " ";
    }
    cout << endl;


    /**********************************************/
    /*  Calculate the starting day for each month  */
    /*********************************************/


    //  Tomohiko Sakamoto's Algorithm

    int y = year - (month < 3);
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int startingDay;
    int d = 1;
    //Nasty trick to solve febuary starting day
    if (month == 2) {
        d = 0;
    }
    startingDay = ((year + year / 4 - year / 100 + year / 400 + t[month - 1] + d) % 7);
    cout << startingDay << endl;
    int dayCount = Date::MonthDays[month - 1];
    cout << dayCount << endl;


    /**********************************************/
    /*          Printing the calendar            */
    /*********************************************/

    //Print and empty space if the day doesn't have a corresponding day 
    for (int x = 0; x < startingDay; ++x) {
        cout << "    ";
    }


    //Print the date corresponding with the day 
    for (int d = 0; d < dayCount; ++d) {
        if (d < 9)

            cout << "0" << d + 1 << "  ";
        else
            cout << d + 1 << "  ";
        ++startingDay;
        if (startingDay == 7) {
            startingDay = 0;
            cout << endl;
        }
    }

    cout << endl;
}

//Display next month

void Calendar::NextMonth() {
    currentDate.IncreaseMonth();
}

//Display previous month

void Calendar::PreviousMonth() {
    currentDate.DecreaseMonth();
}



/********************************************************/
/*   Print a calendar coressponding to the user input   */
/********************************************************/


// Get date from user 

void Calendar::InputDate() {
    int year, month, day;
    do {
        cout << "Year:";
        cin >>year;
    } while (year < 0);

    do {
        cout << "Month:";
        cin>>month;
    } while (1 > month || month > 12);

    do {
        cout << "day:";
        cin>>day;
    } while (1 > day || day > 31);
    currentDate.setDate(day, month, year);
    ;

}
/***************************************************/
/*   Get a date from a user and store as an event  */

/***************************************************/
void Calendar::CreateEvent() {
    Event event;

    int year, month, day;
    cout << "Input Year:";
    cin >> year;

    cout << "Input Month:";
    cin >> month;

    cout << "Input day:";
    cin >> day;

    event.date.setDate(year, month, day);

    string desc;
    cout << "Input description: ";
    cin >> event.description;

    events.push_back(event);
}

void Calendar::ListEvents() {
    for (int i = 0; i < events.size(); ++i) {
        cout << setw(4) << i + 1 << " " << events[i].ToString() << endl;
    }
}

/***************************************************************/
/*  Delete and event corresponding to the user selected index  */

/***************************************************************/
void Calendar::DeleteEvent() {
    int id;
    cout << "Input event ID: ";
    cin >> id;

    if (id < events.size() + 1) {
        events.erase(events.begin() + id - 1);
    } else {
        cerr << "Invalid event ID" << endl;
    }
}
/*****************************************************/
/*  Create and event file and store all the events   */

/*****************************************************/
void Calendar::Save() {
    //string filename = ;
    ofstream file;
    file.open("event.boni", ios::app);

    for (int i = 0; i < events.size(); ++i) {
        file << events[i].date.getYear()
                << events[i].date.getMonth()
                << events[i].date.getDay()
                << events[i].description << endl;
    }

    file.close();

    cout << "Save to file success." << endl;
}
/**********************************************/
/*  Load all event the the event file         */

/*********************************************/
void Calendar::Load() {
    events.clear();

    ifstream file;
    file.open("event.boni", ios::app);

    if (!file.is_open()) {
        cerr << "Unable to open the file: " << endl;
        cerr << "Abort loading events." << endl;
        return;
    }

    while (true) {
        Event event;

        int year, month, day;
        file >> year >> month>> day;

        if (file.eof())
            break;

        event.date.setDate(year, month, day);

        string desc;
        file >> event.description;

        events.push_back(event);
    }


    file.close();
    cout << "Load from file success." << endl;

}
