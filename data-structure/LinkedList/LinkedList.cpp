// LinkedList/
// LinkedList.cpp
// 2019.09.20

#include "LinkedList.h"
#include <iostream>


// ׷�ӽڵ�
void appendNode(ListNode **pHead, int value)
{
	ListNode *pNew = new ListNode();
	pNew->value = value;
	pNew->pNext = NULL;

	if (*pHead == NULL) {
		*pHead = pNew;
	} else {
		ListNode *pNode = *pHead;
		while (pNode->pNext != NULL) {
			pNode = pNode->pNext;
		}
		pNode->pNext = pNew;
	}
}


// ɾ����һ������ָ��ֵ�Ľڵ�
void removeNode(ListNode **pHead, int value)
{
	// ������
	if (pHead == NULL || *pHead == NULL) {
		return;
	}

	ListNode *pDeletedNode = NULL;
	if ((*pHead)->value == value) {  // �����ɾ���ڵ��������ײ�
		pDeletedNode = *pHead;
		*pHead = (*pHead)->pNext;
	} else {
		ListNode *pNode = *pHead;
		while (pNode->pNext != NULL && pNode->pNext->value != value) {  // �ҵ���ɾ���ڵ�ǰһ���ڵ�
			pNode = pNode->value;
		}

		if (pNode->pNext != NULL && pNode->pNext->value == value) {  // �����ɾ���ڵ㲻��β��
			pDeletedNode = pNode->pNext;
			pNode->pNext = pNode->pNext->pNext;
		}
	}

	if (pDeletedNode != NULL) {  // ������ɾ���ڵ�������β�������������ֱ��ɾ��
		delete pDeletedNode;
		pDeletedNode = NULL;
	}
}
