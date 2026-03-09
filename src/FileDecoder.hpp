/// @file FileDecoder.hpp
///
/// @brief Define a classe FileDecoder, utilizada para extrair uma instância do TSP de um arquivo .tsp.

#ifndef FILEDECODER_H
#define FILEDECODER_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "TSPInstance.hpp"

/// @brief Responsável por decodificar o arquivo .tsp correspondente a uma instância do TSP simétrico.
///
/// Sua funcionalidade principal está em decode_input_file, que cria um objeto do tipo TSPInstance após
/// decodificar o arquivo de entrada.
class FileDecoder {
private:
    std::ifstream input_file;   ///< O arquivo de texto .tsp que descreve a instância.
    EdgeWeightFormat format;    ///< O formato no qual os pesos das arestas são dados no arquivo.

    /// @brief Determina a forma como os pesos das arestas serão calculados, a partir do texto do arquivo.
    /// @param s A string de valor correspondente à seção EDGE_WEIGHT_TYPE.
    /// @return Um enum EdgeWeightType, que indica o tipo de peso das arestas.
    EdgeWeightType decode_type(std::string s);

    /// @brief Determina o formato no qual os pesos das arestas são dados, a partir do texto do arquivo.
    /// @param s A string de valor correspondente à seção EDGE_WEIGHT_FORMAT.
    /// @return Um enum EdgeWeightFormat, que indica o formato dos pesos na seção EDGE_WEIGHT_SECTION.
    EdgeWeightFormat decode_format(std::string s);

    /// @brief Lê as informações da seção NODE_COORD_SECTION, armazenando-as em um vetor de pontos.
    /// @param dimension A quantidade de vértices do grafo.
    /// @return Um vetor com as coordenadas de cada ponto lido.
    std::vector<Point> read_node_coords(int dimension);

    /// @brief Lê as informações da seção EDGE_WEIGHT_SECTION, armazenando-as em uma matriz de adjacências.
    /// @param dimension A quantidade de vértices do grafo.
    /// @param format O formato em que os pesos são apresentados.
    /// @return Uma matriz dimension x dimension, em que cada célula (i, j) possui um inteiro com a distância entre i e j.
    std::vector<std::vector<int>> read_edge_weights(int dimension, EdgeWeightFormat format);

public:
    /// @brief Inicializa o FileDecoder, abrindo o arquivo de entrada correspondente.
    /// @param filename O nome do arquivo de entrada, sem a extensão .tsp. Deve estar presente na pasta instance.
    FileDecoder(std::string filename);

    /// @brief Percorre o arquivo de entrada, criando uma TSPInstance com as informações extraídas.
    /// @return Um objeto do tipo TSPInstance, que pode ter o vetor de pontos ou a matriz de 
    /// adjacências preenchida, de acordo com a especificação da instância.
    TSPInstance decode_input_file();
};

#endif