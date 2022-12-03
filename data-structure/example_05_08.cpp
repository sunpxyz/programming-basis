/*
 * example_05_08.cpp
 *
 *  Created on: 2016Äê5ÔÂ11ÈÕ
 *      Author: sunix_prog
 */


#include "example_05.h"


template<typename T>
void arrayList<T>::output(ostream& out) const
{
	copy(element, element + listSize, ostream_iterator<T>(cout, " "));
}


template<typename T>
ostream& operator<<(ostream& out, const arrayList<T>& x)
{
	x.output(out);
	return out;
}
