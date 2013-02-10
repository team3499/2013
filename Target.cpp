#include <math.h>
#include "Target.h"

Target::Target(Target::ID id) {
    switch (id) {
        case LOW:
            position  = Team3499::Point(635,39);
            rectangle = Team3499::Rect(Team3499::Point(270,33), Team3499::Point(299,19));
            value     = 1;
            break;
        case LMEDIUM:
            position  = Team3499::Point(648,234);
            rectangle = Team3499::Rect(Team3499::Point(63,110), Team3499::Point(117,89));
            value     = 2;
            break;
        case RMEDIUM:
            position  = Team3499::Point(648,90);
            rectangle = Team3499::Rect(Team3499::Point(207,110), Team3499::Point(261,89));
            value     = 2;
            break;
        case HIGH:
            position  = Team3499::Point(648,162);
            rectangle = Team3499::Rect(Team3499::Point(135,116), Team3499::Point(189,104));
            value     = 3;
            break;
        default:
            break;
    }
}

Team3499::Point Target::Position() const {
    return position;
}

Team3499::Rect Target::Rectangle() const {
    return rectangle;
}

int Target::Height() const {
    return rectangle.Center().y;
}

int Target::Value() const {
    return value;
}

int Target::DistanceTo(const Team3499::Point &point) const {
    return (int)sqrt(pow(HDistanceTo(point), 2) + pow(Height(), 2));
}

int Target::HDistanceTo(const Team3499::Point &point) const {
    return point.DistanceTo(position);
}
