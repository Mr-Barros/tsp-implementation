#include "TSPInstance.hpp"

TSPInstance::TSPInstance(
    int _dimension, 
    EdgeWeightType _type, 
    std::vector<Point> _points, 
    std::vector<std::vector<double>> _adj_matrix
) : dimension(_dimension), type(_type), points(_points), adj_matrix(_adj_matrix) {}
