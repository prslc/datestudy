#include<iostream>
#include<cassert>
using namespace std;
typedef int elemtype;
#include<ctime>

struct SeqList{
	elemtype *elem;
	int size;
	int length;
};

void SeqListInit(SeqList &L,int initsize)
{
	L.elem=new elemtype[initsize];
	L.size=initsize;
	L.length=0;
}
void SeqListDestroy(SeqList &L)
{
	delete []L.elem;
	L.size=L.length=0;
}
void SeqListIncresize(SeqList &L)
{
	if(L.size==L.length){
	L.size++;}
}
void SeqListInsert(SeqList &L,int i,elemtype e)
{
	assert(i>=1&& i<=L.length+1);
	if(L.size==L.length)
		SeqListIncresize(L);
	for(int j=L.length-1;j>=i-1;j--)
		L.elem[j+1]=L.elem[j];
	L.elem[i-1]=e;
	L.length++;
}
void SeqListDelete(SeqList &L,int i)
{
	assert(i>=1&& i<=L.length);
	for(int j=i;j<=L.length-1;j++)
		L.elem[j-1]=L.elem[j];
	L.length--;
}
void SeqListSet(SeqList &L,int i,elemtype e)
{
	assert(i>=1&& i<=L.length);
	L.elem[i-1]=e;
}
int SeqListLocate(SeqList &L,elemtype e)
{
	for(int i=0;i<L.length;i++)
		if(L.elem[i]==e)
			return i+1;
		return -1;
}
elemtype SeqListGet(SeqList &L,int i)
{
	assert(i>=1 && i <= L.length);
	return L.elem[i-1];
}
void SeqListClear(SeqList &L)
{
	L.length=0;
}
bool SeqListEmpty(SeqList &L)
{
	if(L.length==0)
		return true;
	else 
		return false;
}
int SeqListLength(SeqList &L)
{
	return L.length;
}
void SeqListPrint(SeqList &L)
{
	if(SeqListEmpty(L))
	{
		cout<<"表空"<<endl;
		return;
	}
	for(int i=0;i<L.length;i++)
		cout<<L.elem[i]<<" ";
	cout<<endl;
}

void SeqListTest()
{
	cout<<"SeqList Test:"<<endl;
	SeqList L;
	SeqListInit(L,100);
	srand(unsigned(time(NULL)));
	for(int i=0;i<50;i++)
		SeqListInsert(L,1,rand()%100);
	SeqListPrint(L);
	for(int j=1;j<=5;j++)
		SeqListDelete(L,j);
	SeqListPrint(L);
	int data=100;
	while(SeqListLocate(L,data)<=0)
	{
		data=rand()%100;
		cout<<data<<"在第"<<SeqListLocate(L,data)<<"个位置"<<endl;
	}
}


int main()
{
	SeqListTest();
}