/// @file Multigraph.hpp
///
/// @brief Define a classe Multigraph, que representa um multigrafo não-direcionado com pesos.

#ifndef MULTIGRAPH_H
#define MULTIGRAPH_H

#include <vector>

#include "types.hpp"

/// @brief Descreve um multigrafo não-direcionado com pesos a partir de uma lista de adjacências.
///
/// Utilizado durante a solução, na etapa de combinar a MST com o perfect matching, e em seguida na
/// etapa de encontrar um caminho euleriano.
class Multigraph {
private:
    std::vector<std::vector<Edge>> adj_list;    ///< A lista de adjacências do multigrafo, de tamanho n.
    int n;                                      ///< O número de vértices do multigrafo.
    int m;                                      ///< O número de arestas do multigrafo.

public:
    /// @brief Inicializa o multigrafo com n vértices e nenhuma.
    /// @param _n O número de vértices do multigrafo.
    Multigraph(int _n);

    /// @brief Adiciona uma aresta entre os vértices i e j, com peso cost.
    /// @param i O vértice i do multigrafo.
    /// @param j O vértice j do multigrafo.
    /// @param cost O peso da aresta entre i e j.
    void add_edge(int i, int j, int cost);

    /// @brief Retorna o tamanho do multigrafo, ou seja, o número de vértices.
    /// @return O número de vértices do multigrafo.
    size_t size();

    /// @brief Retorna a quantidade de arestas no multigrafo.
    /// @return O número de arestas do multigrafo.
    int edge_count();

    /// @brief Acessa o vetor de arestas adjacentes a um vértice do multigrafo. 
    /// @param i O vértice i do multigrafo.
    /// @return Uma referência ao vetor de arestas adjacentes a i, representadas pelo tipo Edge.
    std::vector<Edge>& operator[](int i);
};

#endif