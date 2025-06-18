#pragma once

class Date {
private:
    int day;
    int month;
    int year;

    bool isLeapYear() const;

public:
    Date();
    Date(int d, int m, int y);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    bool operator==(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator>=(const Date& other) const;

    int daysBetween(const Date& other) const;
    bool isValid() const;
};