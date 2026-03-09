/// @file Graph.hpp
///
/// @brief Define a classe Graph, a representação de um grafo com pesos não-direcionado.

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

#include "types.hpp"

/// @brief Descreve um grafo com pesos não-direcionado utilizando uma matriz de adjacências.
///
/// Pode ser utilizada para descrever tanto o grafo principal do TSP quanto grafos auxiliares, 
/// como uma Árvore Geradora Mínima. 
class Graph {
private:
    std::vector<std::vector<int>> adj_matrix;   ///< A matriz de adjacências do grafo, de dimensão n x n.
    int n;                                      ///< O número de vértices do grafo.

public:
    /// @brief Inicializa o grafo com todos os pesos das arestas iguais a -1.
    /// @param _n O número de vértices do grafo.
    Graph(int _n);

    /// @brief Inicializa o grafo a partir da matriz de adjacências fornecida.
    /// @param _adj_matrix A matriz de adjacências que representa o grafo, com tamanho igual ao número de vértices.
    Graph(std::vector<std::vector<int>> _adj_matrix);

    /// @brief Adiciona uma aresta ao grafo.
    /// @param e Uma aresta do tipo Edge, que deve conter o nó de origem, o nó de destino e o peso da aresta.
    void add_edge(Edge e);

    /// @brief Retorna o tamanho do grafo, ou seja, o número de vértices.
    /// @return O número de vértices do grafo.
    size_t size();

    /// @brief Acessa o vetor de pesos das arestas adjacentes a um vértice do grafo. 
    /// @param i O vértice i do grafo.
    /// @return Uma referência ao vetor de adjacências de i, no qual a posição j armazena a distância entre i e j.
    std::vector<int>& operator[](int i);

    /// @brief Calcula o comprimento do caminho canônico, para fins de verificação.
    /// @return O comprimento do caminho formado pelos vértices 1, 2, ..., n, 1.
    int canonical_tour_length();

    /// @brief Determina se existe uma aresta entre dois vértices do grafo.
    /// @param i O vértice i do grafo.
    /// @param j O vértice j do grafo.
    /// @return "true" se existe uma aresta entre i e j, "false" caso contrário.
    bool has_edge(int i, int j);
};

#endif