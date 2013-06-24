#ifndef ORDLIST_H
#define ORDLIST_H

#include "linkedlist.h"

template <class Type, class Key>
class OrdList : public LinkedList<Type>
{
	public:
		OrdList();
		~OrdList();
		void insert(Type& item);
		void merge(const OrdList<Type,Key> other_list);
		int search(Key search_key);
};

#endif
