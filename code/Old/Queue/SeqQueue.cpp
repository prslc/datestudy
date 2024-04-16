#include<iostream>
#include<cassert>
#include<ctime>
using namespace std;
typedef int elemtype;

//定义队列
struct SeqQueue{
    int *elem;
    int size;
    int front;
    int rear;
};

//初始化
void SeqQueueInit(SeqQueue &q,int initsize){
    q.elem=new int[initsize];
    q.size=initsize;
    q.front=q.rear=0;
}

//销毁
void SeqQueueDestroy(SeqQueue &q){
    delete[] q.elem;
    q.front=q.rear=0;
    q.size=0;
}

//判空
bool SeqQueueEmpty(SeqQueue &q){
    if(q.front==q.rear){
        return true;}
        else{return false;}
}

//清空
void SeqQueueClear(SeqQueue &q)
{
    q.front=q.rear=0;
}

//求队首元素
elemtype SeqQueueFront(SeqQueue &q)
{
    assert(!SeqQueueEmpty(q));
    return q.elem[q.front];
}

//扩容
void SeqQueueIncresize(SeqQueue &q)
{
    if(q.rear==q.size){
    q.size++;}
}
//入队
void SeqQueueIn(SeqQueue &q,int e){
    if(q.front==(q.rear+1)%q.size){
        cout<<"队满，无法队入!"<<endl;
        return;
    }
    else{
    q.elem[q.rear]=e;
    q.rear=(q.rear+1)%q.size;}
}

//出队
void SeqQueueOut(SeqQueue &q)
{
    assert(!SeqQueueEmpty(q));
    q.front=(q.front+1)%q.size;
}

//打印数据
void SeqQueuePrint(SeqQueue &q)
{
	if(SeqQueueEmpty(q))
	{
		cout<<"队列空"<<endl;
		return;
	}
	for(int i=0;i<(q.rear-q.front+q.size)%q.size;i++)
		cout<<q.elem[(q.front+i)%q.size]<<' ';
	cout<<endl;
}
void SeqQueueTest()
{
	cout<<"SeqQueue Test:"<<endl;
	SeqQueue q;
	SeqQueueInit(q,10);
	//插入元素测试
		SeqQueueIn(q,19);
        SeqQueueIn(q,2);
        SeqQueueIn(q,3);
        SeqQueueIn(q,4);
	SeqQueuePrint(q);
	//删除元素测试
	for(int i=1;i<=3;i++)
	{
		SeqQueueOut(q);
		SeqQueuePrint(q);
	}
}

//测试
int main(){
SeqQueueTest();
}


