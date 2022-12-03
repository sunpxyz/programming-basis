/*
 * example_06_12.cpp
 *
 *  Created on: 2016Äê5ÔÂ24ÈÕ
 *      Author: sunix_prog
 */


#include "example_06.h"

template<typename T>
void extendedChain<T>::clear()
{
	while (firstNode != null) {
		chainNode<T>* nextNode = firstNode->next;
		delete fistNode;
		nextNode = nextNode->next;
	}
	listSize = 0;
}

template<typename T>
void extendedChain<T>::push_back(const T& theElement)
{
	chainNode<T>* newNode = new chainNode<T>(theElement);
	if (firstNode == null)
		firstNode = lastNode = newNode;
	else {
		lastNode->next = newNode;
		lastNode = newNode;
	}
	listSize++;
}
