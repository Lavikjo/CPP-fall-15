#ifndef ELEC_CPP_GRAPH_HH
#error "Invalid usage of graph_implementation.hh"
#endif

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

