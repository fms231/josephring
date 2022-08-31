#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct linklist
{
    int data;
    struct linklist* next;
};

//创建节点,记录编号
struct linklist* createlist(int data)
{
    struct linklist* newlist = (struct linklist*)malloc(sizeof(struct linklist));
    newlist->data = data;
    newlist->next = NULL;
    return newlist;
}

//插入结点,尾插法
void Insertlist(struct linklist* headlist, int data)
{
    struct linklist* newlist = createlist(data);
    struct linklist* p = headlist;
    while (p->next)
    {
        p = p->next;
    }
    p->next = newlist;
}

//循环链表
void looplist(struct linklist* headlist)
{
    struct linklist* p = headlist;
    //找到链表最后一个结点
    while (p->next)
    {
        p = p->next;
    }
    p->next = headlist;              
}

void distrilist(struct linklist* headlist, int m, int n)
{
    struct linklist* p = headlist;
    //分配m个编号的空间
    int* a = (int*)malloc(m * sizeof(int));
    int j = 0, k = 0;
    while (j != m)
    {
        if (p->data != 0)
            k++;
        if (k == n)
        {
            a[j] = p->data;   //记录出列的编号
            //将编号设置为0
            p->data = 0;
            //出队人数+1
            j++;
            k = 0;
        }
        p = p->next;
    }
    p = headlist;
    for (j = 0; j < m; j++)
    {
        p->data = a[j];     //重新给链表分配出队的编号
        p = p->next;
    }
    //释放分配的数组内存
    free(a);
}

//打印和释放链表
void printlist(struct linklist* headlist, int m)
{
    int i = 0;
    while (i != m)
    {
        struct linklist* p = headlist;
        printf("%4d", headlist->data);
        headlist = p->next;
        free(p);
        i++;
    }
}

int main()
{
    int m, n, i;
    printf("请输入约瑟夫环的人数以及出队的号码：\n");
    scanf("%d", &m);
    struct linklist* headlist = createlist(1);
    for (i = 2; i <= m; i++)
        Insertlist(headlist, i);   //为人数编号
    looplist(headlist);
    scanf("%d", &n);
    distrilist(headlist, m, n);
    printlist(headlist, m);
    return 0;
}