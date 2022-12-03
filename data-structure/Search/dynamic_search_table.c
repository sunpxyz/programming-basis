// ���ݽṹ��C����������.��ε��
// ��9��.����/9.2.��̬���ұ�
// dynamic_search_table.c
// 2016.10.18


#include "../Search/search.h"


// �㷨9.05(a)
BiTree SearchBST(BiTree bt, KeyType key) {
	if (!bt || EQ(key, bt->data.key)) {
		return bt;
	} else if (LT(key, bt->data.key)){
		return SearchBST(bt->lchild, key);
	} else {
		return SearchBST(bt->rchild, key);
	}
}


// �㷨9.05(b)
Status SearchBST(BiTree bt, KeyType key, BiTree f, BiTree p) {
	// ��ָ��bt��ָ�����������еݹ�ز�����ؼ��ֵ���key������Ԫ�أ�
	// �����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE��
	// ����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����FALSE
	// ָ��fָ��bt��˫�ף����ʼֵΪNULL
	if (!bt) {
		p = f;
		return FALSE;
	} else if (EQ(key, bt->data.key)) {
		p = bt;
		return TRUE;
	} else if (LT(key, bt->data.key)) {
		return SearchBST(bt->lchild, key, bt, p);
	} else {
		return SearchBST(bt->rchild, key, bt, p);
	}
}


// �㷨9.06
Status InsertBST(BiTree bt, ElemType e) {
	// ������������bt�в����ڹؼ��ֵ���e.key������Ԫ��ʱ��
	// ����e������TRUE�����򷵻�FALSE
	BiTree p;
	if (!SearchBST(bt, e.key, NULL, p)) {
		BiTree s = (BiTree)malloc(Sizeof(BiTNode));
		s->data = e;
		s->lchild = s->rchild = NULL;
		if (!p) {
			bt = s;
		} else if (LT(e.key, p->data.key)) {
			p->lchild = s;
		} else {
			p->rchild = s;
		}
		return TRUE;
	} else {
		return FALSE;
	}
}


// �㷨9.07
Status DeleteBST(BiTree bt, KeyType key) {
	if (!bt) {
		return FALSE;
	} else if (EQ(key, bt->data.key)) {
		return Delete(bt);
	} else if (LT(key, bt->data.key)) {
		return DeleteBST(bt->lchild, key);
	} else {
		return DeleteBST(bt->rchild, key);
	}
}


// �㷨9.08
Status Delete(BiTree bt) {
	// �Ӷ�����������ɾ�����bt������������������������
	if (!bt->rchild) {   // ����������ֻ���ؽ�����������
		BiTree q = bt;
		bt = bt->lchild;
		free(q);
	} else if (!bt->lchild) {   // ����������ֻ���ؽ�����������
		BiTree q = bt;
		bt = bt->rchild;
		free(q);
	} else {   // ������������Ϊ��
		BiTree q = bt;
		BiTree s = bt->lchild;
		while (s->rchild) {   // ת��Ȼ�����ҵ���ͷ
			q = s;
			s = s->rchild;
		}
		bt->data = s->data;   // sָ��ɾ����ǰ��
		if (q != bt) {
			q->rchild = s->lchild;   // �ؽ�*q��������
		} else {
			q->lchild = s->lchild;   // �ؽ�*q��������
		}
		free(s);
	}
	return TRUE;
}


// �㷨9.09
void R_Rotate(BSTree bst) {
	// ����*bstΪ���Ķ�����������������������֮��bstָ���µĸ���㣬
	// ����ת����֮ǰ���������ĸ����
	BSTNode *lc = bst->lchild;   // lcָ���*bst�������������
	bst->lchild = lc->rchild;    // lc���������ҽ�*bst��������
	lc->rchild = bst;            // *bst�ҽӵ�lc����������
	bst = lc;                    // bstָ���µĸ����
}


// �㷨9.10
void L_Rotate(BSTree bst) {
	// ����*bstΪ���Ķ�����������������������֮��bstָ���µĸ���㣬
	// ����ת����֮ǰ���������ĸ����
	BSTNode *lc = bst->rchild;   // lcָ���*bst�������������
	bst->rchild = lc->lchild;    // lc���������ҽ�*bst��������
	lc->lchild = bst;            // *bst�ҽӵ�lc����������
	bst = lc;                    // bstָ���µĸ����
}


// �㷨9.11
typedef enum {
	LH = 1,   // ���
    EH = 0,    // �ȸ�
    RH = -1    // �Ҹ�
} HIGHLEVEL;

Status InsertAVL(BSTree bst, ElemType e, Status taller) {
	// ����ƽ��Ķ�����bst�в����ں�e����ͬ�ؼ��ֵĽ�㣬
	// �����һ������Ԫ��Ϊe���½�㣬������1�����򷵻�0��
	// ��������ʹ����������ʧȥƽ�⣬����ƽ����ת����
	// ��������taller��ӳbst�������
	if (!bst) {
		bst = (BSTree)malloc(sizeof(BSTNode));
		bst->data = e;
		bst->lchild = bst->rchild = NULL;
		bst->bf = EH;
		taller = TRUE;
	} else {
		if (EQ(e.key, bst->data.key)) {
			taller = FALSE;
			return 0;
		} else if (LT(e.key, bst->data.key)) {   // ��*bst���������н�������
			if (!InsertAVL(bst->lchild, e, taller)) {
				return 0;
			}
			if (taller) {   // �Ѳ���*bst����������������������
				switch(bst->bf) {   // ���*bst��ƽ���
					case LH:
						LeftBalance(bst); taller = FALSE; break;
					case EH:
						bst->bf = LH; taller = TRUE; break;
					case RH:
						RightBalance(bst); taller = FALSE; break;
				}
			} // if
		} else {
			if (!InsertAVL(bst->rchild, e, taller)) {
				return 0;
			}
			if (taller) {   // �Ѳ���*bst����������������������
				switch(bst->bf) {   // ���*bst��ƽ���
					case LH:
						bst->bf = LH; taller = FALSE; break;
					case EH:
						bst->bf = RH; taller = TRUE; break;
					case RH:
						RightBalance(bst); taller = FALSE; break;
				}
			} // if
		} // else
	}
	return TRUE;
}


// �㷨9.12
void LeftBalance(BSTree bst) {
	// ����ָ��bst��ָ���Ϊ���Ķ���������ƽ����ת��������ʱbstָ���µĸ����
	BSTNode *lc = bst->lchild;
	switch (lc->bf) {   // ���*bst����������ƽ��ȣ�������Ӧƽ�⴦��
		case LH:	   // �½�������*bst�����ӵ��������ϣ�Ҫ������������
			bst->bf = lc->bf = EH;
			R_Rotate(bst); break;
		case RH:       // �½�������*bst�����������������ϣ�Ҫ��˫������
			BSTNode *rd = lc->rchild;
			switch (rd->bf) {   // �޸�*bst�������ӵ�ƽ������
				case LH:
					bst->bf = RH; lc->bf = EH; break;
				case EH:
					bst->bf = lc->bf = EH; break;
				case RH:
					bst->bf = EH; lc->bf = LH; break;
			}
			rd->bf = EH;
			L_Rotate(bst->lchild);
			R_Rotate(bst);
	}
}


// �㷨9.13
Result SearchBTree(BTree bt, KeyType key) {

}



// �㷨9.14

// �㷨9.15

// �㷨9.16
