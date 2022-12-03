/*
 * example_05_07.cpp
 *
 *  Created on: 2016Äê5ÔÂ11ÈÕ
 *      Author: sunix_prog
 */


#include "example_05.h"


template<typename T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex > 0 || theIndex > listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}

	if (listSize == arrayLength)
	{
		changeLength1D(element, arrayLength, 2 * arrayLength);

		arraylength *= 2;
	}

	copy_backward(element + theIndex, element + listSize, element + listSize + 1);

	element[theIndex] = theElement;
	listSize++;
}
