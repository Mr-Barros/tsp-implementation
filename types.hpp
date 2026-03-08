/// @file types.hpp
///
/// @brief Define os tipos Point, Edge, EdgeWeightType e EdgeWeightFormat.
///
/// Tipos auxiliares utilizados em diferentes partes do projeto, 
/// como para armazenar as informações de uma instância do TSP ou 
/// para auxiliar na representação de um grafo.

#ifndef TYPES_H
#define TYPES_H

/// @brief Representa um ponto no plano cartesiano.
struct Point {
    double x;   ///< A coordenada x do ponto.
    double y;   ///< A coordenada y do ponto.

    /// @brief Inicializa o ponto com ambas as coordenadas em 0.
    Point();

    /// @brief Inicializa o ponto com valores definidos de x e y.
    /// @param _x A coordenada x do ponto.
    /// @param _y A coordenada y do ponto.
    Point(double _x, double _y);
};

/// @brief Representa uma aresta em um grafo com pesos.
struct Edge {
    int id;     ///< O identificador único da aresta.
    int from;   ///< O vértice de origem da aresta.
    int to;     ///< O vértice de destino da aresta.
    int cost;   ///< O peso (ou custo) da aresta.

    /// @brief Inicializa a aresta com os parâmetros from, to e cost fornecidos, e o parâmetro id em -1.
    /// @param _from O vértice de origem da aresta.
    /// @param _to O vértice de destino da aresta.
    /// @param _cost O peso (ou custo) da aresta.
    Edge(int _from, int _to, int _cost);
    
    /// @brief Inicializa a aresta com os parâmetros id, from, to e cost fornecidos.
    /// @param _id O identificador único da aresta.
    /// @param _from O vértice de origem da aresta.
    /// @param _to O vértice de destino da aresta.
    /// @param _cost O peso (ou custo) da aresta.
    Edge(int _id, int _from, int _to, int _cost);

    /// @brief Compara duas arestas e determina se a aresta à esquerda tem peso maior.
    /// @param other A aresta à direita da comparação.
    /// @return "true" caso a aresta à esquerda da comparação tenha peso maior, "false" caso contrário.
    bool operator>(const Edge& other) const;
};

/// @brief Determina a forma como os pesos (ou distâncias) das arestas são dados na instância.
enum EdgeWeightType {
    EXPLICIT,       ///< Pesos são fornecidos explicitamente na seção EDGE_WEIGHT_SECTION.
    EUC_2D,         ///< Os pesos são as distâncias euclidianas em 2D entre os pontos.
    CEIL_2D,        ///< Os pesos são as distâncias euclidianas em 2D entre os pontos, arredondadas para cima.
    GEO,            ///< Os pesos são distâncias geográficas entre pontos na superfície da Terra.
    ATT             ///< Uma função especial determina as distâncias nos problemas att48 e att532.
};

/// @brief Indica o formato no qual os pesos das arestas são fornecidos pela instância, na seção EDGE_WEIGHT_SECTION.
enum EdgeWeightFormat {
    FUNCTION,       ///< Os pesos são determinados por uma função de distância, dentre as opções de EdgeWeightType.
    FULL_MATRIX,    ///< Os pesos são dados em uma matriz completa.
    UPPER_ROW,      ///< Matriz triangular superior, sem a diagonal principal.
    LOWER_ROW,      ///< Matriz triangular inferior, sem a diagonal principal.
    UPPER_DIAG_ROW, ///< Matriz triangular superior, com a diagonal principal.
    LOWER_DIAG_ROW  ///< Matriz triangular inferior, com a diagonal principal.
};

#endif