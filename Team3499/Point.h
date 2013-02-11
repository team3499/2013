#ifndef POINT_H
#define POINT_H

namespace Team3499 {

//
// A point on a 2D plane.  Uses an integer representation so choose a suitably
// small unit (cm or inch).
//
class Point {

public:
    int                      x;
    int                      y;

                             Point();
                             Point(int x, int y);
                             Point(const Point &p);

    int                      DistanceTo(const Point &p) const;
    int                      DistanceTo(int x, int y) const;

    Point                    operator+(const Point &p) const;
    void                     operator+=(const Point &p);
    Point                    operator-(const Point &p) const;
    void                     operator-=(const Point &p);

    bool                     IsLeft(const Point &p) const;
    bool                     IsRight(const Point &p) const;
    bool                     IsAbove(const Point &p) const;
    bool                     IsBelow(const Point &p) const;
    bool                     IsAboveLeft(const Point &p) const;
    bool                     IsAboveRight(const Point &p) const;
    bool                     IsBelowRight(const Point &p) const;
    bool                     IsBelowLeft(const Point &p) const;

    bool                     operator==(const Point &p) const;
    bool                     operator!=(const Point &p) const;

private:

};

} // namespace Team3499

#endif /* POINT_H */
