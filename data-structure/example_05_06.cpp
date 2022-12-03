/*
 * example_05_06.cpp
 *
 *  Created on: 2016Äê5ÔÂ11ÈÕ
 *      Author: sunix_prog
 */


#include "example_05.h"


template<typename T>
void arrayList<T>::erase(int theIndex)
{
	checkIndex(theIndex);

	copy(element + theIndex + 1, element + listSize, element + theIndex);

	element[--list].~T();
}
