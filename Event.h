/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Event.h
 * Author: Bahati Boniface
 *
 * Created on April 25, 2017, 4:30 PM
 */

/**************************************
 *This class is used to create events *
 **************************************/
#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <sstream>
#include "Date.h"
using namespace std;

class Event {
public:
    Date date;
    string description;

    string ToString() const {
        return date.ToString() + ": " + description;
    }
};

#endif /* EVENT_H */

