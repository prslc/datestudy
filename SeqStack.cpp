#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

typedef int elemtype;
struct SeqStack
{
	elemtype *elem;
	int size;
	int top;
};
//栈的初始化
void SeqStackInit(SeqStack &S, int initsize)
{
	S.elem = new elemtype[initsize];
	S.size = initsize;
	S.top = 0;
}
//入栈
void SeqStackPush(SeqStack &S, elemtype e)
{
	if (S.top == S.size)
		return;
	S.elem[S.top] = e;
	S.top++;
}
//出栈
void SeqStackPop(SeqStack &S)
{
	assert(S.top > 0);
	S.top--;
}
//栈空
bool SeqStackEmpty(SeqStack &S)
{
	if (S.top == 0)
		return true;
	else
		return false;
}
//栈满
bool SeqStackFull(SeqStack &s)
{
    return s.top == s.size;
}

//取栈顶
elemtype SeqStackTop(SeqStack &S)
{
	return S.elem[S.top-1];
}

//输出
void SeqStackPrint(SeqStack &s)
{
	if (SeqStackEmpty(s))
	{
		cout << "栈空" << endl;
		return;
	}
	for (int i = 0; i < s.top; ++i)
	{
		printf("%c", s.elem[i]);
	}
	cout << endl;
}
//测试
int main()
{
	SeqStack s;
	SeqStackInit(s, 4);
	SeqStackPush(s,'a');
	SeqStackPush(s,'b');
	SeqStackPush(s,'c');
	SeqStackPush(s,'d');
	SeqStackPrint(s);
	SeqStackPop(s);
	SeqStackPop(s);
	SeqStackPrint(s);
}
