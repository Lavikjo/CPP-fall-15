#ifndef ELEC_CPP_DIJKSTRA_HH
#define ELEC_CPP_DIJKSTRA_HH

#include "graph.hpp"

#include <map>
#include <algorithm>

/* The Djikstra shortest path algorithm for a Graph<int> with default traits
 * The Djikstra algorithm calculates the shortest paths to each graph
 * vertex from the source (second function parameter).
 * These shortest paths are then returned in an std::map associating
 * (vertex, shortest path length)
 * Unreachable vertices are given a shortest path value of infinity
 * designated by the maximum value that can be stored a variable of
 * type size_t */

/* Turn this algorithm into a generic algorithm for a Graph of any
 * vertex type with any traits. I.e. turn this function into a template
 * HINT: You do not have to change the algorithm logic in any way or care
 * about the graph traits yourself. */

/* Write the template here - you can delete the given shortestPaths as it
 * is replaced by the generic implementation */
template <typename V, typename Traits>
std::map<V, size_t> shortestPaths(const Graph<V, Traits> &graph, const typename Graph<V, Traits>::vertex_type &source)
{
    // Infinity constant
    const size_t inf = ~0;
    // All vertices within the graph
    typename Graph<V, Traits>::vertex_list_type vertices = graph.getVertices();
    // Initialisations - distance and knowledge of previous nodes
    std::map<V, size_t> distance;
    for (typename Graph<V, Traits>::vertex_list_type::iterator iter = vertices.begin();iter != vertices.end();iter++)
        distance[*iter] = inf;
    std::map<V, V> previous;
    // From source to source
    distance[source] = 0;

    while (!vertices.empty())
    {
        // Find the vertex with the shortest distance
        V min = vertices.front();
        for (typename Graph<V, Traits>::vertex_list_type::const_iterator iter = vertices.begin();iter != vertices.end();iter++)
            if (distance[min] > distance[*iter])
                min = *iter;
        // Break if no further vertices are accessible
        if (distance[min] == inf)
            break;
        // Remove this vertex from the list of vertices and obtain neighbours
        vertices.erase(std::find(vertices.begin(), vertices.end(), min));
        typename Graph<V, Traits>::edge_list_type neighbours = graph.getNeighbours(min);
        for (typename Graph<V, Traits>::edge_list_type::const_iterator iter = neighbours.begin();iter != neighbours.end();iter++)
        {
            size_t d = distance[min] + iter->weight;
            // Updade distance if necessary
            if (d < distance[iter->second])
            {
                distance[iter->second] = d;
                previous[iter->second] = min;
            }
        }
    }
    return distance;
}



/*
std::map<int, size_t> shortestPaths(const Graph<int> &graph, const V &source)
{
    // Infinity constant
    const size_t inf = ~0;
    // All vertices within the graph
    Graph<int>::vertex_list_type vertices = graph.getVertices();
    // Initialisations - distance and knowledge of previous nodes
    std::map<int, size_t> distance;
    for (Graph<int>::vertex_list_type::iterator iter = vertices.begin();iter != vertices.end();iter++)
        distance[*iter] = inf;
    std::map<int, int> previous;
    // From source to source
    distance[source] = 0;

    while (!vertices.empty())
    {
        // Find the vertex with the shortest distance
        int min = vertices.front();
        for (Graph<int>::vertex_list_type::const_iterator iter = vertices.begin();iter != vertices.end();iter++)
            if (distance[min] > distance[*iter])
                min = *iter;
        // Break if no further vertices are accessible
        if (distance[min] == inf)
            break;
        // Remove this vertex from the list of vertices and obtain neighbours
        vertices.erase(std::find(vertices.begin(), vertices.end(), min));
        Graph<int>::edge_list_type neighbours = graph.getNeighbours(min);
        for (Graph<int>::vertex_list_type::const_iterator iter = neighbours.begin();iter != neighbours.end();iter++)
        {
            size_t d = distance[min] + iter->weight;
            // Updade distance if necessary
            if (d < distance[iter->second])
            {
                distance[iter->second] = d;
                previous[iter->second] = min;
            }
        }
    }
    return distance;
}
*/
#endif
