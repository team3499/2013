#include <math.h>
#include "Target.h"

Target::Target(Target::ID id) {
    switch (id) {
        case LOW:
            position  = Point(635,39);
            rectangle = Rect(Point(270,33), Point(299,19));
            value     = 1;
            break;
        case LMEDIUM:
            position  = Point(648,234);
            rectangle = Rect(Point(63,110), Point(117,89));
            value     = 2;
            break;
        case RMEDIUM:
            position  = Point(648,90);
            rectangle = Rect(Point(207,110), Point(261,89));
            value     = 2;
            break;
        case HIGH:
            position  = Point(648,162);
            rectangle = Rect(Point(135,116), Point(189,104));
            value     = 3;
            break;
        default:
            break;
    }
}

Point Target::Position() const {
    return position;
}

Rect Target::Rectangle() const {
    return rectangle;
}

int Target::Height() const {
    return rectangle.Center().y;
}

int Target::Value() const {
    return value;
}

int Target::DistanceTo(const Point &point) const {
    return (int)sqrt(pow(HDistanceTo(point), 2) + pow(Height(), 2));
}

int Target::HDistanceTo(const Point &point) const {
    return point.DistanceTo(position);
}
