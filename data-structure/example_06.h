/*
 * example_06.h
 *
 *  Created on: 2016Äê5ÔÂ16ÈÕ
 *      Author: sunix_prog
 */

#ifndef CHAPTER_06_EXAMPLE_06_H_
#define CHAPTER_06_EXAMPLE_06_H_

#include "example_05.h"


template<typename T>
struct chainNode
{
	T element;
	chainNode<T>* next;

	chainNode() {}
	chainNode(const T& element) {
		this->element = element;
	}
	chainNode(const T& element, chainNode<T>* next) {
		this->element = element;
		this->next = next;
	}
};


template<typename T>
class chain : public linearList<T>
{
public:
	chain(int initialCapacity = 10);
	chain(const chain<T>&);
	~chain();

	bool empty() const { return listSize == 0; }
	int size() const { return listSize; }
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out) const;

protected:
	void checkIndex(int theIndex) const;
	chainNode<T>* firstNode;
	int listSize;
};


template<typename T>
class extendedLinearList : linearList<T>
{
public:
	virtual ~extendedLinearList();
	virtual void clear() = 0;
	virtual void push_back(const T& theElement) = 0;
};


struct studentRecord
{
	int score;
	string* name;
	int operator!=(const studentRecord& x) const {
		return (score != x.score);
	}
};


ostream& operator<<(ostream& out, const studentRecord& x) {
	out << x.score << ' ' << *x.name << endl;
	return out;
}

#endif /* CHAPTER_06_EXAMPLE_06_H_ */
