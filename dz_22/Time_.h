#pragma once

class Time_ {
    int hour;
    int minutes;
    int seconds;
    bool format;

public:
    Time_();
    Time_(int hour, int minutes, int seconds, bool format = true);
    Time_(const Time_& obj);
    Time_& operator=(const Time_& obj);
    ~Time_();

    void setHour(int hour);
    int getHour() const;
    void setMinutes(int minutes);
    int getMinutes() const;
    void setSeconds(int seconds);
    int getSeconds() const;
    void setFormat(bool format);
    bool getFormat() const;

    bool valid() const;
    void tickTime();
    void untickTime();
    void showTime() const;

    bool operator==(const Time_& obj) const&;
    bool operator!=(const Time_& obj) const&;
    bool operator>(const Time_& obj) const&;
    bool operator<(const Time_& obj) const&;
    bool operator>=(const Time_& obj) const&;
    bool operator<=(const Time_& obj) const&;

    Time_& operator+=(int s);
    Time_& operator-=(int s);
    Time_& operator+=(float m);
    Time_& operator-=(float m);
    Time_& operator+=(long h);
    Time_& operator-=(long h);

    Time_ operator+(int s) const&;
    Time_ operator-(int s) const&;
    Time_ operator+(float m) const&;
    Time_ operator-(float m) const&;
    Time_ operator+(long h) const&;
    Time_ operator-(long h) const&;
};

