/*
 * example_06_18.cpp
 *
 *  Created on: 2016Äê5ÔÂ26ÈÕ
 *      Author: sunix_prog
 */


template<typename T>
void chain<T>::binSort(int range)
{
	chainNode<T>:: **bottom, **top;
	bottom = new chainNode<T>*[range + 1];
	top = new chainNode<T>*[range + 1];
	for (int b = 0; b <= range; b++) {
		bottom[b] = NULL;
	}

	for (; firstNode != NULL; firstNode = firstNode->next) {
		int theBin = firstNode->element;
		if (bottom[theBin] == NULL) {
			bottom[theBin] = top[theBin] = firstNode;
		} else {
			top[theBin]->next = firstNode;
			top[theBin] = firstNode;
		}
	}

	chainNode<T>* y = NULL;
	for (int theBin = 0; theBin <= range; theBin++) {
		if (bottom[theBin] != NULL) {
			if (y == NULL) {
				firstNode = bottom[theBin];
			} else {
				y->next = bottom[theBin];
			}
			y = top[theBin];
		}
	}
	if (y != NULL) {
		y->next = NULL;
	}

	delete [] bottom;
	delete [] top;
}
