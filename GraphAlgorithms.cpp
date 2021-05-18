#include "graphAlgorithm.h"
#include <string>
#include <unordered_map>

GraphOperation::GraphOperation(int vertexcount) : GraphWithAdjacencyMatrix(vertexcount)
{
	cout << "GarphOperation object creating..." << endl;
}

void GraphOperation::createGraph()
{
	cout << "Garph creating process start...." << endl;
	this->addEdge();
}
void GraphOperation::dfsTrav()
{
	int start;
	cout << "************       DFS Traversal         *************" << endl;
	cout << " Please choose starting point of your Garph..." << endl;
	cin >> start;
	stack<int> s;
	//mark the visited node
	int* visited = new int[this->getVertexCount()];
	for (int i = 0; i < this->getVertexCount();i++)
	{
		visited[i] = 0;
	}
	visited[start] = 1;
	s.push(start);
	cout << "Start ";
	while(!s.empty())
	{
		int trav = s.top();
		cout << "->"<< trav;
		s.pop();
		//push all the neighbour vertex on to stack and mark them visited
		for (int i = 0;i < this->getVertexCount();i++)
		{
			//only push non-visited node on to the stack
			if (visited[i] == 0 && this->adjMat[trav][i] != INF)
			{
				visited[i] = 1;
				s.push(i);
			}
		}
	}
	cout << "\n"<< endl;
	delete[] visited;
}
void GraphOperation::bfsTrav()
{
	int start;
	cout << "************       BFS Traversal         *************" << endl;
	cout << " Please choose starting point of your Garph..." << endl;
	cin >> start;
	queue<int> q;
	//mark the visited node
	int* visited = new int[this->getVertexCount()];
	for (int i = 0; i < this->getVertexCount();i++)
	{
		visited[i] = 0;
	}
	visited[start] = 1;
	q.push(start);
	cout << "Start ";
	while (!q.empty())
	{
		int trav = q.front();
		cout << "->" << trav;
		q.pop();
		//push all the neighbour vertex on to stack and mark them visited
		for (int i = 0;i < this->getVertexCount();i++)
		{
			//only push non-visited node on to the stack
			if (visited[i] == 0 && this->adjMat[trav][i] != INF)
			{
				visited[i] = 1;
				q.push(i);
			}
		}
	}
	cout << "\n" << endl;
	delete[] visited;
}

