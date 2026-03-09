/// @file Solution.cpp
///
/// @brief Implementa as funções da classe Solution, definida em Solution.hpp.

#include "Solution.hpp"

Graph Solution::minimum_spanning_tree() {
    using namespace std;

    int n = tsp_graph.size();
    Graph mst(n);
    priority_queue<Edge, vector<Edge>, greater<Edge>> edges;
    vector<bool> included(n, false);

    included[0] = true;
    for (int to = 0; to < n; to++) {
        if (tsp_graph.has_edge(0, to)) edges.push(Edge(0, to, tsp_graph[0][to]));
    }

    while (!edges.empty()) {
        Edge e = edges.top(); 
        edges.pop();

        if (included[e.to]) continue;

        mst.add_edge(e);

        included[e.to] = true;
        for (int i = 0; i < n; i++) {
            if (tsp_graph.has_edge(e.to, i)) edges.push(Edge(e.to, i, tsp_graph[e.to][i]));
        }
    }

    return mst;
}

std::set<int> Solution::odd_degree_nodes(Graph g) {
    int n = g.size();
    std::set<int> nodes;
    for (int i = 0; i < n; i++) {
        int deg = 0;
        for (int j = 0; j < n; j++) {
            if (g.has_edge(i, j)) deg++;
        }
        if (deg % 2 == 1) nodes.insert(i);
    }
    return nodes;
}

Graph Solution::perfect_matching(std::set<int> nodes) {
    using namespace std;

    int n = tsp_graph.size();
    Graph matching(n);
    priority_queue<Edge, vector<Edge>, greater<Edge>> edges;

    for (int i : nodes) {
        for (int j : nodes) {
            if (i >= j) continue;
            edges.push(Edge(i, j, tsp_graph[i][j]));
        }
    }

    while (!edges.empty()) {
        Edge e = edges.top();
        edges.pop();
        
        if (nodes.contains(e.from) and nodes.contains(e.to)) {
            matching.add_edge(e);
            nodes.erase(e.from);
            nodes.erase(e.to);
        }
    }

    return matching;
}

Multigraph Solution::combine_into_multigraph(Graph g1, Graph g2) {
    int n = g1.size();
    Multigraph mg(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (g1.has_edge(i, j)) mg.add_edge(i, j, g1[i][j]);
            if (g2.has_edge(i, j)) mg.add_edge(i, j, g2[i][j]);
        }
    }

    return mg;
}

void Solution::dfs(int i, Multigraph& mg, std::vector<bool>& vis_edge, std::vector<int>& euler_tour) {
    for (Edge e : mg[i]) {
        if (vis_edge[e.id]) continue;
        vis_edge[e.id] = true;
        dfs(e.to, mg, vis_edge, euler_tour);
    }
    euler_tour.push_back(i);
}

std::vector<int> Solution::find_eulerian_tour(Multigraph mg) {
    using namespace std;

    vector<bool> vis_edge(mg.edge_count(), false);
    vector<int> euler_tour;

    dfs(0, mg, vis_edge, euler_tour);

    reverse(euler_tour.begin(), euler_tour.end());

    return euler_tour;
}

std::vector<int> Solution::convert_into_tsp_tour(std::vector<int> euler_tour) {
    using namespace std;

    int n = euler_tour.size();
    vector<int> tsp_tour;

    map<int, bool> vis;

    for (int i = 0; i < n; i++) {
        if (vis[euler_tour[i]]) continue;
        tsp_tour.push_back(euler_tour[i]);
        vis[euler_tour[i]] = true;
    }

    return tsp_tour;
}

Solution::Solution(Graph _tsp_graph) : tsp_graph(_tsp_graph) {}

std::vector<int> Solution::find_tsp_tour() {
    using namespace std;

    // 1 - Encontrar Árvore Geradora Mínima (MST) do grafo
    Graph mst = minimum_spanning_tree();

    // 2 - Isolar conjunto de vértices de grau ímpar da AGM
    set<int> nodes = odd_degree_nodes(mst);

    // 3 - Encontrar perfect matching do conjunto de vértices
    Graph matching = perfect_matching(nodes);

    // 4 - Combinar MST e perfect matching em um multigrafo
    Multigraph mg = combine_into_multigraph(mst, matching);

    // 5 - Gerar caminho euleriano do multigrafo
    vector<int> euler_tour = find_eulerian_tour(mg);

    // 6 - Gerar caminho TSP a partir do caminho euleriano
    vector<int> tsp_tour = convert_into_tsp_tour(euler_tour);

    return tsp_tour;
}

int Solution::tsp_tour_cost(std::vector<int> tsp_tour) {
    if (tsp_graph.size() != tsp_tour.size()) {
        std::cerr << "Erro inesperado: tamanho do caminho TSP é diferente do tamanho do grafo" << std::endl;
        exit(EXIT_FAILURE);
    }

    int n = tsp_graph.size();
    int cost = 0;
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        u = tsp_tour[i];
        v = tsp_tour[i + 1];
        cost += tsp_graph[u][v];
    }
    cost += tsp_graph[v][tsp_tour[0]];

    return cost;
}