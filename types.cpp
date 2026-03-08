#include "types.hpp"

Point::Point() : x(0), y(0) {}
Point::Point(double _x, double _y) : x(_x), y(_y) {}

Edge::Edge(int _from, int _to, int _cost) : id(-1), from(_from), to(_to), cost(_cost) {}
Edge::Edge(int _id, int _from, int _to, int _cost) : id(_id), from(_from), to(_to), cost(_cost) {};
bool Edge::operator>(const Edge& other) const {
    return cost > other.cost;
}
