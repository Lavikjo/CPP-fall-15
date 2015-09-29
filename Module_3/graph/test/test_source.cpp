#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "../src/graph.hpp"
#include "../src/edge.hpp"
#include "../src/graph_traits.hpp"
#include "../src/dijkstra.hpp"

int randomInt(int high)
{
    return std::rand() % high;
}

std::string randomString(int chars, int length)
{
    std::vector<char> str(length);
    for (size_t i = 0;i < (size_t)length;i++)
        str[i] = 'a' + std::rand() % chars;
    return std::string(str.begin(), str.end());
}

std::string returnEdges(std::vector<Edge<int>> edges, int i){
    std::string s = std::to_string(i)+" :";
    std::vector<int> v;
    for(size_t n=0; n<edges.size(); n++){
        if(edges[n].second==i)
            v.push_back(edges[n].first);
        if(edges[n].first==i)
            v.push_back(edges[n].second);
    }
    std::sort(v.begin(), v.end());
    auto it=std::unique(v.begin(), v.end());
    v.resize(std::distance(v.begin(),it) );
    for(auto &n: v)
        s+=" " + std::to_string(n)+"(1)";

    return s;
}

TEST(test_graph, test_int_unweighted) {
    std::srand(time(0));

    Graph<int, graph_traits<int, 0, 0> > g;
    // Add a simple graph
    size_t nEdges = 10 + randomInt(100);

    std::vector<Edge<int> > edges;

    for (size_t i = 0;i < nEdges;i++)
    {
        int origin = randomInt(10);
        int target = randomInt(10);
        if (origin == target)
            continue;
        edges.push_back(Edge<int>(origin, target, randomInt(20) + 1));
    }

    for (size_t i = 0;i < edges.size();i++)
        g.insertEdge(edges[i]);

    std::sort(edges.begin(), edges.end());
    std::unique(edges.begin(), edges.end());

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    std::cout << g << std::endl;

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");

    for(size_t i=0; i<10; i++){
        std::getline(test, checkstr);
        std::string correct=returnEdges(edges, i);
        EXPECT_EQ(correct, checkstr);
    }
}

TEST(test_graph, test_int_weighted) {
    Graph<int, graph_traits<int, 0, 1> > g;
    // Add a simple graph

    std::vector<Edge<int> > edges;

    edges.push_back(Edge<int>(0, 1, 2));
    edges.push_back(Edge<int>(0, 2, 4));
    edges.push_back(Edge<int>(0, 3, 1));
    edges.push_back(Edge<int>(1, 0, 3));
    edges.push_back(Edge<int>(1, 4, 6));
    edges.push_back(Edge<int>(1, 3, 2));
    edges.push_back(Edge<int>(2, 0, 4));
    edges.push_back(Edge<int>(2, 3, 1));
    edges.push_back(Edge<int>(3, 0, 5));
    edges.push_back(Edge<int>(3, 1, 1));
    edges.push_back(Edge<int>(3, 2, 2));
    edges.push_back(Edge<int>(3, 4, 3));
    edges.push_back(Edge<int>(3, 5, 1));
    edges.push_back(Edge<int>(4, 1, 2));
    edges.push_back(Edge<int>(4, 3, 2));
    edges.push_back(Edge<int>(4, 5, 1));
    edges.push_back(Edge<int>(5, 3, 6));
    edges.push_back(Edge<int>(5, 4, 3));

    for (size_t i = 0;i < edges.size();i++)
        g.insertEdge(edges[i]);

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    std::cout << g << std::endl;

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");
    std::getline(test, checkstr);

    std::ostringstream c;
    c << "0 : 1(3) 2(4) 3(5)";
    std::string correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "1 : 0(3) 3(1) 4(2)";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "2 : 0(4) 3(2)";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "3 : 0(5) 1(1) 2(2) 4(2) 5(6)";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "4 : 1(2) 3(2) 5(3)";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);

    c.str("");
    c.clear();

    std::getline(test, checkstr);
    c << "5 : 3(6) 4(3)";
    correct = c.str();
    EXPECT_EQ(correct, checkstr);
}

class MyType
{
    public:
        MyType() : arvo(0.0) {}
        MyType(double val) : arvo(val) {}
        double getValue() const
        {
            return arvo;
        }
    private:
        double arvo;
};

bool operator<(const MyType &left, const MyType &right)
{
    return left.getValue() < right.getValue();
}

bool operator==(const MyType &left, const MyType &right)
{
    return left.getValue() == right.getValue();
}

std::ostream& operator<<(std::ostream& os, const MyType &right)
{
    os << right.getValue();
    return os;
}

std::string returnEdges_o(std::vector<Edge<MyType>> edges, double i){
    std::ostringstream s;
    s << i << " :";
    std::vector<MyType> v;
    for(size_t n=0; n<edges.size(); n++){
        if(edges[n].second==i)
            v.push_back(edges[n].first);
        if(edges[n].first==i)
            v.push_back(edges[n].second);
    }
    std::sort(v.begin(), v.end());
    auto it=std::unique(v.begin(), v.end());
    v.resize(std::distance(v.begin(),it) );
    for(auto &n: v)
        s << " " << n << "(1)";

    return s.str();
}

