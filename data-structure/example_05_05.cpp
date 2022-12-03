/*
 * example_05_05.cpp
 *
 *  Created on: 2016Äê5ÔÂ11ÈÕ
 *      Author: sunix_prog
 */


#include "example_05.h"


template<typename T>
void arrayList<T>::checkIndex(int theIndex) const
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		ostringstream s;
		s << "index = " << theIndex << " size = " <<  listSize;
		throw illegalIndex(s.str());
	}
}


template<typename T>
T& arrayList<T>::get(int theIndex) const
{
	checkIndex(theIndex);
	return element[theIndex];
}


template<typename T>
int arrayList<T>::indexOf(const T& theElement) const
{
	int theIndex = (int) (find(element, element + listSize, theElement) - element);

	if (theIndex == listSize)
		return -1;
	else
		return theIndex;
}
