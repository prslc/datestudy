#include <iostream>
#include <assert.h>
#include <string>
#include "SeqQueue.h"
//#include "LinkStack.h"
using namespace std;
#define INFINITY 1000000
struct Graph{
	int vCount,eCount;
	string *vers;
	int **matrix;
	bool isDirect,isHaveWeight;
};

//search vertex
int GraphLocate(Graph g,string v)
{
	for(int i=0;i<g.vCount;i++)
		if(g.vers[i]==v)
			return i;
	return -1;
}
//create
void GraphCreate(Graph &g)
{
	cout<<"input Graph type:";
	cin>>g.isDirect;
	cin>>g.isHaveWeight;
	cout<<"input vCount:";
	cin>>g.vCount;
	//create vers
	cout<<"input vers:";
	g.vers=new string[g.vCount];
	for(int i=0;i<g.vCount;i++)
		cin>>g.vers[i];
	//init matrix
	g.matrix=new int*[g.vCount];
	for(int j=0;j<g.vCount;j++)
		g.matrix[j]=new int[g.vCount];
	for(int a=0;a<g.vCount;a++)
		for(int b=0;b<g.vCount;b++)
		if(g.isHaveWeight==1)
			g.matrix[a][b]=INFINITY;
		else
			g.matrix[a][b]=0;
	//add edge
	cout<<"input eCount:";	cin>>g.eCount;
	string v1,v2;	int weight;
	for(int q=0;q<g.eCount;q++)	{
		cout<<"input the edges of "<<q+1<<":";
		cin>>v1>>v2;
		if(g.isHaveWeight==1)
			cin>>weight;
		else
			weight=1;
		g.matrix[GraphLocate(g,v1)][GraphLocate(g,v2)]=weight;
		if(g.isDirect==0)
			g.matrix[GraphLocate(g,v2)][GraphLocate(g,v1)]=weight;
	}
}

void GraphPrint(Graph &g)
{
	cout << endl; 
    for(int i = 0; i < g.vCount; i++) {
        for(int j = 0; j < g.vCount; j++) {
            cout << g.matrix[i][j] << " ";
        }
        cout << endl; 
    }
}

//DFS init
void GraphDFSbyRec(Graph &g,string v,bool *&isVisited)
{
    cout<< "" <<v;
    isVisited[GraphLocate(g,v)] = true;
    for (int i = 0; i <g.vCount; i++)
    {
        if (g.matrix[GraphLocate(g,v)][i]!=0 && isVisited[i]==false)
        {
			cout << " -> ";
            GraphDFSbyRec(g,g.vers[i],isVisited);
        }
        
    }
    
}


//DFS
void GraphDFS(Graph &g,string v)
{
    bool *isVisited = new bool [g.vCount];
    for (int i = 0; i < g.vCount; i++)
    {
        isVisited[i]=false;
    }
    cout<< "DFS: ";
    GraphDFSbyRec(g,v,isVisited);
    cout << endl;
}

//BFS init
void GraphBFS_init(Graph &g, string v, bool *&isVisited, SeqQueue &q) {
    isVisited = new bool[g.vCount];
	cout << "BFS: ";
    for (int i = 0; i < g.vCount; i++) {
        isVisited[i] = false;
    }
    cout << "" << v;
    isVisited[GraphLocate(g, v)] = true;
    SeqQueueIn(q, GraphLocate(g, v));
}

//BFS
void GraphBFS(Graph &g, string v, bool *&isVisited, SeqQueue &q) {
    while (!SeqQueueEmpty(q)) {
        int cur = SeqQueueFront(q);
        SeqQueueOut(q);
        for (int i = 0; i < g.vCount; i++) {
            if (g.matrix[cur][i] != 0 && !isVisited[i]) {
                cout << " -> " << g.vers[i];
                isVisited[i] = true;
                SeqQueueIn(q, i);
            }
        }
    }
	cout << endl;
}



void GraphCreateTest()
{
    Graph g;
    GraphCreate(g);
    GraphPrint(g);
    string starting_vertex = g.vers[0];
    bool *isVisited;
	GraphDFS(g, starting_vertex);
    SeqQueue q;
    SeqQueueInit(q, g.vCount);
    GraphBFS_init(g, starting_vertex, isVisited, q);
    GraphBFS(g, starting_vertex, isVisited, q);
    delete[] isVisited;
}



int main(){
	 GraphCreateTest();
	 system("pause");
}