#ifndef TARGET_H
#define TARGET_H

#include "Team3499/Point.h"
#include "Team3499/Rect.h"

class Target {

public:
    typedef enum {
        LOW,
        LMEDIUM,
        RMEDIUM,
        HIGH
    } ID;
                             Target(Target::ID id);

    Team3499::Point          Position() const;  // position on the field floor
    Team3499::Rect           Rectangle() const; // rect defined on target wall
    int                      Height() const;    // height of center from floor
    int                      Value() const;     // point value during teleop

    int                      DistanceTo(const Team3499::Point &point) const;  // 3d distance
    int                      HDistanceTo(const Team3499::Point &point) const; // 2d distance on floor

private:
                             Target() {};

    Team3499::Point          position;   // position on the field floor
    Team3499::Rect           rectangle;  // rect defined on target wall
    int                      height;     // height of center from floor
    int                      value;      // point value during teleop

};

#endif /* TARGET_H */
