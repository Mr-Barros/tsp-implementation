#include "Graph.hpp"

Graph::Graph(int _n) : adj_matrix(_n, std::vector<int>(_n, -1)), n(_n) {}
Graph::Graph(std::vector<std::vector<int>> _adj_matrix) : adj_matrix(_adj_matrix), n(_adj_matrix.size()) {}

void Graph::add_edge(Edge e) {
    adj_matrix[e.from][e.to] = e.cost;
    adj_matrix[e.to][e.from] = e.cost;
}

size_t Graph::size() { return n; }

std::vector<int>& Graph::operator[](int i) { return adj_matrix[i]; }

int Graph::canonical_tour_length() {
    int len = 0;
    for (int i = 0; i < n - 1; i++) {
        len += adj_matrix[i][i + 1];
    }
    len += adj_matrix[n - 1][0];
    return len;
}

bool Graph::has_edge(int i, int j) { 
    return adj_matrix[i][j] != -1; 
}
