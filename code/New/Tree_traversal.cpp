#include<iostream>
#include<ctime>
#include<cassert>
#include<string>
using namespace std;

struct BitreeNode{
	char data;
	BitreeNode *lc,*rc;
};

typedef BitreeNode* Bitree;

//create
void BitreeCreate(Bitree &t,string define,int &i)
{
	if(define[i]=='*'){
		t=0;
		i++;
		return;
	}
	t=new BitreeNode;
	t->data=define[i];
	i++;
	BitreeCreate(t->lc,define,i);
	BitreeCreate(t->rc,define,i);
}

//pre
void BitreePreOrder(Bitree t)
{
	if(t)
	{
		cout<<t->data;
		BitreePreOrder(t->lc);
		BitreePreOrder(t->rc);
	}
}

//CenterOrder
void BitreeCenterOrderOrder(Bitree t)
{
	if(t)
	{
		BitreePreOrder(t->lc);
		cout<<t->data;
		BitreePreOrder(t->rc);
	}
}

//back
void BitreeBackOrder(Bitree t)
{
	if(t)
	{
		cout<<t->data;
		BitreeBackOrder(t->rc);
		BitreeBackOrder(t->lc);
	}
}

//get node number
int BitreeCount(Bitree t)
{
	if(t)
		return BitreeCount(t->lc)+BitreeCount(t->rc)+1;
		return 0;
}

//get height
int BitreeHeight(Bitree t)
{
	if(!t)
		return 0;
	if(BitreeHeight(t->lc)>BitreeHeight(t->rc))
		return BitreeHeight(t->lc)+1;
	return BitreeHeight(t->rc)+1;
}

//Search
Bitree BitreeSearch(Bitree t,char e)
{
	if(t==0)
		return 0;
	if(t->data==e)
		return t;
	if(BitreeSearch(t->lc,e))
		return BitreeSearch(t->lc,e);
	return BitreeSearch(t->rc,e);
}

//test
void BitreeTest()
{
    Bitree t;
    int i = 0;
    BitreeCreate(t, "ab**c**", i);
    cout << "PreOrder: ";
	BitreePreOrder(t);
	cout << "\n";
    cout << "BackOrder: ";
    BitreeBackOrder(t);
	cout << "\n";
    cout << "CenterOrder: ";
    BitreeCenterOrderOrder(t);

	cout << "\n";
	cout << "Node number: ";
	cout << BitreeCount(t) << "\n";

	BitreeCount(t);
	cout << "Height: ";
	BitreeHeight(t);
	cout << BitreeHeight(t) << "\n";
}

int main()
{
	BitreeTest();
}