// ���ݽṹ��C����������.��ε��
// ��2��.���Ա�
// polynomial.h


// ***************
// ADT: Polynomial
// ***************

// ��ı�ʾ������ʽ������ΪLinkList������Ԫ��
typedef struct {
	float coef;     // ϵ��
	int expn;       // ָ��
} Term, ElemType;   // Term���ڱ�ADT, ElemTypeΪLinkList�����ݶ�����

// �ô���ͷ�������������ʾ����ʽ
#include "../ch02_list/list.h"
typedef LinkList Polynomial;

// ���������ĺ���ԭ��˵��
void CreatPolyn(Polynomial p, int m);
void DestroyPplyn(Polynomial p);
void PrintPolyn(Polynomial p);
int PolynLength(Polynomial p);
void AddPolyn(Polynomial p1, Polynomial p2);
void SutractPolyn(Polynomial p1, Polynomial p2);
void MultiplyPolyn(Polynomial p1, Polynomial p2);
int Cmp(Term ta, Term tb);
