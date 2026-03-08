#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

#include "types.hpp"

class Graph {
private:
    std::vector<std::vector<int>> adj_matrix;
    int n;

public:
    Graph(int _n);
    Graph(std::vector<std::vector<int>> _adj_matrix);

    void add_edge(Edge e);

    size_t size();

    std::vector<int>& operator[](int i);

    int canonical_tour_length();

    bool has_edge(int i, int j);
};

#endif