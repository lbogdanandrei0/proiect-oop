#include "LinkedList.h"

template <typename T> T LinkedList<T>::add(T toAdd) {
	if (this->isEmpty()) {
		this->head = new LinkedNode<T>(toAdd);
		this->tail = this->head;
		this->head->previousNode(nullptr)->nextNode(nullptr);
		this->tail->previousNode(nullptr)->nextNode(nullptr);
	}
	else {
		if (this->head == this->tail) {
			LinkedNode<T>* newNode = new LinkedNode<T>(toAdd);
			this->head = newNode;
			this->head->previousNode(nullptr)->nextNode(this->tail);
			this->tail->previousNode(this->head);
		}
		else {
			LinkedNode<T>* newNode = new LinkedNode<T>(toAdd);
			newNode->nextNode(this->head)->previousNode(nullptr);
			this->head->previousNode(newNode);
			this->head = newNode;
		}
	}
	++listSize;
	return toAdd;
}

template <typename T> T LinkedList<T>::addLast(T toAdd) {
	if (this->isEmpty()) {
		this->tail = new LinkedNode<T>(toAdd);
		this->head = this->tail;
		this->head->previousNode(nullptr)->nextNode(nullptr);
		this->tail->previousNode(nullptr)->nextNode(nullptr);
	}
	else {
		if (this->head == this->tail) {
			LinkedNode<T>* newNode = new LinkedNode<T>(toAdd);
			this->tail = newNode;
			this->tail->nextNode(nullptr)->previousNode(this->head);
			this->head->nextNode(this->tail);
		}
		else {
			LinkedNode<T>* newNode = new LinkedNode<T>(toAdd);
			newNode->previousNode(this->tail)->nextNode(nullptr);
			this->tail->nextNode(newNode);
			this->tail = newNode;
		}
	}
	++listSize;
	return toAdd;
}

template <typename T> void LinkedList<T>::deleteNode(LinkedNode<T>* toDelete) {
	if (toDelete == this->head) {
		this->head = this->head->getNext();
		if (this->head != nullptr) {
			this->head->previousNode(nullptr);
		}
	}
	else if (toDelete == this->tail) {
		this->tail = this->tail->getPrevious();
		if (this->tail != nullptr) {
			this->tail->nextNode(nullptr);
		}
	}
	else {
		toDelete->getNext()->previousNode(toDelete->getPrevious());
		toDelete->getPrevious()->nextNode(toDelete->getNext());
		//delete toDelete
	}
	--listSize;
}