#include<iostream>
#include<ctime>
#include<cassert>
#include<stack>
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
void LinkStackClear(LinkStack &S)
{
	while(S->next)
		LinkStackPop(S);
}
//销毁栈
void LinkStackDestroy(LinkStack &S)
{
	LinkStackClear(S);
	delete S;
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
void LinkStackPrint(LinkStack &S)
{
	if(LinkStackEmpty(S))
	{
		cout<<"栈空"<<endl;
		return;
	}
	StackNode *p=S->next;
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

//十进制转M
void Convert(int n,int m)
{
	if(m>16 || m<2)
	{
		cout<<"转换的进制超过范围"<<endl;
		return;
	}
	LinkStack S;
	LinkStackInit(S);
	while(n!=0){
        int remainder = n % m;
        LinkStackPush(S, remainder);
        n /=m;
    }
	cout<<"转换后的"<<m<<"进制数是:";
	while(!LinkStackEmpty(S)){
        cout << LinkStackTop(S);
        LinkStackPop(S);
    }
	cout<<endl;
}

void ConvertTest()
{
	srand(unsigned(time(NULL)));
	int n=rand()%1000;
	cout<<"输入的十进制数为:"<<n<<endl;
	Convert(n,2);
	Convert(n,8);
	Convert(n,16);
}


int main(){
    system("chcp 65001");
    LinkStackTest();
    ConvertTest();

    return 0;
}

