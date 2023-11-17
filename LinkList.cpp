#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;

typedef int elemtype;

struct ListNode {
    elemtype data;
    ListNode *next;
};

typedef ListNode* LinkList;

// 初始化链表
void InitializeLinkedList(LinkList &L) {
    L = new ListNode;
    L->next = 0;
}

// 获取链表长度
int GetLinkedListLength(LinkList &L) {
    int count = 0;
    ListNode *p = L;
    while (p->next) {
        count++;
        p = p->next;
    }
    return count;
}

// 在指定位置插入元素
void InsertElementAtPosition(LinkList &L, int position, elemtype element) {
    assert(position >= 1 && position <= GetLinkedListLength(L) + 1);
    ListNode *p = L;
    int count = 0;
    while (count < position - 1) {
        p = p->next;
        count++;
    }
    ListNode *newNode = new ListNode;
    newNode->data = element;
    newNode->next = p->next;
    p->next = newNode;
}

// 删除指定位置的元素
void DeleteElementAtPosition(LinkList &L, int position) {
    assert(position >= 1 && position <= GetLinkedListLength(L));
    ListNode *p = L;
    int count = 0;
    while (count < position - 1) {
        p = p->next;
        count++;
    }

    ListNode *toBeDeleted = p->next;
    p->next = toBeDeleted->next;
    delete toBeDeleted;
}

// 清空链表
void ClearLinkedList(LinkList &L) {
    while (L->next)
        DeleteElementAtPosition(L, 1);
}

// 销毁链表
void DestroyLinkedList(LinkList &L) {
    ClearLinkedList(L);
    delete L;
}

// 设置指定位置的元素值
void SetElementAtPosition(LinkList &L, int position, elemtype element) {
    assert(position >= 1 && position <= GetLinkedListLength(L));
    ListNode *p = L;
    int count = 0;
    while (count < position) {
        p = p->next;
        count++;
    }
    p->data = element;
}

// 查找元素的位置
int LinkListLocate(LinkList &L,elemtype e)
{
	ListNode *p=L->next;
	int count=1;
	while(p){
		if(p->data==e)
			return count;
		p=p->next;
		count++;
	}
return 0;
}

// 获取指定位置的元素值
elemtype GetElementAtPosition(LinkList &L, int position) {
    assert(position >= 1 && position <= GetLinkedListLength(L));
    ListNode *p = L;
    int count = 0;
    while (count < position) {
        p = p->next;
        count++;
    }
    return p->data;
}

// 检查链表是否为空
bool IsLinkedListEmpty(LinkList &L) {
    if (L->next)
        return false;
    return true;
}

// 打印链表元素
void PrintLinkedList(LinkList &L) {
    if (IsLinkedListEmpty(L)) {
        cout << "链表为空" << endl;
        return;
    }
    ListNode *p = L->next;
    int count = 1;
    while (p) {
        cout << p->data << " ";
        p = p->next;
        count++;
    }
    cout << endl;
}

// 链表测试
void LinkListTest() {
    cout << "链表测试:" << endl;
    LinkList L;
    InitializeLinkedList(L);

    // 插入元素测试
    srand(unsigned(time(NULL)));
    for (int i = 0; i < 50; i++)
        InsertElementAtPosition(L, 1, rand() % 100);
    PrintLinkedList(L);

    // 删除元素测试
    for (int i = 1; i <= 5; i++)
        DeleteElementAtPosition(L, i);
    PrintLinkedList(L);

    // 查找元素测试
    int data=100;
	while(LinkListLocate(L,data)<=0)
	{
		data=rand()%100;
		cout<<data<<"在第"<<LinkListLocate(L,data)<<"个位置"<<endl;
	}
}


int main() {
    system("chcp 65001");
    LinkListTest();
    return 0;
}