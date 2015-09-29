#include "graph.hpp"
#include "dijkstra.hpp"

int main()
{
    Graph<int> g;
    // Add a simple graph
    g.insertEdge(Edge<int>(1,2, 2));
    g.insertEdge(Edge<int>(1,5, 8));
    g.insertEdge(Edge<int>(2,3, 1));
    g.insertEdge(Edge<int>(2,4, 3));
    g.insertEdge(Edge<int>(3,4, 1));
    g.insertEdge(Edge<int>(4,5, 2));

    // Print the graph
    std::cout << "Graph:" << std::endl;
    std::cout << g << std::endl;

    // Calculate shortest paths and print
    std::map<int, size_t> paths = shortestPaths(g, 1);
    std::cout << "Shortest paths:" << std::endl;
    for (std::map<int, size_t>::const_iterator iter = paths.begin();iter != paths.end();iter++)
	std::cout << iter->first << " : " << iter->second << "\n";
}
