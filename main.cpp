#include "main.h"
int menu()
{
	int input;
	cout << "1. Construct Graph " << endl;
	cout << "2. Display Garph" << endl;
	cout << "3. DFS Traversal" << endl;
	cout << "4. BFS Traversal" << endl;
	cout << "5. check Connected or not"<< endl;
	cout << "6. dfsSpanningTree" << endl;
	cout << "7. bfsSpanningTree" << endl;
	cout << "8. singleSourceShortestDistance" << endl;
	cout << "9. check for Bi-Parted or Not" << endl;
	cout << "10. Does Graph have cycle?" << endl;
	cout << "11. kruskal's Minimum Spanning Tree" << endl;
	cout << "12. Prim's Minimum Spanning Tree" << endl;
	cout << "13. Dijkstra's (Sigle source shortest Path)Algorithm " << endl;
	cout << "14. Bellman-Ford (Sigle source shortest Path)Algorithm" << endl;
	cout << "15. Floyd-Warshall (All pair shortest Path)Algorithm" << endl;
	cout << "0. Exit" << endl;
	cin >> input;
	return input;
}
int main()
{

	int numberofVertex;
	cout << "!!! Welcome to Graph Algorithm implementation Project !!!" << endl;
	cout << "How many vertex do you have for your Garph?" << endl;
	cin >> numberofVertex;
	GraphOperation* g = new GraphOperation(numberofVertex);
	int choice;
	do
	{
		choice = menu();
		switch (choice)
		{
		case 0:
			exit(0);
			break;
		case 1:
			g->createGraph();
			break;
		case 2:
			g->display();
			break;
		case 3:
			g->dfsTrav();
			break;
		case 4:
			g->bfsTrav();
			break;
		case 5:
			g->isConnected() ? cout << "\n Garph is connected. \n"<<endl : cout << "\nGraph is not connected.\n"<<endl;
			break;
		case 6:
			g->dfsSpanningTree();
			break;
		case 7:
			g->bfsSpanningTree();
			break;
		case 8:
			g->singleSourceShortestDistance();
			break;
		case 9:
			g->isBiparted() ? cout << "\n Garph is Bi-Parted. \n" << endl : cout << "\nGraph is not Bi-Parted.\n" << endl;
			break;
		case 10:
			g->detectCycle(g->getEdgeList()) ? cout << "\n Garph is having cycle. \n" << endl : cout << "\nGraph is not having any cycle.\n" << endl;
			break;
		case 11:
			cout << "Total Weight of Kruskal's MST :- " << g->kruskalMST() << "\n"<<endl;
			break;
		case 12:
			cout << "Total Weight of Prims's MST :- " << g->primsMST() << "\n" << endl;
			break;
		case 13:
			g->dijkstraSPT();
			break;
		case 14:
			g->bellmanFordSSSP();
			break;
		case 15:
				g->floydWarshallAPSP();
				break;
		default:
			cout << "Sorry, wrong input !!!" << endl;
			break;
		}

	} while (choice);

	return 0;
}


// --------------- INPUT Sequence Order ------------
//vertex: 6
//then construct Graph 1
// then type of Garph (0 ->unw,1 ->uw,2 ->dnw,3 ->dw)
//Number of Edges : 7
//Edges :(here for unw) 0 1 0 2 0 3 1 2 1 4 3 4 3 5

//---------------INPUT------------------
//General :- 6 1 0 7 0 1 0 2 0 3 1 2 1 4 3 4 3 5
//for biparted :- 6 1 0 8  0 1 0 3 0 5 2 1 2 5 4 1 4 3 4 5

//for weighted Graph:- 
//9 1 1 14 7 6 1 8 2 2 6 5 2 0 1 4 2 5 4 8 6 6 2 3 7 7 8 7 0 7 8 1 2 8 3 4 9 5 4 10 1 7 11 3 5 14

//for weighted Directed Graph:-
//5 1 3 7 3 4 3 2 4 3 2 3 4 2 1 -2 1 3 -1 0 2 5 0 1 6