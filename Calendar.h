/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Calendar.h
 * Author: Bahati Boniface
 *
 * Created on April 25, 2017, 4:18 PM
 */

#ifndef CALENDAR_H
#define CALENDAR_H

//Include dependencies 
#include <vector>
#include <iostream>
#include "Date.h"
#include "Event.h"
using namespace std;

class Calendar {
public:
    void Run(); //Main Menu system
    void Draw(); //Main calendar draw loop
    void NextMonth(); // Print Next month
    void PreviousMonth(); //Print Previous Month 
    void InputDate(); // print a calendar corresponding to user input
    void CreateEvent(); //get date from users and create and event
    void ListEvents(); //List  all event created while program was running
    void DeleteEvent(); // Delete e selected event; 
    void Save(); //save all event to event file 
    void Load(); //Load all event from event file
    Calendar();
private:
    Date currentDate;
    vector <Event> events;
};

#endif /* CALENDAR_H */

