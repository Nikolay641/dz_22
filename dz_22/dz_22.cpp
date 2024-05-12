// dz_22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Time_.h"
using namespace std;
int main() {
    Time_ currentTime;
    cout << "Current Local Time:" << endl;
    currentTime.showTime();

    Time_ customTime(10, 30, 45, false);
    cout << "\nCustom Time (12-hour Format):" << endl;
    customTime.showTime();

    Time_ copyTime(customTime);
    cout << "\nCopied Time:" << endl;
    copyTime.showTime();

    Time_ addSeconds = currentTime + 123;
    cout << "\nCurrent Time + 123 seconds :" << endl;
    addSeconds.showTime();

    Time_ subtractMinutes = currentTime - static_cast<float>(3.5);
    cout << "\nCurrent Time - 3.5 Minutes:" << endl;
    subtractMinutes.showTime();

    Time_ addHours = currentTime + static_cast<long>(5);
    cout << "\nCurrent Time + 5 Hours:" << endl;
    addHours.showTime();

    return 0;
}
