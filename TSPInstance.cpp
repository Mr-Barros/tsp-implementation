#include "TSPInstance.hpp"

int TSPInstance::nint(double x) { return (int) (x + 0.5); }

void TSPInstance::calculate_geo_coords() {
    latitude.assign(n, 0);
    longitude.assign(n, 0);

    const double PI = 3.141592;
    int deg, min;
    
    for (int i = 0; i < n; i++) {
        deg = nint(points[i].x);
        min = points[i].x - deg;
        latitude[i] = PI * (deg + 5.0 * min / 3.0) / 180.0;
        deg = nint(points[i].y);
        min = points[i].y - deg;
        longitude[i] = PI * (deg + 5.0 * min / 3.0) / 180.0;
    }
}

int TSPInstance::euclidean_distance(int i, int j) {
    double xd = points[i].x - points[j].x;
    double yd = points[i].y - points[j].y;
    return nint(sqrt(xd * xd + yd * yd));
}

int TSPInstance::geographical_distance(int i, int j) {
    const double RRR = 6378.388;
    double q1 = cos(longitude[i] - longitude[j]);
    double q2 = cos(latitude[i] - latitude[j]);
    double q3 = cos(latitude[i] + latitude[j]);
    return (int) (RRR * acos(0.5 * ((1.0 + q1) * q2 - (1.0 - q1) * q3)) + 1.0);
}

int TSPInstance::pseudo_euclidean_distance(int i, int j) {
    double xd = points[i].x - points[j].x;
    double yd = points[i].y - points[j].y;
    double r = sqrt((xd * xd + yd * yd) / 10.0);
    int t = nint(r);
    return t < r ? t + 1 : t;
}

int TSPInstance::ceiling_euclidean_distance(int i, int j) {
    double xd = points[i].x - points[j].x;
    double yd = points[i].y - points[j].y;
    return (int) ceil(sqrt(xd * xd + yd * yd));
}

TSPInstance::TSPInstance(
    int _n, 
    EdgeWeightType _type, 
    std::vector<Point> _points, 
    std::vector<std::vector<int>> _adj_matrix
) : n(_n), type(_type), points(_points), adj_matrix(_adj_matrix) {}

Graph TSPInstance::build_graph() {
    adj_matrix.assign(n, std::vector<int>(n, 0));

    if (type == GEO) calculate_geo_coords();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            switch (type) {
            case EXPLICIT:
                break;
            case EUC_2D:
                adj_matrix[i][j] = euclidean_distance(i, j);
                break;
            case CEIL_2D:
                adj_matrix[i][j] = ceiling_euclidean_distance(i, j);
                break;
            case GEO:
                adj_matrix[i][j] = geographical_distance(i, j);
                break;
            case ATT:
                adj_matrix[i][j] = pseudo_euclidean_distance(i, j);
                break;
            }

            adj_matrix[j][i] = adj_matrix[i][j];
        }
    }

    return Graph(adj_matrix);
}