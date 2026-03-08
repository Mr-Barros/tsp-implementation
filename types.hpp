#ifndef TYPES_H
#define TYPES_H

struct Point {
    double x, y;

    Point();
    Point(double _x, double _y);
};

struct Edge {
    int from, to, cost;

    Edge(int _from, int _to, int _cost);

    bool operator>(const Edge& other) const;
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