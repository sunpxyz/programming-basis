// ���ݽṹ��C����������.��ε��
// ��7��.ͼ
// graph.h
// 2016.09.26


#include "../Graph/graph.h"


// �㷨7.1
Status CreateGraph(MGraph mg) {
	// �������飨�ڽӾ��󣩱�ʾ��������ͼmg
	scanf(&mg.kind);
	switch(mg.kind) {
		case DG: return CreateDG(mg);
		case DN: return CreateDN(mg);
		case UDG: return CreateUDG(mg);
		case UDN: return CreateUDN(mg);
	}
}


// �㷨7.2
Status CreateUDN(MGraph mg) {
	// �������飨�ڽӾ��󣩱�ʾ��������������mg
	char *IncInfo;
	scanf(&mg.vex_num, &mg.arc_num, &IncInfo);   // IncInfoΪ0���������������Ϣ
	// ���춥������
	for (int i = 0; i < mg.vex_num; ++i) { scanf(&mg.vex_num); }
	// ��ʼ���ڽӾ���
	for (int i = 0; i < mg.vex_num; ++i) {
		for (int j = 0; j < mg.vex_num; ++j) {
			mg.arcs[i][j].adj = INFINITY;
			mg.arcs[i][j].info = NULL;
		}
	}
	// �����ڽӾ���
	for (int k = 0; k < mg.arc_num; ++k) {
		VRType v1, v2;   // ����
		int w;           // Ȩֵ
		scanf(&v1, &v2, &w);
		// ȷ��v1��v2��ͼmg�е�λ��
		int i = LocateVex(mg, v1);
		int j = LocateVex(mg, v2);
		mg.arcs[i][j].adj = w;
		// �������������Ϣ��������
		if (IncInfo) {
			Input(*mg.arcs[i][j].info);
			mg.arcs[j][i] = mg.arcs[i][j];
		}
	}
	return TRUE;
}


// �㷨7.3
Status CreateDG(OLGraph olg) {
	// ����ʮ������洢��ʾ����������ͼolg
	char *IncInfo;   // IncInfoΪ0���������������Ϣ
	scanf(&olg.vex_num, &olg.arc_num, &IncInfo);
	for (int i = 0; i < olg.vex_num; ++i) {   // �����ͷ����
		scanf(&olg.xlist[i].data);
		olg.xlist[i].firstin = NULL;
		olg.xlist[i].firstout = NULL;
	}
	for (int k = 0; k < olg.arc_num; ++k) {   // �������������ʮ������
		ArcBox v1, v2;
		scanf(&v1, &v2);
		int i = LocateVex(olg, v1);
		int j = LocateVex(olg, v2);
		ArcBox *p = (ArcBox *)malloc(sizeof(ArcBox));
		*p->tail_vex = i;
		*p->head_vex = j;
		*p->hlink = olg.xlist[j].firstin;
		*p->tlink = olg.xlist[i].firstout;
		*p->info = NULL;
		olg.xlist[j].firstin = olg.xlist[i].firstout = p;
		if (IncInfo) { Input(*p->info); }
	}
}


// �㷨7.4
void DFSTraverse(MGraph mg, Status (*Visit)(int v)) {
	// ��ͼmg��������ȱ���
	VisitFunc = Visit;   // ʹ��ȫ�ֱ���VisitFunc��ʹDFS�����躯��ָ�����
	for (int v = 0; v < mg.vex_num; ++v) {
		visited[v] = FALSE;
	}
	for (int v = 0; v < mg.vex_num; ++v) {
		if (!visited[v]) {
			DFS(mg, v);
		}
	}
}


// �㷨7.5
void DFS(MGraph mg, int v) {
	// �ӵ�v����������ݹ��������ȱ���ͼmg
	visited[v] = TRUE;
	VisitFunc(v);
	for (int w = FirstAdjVex(mg, v); w >= 0;
			 w = NextAdjVex(mg, v, w)) {
		if (!visited[w]) {   // ��v����δ���ʵ��ڽӶ���w�ݹ����DFS
			DFS(mg, w);
		}
	}
}


