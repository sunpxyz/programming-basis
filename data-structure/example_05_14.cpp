/*
 * example_05_14.cpp
 *
 *  Created on: 2016Äê5ÔÂ16ÈÕ
 *      Author: sunix_prog
 */


#include "example_05.h"


template<typename T>
void vectorList<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	element->erase(begin() + theIndex);
}

template<typename T>
void vectorList<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex < 0 || theIndex > size())
	{
		ostreamstream s;
		s << "index = " << theIndex << " size = " << size();
		throw illegalIndex(s.str());
	}

	element->insert(element->begin() + theIndex, theElement);
}
