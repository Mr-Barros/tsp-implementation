#ifndef FILEDECODER_H
#define FILEDECODER_H

#include <iostream>
#include <fstream>
#include <sstream>

#include "TSPInstance.hpp"

class FileDecoder {
private:
    std::ifstream input_file;
    EdgeWeightFormat format;

    EdgeWeightType decode_type(std::string s);

    EdgeWeightFormat decode_format(std::string s);

    std::vector<Point> read_node_coords(int dimension);

    std::vector<std::vector<int>> read_edge_weights(int dimension, EdgeWeightFormat format);

public:
    FileDecoder(std::string filename);

    TSPInstance decode_input_file();
};

#endif