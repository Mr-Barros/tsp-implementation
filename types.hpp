#ifndef TYPES_H
#define TYPES_H

struct Point {
    double x, y;

    Point();
    Point(double _x, double _y);
};

enum EdgeWeightType {
    EXPLICIT,
    EUC_2D,
    CEIL_2D,
    GEO,
    ATT
};

#endif