/*
 * example_06_04.cpp
 *
 *  Created on: 2016Äê5ÔÂ18ÈÕ
 *      Author: sunix_prog
 */


#include "example_06.h"

template<typename T>
chain<T>::~chain()
{
	while (firstNode != NULL)
	{
		chainNode<T>* nextNode = fistNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}
