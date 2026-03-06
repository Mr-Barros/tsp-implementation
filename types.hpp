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

enum EdgeWeightFormat {
    FUNCTION,
    FULL_MATRIX,
    UPPER_ROW,
    LOWER_ROW,
    UPPER_DIAG_ROW,
    LOWER_DIAG_ROW
};

#endif