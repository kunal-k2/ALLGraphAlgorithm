#include "Graph.h"
#include <stack>
#include <queue>
#include <unordered_map>

class GraphOperation : public GraphWithAdjacencyMatrix
{
protected:
	class Node
	{
	public:
		int data;
		vector<Node*> childs;
		Node(int data)
		{
			this->data = data;
		}
		Node(int key, vector<Node*> childs)
		{
			this->data = key;
			this->childs = childs;

			/*for (auto item : childs)
			{
				this->childs.push_back(item);
			}*/
		}
		void operator = (const Node& obj)
		{
			this->data = obj.data;
			this->childs = obj.childs;
		}
	};

public:
	
	GraphOperation(int vertexcount);
	void createGraph();
	void dfsTrav();
	void bfsTrav();
	bool isConnected();
	void dfsSpanningTree();
	void bfsSpanningTree();
	void singleSourceShortestDistance();
	bool isBiparted();
	// findParent, unionset, required for detect cycle
	int findParent(int,int*);
	void unionSet(int,int,int*);
	bool detectCycle(vector<shared_ptr<Graph::EdgeList>> edgeList);
	//detectCycle needed for KruskalMST
	int kruskalMST();
	// getMinimumWeightVertex needed for primsMST and DijkstraSPT
	int getMinimumWeightVertex(int*,bool*);
	int primsMST(); // MST -> minimum spanning tree
	void dijkstraSPT(); // SPT -> Single source shortest tree(path)
	// addnode, createNode, printTree needed to print each reachable path
	//   from  soure in bellmanFordSSSP
	void addNode(Node** , Node*);
	GraphOperation::Node* createNode(int, vector<int>);
	void printmap(unordered_map<int, vector<int>>, int, vector<int>&);
	void printRoottoLeafNode(Node*);
	void printRoottoLeafNode(Node* root, vector<int>&);
	void bellmanFordSSSP();// SSSPT -> single source shortes path(Tree) 
	void floydWarshallAPSP(); // APSPT -> All pair shortes path(Tree)
};