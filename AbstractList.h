#pragma once
#include "LinkedNode.h"

template <class T> class AbstractList {

protected:
	LinkedNode<T>* head;
	LinkedNode<T>* tail;
public:
	LinkedNode<T>* getHead() {
		return this->head;
	}
	LinkedNode<T>* getTail() {
		return this->tail;
	}
	void map(T(*func)(T)) {
		LinkedNode<T>* iterator = this->head;
		while (iterator != nullptr) {
			iterator->setData(func(iterator->getData()));
			iterator = iterator->getNext();
		}
	}
	inline bool isEmpty() { return head == nullptr; }
};