#ifndef MULTIGRAPH_H
#define MULTIGRAPH_H

#include <vector>

#include "types.hpp"

class Multigraph {
private:
    std::vector<std::vector<Edge>> adj_list;
    int n;

public:
    Multigraph(int _n);
    Multigraph(std::vector<std::vector<int>> adj_matrix);

    void add_edge(Edge e);

    size_t size();

    std::vector<Edge>& operator[](int i);
};

#endif