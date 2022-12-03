/*
 * example_06_06.cpp
 *
 *  Created on: 2016Äê5ÔÂ23ÈÕ
 *      Author: sunix_prog
 */


#include "example_06.h"

template<typename T>
int chain<T>::indexOf(const T& theElement) const
{
	chain<T>* currentNode = firstNode;
	int index = 0;

	while(currentNode != NULL &&
		  currentNode->element != theElement)
	{
		currentNode = currentNode->next;
		index++;
	}

	if (currentNode == NULL)
		return -1;
	else
		return index;
}
