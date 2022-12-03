/*
 * example_06_09.cpp
 *
 *  Created on: 2016Äê5ÔÂ24ÈÕ
 *      Author: sunix_prog
 */


#include "example_06.h"

template<typename T>
void chain<T>::output(ostream& out) const
{
	for (chainNode<T>* currentNode = firstNode;
			           currentNode != null;
			           currentNode = currentNode->next) {
		out << current->element << " ";
	}
}

template<typename T>
ostream& operator<<(ostream& out, const chain<T>& x)
{
	x.output(out);
	return out;
}
