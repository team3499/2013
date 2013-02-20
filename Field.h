#ifndef FIELD_H
#define FIELD_H

#include "Target.h"
#include "Team3499/Point.h"
#include "Team3499/Rect.h"

/*
 * This class represents the playing field for the 2013 FRC game, Ultimate Ascent
 *
 *               0         1         2         3         4         5   5
 *               0         0         0         0         0         0   4
 *
 * 28    Their      /----------------------------------------------\
 * 26  Target(1)   /              |        |        |               \
 * 24             /               |        |        |                \
 * 22            |                |        |        |                 |   Our
 * 20  Target(2) |                |        |        |                 | Target(2)
 * 18            |        X       X        |        X       X         |
 * 16            |          Their |        |        |  Our            |
 * 14  Target(3) |         Pyramid|        |        |Pyramid          | Target(3)
 * 12            |                |        |        |                 |
 * 10            |        X       X        |        X       X         |
 * 08  Target(2) |                |        |        |                 | Target(2)
 * 06            |                |        |        |                 |
 * 04             \               |        |        |                /
 * 02              \              |        |        |               /   Target(1)
 * 00               \----------------------------------------------/
 *
 * Since the field is symetrical, this class models the field in terms of a
 * given team's offensive view with the coordinate origin in the lower left.
 */
class Field {

protected:
    Target                   lowTarget;
    Target                   leftMediumTarget;
    Target                   rightMediumTarget;
    Target                   highTarget;
    Team3499::Rect           offensivePyramid;
    Team3499::Rect           defensivePyramid;
    Team3499::Point          robotPosition;

};

#endif /* FIELD_H */
