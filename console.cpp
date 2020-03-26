/*
 * Determines input and outputs correctly to the console.
 * This program uses the MIT license.
 * Written by Jordan Sola 2020
 */

#include <iostream>
#include "console.h"

using std::cin;
using std::cout;

int Console::ReceiveNumInput()
{
    int output;
    bool correct_input = false;
    while (!correct_input)
    {
        cin >> output;
        //check input is integer type
        if (cin)
        {
            correct_input = true;
        }
        else
        {
            //clear input buffer
            cin.clear();
            cin.ignore();
            PrintInvalidInput(0);
        }
    }
    return output;
}

void Console::PrintStartup()
{
    cout << "-- WELCOME TO LOVE LETTER --" << '\n';
    cout << "How many players will be playing?" << '\n';
}

void Console::PrintInvalidInput(int type)
{
    switch (type)
    {
    case 0:
        cout << "Invalid input. Please input an integer: " << '\n';
        break;
    case 1:
        cout << "Invalid input. Please input a number between 2 and 6: " << '\n';
        break;
    }
}