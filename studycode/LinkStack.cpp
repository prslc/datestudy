#include<iostream>
#include<ctime>
#include<cassert>
using namespace std;
typedef int elemtype;

struct StackNode{
	elemtype data;
	StackNode *next;
};
typedef StackNode* LinkStack;

//初始化栈
void LinkStackInit(LinkStack &S)
{
	S=new StackNode;
	S->next= 0;
}
//入栈
void LinkStackPush(LinkStack &S,elemtype e)
{
	StackNode *q=new StackNode;
	q->data=e;
	q->next=S->next;
	S->next=q;
}
//出栈
void LinkStackPop(LinkStack &S)
{
	assert(S->next);
	StackNode *p=S->next;
	S->next=p->next;
	delete p;
}
//清空栈
void LinkStackClear(LinkStack &s)
{
	while(s->next)
		LinkStackPop(s);
}
//销毁栈
void LinkStackDestroy(LinkStack &s)
{
	LinkStackClear(s);
	delete s;
}
//判空
bool LinkStackEmpty(LinkStack &S)
{
	if(S->next)
		return false;
	return true;
}
//取栈
elemtype LinkStackTop(LinkStack &S)
{
	assert(S->next);
	return S->next->data;
}
//输出
void LinkStackPrint(LinkStack &s)
{
	if(LinkStackEmpty(s))
	{
		cout<<"栈空"<<endl;
		return;
	}
	StackNode *p=s->next;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
//测试
void LinkStackTest()
{
	cout<<"LinkStack Test:"<<endl;
	LinkStack S;
	LinkStackInit(S);
	//插入元素测试
	srand(unsigned(time(NULL)));
	for(int i=0;i<10;i++)
		LinkStackPush(S,rand()%100);
	LinkStackPrint(S);
	//删除元素测试
	for(int i=1;i<=3;i++)
	{
		LinkStackPop(S);
		LinkStackPrint(S);
	}
}
int main()
{
	LinkStackTest();
}
