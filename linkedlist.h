#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


template < class Type >
class LinkedList
{
    public:
		LinkedList();
		~LinkedList();
  		
		void insert(const Type &item, int);
		void remove();
		Type retrieve() const;
		int  gotoPrior();
		int  gotoNext();
		int  gotoBeginning();
		void clear();
		int  empty() const;

		LinkedList(const LinkedList &src);

    protected:
		class ListElement
		{
			public:
				ListElement(const Type &item, ListElement* nextP):
					element(item), next(nextP) {}
				Type element;
				ListElement* next;
		};
		ListElement *head;
		ListElement *cursor;
};

template < class Type >
LinkedList<Type>::LinkedList(){
		head = NULL;
		cursor = NULL;
}

template < class Type >
void LinkedList<Type>::insert(const Type &item, int flag){

	if(!head){

		head = new ListElement(item,NULL);
		cursor = head;

	} else if(flag == 0){	
		
		ListElement* temp = cursor->next;
		cursor->next = new ListElement(item,temp);	
		cursor = cursor->next;

	} else if (flag == -1) {
			

		ListElement* temp = head;
		
		if(cursor == head){
			temp = new ListElement(item,head);
			head = temp;
			cursor = temp;
		} else {
			while(temp){
				if(temp->next == cursor)
					break;
				temp = temp->next;
			}
				
			temp->next = new ListElement(item,cursor);

			cursor = temp->next;
		}

	}

}

template < class Type >
LinkedList<Type>::~LinkedList(){
	clear();
}
template < class Type >
void LinkedList<Type>::remove(){

	if(cursor){
		if(cursor == head){
			ListElement* removeElement = head;

			head = removeElement->next;
			cursor = head;

			delete removeElement;

		} else {
			ListElement* temp = head;
			
			while(temp->next != cursor){
				temp = temp->next;
			}

			ListElement* removeElement = temp->next;			

			temp->next = removeElement->next;
			delete removeElement;

			cursor = temp;
		}

	}

}  		

template < class Type >
Type LinkedList<Type>::retrieve()const{
	if(cursor)
		return cursor->element;
}

template < class Type >
int  LinkedList<Type>::gotoPrior(){
	if(!cursor || cursor == head)
		return 0;
	
	ListElement* temp = head;
			
	while(temp->next != cursor){
		temp = temp->next;
	}

	cursor = temp;

	return 1;
}

template < class Type >
int  LinkedList<Type>::gotoNext(){
	
	if(cursor && cursor->next){
		cursor = cursor->next;
		return 1;
	}
	return 0;
}

template < class Type >
int  LinkedList<Type>::gotoBeginning(){
	if(head){
		cursor = head;
		return 1;
	}

	return 0;
}

template < class Type >
void LinkedList<Type>::clear(){

	ListElement* temp = head;

	while(temp){
		head = head->next;
		delete temp;
		temp = head;
	}
	cursor = head;
}
template < class Type >
int LinkedList<Type>::empty() const{
	return !(bool)head;
}

template < class Type >
LinkedList<Type>::LinkedList(const LinkedList &src){	
	if(&src != this){				
		head = cursor = NULL;
		ListElement* temp = src.head;
		while(temp){
			insert(temp->element,0);
			temp = temp->next;
		}
	}
}
#endif
