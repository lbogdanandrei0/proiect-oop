#pragma once
#include <iostream>

template <class T> class LinkedNode {
private:
	T data;
	LinkedNode* next;
	LinkedNode* previous;
public:
	LinkedNode(T d) : data(d), next(nullptr), previous(nullptr) {};
	inline T getData() { return data; }
	inline void setData(T newData) { data = newData; }
	inline LinkedNode* nextNode(LinkedNode* n) { next = n; return this; }
	inline LinkedNode* getNext() { return next; }
	inline LinkedNode* previousNode(LinkedNode* n) { previous = n; return this; }
	inline LinkedNode* getPrevious() { return previous; }
};