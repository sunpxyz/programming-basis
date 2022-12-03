/*
 * List.h
 *
 *  Created on: 2016Äê5ÔÂ31ÈÕ
 *      Author: sunix_prog
 */

#ifndef SOURCE_CH3_LIST_STACK_QUEUE_LIST_H_
#define SOURCE_CH3_LIST_STACK_QUEUE_LIST_H_

/*************************************
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
*************************************/


#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
	T element;   // Element contained in the node.
	Node* next;  // Pointer to the next node.

	Node() { next = NULL; }
	Node(T element) { this->element = element; next = NULL; }
};


template<typename T>
class List
{
public:
	List();
	void addFirst(T element);
	void addLast(T element);
	T getFirst();
	T getLast();
	T removeFirst();
	T removeLast();
	void add(T element);
	void add(int index, T element);
	void clear();
	bool contain(T element);
	T get(int index);
	int indexOf(T element);
	bool isEmpty();
	int lastIndexOf(T element);
	void remove(T element);
	int getSize();
	T removeAt(int index);
	T set(int index, T element);

private:
	Node<T>* head;
	Node<T>* tail;
	int size;
};


#endif /* SOURCE_CH3_LIST_STACK_QUEUE_LIST_H_ */
