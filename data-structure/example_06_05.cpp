/*
 * example_06_05.cpp
 *
 *  Created on: 2016Äê5ÔÂ23ÈÕ
 *      Author: sunix_prog
 */


#include "example_06.h"

template<typename T>
T& chain<T>::get(int theIndex) const
{
	checkIndex(theIndex);

	chainNode<T>* currentNode = firstNode;
	for (int i = 0; i < theIndex; i++)
	{
		currentNode = currentNode->next;
	}

	return currentNode->element;
}
