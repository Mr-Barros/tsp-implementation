#ifndef MULTIGRAPH_H
#define MULTIGRAPH_H

#include <vector>

#include "types.hpp"

class Multigraph {
private:
    std::vector<std::vector<Edge>> adj_list;
    int n, m;

public:
    Multigraph(int _n);

    void add_edge(int i, int j, int cost);

    size_t size();

    int edge_count();

    std::vector<Edge>& operator[](int i);
};

#endif