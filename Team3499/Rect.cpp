
#include <stdlib.h>
#include "Rect.h"

using namespace Team3499;

Rect::Rect() {
    SetUpperLeft(Point(0,0));
    SetLowerRight(Point(0,0));
}

Rect::Rect(const Point &a, const Point &b) {
    this->a = Point(a);
    SetLowerRight(b);
}

Rect::Rect(const Rect &r) {
    this->a = r.UpperLeft();
    this->b = r.LowerRight();
}

int Rect::Area() const {
    return (int)labs(b.x - a.x) * (int)labs(b.y - a.y);
}

Point Rect::Center() const {
    return Point(a.x + (b.x - a.x)/2, a.y + (b.y - a.y)/2);
}

Point Rect::UpperLeft() const {
    return a;
}

Point Rect::UpperRight() const {
    return Point(b.x, a.y);
}

Point Rect::LowerRight() const {
    return b;
}

Point Rect::LowerLeft() const {
    return Point(a.x, b.y);
}

void Rect::SetUpperLeft(const Point &p) {
    if (p.IsAboveRight(b)) {
        a = Point(b.x, p.y);
        b = Point(p.x, b.y);
    } else if (p.IsBelowLeft(b)) {
        a = Point(p.x, b.y);
        b = Point(b.x, p.y);
    } else if (p.IsBelowRight(b)) {
        a = b;
        b = Point(p);
    } else {
        a = Point(p);
    }
}

void Rect::SetLowerRight(const Point &p) {
    if (p.IsBelowLeft(a)) {
        b = Point(a.x, p.y);
        a = Point(p.x, a.y);
    } else if (p.IsAboveRight(a)) {
        b = Point(p.x, a.y);
        a = Point(a.x, p.y);
    } else if (p.IsAboveLeft(a)) {
        b = a;
        a = Point(p);
    } else {
        b = Point(p);
    }
}

bool Rect::Contains(const Point &p) const {
    return p.IsBelowRight(a) && p.IsAboveLeft(b);
}

bool Rect::operator==(const Rect &r) const {
    return a == r.a && b == r.b;
}

bool Rect::operator!=(const Rect &r) const {
    return !operator==(r);
}
