#include <math.h>

#include "Point.h"

using namespace Team3499;

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

bool Point::IsLeft(const Point &p) const {
    return x <= p.x;
}

bool Point::IsRight(const Point &p) const {
    return x >= p.x;
}

bool Point::IsAbove(const Point &p) const {
    return y >= p.y;
}

bool Point::IsBelow(const Point &p) const {
    return y <= p.y;
}

bool Point::IsAboveLeft(const Point &p) const {
    return IsAbove(p) && IsLeft(p);
}

bool Point::IsAboveRight(const Point &p) const {
    return IsAbove(p) && IsRight(p);
}

bool Point::IsBelowRight(const Point &p) const {
    return IsBelow(p) && IsRight(p);
}

bool Point::IsBelowLeft(const Point &p) const {
    return IsBelow(p) && IsLeft(p);
}

bool Point::operator==(const Point &p) const {
    return x == p.x && y == p.y;
}

bool Point::operator!=(const Point &p) const {
    return !operator==(p);
}

