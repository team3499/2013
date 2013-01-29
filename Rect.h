#ifndef RECT_H
#define RECT_H

#include "Point.h"

//
// A rectangle defined by 2 points -- upper left and lower right.  Uses an
// integer representation so choose a suitably small unit (cm or inch).
//
class Rect {

  public:
                             Rect();
                             Rect(const Point &a, const Point &b);
                             Rect(const Rect &r);

    int                      Area() const;
    Point                    Center() const;
    Point                    UpperLeft() const;
    Point                    UpperRight() const;
    Point                    LowerRight() const;
    Point                    LowerLeft() const;

    void                     SetUpperLeft(const Point &p);
    void                     SetLowerRight(const Point &p);

    bool                     Contains(const Point &p) const;

    bool                     operator==(const Rect &r) const;
    bool                     operator!=(const Rect &r) const;

private:
    Point                    a;
    Point                    b;

};


#endif /* RECT_H */
