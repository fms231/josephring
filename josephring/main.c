#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct linklist
{
    int data;
    struct linklist* next;
};

//�����ڵ�,��¼���
struct linklist* createlist(int data)
{
    struct linklist* newlist = (struct linklist*)malloc(sizeof(struct linklist));
    newlist->data = data;
    newlist->next = NULL;
    return newlist;
}

//������,β�巨
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

//ѭ������
void looplist(struct linklist* headlist)
{
    struct linklist* p = headlist;
    //�ҵ��������һ�����
    while (p->next)
    {
        p = p->next;
    }
    p->next = headlist;              
}

void distrilist(struct linklist* headlist, int m, int n)
{
    struct linklist* p = headlist;
    //����m����ŵĿռ�
    int* a = (int*)malloc(m * sizeof(int));
    int j = 0, k = 0;
    while (j != m)
    {
        if (p->data != 0)
            k++;
        if (k == n)
        {
            a[j] = p->data;   //��¼���еı��
            //���������Ϊ0
            p->data = 0;
            //��������+1
            j++;
            k = 0;
        }
        p = p->next;
    }
    p = headlist;
    for (j = 0; j < m; j++)
    {
        p->data = a[j];     //���¸����������ӵı��
        p = p->next;
    }
    //�ͷŷ���������ڴ�
    free(a);
}

//��ӡ���ͷ�����
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
    printf("������Լɪ�򻷵������Լ����ӵĺ��룺\n");
    scanf("%d", &m);
    struct linklist* headlist = createlist(1);
    for (i = 2; i <= m; i++)
        Insertlist(headlist, i);   //Ϊ�������
    looplist(headlist);
    scanf("%d", &n);
    distrilist(headlist, m, n);
    printlist(headlist, m);
    return 0;
}