#include "Date.h"

Date::Date() : day(1), month(1), year(2000) {}
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator<=(const Date& other) const {
    return *this < other || *this == other;
}

bool Date::operator>(const Date& other) const {
    return !(*this <= other);
}

bool Date::operator>=(const Date& other) const {
    return !(*this < other);
}

bool Date::isLeapYear() const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Date::isValid() const {
    if (year < 1900 || month < 1 || month > 12 || day < 1) return false;
    int daysInMonth[] = { 31, (isLeapYear() ? 29 : 28), 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31 };
    return day <= daysInMonth[month - 1];
}

int Date::daysBetween(const Date& other) const {
    return ((other.year - year) * 360 + (other.month - month) * 30 + (other.day - day));
}