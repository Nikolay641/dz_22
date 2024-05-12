#include "Time_.h"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
Time_::Time_() {
    time_t now;
    time(&now);
    tm ltm;
    localtime_s(&ltm, &now);
    hour = ltm.tm_hour;
    minutes = ltm.tm_min;
    seconds = ltm.tm_sec;
    format = true;
}


Time_::Time_(int hour, int minutes, int seconds, bool format) : hour(hour), minutes(minutes), seconds(seconds), format(format) {}

Time_::Time_(const Time_& obj) : hour(obj.hour), minutes(obj.minutes), seconds(obj.seconds), format(obj.format) {}

Time_& Time_::operator=(const Time_& obj) {
    if (this != &obj) {
        hour = obj.hour;
        minutes = obj.minutes;
        seconds = obj.seconds;
        format = obj.format;
    }
    return *this;
}

Time_::~Time_() {}

void Time_::setHour(int hour) {
    this->hour = hour;
}

int Time_::getHour() const {
    return hour;
}

void Time_::setMinutes(int minutes) {
    this->minutes = minutes;
}

int Time_::getMinutes() const {
    return minutes;
}

void Time_::setSeconds(int seconds) {
    this->seconds = seconds;
}

int Time_::getSeconds() const {
    return seconds;
}

void Time_::setFormat(bool format) {
    this->format = format;
}

bool Time_::getFormat() const {
    return format;
}

bool Time_::valid() const {
    return (hour >= 0 && hour < 24 && minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60);
}

void Time_::tickTime() {
    seconds++;
    if (seconds >= 60) {
        seconds = 0;
        minutes++;
        if (minutes >= 60) {
            minutes = 0;
            hour++;
            if (hour >= 24) {
                hour = 0;
            }
        }
    }
}

void Time_::untickTime() {
    seconds--;
    if (seconds < 0) {
        seconds = 59;
        minutes--;
        if (minutes < 0) {
            minutes = 59;
            hour--;
            if (hour < 0) {
                hour = 23;
            }
        }
    }
}

void Time_::showTime() const {
    using namespace std;
    cout << "Time: ";
    if (format) {
        cout << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " UTC" << endl;
    }
    else {
        int displayHour = hour % 12;
        if (displayHour == 0) displayHour = 12;
        cout << setw(2) << setfill('0') << displayHour << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds;
        if (hour >= 12) {
            cout << " PM";
        }
        else {
            cout << " AM";
        }
        cout << endl;
    }
}


bool Time_::operator==(const Time_& obj) const& {
    return (hour == obj.hour && minutes == obj.minutes && seconds == obj.seconds && format == obj.format);
}

bool Time_::operator!=(const Time_& obj) const& {
    return !(*this == obj);
}

bool Time_::operator>(const Time_& obj) const& {
    if (hour > obj.hour) {
        return true;
    }
    else if (hour == obj.hour && minutes > obj.minutes) {
        return true;
    }
    else if (hour == obj.hour && minutes == obj.minutes && seconds > obj.seconds) {
        return true;
    }
    return false;
}

bool Time_::operator<(const Time_& obj) const& {
    return !(*this > obj || *this == obj);
}

bool Time_::operator>=(const Time_& obj) const& {
    return (*this > obj || *this == obj);
}

bool Time_::operator<=(const Time_& obj) const& {
    return (*this < obj || *this == obj);
}

Time_& Time_::operator+=(int s) {
    int totalSeconds = hour * 3600 + minutes * 60 + seconds + s;
    hour = totalSeconds / 3600;
    totalSeconds %= 3600;
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;
    return *this;
}

Time_& Time_::operator-=(int s) {
    int totalSeconds = hour * 3600 + minutes * 60 + seconds - s;
    if (totalSeconds < 0) totalSeconds += 86400;
    hour = totalSeconds / 3600;
    totalSeconds %= 3600;
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;
    return *this;
}

Time_& Time_::operator+=(float m) {
    int totalSeconds = hour * 3600 + minutes * 60 + seconds + m * 60;
    hour = totalSeconds / 3600;
    totalSeconds %= 3600;
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;
    return *this;
}

Time_& Time_::operator-=(float m) {
    int totalSeconds = hour * 3600 + minutes * 60 + seconds - m * 60;
    if (totalSeconds < 0) totalSeconds += 86400;
    hour = totalSeconds / 3600;
    totalSeconds %= 3600;
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;
    return *this;
}

Time_& Time_::operator+=(long h) {
    hour = (hour + h) % 24;
    return *this;
}

Time_& Time_::operator-=(long h) {
    if (hour - h < 0) {
        hour = 24 + (hour - h);
    }
    else {
        hour -= h;
    }
    return *this;
}



Time_ Time_::operator+(int s) const& {
    Time_ temp(*this);
    temp += s;
    return temp;
}

Time_ Time_::operator-(int s) const& {
    Time_ temp(*this);
    temp -= s;
    return temp;
}

Time_ Time_::operator+(float m) const& {
    Time_ temp(*this);
    temp += m;
    return temp;
}

Time_ Time_::operator-(float m) const& {
    Time_ temp(*this);
    temp -= m;
    return temp;
}

Time_ Time_::operator+(long h) const& {
    Time_ temp(*this);
    temp.hour += h;
    if (temp.hour >= 24) {
        temp.hour %= 24;
    }
    return temp;
}


Time_ Time_::operator-(long h) const& {
    Time_ temp(*this);
    temp -= h;
    return temp;
}

