/*
 * example_06_07.cpp
 *
 *  Created on: 2016Äê5ÔÂ23ÈÕ
 *      Author: sunix_prog
 */


#include "example_06.h"

template<typename T>
void chain<T>::erase(int theIndex)
{
	checkIndex(theIndex);

	chain<T>* deleteNode;
	if (theIndex == 0) {
		deleteNode = firstNode;
		firstNode = firstNode->next;
	} else {
		int index = 0;
		chain<T>* currentNode = firstNode;
		while (index != theIndex - 1) {
			currentNode = currentNode->next;
			index++;
		}
		deleteNode = currentNode->next;
		currentNode->next = current->next->next;
	}
	listSize--;

	delete deleteNode;
}
