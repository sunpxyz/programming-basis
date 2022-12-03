/*
 * example_06_08.cpp
 *
 *  Created on: 2016Äê5ÔÂ24ÈÕ
 *      Author: sunix_prog
 */


#include "example_06.h"

template<typename T>
void chain<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex < 0 || theIndex > listSize) {
		ostringstream s;
		s << "index = " << theIndex << "size = " << listSize;
		throw illegalIndex(s.str());
	}

	if (theIndex == 0)
		firstNode = new chainNode<T>(theElement, firstNode);
	else {
		chainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; i++) {
			p = p->next;
		}
		p->next = new chainNode<T>(theElement, p->next);
	}
	listSize++;
}
