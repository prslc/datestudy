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

//in
void BitreeInOrder(Bitree t)
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

//获取结点
int BitreeCount(Bitree t)
{
	if(t){
		int i = int(BitreeCount(t->lc))+int(BitreeCount(t->rc))+1;
		printf("%d",i);
	}
	return 0;
}

//获取高度
int BitreeHeight(Bitree t)
{
	if(!t)
		return 0;
	if(BitreeHeight(t->lc)>BitreeHeight(t->rc))
		return BitreeHeight(t->lc)+1;
	return BitreeHeight(t->rc)+1;
}

//create Bitree
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
    cout << "InOrder: ";
    BitreeInOrder(t);

	cout << "\n";
	cout << "结点数: ";

	BitreeCount(t);
	cout << "\n";
	cout << "高度: ";
	BitreeHeight(t);
	cout << "\n";
	
}

int main()
{
	BitreeTest();
}