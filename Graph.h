#include <iostream>
#include <memory>
#include <list>
#include <vector>
#include <map>
#include <iterator>
using namespace std;
int INF = 99999;

class Graph
{
private:
    int vertexCount;
    int edgeCount;
public:
    class EdgeList
    {
    protected:
        int src, dest, weight;
    public:
        EdgeList(int src, int dest, int weight);
        int getWeight();
        int getSrc();
        int getDest();
    };
public:
    Graph();
    Graph(int);

    virtual void addEdge() = 0;
    virtual void addEdgeWithoutWeight() {};
    virtual void addEdgeWithWeight() {};
    virtual void addEdgeWithoutWeightForDirectedGraph() {};
    virtual void addEdgeWithWeightForDirectedGraph() {};
    virtual void display() {};
    virtual ~Graph();
    int getVertexCount();
    int getEdgeCount();
};

class GraphWithAdjacencyMatrix : public Graph
{
protected:
    int** adjMat;
    vector<shared_ptr<Graph::EdgeList>> edgeList;
public:
    GraphWithAdjacencyMatrix(int);
    void addEdge();
    void addEdgeWithWeight();
    void addEdgeWithoutWeight();
    void addEdgeWithoutWeightForDirectedGraph();
    void addEdgeWithWeightForDirectedGraph();
    void display();
    vector<shared_ptr<Graph::EdgeList>>& getEdgeList();
    ~GraphWithAdjacencyMatrix();
};

class GarphWithAdjacencyList : public Graph
{
protected:
    /*
     //Dificult to track the node and it's connection
      vector<list<int>> adjList;
     // cann't be possiable, because we need to know the size of array
      list<int> adgList[];
   */
    map<int, list<int>> adjList;
public:
    GarphWithAdjacencyList(int);
    void addEdge();
    void addEdgeWithoutWeight();
    void display();
    ~GarphWithAdjacencyList();
};