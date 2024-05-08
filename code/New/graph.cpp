#include <iostream>
#include <assert.h>
#include <string>
//#include "SeqQueue.h"
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
	//让输出的结果带边框和换行，让输出的结果更美观
    cout << endl;
    for(int i = 0; i < g.vCount; i++) {
        cout << "|";
        for(int j = 0; j < g.vCount; j++) {
            cout << g.matrix[i][j] << " ";
        }
        cout << "|" << endl;
    }
}



void GraphCreateTest()
{
	Graph g;
	GraphCreate(g);
	GraphPrint(g);
}

int main(){
	 GraphCreateTest();
	 system("pause");
}