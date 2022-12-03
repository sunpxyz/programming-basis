/*
 * ch_09_graph_theory_algorithm/kruskal.c
 *
 * 2019/3/20
 */


void Kruskal(Graph G)
{
	int EdgesAccepted;
	DisjSet S;
	PriorityQueue H;
	Vertex U, V;
	SetType Uset, Vset;
	Edge E;

	Initialize(S);
	ReadGraphIntoHeapArray(G, H);
	BuildHeap(H);

	EdgesAccepted = 0;
	while (EdgesAccepted < NumVertex - 1) {
		E = DeleteMin(H);
		Uset = Find(U, S);
		Vset = Find(V, S);
		if (Uset != Vset) {
			EdgesAccepted++;
			SetUion(S, USet, VSet);
		}
	}
}
