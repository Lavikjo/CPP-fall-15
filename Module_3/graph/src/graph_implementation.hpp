#ifndef ELEC_CPP_GRAPH_HH
#error "Invalid usage of graph_implementation.hh"
#endif

#include "graph.hpp"
/* ATTENTION
 * Do NOT #include this file yourself as it is a part of the graph.hh
 *  header and does not work properly if used without the template
 *  definitions within graph.hh. */

/* A graph is a mathematical entity common in computer science consisting of vertices (nodes) and edges (connections) between the vertices.
 * In this exercise you get to implement a type generic graph with customisable traits and "templatise" the Djikstra's shortest path algorithm for the graph.
 * The graph representation used in this exercise is that of a set of edges with a custom Edge data type.
 * While useful and interesting, graph theory and details on graph operations are not actually required for this exercise.
 *
 * The Graph we use is generic in three ways.
 * The Graph vertex type is generic with the assumptions listed below.
 * Additionally the graph_traits define whether the graph is directed (edges are one way) or 
 * undirected (edges are bidirectional - they go both ways) an whether the graph is weighted 
 * (all edges have a weight value associated with them) or unweighted (all edges have a constant unity weight).
 * The graph class Graph is described, in detail, in the graph.hh file.
 *
 * The file djikstra.hh contains a non-generic implementation of the Djikstra's shortest path algorithm for you to templatise.
 *
 * Assumptions on the generic vertex type:
 * Copyable
 * Assignable
 * Default constructible (can be constructed without parameters)
 * Comparable with the &lt; and == operators
 * Output << streamable to an std::ostream
 *
 * Expected output from the given test program
  Graph:
  1 : 2(2) 5(8)
  2 : 3(1) 4(3)
  3 : 4(1)
  4 : 5(2)
  Shortest paths:
  1 : 0
  2 : 2
  3 : 3
  4 : 4
  5 : 6
 * Notes    
 * Remember dependant type names. They are assumed variables by the compiler and require the "typename" keyword to correct their type status.
 * Template default parameters for a class are not repeated in the member function implementations outside the class.
 * As always with templates - think before you write as extended iteration with the compiler template error messages can be considered detrimental to mental health
 */

// Write the class member function implementations here

template <typename V, typename Traits>
const typename Graph<V, Traits>::edge_list_type& Graph<V, Traits>::getEdges() const {
  return this->edges;
}


template <typename V, typename Traits>
typename Graph<V, Traits>::vertex_list_type Graph<V, Traits>::getVertices() const {
  typename Graph<V, Traits>::vertex_list_type vertex_list;

  for(typename Graph<V, Traits>::edge_list_type::iterator it = this->getEdges().begin(); it != this->getEdges().end(); it++) {

    vertex_list.push_back(it->first);
    vertex_list.push_back(it->second);
  }
  // sort vertices first
  vertex_list.sort();

  return vertex_list;
}

template <typename V, typename Traits>
typename Graph<V, Traits>::edge_list_type Graph<V, Traits>::getNeighbours(const typename Graph<V, Traits>::vertex_type& ver) const {
 typename Graph<V, Traits>::edge_list_type edge_list;

  for(typename Graph<V, Traits>::edge_list_type::iterator it = this->getEdges().begin();  it != this->getEdges().end(); it++) {
    if(it->first == ver) {
      edge_list.insert(*it);
    }
  }
  return edge_list;
}

template <typename V, typename Traits>
void Graph<V, Traits>::insertEdge(const typename Graph<V, Traits>::edge_type &edge) {
 
  auto it = this->edges.find(edge);
  if(it != edges.end()) {
    this->eraseEdge(*it);
  }
  
  if(not this->directed) {
  for(typename Graph<V, Traits>::edge_list_type::iterator it = this->edges.begin(); it != this->edges.end();it++ ) {
    if((it->first == edge.first) and (it->second == edge.second) and (it->weight != edge.weight)) {
      // almost the same except different weight
      // remove the original

      this->eraseEdge(*it);
      return;
    }
  }
}

  

  if(this->weighted) {

      if(this->directed) {

        this->edges.insert(edge);
      
      } else {
        // graph is undirected --> insert opposite edge aswell
        this->edges.insert(edge);
        this->edges.emplace(edge.second, edge.first, edge.weight);
        //this->edges.insert(Graph<V, Traits>::edge_type(edge.second,edge.first,edge.weight));
      }

  } else {

      if(this->directed) {
        this->edges.emplace(edge.first, edge.second, 1);
        //this->edges.insert(Graph<V, Traits>::edge_type(edge.first,edge.second, 1));
      } else {
        // graph is undirected --> insert opposite edge aswell
        this->edges.emplace(edge.first, edge.second, 1);
        this->edges.emplace(edge.second, edge.first, 1);
        //this->edges.insert(Graph<V, Traits>::edge_type(edge.first,edge.second, 1));
        //this->edges.insert(Graph<V, Traits>::edge_type(edge.second,edge.first, 1));
        }
  }
}


template <typename V, typename Traits>
void Graph<V, Traits>::eraseEdge(const Graph<V, Traits>::edge_type  &edge) {
  if(this->directed) {
  this->edges.erase(edge);
  } else {
    this->edges.erase(edge);
    this->edges.erase(Graph<V, Traits>::edge_type(edge.second,edge.first, edge.weight));
  }
}

template <typename V, typename Traits>
std::ostream& operator<<(std::ostream &os, const Graph<V, Traits> &graph) {

    typename Graph<V, Traits>::edge_list_type edge_list = graph.getEdges();
    
    if(edge_list.empty()) {
      return os;
    }
    V temp = edge_list.begin()->first;

    for(typename Graph<V, Traits>::edge_list_type::const_iterator it = edge_list.begin(); it != edge_list.end(); it++) {
        if((it == edge_list.begin()) | !(temp == it->first)) {
          if(it != edge_list.begin()) {
            os << std::endl;
          }

          os << it->first << " :";
          temp = it->first;
      
        
        }
        os << " " << it->second << "(" << it->weight << ")" ;
        
    }
    
    return os;
}

template <typename V, typename Traits>
Graph<V, Traits>::Graph() {}