bool GraphOperation::isConnected() {
	int start=0, count=0;
	stack<int> s;
	//mark the visited node
	int* visited = new int[this->getVertexCount()];
	for (int i = 0; i < this->getVertexCount();i++)
	{
		visited[i] = 0;
	}
	visited[start] = 1;
	count++;
	s.push(start);
	while (!s.empty())
	{
		int trav = s.top();
		s.pop();
		for (int i = 0;i < this->getVertexCount();i++)
		{
			if (visited[i] == 0 && this->adjMat[trav][i] != INF)
			{
				visited[i] = 1;
				s.push(i);
				count++;
			}
		}
	}
	delete[] visited;
	return count == this->getVertexCount() ? 1 : 0;

}
void GraphOperation::dfsSpanningTree() {
	int start;
	cout << "************       DFS Spanning Tree        *************" << endl;
	cout << " Please choose starting point of your Garph..." << endl;
	cin >> start;
	stack<int> s;
	//mark the visited node
	int* visited = new int[this->getVertexCount()];
	for (int i = 0; i < this->getVertexCount();i++)
	{
		visited[i] = 0;
	}
	visited[start] = 1;
	s.push(start);
	cout << "Start ";
	while (!s.empty())
	{
		int trav = s.top();
		
		s.pop();
		for (int i = 0;i < this->getVertexCount();i++)
		{
			if (visited[i] == 0 && this->adjMat[trav][i] != INF)
			{
				visited[i] = 1;
				s.push(i);
				cout << trav << "->" << i << endl;
			}
		}
	}
	cout << "\n" << endl;
	delete[] visited;
}
void GraphOperation::bfsSpanningTree() {
	int start;
	cout << "************       BFS Spanning Tree         *************" << endl;
	cout << " Please choose starting point of your Garph..." << endl;
	cin >> start;
	queue<int> q;
	int* visited = new int[this->getVertexCount()]{ 0 };
	visited[start] = 1;
	q.push(start);
	cout << "Start ";
	while (!q.empty())
	{
		int trav = q.front();
		
		q.pop();
		for (int i = 0;i < this->getVertexCount();i++)
		{
			if (visited[i] == 0 && this->adjMat[trav][i] != INF)
			{
				visited[i] = 1;
				q.push(i);
				cout << trav<< "->" << i<<endl;
			}
		}
	}
	cout << "\n" << endl;
	delete[] visited;
}
void GraphOperation::singleSourceShortestDistance()
{
	int start;
	//keep distance of every node form start
	int *distance = new int[this->getVertexCount()];
	//mark the visited node
	int* visited = new int[this->getVertexCount()];
	for (int i = 0; i < this->getVertexCount();i++)
	{
		distance[i] = 0;
		visited[i] = 0;
	}
	cout << "************    Single Source Shortest Distance      *************" << endl;
	cout << " Please choose starting point of your Garph..." << endl;
	cin >> start;
	distance[start] = 0;
	visited[start] = 1;
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int trav = q.front();
		q.pop();
		for (int i = 0; i < this->getVertexCount(); i++)
		{
			if (visited[i] == 0 && this->adjMat[trav][i] != INF)
			{
				visited[i] = 1;
				q.push(i);
				distance[i] = distance[trav] + 1;
			}
		}
	}
	for (int i = 0; i < this->getVertexCount(); i++)
	{
		cout << "Distace from " << start << "-> " << i << "is : " << distance[i] << endl;
	}
	delete[] visited;
	delete[] distance;
}
bool GraphOperation::isBiparted()
{
	int start = 0;
	int* visited = new int[start];
	int* colour = new int[this->getVertexCount()];
	for (int i = 0; i < this->getVertexCount();i++)
	{
		colour[i] = 0;
		visited[i] = 0;
	}
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	colour[start] = 1;
	
	while (!q.empty())
	{
		int trav = q.front();
		q.pop();
		for(int i=0;i<this->getVertexCount();i++)
		{
			if (colour[trav] == colour[i] && this->adjMat[trav][i] != INF)
				return false;
			if (visited[i] == 0 && this->adjMat[trav][i] != INF)
			{
				q.push(i);
				visited[i] = 1;
				colour[i] = colour[trav] * -1;
			}
		}
	}
	delete[] visited;
	delete[] colour;
	return true;
}


int GraphOperation::findParent(int vertex, int *parent) {

	while (parent[vertex] != -1)
	{
		vertex = parent[vertex];
	}
	return vertex;
}
void GraphOperation::unionSet(int src, int dest,int *parent) {
	parent[src] = dest;                                                                                                                          
}
bool GraphOperation::detectCycle(vector<shared_ptr<Graph::EdgeList>> edgeList ) {
	int* parent = new int[this->getVertexCount()];
	memset(parent, -1, this->getVertexCount() * sizeof(int));
	if (this->edgeList.size() == 0)
	{
		cout << "\n Sorry! You don't have weight for the edges...\n" << endl;
		return;
	}
	for (auto &e :edgeList)
	{
		int srcP = this->findParent(e->getSrc(),parent);
		int destP = this->findParent(e->getDest(), parent);
		if (srcP == destP) return true;
		unionSet(srcP,destP,parent);
	}
	return false;
}

struct CompareWeight {
	bool operator() (shared_ptr<Graph::EdgeList> e1, shared_ptr<Graph::EdgeList> e2)
	{
		return e1->getWeight() < e2->getWeight();
	}
} compareWeight;

