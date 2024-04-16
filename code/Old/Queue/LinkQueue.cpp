#include<iostream>
#include<cassert>
#include<ctime>
using namespace std;
typedef int elemtype;

struct QueueNode{
    elemtype date;
    QueueNode *next;
};
typedef struct{
    QueueNode *front,*rear;
}LinkQueue;

//初始化
void LinkQueueInit(LinkQueue &q){
    q.front=new QueueNode;
    q.rear=q.front;
    q.front->next=0;
}

//判空
bool LinkQueueEmpty(LinkQueue &q)
{
    if(q.front==q.rear)
        return true;
    return false;
}

//入队
void LinkQueueIn(LinkQueue &q,elemtype e){
    QueueNode *p=new QueueNode;
    p->date=e;
    p->next=0;
    q.rear->next=p;
    q.rear=p;
}

//出队
void LinkQueueOut(LinkQueue &q){
    assert(!LinkQueueEmpty(q));
    QueueNode *p;
    p=q.front->next;
    q.front->next=p->next;
    delete p;
    if(q.front->next==0)
        q.rear=q.front;
}
//取头
elemtype LinkQueueFront(LinkQueue &q){
    assert(!LinkQueueEmpty(q));
    return q.front->next->date;
}

//清空
void LinkQueueClear(LinkQueue &q)
{
    while(!LinkQueueEmpty(q))
        LinkQueueOut(q);
}

//销毁
void LinkQueueDestroy(LinkQueue &q){
    LinkQueueClear(q);
    delete q.front;
    q.front=q.rear=0;
}

//打印
void LinkQueuePrint(LinkQueue &q){
    if(LinkQueueEmpty(q))
    {
        cout<<"队列空"<<endl;
        return;
    }
    QueueNode *p;
    p=q.front->next;
    while(p)
    {
        cout<<p->date<<" ";
        p=p->next;
    }
    cout<<endl;
    
}

//测试
int main(){
LinkQueue q;
QueueNode p;
LinkQueueInit(q);
LinkQueueIn(q,2);
LinkQueueIn(q,6);
LinkQueuePrint(q);
LinkQueueIn(q,5);
LinkQueueOut(q);
LinkQueuePrint(q);
}
