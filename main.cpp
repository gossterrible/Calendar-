/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Bahati Boniface
 *
 * Created on April 25, 2017, 4:15 PM
 */

/******************
 *Main Program loop*
 ******************/
#include <cstdlib>
#include "Calendar.h"
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    system("Color 1A");
    Calendar calendar;
    //Create event data file if it doesn't exist
    ifstream ifs("db.event");
    if (!ifs.is_open()) {
        ofstream outfile("db.event"); // create file
    }
    calendar.Draw(); // print calendar 
    calendar.Run(); //Menu options

    return 0;
}
