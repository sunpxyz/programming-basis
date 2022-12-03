// ���ݽṹ��C����������.��ε��
// ��2��.���Ա�
// list.h
// 2016.09.18


#include "..\public.h"


// ***************
// ADT: List
// ***************

// ���Ա�Ķ�̬����˳��洢�ṹ
#define LIST_INIT_SIZE 100   // ���Է�����
#define LIST_INCREMENT 10    // �ٷ�������

typedef struct {
	ElemType *elem;   // �洢�ռ��ַ
	int length;       // ��ǰ����
	int list_size;    // ��ǰ����Ĵ�������
} SqList;

// �㷨2.3 ~ 2.7


// ���Ա�ľ�̬������洢�ṹ
#define MAX_SIZE 1000   // �������󳤶�

typedef struct {
	ElemType data;
	int cur;
} Component, SLinkList[MAX_SIZE];

// �㷨2.13 ~ 2.17


// ���Ա��˫������洢�ṹ
typedef struct {
	ElemType data;
	DulNode *prior;
	DulNode *next;
} DulNode, *DulLinkList;

// �㷨2.18 ~ 2.19


// һ����ͷ����������������
typedef struct {
	ElemType element;
	Node next;
} *Node, *Position;

typedef struct {
	Node head, tail;   // �ֱ�ָ�����������е�ͷ�������һ�����
	int len;           // ָʾ��������������Ԫ�صĸ���
} LinkList;

// ���������ĺ���ԭ������
Status MakeNode(Node p, ElemType e);
void FreeNode(Node p);
Status InitList(LinkList ll);
Status DestroyList(LinkList ll);
Status ClearList(LinkList ll);
Status InsFirst(Node h, Node s);
Status DelFirst(Node h, Node s);
Status Apped(LinkList h, Node s);
Status Remove(LinkList h, Node s);
Status InsBefore(LinkList h, Node p, Node s);
Status InsAfter(LinkList l, Node p, Node s);
Status SetCurElem(Node p, ElemType e);
ElemType GetCurElem(Node p);
Status ListEmpty(LinkList l);
int ListLength(LinkList l);
Position GetHead(LinkList l);
Position PriorPos(LinkList, Node p);
Position NextPos(LinkList p, Node p);
Status LocatePos(LinkList l, int i, Node p);
Position LocateElem(LinkList l, ElemType e, Status (*compare)(ElemType, ElemType));
Status ListTraverse(LinkList l, Status (*visit)());


// �㷨2.20
Status ListInsert_L(LinkList l, int ,ElemType et);

// �㷨2.21
Status MergeList_L(LinkList la, LinkList lb, LinkList lc,
		           int (*compare)(ElemType, ElemType));


/*

// �㷨2.1
void Union(LinkList la, LinkList lb);

// �㷨2.2
void MergeList(LinkList la, LinkList lb, LinkList lc);

// �㷨2.3
bool InitList_Sq(SqList l);

// �㷨2.4
bool ListInsert_Sq(SqList l, int i, ElemType et);

// �㷨2.5
bool ListDelete_Sq(SqList l, int i, ElemType et);