// �㷨7.6
void BFSTraverse(MGraph mg, Status (*Visit)(int v)) {
	// ��������ȷǵݹ����ͼmg��ʹ�ø�������q�ͷ��ʱ�־����visited��
	for (int v = 0; v < mg.vex_num; ++v) {
		visited[v] = FALSE;
	}
	InitQueue(queue);
	for (int v = 0; v < mg.vex_num; ++v) {
		if (!visited[v]) {
			visited[v] = TRUE;
			Visit(v);
			EnQueue(queue, v);
			while (!QueueEmpty(queue)) {
				DeQueue(queue, u);   // ����ͷԪ�س��Ӳ���Ϊu
				for (int w = FirstAdjVex(mg, u); w >= 0;
						 w = NextAdjVex(mg, u, w)) {
					if (!visited[w]) {   // wΪu����δ���ʵ��ڽӶ���
						visited[w] = TRUE;
						Visit(w);
						EnQueue(queue, w);
					}   // if
				}   // for
			}   // while
		}   // if
	}   // for
}


// �㷨7.7
void DFSForest(MGraph mg, CSTree t) {
	// ��������ͼmg�������������ɭ�ֵģ����󣩺��ӣ��ң��ֵ�����t
	t = NULL;
	for (int v = 0; v < mg.vex_num; ++v) {
		visited[v] = FALSE;
	}
	for (int v = 0; v < mg.vex_num; ++v) {
		if (!visited[v]) {   // ��v����Ϊ�µ��������ĸ����
			CSTree *qcst;
			CSTree *pcst = (CSTree)malloc(sizeof(CSNode));
			*pcst->data = GetVex(mg, v);
			*pcst->first_child = NULL;
			*pcst->next_sibling = NULL;
			if (!t) {
				t = pcst;
			} else {
				qcst->next_sibling = pcst;
			}
			qcst = pcst;
			DFSTree(mg, v, pcst);
		}   // if
	}   // for
}


// �㷨7.8
void DFSTree(MGraph mg, int v, CSTree cst) {
	// �ӵ�v���������������ȱ���ͼmg��������cstΪ����������
	visited[v] = TRUE;
	Status first = TRUE;
	for ( int w = FirstAdjVex(mg, v); w >= 0; w = NextAdjVex(mg, v, w)) {
		if (!visited[w]) {
			CSTree *qcst;
			CSTree *pcst = (CSTree)malloc(sizeof(CSNode));
			*pcst->data = GetVex(mg, v);
			*pcst->first_child = NULL;
			*pcst->next_sibling = NULL;
			if (first) {
				cst->first_child = pcst;
				cst->next_sibling = FALSE;
			} else {
				qcst->next_sibling = pcst;
			}
			qcst = pcst;
			DFSTree(mg, w, qcst);
		}   // if
	}   // for
}


// �㷨7.9
void MST_PRIM(MGraph mg, VertexType u) {
	// ������ķ�㷨�ӵ�u���������������mg����С������mst�����mst�ĸ�����
	// ��¼�Ӷ��㼯U��V-U�Ĵ�����С�ıߵĸ������鶨��
	struct {
		VertexType adjvex;
		VRType lowcost;
	} closedge[MAX_VERTEX_NUM];
	int k = LocateVex(mg, u);
	for (int j = 0; j < mg.vex_num; ++j) {
		if (j != k) {
			closedge[j].adjvex = u;
			closedge[j].lowcost = mg.arcs[k][j].adj;
		}
	}
	closedge[k].lowcost = 0;
	// ѡ������mg.vex_num������
	for (int i = 1; i < mg.vex_num; ++i) {
		k = minimum(closedge);   // ���mst����һ����㣺��k����
		printf(closedge[k].adjvex, mg.vexs[k]);   //����������ı�
		closedge[k].lowcost = 0;   // ��k���㲢��U��
		// �¶��㲢��U������ѡ����С��
		for (int j = 0; j < mg.vex_num; ++j) {
			if (mg.arcs[k][j].adj < closedge[j].lowcost) {
				closedge[j].adjvex = mg.vexs[k];
				closedge[j].lowcost = mg.arcs[k][j].adj;
			}   // if
		}   // for
	}   // for
}


