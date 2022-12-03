/*
 * example_06_13.cpp
 *
 *  Created on: 2016Äê5ÔÂ25ÈÕ
 *      Author: sunix_prog
 */


#include "example_06.h"

template<typename T>
circularListWithHeader<T>::circularListWithHeader()
{
	headerNode = new chainNode<T>();
	headerNode->next = headerNode;
	listSize = 0;
}


template<typename T>
int circularListWithHeader<T>::indexOf(const T& theElement) const
{
	header->element = theElement;

	chainNode<T>* currentNode = header->next;
	int index = 0;
	while (currenNode->element != theElement) {
		currentNode = currentNode->next;
		index++;
	}

	if (currentNode == headerNode)
		return -1;
	else
		return index;
}
