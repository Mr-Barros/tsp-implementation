#include "Multigraph.hpp"

Multigraph::Multigraph(int _n) : adj_list(_n, std::vector<Edge>()), n(_n) {}
Multigraph::Multigraph(std::vector<std::vector<int>> adj_matrix) : n(adj_matrix.size()) {
    adj_list.assign(n, std::vector<Edge>());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            adj_list[i].push_back(Edge(i, j, adj_matrix[i][j]));
        }
    }
}

void Multigraph::add_edge(Edge e) { 
    adj_list[e.from].push_back(Edge(e.from, e.to, e.cost));
    adj_list[e.to].push_back(Edge(e.to, e.from, e.cost));
}

size_t Multigraph::size() { return n; }

std::vector<Edge>& Multigraph::operator[](int i) { return adj_list[i]; }