int GraphOperation::kruskalMST() {
	if (this->edgeList.size() == 0)
	{
		cout << "\n Sorry! You don't have weight for the edges...\n" << endl;
		return 0;
	}
	vector<shared_ptr<Graph::EdgeList>> edges(this->edgeList);
	vector<shared_ptr<Graph::EdgeList>> MSTEdges;
	int totalWeight = 0;
	sort(edges.begin(),edges.end(), compareWeight);
	/*for (auto& e : edges)
	{
		cout << e->getSrc() << " ->" << e->getDest() << " = " << e->getWeight() << endl;
	}*/
	cout << "Edges involve in kruskalMST :-" << endl;
	for (auto& e : edges)
	{
		MSTEdges.push_back(shared_ptr<Graph::EdgeList>(new EdgeList(e->getSrc(),e->getDest(),e->getWeight())));
		if (this->detectCycle(MSTEdges))
		{
			MSTEdges.pop_back();
			totalWeight -= e->getWeight();
		}
		totalWeight += e->getWeight();
		if (MSTEdges.size() == this->getVertexCount()-1)
		{
			for (auto& mst : MSTEdges)
			{
				cout << mst->getSrc() << " ->" << mst->getDest() << " = " << mst->getWeight() << endl;
			}
			cout << endl;
			return totalWeight;
		}
			
	}
	for (auto& mst : MSTEdges)
	{
		cout << mst->getSrc() << " ->" << mst->getDest() << " = " << mst->getWeight() << endl;
	}
	cout << endl;
	return totalWeight;
}

int GraphOperation::getMinimumWeightVertex(int* mst, bool* visited)
{
	int mw = INT_MAX,mwv = 0;
	for (int i = 0; i < this->getVertexCount();i++)
	{
		if (!visited[i])
		{
			mwv = mst[i] < mw ? i : mwv;
			mw = mst[i] < mw ? mst[i] : mw;
		}
	}
	return mwv;
}
int GraphOperation::primsMST() {
	int start = 0, count = 0;
	cout << "************     Prim's Minimum spanning tree      ************" << endl;
		cout << "Choose starting point of MST........." << endl;
		cin >> start;
	bool *visited = new bool[this->getVertexCount()];
	int* mst = new int[this->getVertexCount()];
	int* parent = new int[this->getVertexCount()];
	for (int i = 0;i < this->getVertexCount();i++)
	{
		mst[i] = INT_MAX;
		visited[i] = false;
		parent[i] = -1;
	}
	mst[start] = 0;
	parent[start] = start;

	while (count < this->getVertexCount())
	{
		visited[start] = true;
		count++;
		for (int i = 0;i < this->getVertexCount();i++)
		{
			if (!visited[i] && (this->adjMat[start][i] != INF && this->adjMat[start][i] < mst[i]))
			{
					mst[i] = this->adjMat[start][i];
					parent[i] = start;
			}
		}
		start = this->getMinimumWeightVertex(mst, visited);
	}
	cout << "Edges involved in Prim's MST :-" << endl;
	int totalWeight = 0;
	for (int i=0;i<this->getVertexCount();i++)
	{
		cout << parent[i] << " -> " << i << endl;
		totalWeight += this->adjMat[parent[i]][i];
	}
	return totalWeight;
}


