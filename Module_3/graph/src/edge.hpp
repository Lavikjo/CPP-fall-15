#ifndef ELEC_CPP_EDGE_HH
#define ELEC_CPP_EDGE_HH

#include <utility>
#include <cstddef>

/* Edge - a type generic edge of a graph between two vertices
 * An Edge is a homogeneous std::pair with an added weight value
 * An Edge provides the following interface:
 *  .first   - Origin vertex
 *  .second  - Target vertex
 *  .weight  - Edge weight, defaults to 1
 * Comparison with < and == oeprators
 * NOTE: Comparison operators ignore the weight value, thus
 *  edges (1,2,4) and (1,2,3) are considered identical. */

template <typename T>
struct Edge;

template <typename T>
bool operator<(const Edge<T>& left, const Edge<T>& right)
{
    return static_cast<std::pair<T, T> >(left) < static_cast<std::pair<T, T> >(right);
}

template <typename T>
bool operator==(const Edge<T>& left, const Edge<T>& right)
{
    return static_cast<std::pair<T, T> >(left) == static_cast<std::pair<T, T> >(right);
}

template <typename T>
struct Edge : private std::pair<T, T>
{
    Edge(const T &first, const T &second, size_t weight = 1) :
  	  std::pair<T, T>(first, second), weight(weight) { }

    friend bool operator< <T>(const Edge&, const Edge&);
    friend bool operator==<T>(const Edge&, const Edge&);
    using std::pair<T, T>::first;
    using std::pair<T, T>::second;
    size_t weight;
};

#endif
