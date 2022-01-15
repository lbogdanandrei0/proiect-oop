#pragma once
#include "Node.h"

template <class T> class Stack {
private:
	Node<T>* top;
public:
	Stack() { top = nullptr; }

	inline Node<T> addNode(Node<T> nextTop) { nextTop.nextNode(top); top = &nextTop; return *top; }
	inline Node<T> getTop() { return *top; }
	inline Node<T> popTop() { Node<T> currentTop(top->getData()); top = top->getNext(); return currentTop; }
	inline bool isEmpty() { return top == nullptr; }
};