// �㷨7.10
void FindArticul(ALGraph alg) {
	// ��ͨͼalg���ڽӱ����洢�ṹ�����Ҳ����alg��ȫ���ؽڵ�
	// ȫ����count�Է��ʼ���
	int count = 1;
	visited[0] = 1;   // �趨�ڽӱ���0�Ŷ���Ϊ�������ĸ�
	for (int i = 1; i < alg.vex_num; ++i) {
		visited[i] = 0;
	}
	ArcNode *p = alg.vertices[0].first_arc;
	int v = p->adj_vex;
	DFSArticul(alg, v);   // �ӵ�v�������������Ȳ��ҹؽڵ�
	if (count < alg.vex_num) {
		printf(0, alg.vertices[0].data);
		while (p->next_arc) {
			p = p->next_arc;
			v = p->adj_vex;
			if (visited[v] == 0) {
				DFSArticul(alg, v);
			}   // if
		}   // while
	}   // if
}


// �㷨7.11
void DFSArticul(ALGraph alg, int v0) {
	// �ӵ�v0���������������ȱ���ͼalg�����Ҳ�����ؽڵ�
	visited[v0] = min = ++count;
	ArcNode *p = alg.vertices[v0].first_arc;
	for (; p; p = p->next_arc) {
		int w = p->adj_vex;
		if (visited[w] == 0) {
			DFSArticul(alg, w);
			if (low[w] < min) { min = low[w]; }
			if (low[w] >= visited[v0]) { printf(v0, alg.vertices[v0].data); }
		} else if (visited[w] < min) {
			min = visited[w];
		}
	}
	low[v0] = min;
}


// �㷨7.12
Status ToplogicalSort(ALGraph alg) {
	// ����ͼalg�����ڽӱ�洢�ṹ
	// ��alg�޻�·�������alg�Ķ����һ���������в�����OK�����򷵻�ERROR
	Stack stack;
	int indegree[alg.vex_num];
	FindInDegree(alg, indegree);   // �Ը����������indgree[0..alg.vex_num-1]
	InitStack(stack);
	for (int i = 0; i < alg.vex_num; ++i) {
		if (!indegree[i]) {
			push(stack, i);
		}
	}
	int i = 0;
	int count = 0;
	while (!StackEmpty(stack)) {
		pop(stack, i);
		printf(i, alg.vertices[i].data);
		count++;
		for (ArcNode* p = alg.vertices[i].first_arc; p; p = p->next_arc) {
			int k = p->adj_vex;   // �Զ���i��ÿ���ڽӵ����ȼ�1
			if (!(--indegree[k])) {
				push(stack, k);
			} // if
		} // for
	} // while
	if (count < alg.vex_num) {
		return ERROR;
	} else {
		return OK;
	}
}


// �㷨7.13
Status TopologicalOrder(ALGraph alg, Stack t) {
	// ������alg�����ڽӱ�洢�ṹ����������¼������緢��ʱ��ve
	// tΪ�������ж���ջ�� sΪ����ȶ���ջ
	// ��alg�޻�·����ջt����alg��һ���������У��Һ���ֵΪOK������ΪERROR
	int ve[alg.vex_num];
	int indegree[alg.vex_num];
	Stack s, t;
	FindInDegree(alg, indegree);
	InitStack(t);
	int count = 0;
	for (int i = 0; i < alg.vex_num; ++i) {
		ve[i] = 0;
	}
	while (!StackEmpty(s)) {
		int j;
		pop(s, j);
		push(t, j);
		++count;
		for (ArcNode* p = alg.vertices[j].first_arc; p; p = p->next_arc) {
			int k = p->adj_vex;
			if (--indegree[k] == 0) {
				push(s, k);
			} // if
			if (ve[j] + *(p->info) > ve[k]) {
				ve[k] = ve[j] + *(p->info);
			} // if
		} // for
	} // while
	if (count < alg.vex_num) {
		return ERROR;
	} else {
		return OK;
	}
}


