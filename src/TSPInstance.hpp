/// @file TSPInstance.hpp
///
/// @brief Define a classe TSPInstance, que armazena e interpreta os dados da instância para criar o grafo correspondente.

#ifndef TSPINSTANCE_H
#define TSPINSTANCE_H

#include <vector>
#include <cmath>

#include "types.hpp"
#include "Graph.hpp"

/// @brief Responsável por construir um objeto do tipo Graph, a partir das informações da instância do TSP.
class TSPInstance {
private:
    int n;                                      ///< A dimensão do grafo.

    EdgeWeightType type;                        ///< A forma como os pesos das arestas devem ser calculados.

    std::vector<Point> points;                  ///< Armazena as coordenadas de cada vértice do grafo.
    std::vector<std::vector<int>> adj_matrix;   ///< Matriz de adjacências do grafo, de dimensão n x n.

    std::vector<double> latitude;               ///< As latitudes dos vértices do grafo.
    std::vector<double> longitude;              ///< As longitudes dos vértices do grafo.

    /// @brief Arredonda um número de ponto flutuante para o inteiro mais próximo.
    /// @param x O valor a ser arredondado.
    /// @return O inteiro resultante da operação.
    int nint(double x);

    /// @brief Calcula a latitude e longitude de cada vértice do grafo, a partir da representação descrita na seção 2.4 do artigo.
    void calculate_geo_coords();

    /// @brief Calcula a distância euclidiana entre dois vértices do grafo.
    /// @param i O vértice i do grafo.
    /// @param j O vértice j do grafo.
    /// @return A distância euclidiana entre os vértices i e j.
    int euclidean_distance(int i, int j);

    /// @brief Calcula a distância geográfica entre dois vértices do grafo.
    /// @param i O vértice i do grafo.
    /// @param j O vértice j do grafo.
    /// @return A distância geográfica entre os vértices i e j.
    int geographical_distance(int i, int j);

    /// @brief Calcula a distância entre dois vértices do grafo, utilizando a função especial ATT.
    /// @param i O vértice i do grafo.
    /// @param j O vértice j do grafo.
    /// @return A distância ATT entre os vértices i e j.
    int pseudo_euclidean_distance(int i, int j);

    /// @brief Calcula o teto da distância euclidiana entre dois vértices do grafo.
    /// @param i O vértice i do grafo.
    /// @param j O vértice j do grafo.
    /// @return A distância euclidiana entre os vértices i e j, arredondada para cima.
    int ceiling_euclidean_distance(int i, int j);

public:
    /// @brief Inicializa um objeto TSPInstance com as informações extraídas do arquivo .tsp.
    /// @param _n A dimensão do grafo.
    /// @param _type A forma como os pesos das arestas são calculados.
    /// @param _points O vetor de coordenadas dos pontos do grafo.
    /// @param _adj_matrix A matriz de adjacências do grafo.
    TSPInstance(
        int _n, 
        EdgeWeightType _type, 
        std::vector<Point> _points, 
        std::vector<std::vector<int>> _adj_matrix
    );

    /// @brief Preenche a matriz de adjacências com as distâncias entre os vértices e cria um objeto do tipo Graph. 
    /// @return O objeto do tipo Graph correspondente ao grafo da instância, com todos os pesos calculados.
    Graph build_graph();
};

#endif