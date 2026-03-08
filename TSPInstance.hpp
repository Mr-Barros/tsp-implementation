#ifndef TSPINSTANCE_H
#define TSPINSTANCE_H

#include <vector>
#include <cmath>

#include "types.hpp"
#include "Graph.hpp"

class TSPInstance {
private:
    int n;

    EdgeWeightType type;

    std::vector<Point> points;
    std::vector<std::vector<int>> adj_matrix;

    std::vector<double> latitude, longitude;

    int nint(double x);

    void calculate_geo_coords();

    int euclidean_distance(int i, int j);

    int geographical_distance(int i, int j);

    int pseudo_euclidean_distance(int i, int j);

    int ceiling_euclidean_distance(int i, int j);

public:
    TSPInstance(
        int _n, 
        EdgeWeightType _type, 
        std::vector<Point> _points, 
        std::vector<std::vector<int>> _adj_matrix
    );

    Graph build_graph();
};

#endif