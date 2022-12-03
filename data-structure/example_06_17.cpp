/*
 * example_06_17.cpp
 *
 *  Created on: 2016Äê5ÔÂ25ÈÕ
 *      Author: sunix_prog
 */


#include "example_06.h"

void binsort(chain<studentRecord>& theChain, int range)
{
	chain<studentRecord>* bin = new chain<studentRecord>[range + 1];

	int numberOfElements = theChain.size();
	for (int i = 1; i <= numberOfElements; i++) {
		studentRecord tmp = theChain.get(0);
		theChain.erase(0);
		bin[tmp.score].insert(0, tmp);
	}

	for (int j = range; j >= 0; j--) {
		while (!bin[j].empty()) {
			studentRecord tmp2 = bin[j].get(0);
			bin[j].erase(0);
			theChain.insert(0, tmp2);
		}
	}

	delete [] bin;
}