// �㷨7.14
Status CriticalPath(ALGraph alg) {
	// algΪ�����������alg�ĸ���ؼ��
	if (!TopologicalOrder(alg, t)) return ERROR;
	int vl[alg.vex_num];
	for (int i = 0; i < alg.vex_num; ++i) {
		vl[i] = ve[i];
	}
	while (!StackEmpty(t)) {
		pop(t, j);
		ArcNode* p = alg.vertices[j].first_arc;
		for (; p; p = p->next_arc) {
			int k = p->adj_vex;
			int dut = *(p->info);
			if (vl[k] - dut < vl[j]) {
				vl[j] = vl[k] - dut;
			} // if
		} // for
	} // while
	for(int j = 0; j < alg.vex_num; ++j) {
		ArcNode* p = alg.vertices[j].first_arc;
		for (; p; p->next_arc) {
			int k = p->adj_vex;
			int dut = *(p->info);
			int ee = ve[j];
			int el = vl[k] - dut;
			char tag = (ee == el) ? '*' : '';
			printf(j, k, dut, ee, el, tag);   // ����ؼ�·��
		} // for
	} // for
}


// �㷨7.15
void ShortestPath_Dijkstra(MGraph mg, PathMatrix pm, ShortPathTable spt) {
	// ��Dijkstra�㷨��������mg��v0���㵽���ඥ��v�����·��pm[v]�����Ȩ����spt[v]
	// ��pm[v][w]ΪTRUE����w�Ǵ�v0��v��ǰ������·���ϵĶ��㡣
	// final[v]ΪTRUE���ҽ���v����S�����Ѿ���ô�v0��v�����·����
	for (int v = 0; v < mg.vex_num; ++v) {
		final[v] = FALSE;
		spt[v] = mg.arcs[v0][v];
		for (int w = 0; w < mg.vex_num; ++w) {
			pm[v][w] = FALSE;
		}
		if (spt[v] < INFINITY) {
			pm[v][v0] = TRUE;
			pm[v][v] = TRUE;
		}
	}
	// ��ʼ����v0��������S����
	spt[v0] = 0;
	final[v0] = TRUE;
	// ��ʼ��ѭ����ÿ�����v0��ĳ��v��������·��������v��S��
	for (int i = 1; i < mg.vex_num; ++i) {
		int min = INFINITY;
		for (int w = 0; w < mg.vex_num; ++i) {
			if (!final[w]) {          // w������V-S��
				if (spt[w] < min) {   // w������v0�������
					int v = w;
					min = spt[w];
				} // if
			} // if
		} // for
		final[v] = TRUE;   // �붥�������v����S��
		for (int w = 0; w < mg.vex_num; ++w) {   // ���µ�ǰ���·��������
			if (!final[w] && (min + mg.arcs[v][w] < spt[w])) {   // �޸�spt[w]��pm[w]
				spt[w] = min + mg.arcs[v][w];
				pm[w] = pm[v];
				pm[w][w] = TRUE;
			} // if
		} // for
	} // for
}


// �㷨7.16
void ShortestPath_Floyd(MGraph mg, PathMatrix pm, DistanceMatrix dm) {
	// ��Floyd�㷨��������mg�и��Զ���v��w֮�����̵�·��pm[v][w]�����Ȩ����dm[v][w]��
	// ��pm[v][w][u]ΪTRUE�����u�Ǵ�v��w��ǰ������·���ϵĶ��㡣
	for (int v = 0; v < mg.vex_num; ++v) {   // ���Խ��֮�������֪·��������
		for (int w = 0; w < mg.vex_num; ++w) {
			dm[v][w] = mg.arcs[v][w];
			for (int u = 0; u < mg.vex_num; ++u) {
				pm[v][w][u] = FALSE;
			}
			if (dm[v][w] < INFINITY) {
				pm[v][w][v] = TRUE;
				pm[v][w][w] = TRUE;
			} // if
		} // for
	} // for
	for (int u = 0; u < mg.vex_num; ++u) {
		for (int v = 0; u < mg.vex_num; ++v) {
			for (int w = 0; u < mg.vex_num; ++w) {
				if (dm[v][u] + dm[u][w] < dm[v][w]) {
					dm[v][w] = dm[v][u] + dm[u][w];
					for (int i = 0; i < mg.vex_num; ++i) {
						pm[v][w][i] = pm[v][u][i] || pm[u][w][i];
					} // for
				} // if
			} // for
		} // for
	} // for
}
