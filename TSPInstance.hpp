#ifndef TSPINSTANCE_H
#define TSPINSTANCE_H

#include <vector>

#include "types.hpp"
#include "Graph.hpp"

class TSPInstance {
private:
    int dimension;

    EdgeWeightType type;

    std::vector<Point> points;
    std::vector<std::vector<int>> adj_matrix;

public:
    TSPInstance(
        int _dimension, 
        EdgeWeightType _type, 
        std::vector<Point> _points, 
        std::vector<std::vector<int>> _adj_matrix
    );
};

#endif