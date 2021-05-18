#include <iostream>
#include "Graph.h"

using namespace std;


Graph::EdgeList::EdgeList(int src, int dest, int weight)
{
    this->src = src;
    this->dest = dest;
    this->weight = weight;
}
int Graph::EdgeList::getWeight()
{
    return this->weight;
}
int Graph::EdgeList::getSrc()
{
    return this->src;
}
int Graph::EdgeList::getDest()
{
    return this->dest;
}

int Graph::getVertexCount()
{
    return this->vertexCount;
}
int Graph::getEdgeCount()
{
    return this->edgeCount;
}
Graph::Graph()
{
    cout << " Graph() object is creating..." << endl;
    this->vertexCount = 0;
    this->edgeCount = 0;
}
Graph::Graph(int vertexCount)
{
    cout << " Graph(int) object is creating..." << endl;
    this->vertexCount = vertexCount;
    this->edgeCount = 0;
}
Graph::~Graph()
{
    cout << " Graph object is deleteing..." << endl;
    delete this;
}

vector<shared_ptr<Graph::EdgeList>>& GraphWithAdjacencyMatrix::getEdgeList()
{
    return this->edgeList;
}


GraphWithAdjacencyMatrix::GraphWithAdjacencyMatrix(int vertex=0):Graph(vertex)
{
    cout << "GraphWithAdjacencyMatrix obj is constructing..." << endl;
    adjMat = new int*[this->getVertexCount()];
    for (int i = 0;i < this->getVertexCount();i++)
    {
        adjMat[i] = new int[this->getVertexCount()];
    }
    for (int i = 0;i < this->getVertexCount();i++)
    {
        for (int j = 0;j < this->getVertexCount();j++)
        {
            adjMat[i][j] = INF;
        }
    }
}
void GraphWithAdjacencyMatrix::addEdge() {
    int choice;

    cout << "Please choose type of Garph...\n" << endl;
    cout << "0. Un-directed garph without weight" << endl;
    cout << "1. Un-directed garph with weight" << endl;
    cout << "2. Directed garph without weight" << endl;
    cout << "3. Directed garph with weight\n" << endl;
    cin >> choice;
    switch (choice)
    {
    case 0:
        this->addEdgeWithoutWeight();
        break;
    case 1:
        this->addEdgeWithWeight();
        break;
    case 2:
        this->addEdgeWithoutWeightForDirectedGraph();
        break;
    case 3:
        this->addEdgeWithWeightForDirectedGraph();
        break;
    default:
        cout << "Wrong input!!!" << endl;
        break;
    }
}
void GraphWithAdjacencyMatrix::addEdgeWithoutWeight()
{
    int numberOfEdges,to,from;
    cout << "How many Edges do you have ?" << endl;
    cin >> numberOfEdges;
    for (int i = 0;i < numberOfEdges;i++)
    {
        cout << "Enter 'from' and 'to' :";
        cin >> from >> to;
        this->adjMat[to][from] = 1;
        this->adjMat[from][to] = 1;
    } 
}
void GraphWithAdjacencyMatrix::addEdgeWithWeight()
{
    int numberOfEdges, to, from, weight;
    cout << "How many Edges do you have ?" << endl;
    cin >> numberOfEdges;
    for (int i = 0;i < numberOfEdges;i++)
    {
        cout << "Enter 'from' and 'to' :";
        cin >> from >> to;
        cout << "What is the weight if the edge";
        cin >> weight;
        this->adjMat[from][to] = weight;
        this->adjMat[to][from] = weight;
        this->edgeList.push_back(shared_ptr<Graph::EdgeList>(new Graph::EdgeList(from, to, weight)));
    }
}
void GraphWithAdjacencyMatrix::addEdgeWithoutWeightForDirectedGraph()
{
    int numberOfEdges, to, from;
    cout << "How many Edges do you have ?" << endl;
    cin >> numberOfEdges;
    for (int i = 0;i < numberOfEdges;i++)
    {
        cout << "Enter 'from' and 'to' :";
        cin >> from >> to;

        this->adjMat[from][to] = 1;
        this->edgeList.push_back(shared_ptr<Graph::EdgeList>(new Graph::EdgeList(from, to, 1)));
    }

}
void GraphWithAdjacencyMatrix::addEdgeWithWeightForDirectedGraph()
{
    int numberOfEdges, to, from, weight;
    cout << "How many Edges do you have ?" << endl;
    cin >> numberOfEdges;
    for (int i = 0;i < numberOfEdges;i++)
    {
        cout << "Enter 'from' and 'to' :";
        cin >> from >> to;
        cout << "What is the weight if the edge";
        cin >> weight;
        this->adjMat[from][to] = weight;
        this->edgeList.push_back(shared_ptr<Graph::EdgeList>(new Graph::EdgeList(from, to, weight)));
    }
}
void GraphWithAdjacencyMatrix::display() {

    cout << "\nGraph using Adjacency Matrix \n ";
    for (int i = 0;i < this->getVertexCount();i++)
    {
        cout << "  |" << i;
    }
    cout << endl<< std::string(4*this->getVertexCount(), '-')<<endl;
    for (int i = 0;i < this->getVertexCount(); i++)
    {
        cout << i;
        for (int j = 0; j < this->getVertexCount();j++)
        {
            cout << "  |" <<this->adjMat[i][j];
        }
        cout << endl;
    }
}
GraphWithAdjacencyMatrix::~GraphWithAdjacencyMatrix()
{
    delete this;
    cout << "GraphWithAdjacencyMatrix obj got deleted !!!" << endl;
}

//************************    GarphWithAdjacencyList impl **************************

GarphWithAdjacencyList::GarphWithAdjacencyList(int vertex = 0) :Graph(vertex)
{ 
    cout << "GarphWithAdjacencyList object is constructing..." << endl;
}
void GarphWithAdjacencyList::addEdge() {
    this->addEdgeWithoutWeight();
}
void GarphWithAdjacencyList::addEdgeWithoutWeight()
{
    int numberOfEdges, to, from;
    cout << "How many Edges do you have ?" << endl;
    cin >> numberOfEdges;
    for (int i = 0;i < numberOfEdges;i++)
    {
        cout << "Enter 'from' and 'to' :";
        cin >> from >> to;
        auto itr = adjList.find(from);
        if (itr == adjList.end())
        {
            list<int> temp;
            temp.push_back(to);
            adjList.insert(pair<int, list<int>>(from, temp));
        }
        else
        {
            itr->second.push_back(to);
        }
    }
}
void GarphWithAdjacencyList::display()
{

    cout << "\nGraph using Adjacency List \n ";
    cout << std::string(3 * this->getVertexCount(), '-') << endl;
    for (auto itr = adjList.begin(); itr != adjList.end(); itr++)
    {
        cout << itr->first << "  |";
        for (auto itr : itr->second)
        {
            cout << "  -> " << itr;
        }
        cout << endl;
    }
}
GarphWithAdjacencyList::~GarphWithAdjacencyList()
{
    cout << "GarphWithAdjacencyList obj got deleted !!!" << endl;
    delete this;
}
