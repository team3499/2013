#ifndef TARGET_H
#define TARGET_H

#include "Point.h"
#include "Rect.h"

class Target {

public:
    typedef enum {
        LOW,
        LMEDIUM,
        RMEDIUM,
        HIGH
    } ID;
                             Target(Target::ID id);

    Point                    Position() const;  // position on the field floor
    Rect                     Rectangle() const; // rect defined on target wall
    int                      Height() const;    // height of center from floor
    int                      Value() const;     // point value during teleop

    int                      DistanceTo(const Point &point) const;  // 3d distance
    int                      HDistanceTo(const Point &point) const; // 2d distance on floor

private:
                             Target() {};

    Point                    position;   // position on the field floor
    Rect                     rectangle;  // rect defined on target wall
    int                      height;     // height of center from floor
    int                      value;      // point value during teleop

};

#endif /* TARGET_H */
