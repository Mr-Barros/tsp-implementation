#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>

#include "Graph.hpp"
#include "Multigraph.hpp"

class Solution {
private:
    Graph minimum_spanning_tree(Graph g);

    std::set<int> odd_degree_nodes(Graph g);

    Graph perfect_matching(Graph g, std::set<int> nodes);

    Multigraph combine_into_multigraph(Graph g1, Graph g2);

    void dfs(int i, Multigraph& mg, std::map<Edge, bool>& vis_edge, std::vector<int>& euler_tour);

    std::vector<int> find_eulerian_tour(Multigraph mg);

    std::vector<int> convert_into_tsp_tour(std::vector<int> euler_tour);

public:
    std::vector<int> find_tsp_tour(Graph g);
};

#endif