void GraphOperation::dijkstraSPT()
{
	int start;
	int count=0;
	cout << "***********    Dijkstra's Shortest Path Algorithm    **********" << endl;
	cout << "Choose starting point from where you want to calculate distance of each vertex ........." << endl;
	cin >> start;
	//mark the visited node
	bool *visited = new bool[this->getVertexCount()];
	//to maintain the edges from source node to every other node
	int *parent = new int[this->getVertexCount()];
	// it will keep the distances of every node from source node
	int *distance = new int[this->getVertexCount()];

	for (int i = 0;i < this->getVertexCount();i++)
	{
		visited[i] = false;
		parent[i] = -1;
		distance[i] = INT_MAX;
	}

	distance[start] = 0;
	parent[start] = 0;

	while (count < this->getVertexCount())
	{
		visited[start] = true;
		count++;

		for (int i = 0;i < this->getVertexCount();i++)
		{
			if (!visited[i] && (this->adjMat[start][i] != INF
				&& this->adjMat[start][i] + distance[start] < distance[i]))
			{
				distance[i] = this->adjMat[start][i] + distance[start];
				parent[i] = start;
			}
		}
		start = this->getMinimumWeightVertex(distance,visited);
	}
	cout << "Distance from " << start << "to each Vertex is :- \n " << endl;
	for (int i = 0;i < this->getVertexCount();i++)
	{
		cout << start << "->" << i << " = " << distance[i] << endl;
	}
	cout << "\n" << endl;
}
void GraphOperation::addNode(GraphOperation::Node **root, GraphOperation::Node *node)
{
	if (*root == NULL)
	{
		*root = node;
	}
	GraphOperation::Node** temp = root;
	if ((*temp)->data != node->data)
	{
		if ((*temp)->childs.size() == 0) return;
		for (auto item : (*temp)->childs)
		{
			addNode(&item,node);
		}
	}
	else
	(*temp)->childs = node->childs;
}
void GraphOperation::printRoottoLeafNode(GraphOperation::Node* node, vector<int>& path)
{
	if (node->childs.size() == 0) 
	{ 
		path.push_back(node->data);
		cout << "Path :- ";
		for (auto data : path)
		{
			cout << " -> " <<data;
		}
		path.pop_back();
		cout << endl;
		return; 
	}
	path.push_back(node->data);
	for (auto e : node->childs)
	{
		printRoottoLeafNode(e, path);
	}
	path.pop_back();
}
void GraphOperation::printRoottoLeafNode(GraphOperation::Node* root)
{
	if (root == NULL)
	{
		cout << "\nSorry, Not possiable to reach anywhere !!!" << endl;
		return;
	}
	vector<int> path;
	this->printRoottoLeafNode(root,path);
	cout << endl;
}
GraphOperation::Node* GraphOperation::createNode(int key,vector<int> values)
{
	vector<Node*> childs;
	for (auto item : values)
	{
		childs.push_back(new GraphOperation::Node(item));
	}
	GraphOperation::Node* nn = new GraphOperation::Node(key, childs);
	return  nn;
}
void GraphOperation::printmap(unordered_map<int,vector<int>>items,int start,vector<int> &v)
{
	vector<int> vec = items[start];
	v.push_back(start);
	if (items.end() == items.find(start)) return;
	
	for (auto i : vec)
	{
		printmap(items, i, v);
	}
	cout << "Path usinh map ";
	for (auto i : v)
	{
		cout << " -> " << i;
	}
	cout << endl;
	v.pop_back();
}
void GraphOperation::bellmanFordSSSP()
{
	if (this->getEdgeCount() == 0)
	{
		cout << "\n Sorry! You don't have weight for the edges...\n" << endl;
		return;
	}
	int start;
	int* dist = new int[this->getVertexCount()];
	int* parent = new int[this->getVertexCount()];
	//used to print every involved path in bellmanFord 
	int* temparr = new int[this->getVertexCount()];
	vector<shared_ptr<Graph::EdgeList>> edges(this->edgeList);

	for (int i = 0;i < this->getVertexCount();i++)
	{
		dist[i] = INT_MAX;
		parent[i] = -1;
		temparr[i] = -1;
	}
	cout << "Choose starting point of Garph....." << endl;
	cin >> start;
	dist[start] = 0;
	parent[start] = start;
	bool flag = true;
	for (int i = 0;flag && i < this->getVertexCount();i++)
	{
		flag = false;
		for (auto& e : edges)
		{
			int src = e->getSrc(), dest = e->getDest(), weight = e->getWeight();
			if (dist[src] != INT_MAX && (dist[src] + weight < dist[dest]))
			{
				dist[dest] = dist[src] + weight;
				parent[dest] = src;
				flag = true;
			}
		}
	} 
	flag = true;
	// check for negative weight cycle
	for (auto& e : edges)
	{
		int src = e->getSrc(), dest = e->getDest(), weight = e->getWeight();
		if (dist[src] != INT_MAX && (dist[src] + weight < dist[dest]))
		{
			flag = false;
			cout << "\n--------- Warning Alert !!! ----------\n"
				" Negative weight cycle detected\n"
				" Bellmon Ford can't be use for such a Graph !\n"
				<< endl;
			break;
		}
	}
	//print the Shortest path from Source to all vertices
	if (flag)
	{
		string res;
		for (int i = 0;i < this->getVertexCount();i++)
		{
			if (dist[i] == INT_MAX)
				res = "Not Possible";
			else
				res = to_string(dist[i]);
			cout << "Shortes distance from " << start << "-> " << i << " = " << res << endl;
		}

	//print Path from source to all reachable vertex

		GraphOperation::Node* root = NULL;
		//store parent of  childs (key=parent, values=childs)
		unordered_map<int, vector<int>> items;
		int start=0;
		for (int i = 0;i < this->getVertexCount();i++)
		{
			if (parent[i] == i) start = i;
			if(parent[i] != -1 && parent[i] != i)
				items[parent[i]].push_back(i);
		}
		//-------------- Method 1 -------------------
		/*unordered_map<int, vector<int>> check;
		check[2].push_back(1);
		check[2].push_back(3);
		check[1].push_back(4);
		check[1].push_back(0);
		check[3].push_back(6);*/
		vector<int> v;
		this->printmap(items,start,v);

		//-------------- Method 2 -------------------
		//make a tree from map 
		for (auto& i : items)
		{
			GraphOperation::Node* node =  this->createNode(i.first,i.second);
			this->addNode(&root,node);
		}
		//print All path from Root to leaf
		this->printRoottoLeafNode(root);
		/*
		//reverse parent array with temp[parent[i]] = i;
		for (int i = 0;i < this->getVertexCount();i++)
		{
			temparr[parent[i]] = i;
		}
		cout << "Path :- "<< start;
		int temp = start;
		for (int i = 0;temparr[temp] != -1 && i < this->getVertexCount();i++)
		{
			cout << " -> " << temparr[temp];
			temp = temparr[temp];
		}

		cout << endl<<" parent :-";
		for (int i = 0;i < this->getVertexCount();i++)
		{
			cout << i<< " -> " << parent[i]<< ", ";
		}*/
		cout << "\n" << endl;
	}

}
void GraphOperation::floydWarshallAPSP()
{
	if (this->edgeList.size() == 0)
	{
		cout << "\n Sorry! You don't have weight for the edges...\n" << endl;
		return;
	}
	int x = this->getVertexCount();
	int** dist = new int*[this->getVertexCount()];

	for (int i = 0;i < this->getVertexCount();i++)
	{
		dist[i] = new int[this->getVertexCount()];
		for (int j = 0;i < this->getVertexCount();i++)
		{
			dist[i][j] = this->adjMat[i][j];
		}
		dist[i][i] = 0;
	}

	for (int i = 0;i < this->getVertexCount();i++)
	{
		for (int s = 0;s < this->getVertexCount();i++)
		{

			for (int d = 0;d < this->getVertexCount();i++)
			{
				if (dist[s][i] != INF && dist[i][d] != INF && dist[s][i] + dist[i][d] < dist[s][d])
					dist[s][i] = dist[s][i] + dist[i][d];
			}
		}
	}
	//print the array
	string res;
	for (int i = 0;i < this->getVertexCount();i++)
	{
		for (int j = 0;i < this->getVertexCount();i++)
		{
			res = dist[i][j] == INF ? "Not possiable" : to_string(dist[i][j]);
			cout << " distance of " << j <<" ->  "<< i <<" = " << res << endl;
		}
	}
}