TEST(test_graph2, test_owntype) {
    std::srand(time(0));

    Graph<MyType, graph_traits<MyType, 0, 0> > g;

    size_t nEdges = 50 + randomInt(150);

    std::vector<Edge<MyType> > edges;

    for (size_t i = 0;i < nEdges;i++)
    {
        MyType origin(randomInt(40) / (double)4);
        MyType target(randomInt(40) / (double)4);
        if (origin == target)
            continue;
        edges.push_back(Edge<MyType>(origin, target, randomInt(20) + 1));
    }

    for (size_t i = 0;i < edges.size();i++)
        g.insertEdge(edges[i]);

    std::sort(edges.begin(), edges.end());
    std::unique(edges.begin(), edges.end());

    //use file out.txt as standard output
    std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    std::cout << g << std::endl;

    std::cout.rdbuf(coutbuf); //reset to standard output again

    //read output from function
    std::string checkstr;
    std::ifstream test("out.txt");

    for(double i=0; i<10; i+=0.25){
        std::getline(test, checkstr);
        std::string correct=returnEdges_o(edges, i);
        EXPECT_EQ(correct, checkstr);
    }
}

std::map<int, size_t> dijkstra(const Graph<int, graph_traits<int, false,false>> &graph, const int &source)
{
    const size_t inf = ~0;
    Graph<int>::vertex_list_type vertices = graph.getVertices();
    std::map<int, size_t> distance;
    for (Graph<int>::vertex_list_type::iterator iter = vertices.begin();iter != vertices.end();iter++)
        distance[*iter] = inf;
    std::map<int, int> previous;
    distance[source] = 0;
    while (!vertices.empty())
    {
        int min = vertices.front();
        for (Graph<int>::vertex_list_type::const_iterator iter = vertices.begin();iter != vertices.end();iter++)
            if (distance[min] > distance[*iter])
                min = *iter;
        if (distance[min] == inf)
            break;
        vertices.erase(std::find(vertices.begin(), vertices.end(), min));
        Graph<int>::edge_list_type neighbours = graph.getNeighbours(min);
        for (Graph<int>::edge_list_type::const_iterator iter = neighbours.begin();iter != neighbours.end();iter++)
        {
            size_t d = distance[min] + iter->weight;
            if (d < distance[iter->second])
            {
                distance[iter->second] = d;
                previous[iter->second] = min;
            }
        }
    }
    return distance;
}

std::map<MyType, size_t> dijkstra_o(const Graph<MyType, graph_traits<MyType, false,false>> &graph, const MyType &source){
    const size_t inf = ~0;
    Graph<MyType>::vertex_list_type vertices = graph.getVertices();
    std::map<MyType, size_t> distance;
    for(Graph<MyType>::vertex_list_type::iterator iter = vertices.begin(); iter != vertices.end(); iter++)
        distance[*iter] = inf;
    std::map<MyType, MyType> previous;
    distance[source]=0;
    while(!vertices.empty()){
        MyType min = vertices.front();
        for (Graph<MyType>::vertex_list_type::const_iterator iter = vertices.begin();iter != vertices.end();iter++)
            if (distance[min] > distance[*iter])
                min = *iter;
        if (distance[min] == inf)
            break;
        vertices.erase(std::find(vertices.begin(), vertices.end(), min));
        Graph<MyType>::edge_list_type neighbours = graph.getNeighbours(min);
        for (Graph<MyType>::edge_list_type::const_iterator iter = neighbours.begin();iter != neighbours.end();iter++)
        {
            size_t d = distance[min] + iter->weight;
            if (d < distance[iter->second])
            {
                distance[iter->second] = d;
                previous[iter->second] = min;
            }
        }
    }
    return distance;
}


TEST(test_graph3, test_shortest_path_int) {
    std::srand(time(0));

    Graph<int, graph_traits<int, 0, 0> > g;
    // Add a simple graph
    size_t nEdges = 10 + randomInt(100);

    std::vector<Edge<int> > edges;

    for (size_t i = 0;i < nEdges;i++)
    {
        int origin = randomInt(10);
        int target = randomInt(10);
        if (origin == target)
            continue;
        edges.push_back(Edge<int>(origin, target, randomInt(20) + 1));
    }

    for (size_t i = 0;i < edges.size();i++)
        g.insertEdge(edges[i]);

    std::map<int, size_t> paths = shortestPaths(g, *g.getVertices().begin());
    std::map<int, size_t> paths_c = dijkstra(g, *g.getVertices().begin());
    for (std::map<int, size_t>::const_iterator iter = paths.begin(), iter2 = paths_c.begin();iter != paths.end();iter++,iter2++)
        EXPECT_EQ(*iter2, *iter);
}

TEST(test_graph3, test_shortest_path_mytype) {
    std::srand(time(0));

    Graph<MyType, graph_traits<MyType, 0, 0> > g;

    size_t nEdges = 50 + randomInt(150);

    std::vector<Edge<MyType> > edges;

    for (size_t i = 0;i < nEdges;i++)
    {
        MyType origin(randomInt(40) / (double)4);
        MyType target(randomInt(40) / (double)4);
        if (origin == target)
            continue;
        edges.push_back(Edge<MyType>(origin, target, randomInt(20) + 1));
    }

    for (size_t i = 0;i < edges.size();i++)
        g.insertEdge(edges[i]);

    std::map<MyType, size_t> paths = shortestPaths(g, *g.getVertices().begin());
    std::map<MyType, size_t> paths_c = dijkstra_o(g, *g.getVertices().begin());
    for (std::map<MyType, size_t>::const_iterator iter = paths.begin(), iter2 = paths_c.begin();iter != paths.end();iter++,iter2++)
        EXPECT_EQ(*iter2, *iter);
}
