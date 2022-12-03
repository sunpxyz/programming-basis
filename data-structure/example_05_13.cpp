/*
 * example_05_13.cpp
 *
 *  Created on: 2016Äê5ÔÂ16ÈÕ
 *      Author: sunix_prog
 */


#include "example_05.h"


template<typename T>
vectorList<T>::vectorList(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << "Initial capacity = " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}

	element = new vector<T>;

	element->reverse(initialCapacity);
}

template<typename T>
vectorList<T>::vectorList(const vectorList<T>& theList)
{
	element = new vector<T>(*theList.element);
}
