/*
 * example_05.h
 *
 *  Created on: 2016Äê5ÔÂ11ÈÕ
 *      Author: sunix_prog
 */

#ifndef CHAPTER_05_EXAMPLE_05_H_
#define CHAPTER_05_EXAMPLE_05_H_


#include <fstream>
#include <vector>
using namespace std;


template<typename T>
class linearList
{
public:
	virtual ~linearList() {};
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual T& get(int theIndex) const = 0;
	virtual int indexOf(const T& theElement) const = 0;
	virtual void erase(int theIndex) = 0;
	virtual void insert(int theIndex, const T& theElement) = 0;
	virtual void output(ostream& out) const = 0;
};


template<typename T>
class arrayList : public linearList<T>
{
public:
	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T>&);
	~arrayList() { delete [] element; };

	bool empty() const { return listSize == 0; }
	int size() const { return listSize; }
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out) const;
	int capacity() const { return arrayLength; }

	class iterator
	{
	public:
		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;

		iterator(T* thePosition = 0) { position = thePosition; }

		T& operator*() const { return *position; }
		T* operator->() const { return &*position; }

		iterator& operator++()
		{
			++position;
		    return *this;
		}
		iterator operator++(int)
		{
			iterator old = *this;
			++position;
			return old;
		}

		iterator& operator--()
		{
			--position;
		    return *this;
		}
		iterator operator--(int)
		{
			iterator old = *this;
			--position;
			return old;
		}

		bool operator!=(const iterator right) const
		{
			return position != right.position;
		}
		bool operator==(const iterator right) const
		{
			return position == right.position;
		}

	protected:
		T* position;
	};

	iterator begin() { return iterator(element); }
	iterator end() { return iterator(element + listSize); }

protected:
	void checkIndex(int theIndex) const;
	T* element;
	int arrayLength;
	int listSize;
};


template<class T>
class vectorList : public linearList<T>
{
public:
	vectorList(int initialCapacity = 10);
	vectorList(const vectorList<T>&);
	~vectorList() { delete element; }

	bool empty() const { return element->empty(); }
	int size() const { return (int)element->size(); }
	T& get(int index) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	void output(ostream& out) const;
	int capacity() const { return (int)element->capacity(); }

	typedef typename vector<T>::iterator iterator;
	iterator begin() { return element->begin(); }
	iterator end() { return element->end(); }

protected:
	void checkIndex(int theIndex) const;
	vector<T>* element;
};

#endif /* CHAPTER_05_EXAMPLE_05_H_ */
