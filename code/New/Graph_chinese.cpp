#include <iostream>
#include <assert.h>
#include <string>
#include "SeqQueue.h"
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
	cout<<"是否为有向图，0.无向图 1.有向图，" << endl;
	cin>>g.isDirect;
	cout<<"是否为带权图，0.不带权 1.带权，" << endl;
	cin>>g.isHaveWeight;
	cout<<"请输入图的顶点数:" << endl;
	cin>>g.vCount;
	//create vers
	cout<<"请输入图的顶点，例：v1，v2:" << endl;
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
	cout<<"请输入图的边数:" << endl;	
	cin>>g.eCount;
	string v1,v2;	int weight;
	for(int q=0;q<g.eCount;q++)	{
		cout<<"请输入边的方向，例v1，换行v2 "<<q+1<<":" << endl;
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
	if (g.isDirect==1)
	{
		cout <<"有向图" << endl ; 
	}else{
		cout <<"无向图" << endl;
	}
	if (g.isHaveWeight==1)
	{
		cout <<"带权图" << endl;
	}else{
		cout<< "不带权" << endl;
	}
	cout << "图的顶点数为：" << g.vCount << endl;
	cout << "图的边数为：" << g.eCount << endl;
    for(int i = 0; i < g.vCount; i++) {
        for(int j = 0; j < g.vCount; j++) {
            cout << g.matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//DFS init
void GraphDFSbyRec(Graph &g,string v,bool *&is_visited)
{
    cout<< "" <<v;
    is_visited[GraphLocate(g,v)] = true;
    for (int i = 0; i <g.vCount; i++)
    {
        if (g.matrix[GraphLocate(g,v)][i]!=0 && is_visited[i]==false)
        {
			cout << " -> ";
            GraphDFSbyRec(g,g.vers[i],is_visited);
        }
        
    }
    
}


//DFS
void GraphDFS(Graph &g,string v)
{
    bool *is_visited = new bool [g.vCount];
    for (int i = 0; i < g.vCount; i++)
    {
        is_visited[i]=false;
    }
    cout<< "深度优先搜索: ";
    GraphDFSbyRec(g,v,is_visited);
    cout << endl;
}

//BFS init
void GraphBFS_init(Graph &g, string v, bool *&is_Visited, SeqQueue &q) {
    is_Visited = new bool[g.vCount];
	cout << "广度优先搜索: ";
    for (int i = 0; i < g.vCount; i++) {
        is_Visited[i] = false;
    }
    cout << "" << v;
    is_Visited[GraphLocate(g, v)] = true;
    SeqQueueIn(q, GraphLocate(g, v));
}

//BFS
void GraphBFS(Graph &g, string v, bool *&is_Visited, SeqQueue &q) {
    while (!SeqQueueEmpty(q)) {
        int cur = SeqQueueFront(q);
        SeqQueueOut(q);
        for (int i = 0; i < g.vCount; i++) {
            if (g.matrix[cur][i] != 0 && !is_Visited[i]) {
                cout << " -> " << g.vers[i];
                is_Visited[i] = true;
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
    bool *is_visited;
	GraphDFS(g, starting_vertex);
    SeqQueue q;
    SeqQueueInit(q, g.vCount);
    GraphBFS_init(g, starting_vertex, is_visited, q);
    GraphBFS(g, starting_vertex, is_visited, q);
    delete[] is_visited;
}

int main(){
	 system("chcp 65001");
	 GraphCreateTest();
	 system("pause");
}