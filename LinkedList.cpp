#include "LinkedList.h"

template <typename T> T LinkedList<T>::add(T toAdd) {
	if (this->isEmpty()) {
		this->head = new LinkedNode<T>(toAdd);
		this->tail = this->head;
		this->head->previousNode(nullptr)->nextNode(nullptr);
		this->tail->previousNode(nullptr)->nextNode(nullptr);
		++listSize;
	}
	else {
		if (this->head == this->tail) {
			LinkedNode<T>* newNode = new LinkedNode<T>(toAdd);
			this->head = newNode;
			this->head->previousNode(nullptr)->nextNode(this->tail);
			this->tail->previousNode(this->head);
			++listSize;
		}
		else {
			LinkedNode<T>* newNode = new LinkedNode<T>(toAdd);
			newNode->nextNode(this->head)->previousNode(nullptr);
			this->head->previousNode(newNode);
			this->head = newNode;
			++listSize;
		}
	}
	return toAdd;
}

template <typename T> T LinkedList<T>::addLast(T toAdd) {
	if (this->isEmpty()) {
		this->tail = new LinkedNode<T>(toAdd);
		this->head = this->tail;
		this->head->previousNode(nullptr)->nextNode(nullptr);
		this->tail->previousNode(nullptr)->nextNode(nullptr);
		++listSize;
	}
	else {
		if (this->head == this->tail) {
			LinkedNode<T>* newNode = new LinkedNode<T>(toAdd);
			this->tail = newNode;
			this->tail->nextNode(nullptr)->previousNode(this->head);
			this->head->nextNode(this->tail);
			++listSize;
		}
		else {
			LinkedNode<T>* newNode = new LinkedNode<T>(toAdd);
			newNode->previousNode(this->tail)->nextNode(nullptr);
			this->tail->nextNode(newNode);
			this->tail = newNode;
			++listSize;
		}
	}
	return toAdd;
}