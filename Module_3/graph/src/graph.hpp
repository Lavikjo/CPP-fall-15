#ifndef ELEC_CPP_GRAPH_HH
#define ELEC_CPP_GRAPH_HH

#include "edge.hpp"
#include "graph_traits.hpp"

#include <list>
#include <set>
#include <iostream>

/* Graph - a type generic graph class with optional traits
 * Template parameters:
 *  V      - assignable and copyable vertex type that supports:
 *   < and == comparison
 *   << output
 *  Traits - graph traits ((un)directed and (un)weighted)
 * The template implementations are in the separate header file
 * NOTE: The graph is very error tolerant, i.e. it does not throw exceptions,
 *  consider any input invalid nor complain about trying to erase
 *  non-existant values.
 * The privately inherited graph_traits provides the class with two
 *  private boolean members:
 *  bool .weighted
 *  bool .directed
 * Which have the obvious meaning. */

template <typename V, typename Traits = graph_traits<V> >
class Graph : private Traits
{
public:
    // Constructors - iterator range and default
    /* Construct a graph from a given iterator range
     * The behaviour is as if insertEdge() were called for each iterated value */
    template <typename Iter>
	  Graph(Iter begin, Iter end);
    /* Default construction of an empty graph */
    Graph();

    // Type members for vertex and edge
    typedef V vertex_type;
    typedef Edge<V> edge_type;
    // Type members for edge list and vertex list
    typedef std::set<edge_type> edge_list_type;
    typedef std::list<vertex_type> vertex_list_type;

    // Accessors for graph features

    /* Returns the list (set) of Edges as it is stored in the Graph */
    const edge_list_type& getEdges() const;

    /* Returns a list of vertices for the Graph
     * The list is ordered according to < for the vertex values
     * Note: You will have to construct the list yourself since only the
     *  edges of the Graph are stored by the class. */
    vertex_list_type getVertices() const;

    /* Returns a list of neighbour Edges for a vertex
     * The list consists of all edges that connect the parameter vertex V
     *  to some other vertex, i.e. all edges E(V, other_vertex, w)
     * The list is ordered according to < for Edges (default for the set) */
    edge_list_type getNeighbours(const V&) const;

    // Modifiers

    /* Inserts an edge to the graph
     * If the edge already exists within the graph, the old edge is simply
     *  replaced with the new one that might have a different weight value.
     * NOTE: (this bit is actually important)
     *  For an undirected graph you will have to also insert the corresponding
     *   opposite edge, i.e. for E(n,m,w) you will have to insert
     *   both E(n,m,w) and E(m,n,w) to maintain the undirected criterion.
     *  For an unweighted graph the weight value of the edge is ignored and
     *   1 is used instead. */
    void insertEdge(const Edge<V> &edge);

    /* Erases an edge from the graph
     * If the edge does not exist within the graph, the function does nothing.
     * NOTE: (again this bit is important)
     *  For an undirected graph you will also have to erase the corresponding
     *  opposite edge, i.e. for E(n,m,w) you will also have to erase the edge
     *  E(m,n,w). */
    void eraseEdge(const Edge<V> &edge);

private:
    std::set<edge_type> edges;
};

/* Output stream operation for a Graph
 * The graph is printed in the following format:
 * OriginVertex1 : TargetVertex1_1(Weight1_1) TargetVertex1_2(Weight1_2)\n
 * OriginVertex2 : TargetVertex2_1(Weight2_1) TargetVertex2_2(Weight2_2)\n
 * I.e. for each vertex the neighbouring vertices and the edge weight
 *  between the vertices is printed.
 * This function does not consider the graph traits.
 * The vertices are printed in the order they appear on the Graph edge list
 * A newline character is not printed after the last line */
template <typename V, typename Traits>
std::ostream& operator<<(std::ostream &, const Graph<V, Traits> &);

#include "graph_implementation.hpp"

#endif
