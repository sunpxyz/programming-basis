/*
 * example_06_03.cpp
 *
 *  Created on: 2016Äê5ÔÂ18ÈÕ
 *      Author: sunix_prog
 */


#include "example_06.h"


template<typename T>
chain<T>::chain(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		ostrinstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}

	firstNode = NULL;
	listSize = 0;
}


template<typename T>
chain<T>::chain(const chain<T>& theList)
{
	listSize = theList.listSize;

	if (listSize == 0)
	{
		firstNode = NULL;
		return;
	}

	chainNode<T>* sourceNode = theList.firstNode;
	firstNode = new chainNode<T>(sourceNode->element);
	sourceNode = sourceNode->next;
	chainNode<T>* targetNode = firstNode;

	while (sourceNode != NULL)
	{
		targetNode->next = new chainNode<T>(sourceNode->element);
		targetNode = targetNode->next;
		sourceNode = sourceNode->next;
	}
	targetNode->next = NULL;
}

