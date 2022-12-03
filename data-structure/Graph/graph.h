// ���ݽṹ��C����������.��ε��
// ��7��.ͼ
// graph.h


#include "public.h"


// ***************
// ADT: Graph
// ***************
/*
ADT Graph {
	CreateGraph(&G, V, VR);
	DestroyGraph(&G);
	LocateVex(G, u);
	GetVex(G, v);
	PutVex(&G, v, value);
	FirstAdjVex(G, v);
	NextAdjVex(G, v, w);
	InsertVex(&G, v);
	DeleteVex(&G, v);
	InsertArc(&G, v, w);
	DeleteArc(&G, v, w);
	DFSTraverse(G, Visit());
	BFSTraverse(G, Visit());
} ADT Graph
*/


#define INFINITY 10000000   // ���ֵ
#define MAX_VERTEX_NUM 20   // ��󶥵����
typedef enum {
	DG, DN, UDG, UDN   // ����ͼ��������������ͼ��������
} GraphKind;


// ͼ �����飨�ڽӾ��󣩴洢��ʾ
typedef int VRType;       // VRType�Ƕ����ϵ���͡�����Ȩͼ����1��0��ʾ������񣻶Դ�Ȩͼ����ΪȨֵ����
typedef char* InfoType;   // �û������Ϣ��ָ��
typedef struct ArcCell {
	VRType adj;
	InfoType *info;
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef int VertexType;
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];   // ��������
	AdjMatrix arcs;                    // �ڽӾ���
	int vex_num, arc_num;              // ͼ�ĵ�ǰ�������ͻ���
	GraphKind kind;                    // ͼ�������־
} MGraph;


// ͼ���ڽӱ�洢��ʾ
typedef struct ArcNode {
	int adj_vex;         // �û���ָ��Ķ����λ��
	ArcNode *next_arc;   // ָ����һ������ָ��
	InfoType *info;      // �û������Ϣ��ָ��
} ArcNode;

typedef struct VNode {
	VertexType data;      // ������Ϣ
	ArcNode *first_arc;   // ָ���һ�������ö���Ļ���ָ��
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct ALGraph {
	AdjList vertices;
	int vex_num, arc_num;   // ͼ�ĵ�ǰ�������ͻ���
	int kind;               // ͼ�������־
} ALGraph;


// ����ͼ��ʮ������洢��ʾ
typedef struct ArcBox {
	int tail_vex, head_vex;   // �ֱ�Ϊ����β��ͷ�Ķ����λ��
	ArcBox *hlink, *tlink;    // �ֱ�Ϊ��ͷ��ͬ�ͻ�β��ͬ�Ļ�������
	InfoType *info;           // �������Ϣ��ָ��
} ArcBox;

typedef struct VexNode {
	VertexType data;
	ArcBox *firstin, * firstout;    // �ֱ�ָ��ö����һ���뻡�ͳ���
} VexNode;

typedef struct OLGraph {
	VexNode xlist[MAX_VERTEX_NUM];   // ��ͷ����
	int vex_num, arc_num;            // ����ͼ�ĵ�ǰ�������ͻ���
} OLGraph;


// ����ͼ���ڽӶ��ر�洢��ʾ
typedef enum VisitIF { unvisited, visited } VisitIF;

typedef struct EBox {
	VisitIF mark;          // ���ʱ��
	int ivex, jvex;        // �ñ����������������λ��
	EBox *ilink, *jlink;   // �ֱ�ָ�������������������һ����
	InfoType *info;        // �ñ���Ϣָ��
} EBox;

typedef struct VexBox {
	VertexType data;
	EBox *first_edge;   // ָ���һ�������ö���ı�
} VexBox;

typedef struct {
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vex_num, arc_num;   // ����ͼ�ĵ�ǰ�������ͱ���
} AMLGraph;


// �㷨7.1
Status CreateGraph(MGraph mg);

// �㷨7.2
Status CreateUDN(MGraph mg);

// �㷨7.3
Status CreateDG(OLGraph olg);

// �㷨7.4
Status visited[];             // ���ʱ�־����
Status (*VisitFunc)(int v);   // ��������
void DFSTraverse(MGraph mg, Status (*Visit)(int v));

// �㷨7.5
void DFS(MGraph mg, int v);

// �㷨7.6
void BFSTraverse(MGraph mg, Status (*Visit)(int v));

// �㷨7.7
void DFSForest(MGraph mg, CSTree cst);

// �㷨7.8
void DFSTree(MGraph mg, int v, CSTree cst);

// �㷨7.9
void MST_PRIM(MGraph, VertexType vt);

// �㷨7.10
void FindArticul(ALGraph alg);

// �㷨7.11
void DFSArticul(ALGraph alg, int v0);

// �㷨7.12
Status ToplogicalSort(ALGraph alg);

// �㷨7.13
Status TopologicalOrder(ALGraph alg, Stack stack);

// �㷨7.14
Status CriticalPath(ALGraph alg);

// �㷨7.15
void ShortestPath_Dijkstra(MGraph mg, PathMatrix pm, ShortPath spt);

// �㷨7.16
void ShortestPath_Floyd(MGraph mg, PathMatrix pm, DistanceMatrix dm);
