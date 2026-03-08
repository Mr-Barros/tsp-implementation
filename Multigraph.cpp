#include "Multigraph.hpp"

Multigraph::Multigraph(int _n) : adj_list(_n, std::vector<Edge>()), n(_n), m(0) {}

void Multigraph::add_edge(int i, int j, int cost) {
    int id = m++;
    adj_list[i].push_back(Edge(id, i, j, cost));
    adj_list[j].push_back(Edge(id, j, i, cost));
}

size_t Multigraph::size() { return n; }

int Multigraph::edge_count() { return m; }

std::vector<Edge>& Multigraph::operator[](int i) { return adj_list[i]; }