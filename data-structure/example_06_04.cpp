/*
 * example_06_04.cpp
 *
 *  Created on: 2016��5��18��
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
