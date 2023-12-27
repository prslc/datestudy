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

//初始化
void SeqListInit(SeqList &L,int initsize)
{
	L.elem=new elemtype[initsize];
	L.size=initsize;
	L.length=0;
}

//销毁
void SeqListDestroy(SeqList &L)
{
	delete []L.elem;
	L.size=L.length=0;
}

//扩容
void SeqListIncresize(SeqList &L)
{
	if(L.size==L.length){
	L.size++;}
}

//插入
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

//删除
void SeqListDelete(SeqList &L,int i)
{
	assert(i>=1&& i<=L.length);
	for(int j=i;j<=L.length-1;j++)
		L.elem[j-1]=L.elem[j];
	L.length--;
}

//设置
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

//获取
elemtype SeqListGet(SeqList &L,int i)
{
	assert(i>=1 && i <= L.length);
	return L.elem[i-1];
}

//清除
void SeqListClear(SeqList &L)
{
	L.length=0;
}

//判空
bool SeqListEmpty(SeqList &L)
{
	if(L.length==0)
		return true;
	else 
		return false;
}

//长度
int SeqListLength(SeqList &L)
{
	return L.length;
}

//打印
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

//切换
void ListSwap(SeqList &L, int i, int j) {
    elemtype temp = L.elem[i];
    L.elem[i] = L.elem[j];
    L.elem[j] = temp;
}

//冒泡排序
void BubbleSort(SeqList &L)
{
    if(L.length<=1)return;
    bool flag=false;
    for(int i=L.length-1;i>=1;i--)
        if(!flag){
            flag=true;
            for(int j=0;j<i;j++)
                if(L.elem[j]>L.elem[j+1]){
                    ListSwap(L,j,j+1);
                    flag=false;
                }
                //cout << "After pass " << L.length - i << ": ";
            for(int k = 0; k < L.length; k++)
                cout << L.elem[k] << " ";
            cout << endl;
        }
}

//测试
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
    system("chcp 65001");
    SeqList L;
	SeqListInit(L,10);
    int arr[10] = {15,18,11,13,19,16,12,17,10,8};
    for(int i = 0; i < 10; i++)
        SeqListInsert(L, i+1, arr[i]);
    cout << "Before BubbleSort: ";
    SeqListPrint(L);
    BubbleSort(L);
    cout << "After BubbleSort: ";
    SeqListPrint(L);
}