/// @file Solution.cpp
///
/// @brief Define a classe Solution, responsável por encontrar uma solução heurística do TSP em tempo polinomial.

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

/// @brief Implementa o algoritmo de Christofides para resolver uma instância do TSP. 
/// 
/// Como funções auxiliares, implementa o algoritmo de Prim para encontrar a MST, 
/// um algoritmo guloso para fazer o perfect matching, e um algoritmo baseado em 
/// depth first search para encontrar o caminho euleriano.
class Solution {
private:
    /// @brief Encontra a Árvore Geradora Mínima (MST) do grafo do TSP, utilizando o algoritmo de Prim.
    /// @param g O grafo completo com pesos não-direcionado que representa a instância do TSP.
    /// @return O grafo que representa a MST do grafo original.
    Graph minimum_spanning_tree(Graph g);

    /// @brief Determina o conjunto de vértices do grafo g que possuem grau ímpar.
    /// @param g Um grafo com pesos não-direcionado.
    /// @return O conjunto de inteiros que representam os vértices de grau ímpar.
    std::set<int> odd_degree_nodes(Graph g);

    /// @brief Seleciona as arestas de um grafo completo para fazer um perfect 
    /// matching entre um conjunto par de vértices. Utiliza um algoritmo guloso
    /// para tentar minimizar o custo total.
    /// @param g Um grafo completo com pesos não-direcionado.
    /// @param nodes Um conjunto par de vértices de g.
    /// @return Um grafo que representa o matching realizado.
    Graph perfect_matching(Graph g, std::set<int> nodes);

    /// @brief Combina dois grafos de mesma dimensão em um multigrafo.
    /// @param g1 O primeiro grafo.
    /// @param g2 O segundo grafo.
    /// @return Um multigrafo cujo conjunto de arestas é a junção das arestas de g1 e g2.
    Multigraph combine_into_multigraph(Graph g1, Graph g2);

    /// @brief Implementa uma busca em profundidade baseada em arestas de um multigrafo, 
    /// inserindo os vértices visitados no caminho euleriano.
    /// @param i O vértice a ser visitado.
    /// @param mg O multigrafo a ser percorrido.
    /// @param vis_edge O vetor de arestas visitadas.
    /// @param euler_tour O vetor com os vértices do caminho euleriano.
    void dfs(int i, Multigraph& mg, std::vector<bool>& vis_edge, std::vector<int>& euler_tour);

    /// @brief Encontra um caminho euleriano em um multigrafo.
    /// @param mg Um multigrafo.
    /// @return Um vetor de vértices de mg, na ordem em que aparecem no caminho euleriano.
    std::vector<int> find_eulerian_tour(Multigraph mg);

    /// @brief Converte um caminho euleriano em um caminho TSP.
    /// @param euler_tour O caminho euleriano de um grafo.
    /// @return O vetor de vértices do grafo, na ordem em que aparecem no caminho TSP.
    std::vector<int> convert_into_tsp_tour(std::vector<int> euler_tour);

public:
    /// @brief Encontra um caminho TSP para o grafo descrito em uma instância do TSP, 
    /// utilizando uma implementação do algoritmo de Christofides.
    /// @param g O grafo que representa a instância do TSP.
    /// @return O vetor referente a um caminho TSP em g. 
    /// Contém vértices de g na ordem em que aparecem no caminho.
    std::vector<int> find_tsp_tour(Graph g);
};

#endif