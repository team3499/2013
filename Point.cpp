#include <math.h>

#include "Point.h"

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point::Point(const Point &p) {
    x = p.x;
    y = p.y;
}

int Point::DistanceTo(const Point &p) const {
    return DistanceTo(p.x, p.y);
}

int Point::DistanceTo(int x, int y) const {
    return (int)sqrt(pow(this->x - x, 2) + pow(this->y - y, 2));
}

Point Point::operator+(const Point &p) const {
    Point q = Point(*this);
    q += p;
    return q;
}

void Point::operator+=(const Point &p) {
    x += p.x;
    y += p.y;
}

Point Point::operator-(const Point &p) const {
    Point q = Point(*this);
    q -= p;
    return q;
}

void Point::operator-=(const Point &p ) {
    x -= p.x;
    y -= p.y;
}

bool Point::operator<(const Point &p) const {
    return true;
}

bool Point::operator>(const Point &p) const {
    return true;
}

bool Point::operator<=(const Point &p) const {
    return true;
}

bool Point::operator>=(const Point &p) const {
    return true;
}

bool Point::operator==(const Point &p) const {
    return x == p.x && y == p.y;
}

bool Point::operator!=(const Point &p) const {
    return !operator==(p);
}

