#include <Solution.hpp>

Graph Solution::minimum_spanning_tree(Graph g) {
    using namespace std;

    int n = g.size();
    Graph mst(n);
    priority_queue<Edge, vector<Edge>, greater<Edge>()> edges;
    vector<bool> included(n, false);

    included[0] = true;
    for (int to = 0; to < n; to++) {
        edges.push(Edge(0, to, g[0][to]));
    }

    while (!edges.empty()) {
        Edge e = edges.top(); 
        edges.pop();

        if (included[e.to]) continue;

        mst.add_edge(e);

        included[e.to] = true;
        for (int i = 0; i < n; i++) {
            edges.push(Edge(e.to, i, g[e.to][i]));
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

Graph Solution::perfect_matching(Graph g, std::set<int> nodes) {
    using namespace std;

    int n = g.size();
    Graph matching(n);
    priority_queue<Edge, vector<Edge>, greater<Edge>()> edges;

    for (int i : nodes) {
        for (int j : nodes) {
            if (i >= j) continue;
            edges.push(Edge(i, j, g[i][j]));
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
            if (g1.has_edge(i, j)) mg.add_edge(Edge(i, j, g1[i][j]));
            if (g2.has_edge(i, j)) mg.add_edge(Edge(i, j, g2[i][j]));
        }
    }

    return mg;
}

void Solution::dfs(int i, Multigraph& mg, std::map<Edge, bool>& vis_edge, std::vector<int>& euler_tour) {
    for (Edge e : mg[i]) {
        if (vis_edge[e]) continue;
        dfs(e.to, mg, vis_edge, euler_tour);
    }
    euler_tour.push_back(i);
}

std::vector<int> Solution::find_eulerian_tour(Multigraph mg) {
    using namespace std;

    map<Edge, bool> vis_edge;
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

std::vector<int> Solution::find_tsp_tour(Graph g) {
    using namespace std;

    // 1 - Encontrar Árvore Geradora Mínima do grafo
    Graph mst = minimum_spanning_tree(g);

    // 2 - Isolar conjunto S de vértices de grau ímpar da AGM
    set<int> nodes = odd_degree_nodes(mst);

    // 3 - Encontrar Min Weight Perfect Matching M do conjunto S
    Graph matching = perfect_matching(g, nodes);

    // 4 - Combinar T e M em um multigrafo G
    Multigraph mg = combine_into_multigraph(mst, matching);

    // 5 - Gerar caminho euleriano de G
    vector<int> euler_tour = find_eulerian_tour(mg);

    // 6 - Gerar caminho TSP a partir do caminho euleriano
    vector<int> tsp_tour = convert_into_tsp_tour(euler_tour);

    return tsp_tour;
}