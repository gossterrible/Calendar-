/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.h
 * Author: Terrible Goss
 *
 * Created on April 25, 2017, 4:28 PM
 */
#include <string>
#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>
using namespace std;

class Date {
public:
    Date();
    int getYear(); //get the current year
    int getMonth(); //get the current month 
    int getDay(); //get the current day 

    void setDate(int, int, int);

    void IncreaseMonth();
    void DecreaseMonth();
    static const std::string DayNames[7]; //all object have weekdays
    static const std::string MonthNames[12]; //*************** Months
    static const int MonthDays[12]; //*************** Days
    string ToString() const;
private:
    int year;
    int month;
    int day;

};

#endif /* DATE_H */

