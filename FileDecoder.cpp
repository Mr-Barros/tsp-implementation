#include "FileDecoder.hpp"

EdgeWeightType FileDecoder::decode_type(std::string s) {
    if (s.contains("EXPLICIT")) return EXPLICIT;
    if (s.contains("EUC_2D")) return EUC_2D;
    if (s.contains("CEIL_2D")) return CEIL_2D;
    if (s.contains("GEO")) return GEO;
    if (s.contains("ATT")) return ATT;
    std::cerr << "Tipo inválido: " << s << std::endl;
    exit(EXIT_FAILURE);
}

EdgeWeightFormat FileDecoder::decode_format(std::string s) {
    if (s.contains("FUNCTION")) return FUNCTION;
    if (s.contains("FULL_MATRIX")) return FULL_MATRIX;
    if (s.contains("UPPER_ROW")) return UPPER_ROW;
    if (s.contains("LOWER_ROW")) return LOWER_ROW;
    if (s.contains("UPPER_DIAG_ROW")) return UPPER_DIAG_ROW;
    if (s.contains("LOWER_DIAG_ROW")) return LOWER_DIAG_ROW;
    std::cerr << "Formato inválido: " << s << std::endl;
    exit(EXIT_FAILURE);
}

std::vector<Point> FileDecoder::read_node_coords(int dimension) {
    int id;
    double x, y;
    std::vector<Point> points(dimension, Point());

    for (int i = 0; i < dimension; i++) {
        input_file >> id >> x >> y; id--;
        points[id] = Point(x, y);
    }

    return points;
}

std::vector<std::vector<double>> FileDecoder::read_edge_weights(int dimension, EdgeWeightFormat format) {
    using namespace std;
    vector<vector<double>> adj_matrix(dimension, vector<double>(dimension, 0));

    for (int row = 0; row < dimension; row++) {
        int col_i = 0, col_f = dimension;

        switch (format) {
            case FUNCTION:
                cerr << "Tipo FUNCTION incompatível com a seção EDGE_WEIGHT_SECTION" << endl;
                exit(EXIT_FAILURE);
            case FULL_MATRIX: break;
            case UPPER_ROW: col_i = row + 1; break;
            case LOWER_ROW: col_f = row; break;
            case UPPER_DIAG_ROW: col_i = row; break;
            case LOWER_DIAG_ROW: col_f = row + 1; break;
        }

        for (int col = col_i; col < col_f; col++) {
            input_file >> adj_matrix[row][col];
            adj_matrix[col][row] = adj_matrix[row][col];
        }
    }

    return adj_matrix;
}

FileDecoder::FileDecoder(std::string filename) {
    using namespace std;
    string path("instance/" + filename + ".tsp");
    input_file = ifstream(path, ios_base::in);
    if (input_file.fail()) {
        throw std::format("Não foi possível abrir o arquivo: {}", filename);
    }
}

TSPInstance FileDecoder::decode_input_file() {
    using namespace std;

    int dimension;
    EdgeWeightType type;
    vector<Point> points;
    vector<vector<double>> adj_matrix;

    string line, keyword, value;
    while (getline(input_file, line)) {
        
        stringstream ss(line);
        if (line.contains(':')) {
            getline(ss, keyword, ':');
            getline(ss, value);
        } else {
            getline(ss, keyword);
        }

        if (keyword.contains("DIMENSION")) stringstream(value) >> dimension;
        else if (keyword.contains("EDGE_WEIGHT_TYPE")) type = decode_type(value);
        else if (keyword.contains("EDGE_WEIGHT_FORMAT")) format = decode_format(value);
        else if (keyword.contains("NODE_COORD_SECTION")) points = read_node_coords(dimension);
        else if (keyword.contains("EDGE_WEIGHT_SECTION")) adj_matrix = read_edge_weights(dimension, format);
    }

    return TSPInstance(dimension, type, points, adj_matrix);
}