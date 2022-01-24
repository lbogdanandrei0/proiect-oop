#pragma once
#include "AbstractList.h"
#include "GameObject.h"
#include "CollidingGameObject.h"
#include "MobileGameObject.h"


template <typename T> class LinkedList : public AbstractList<T> {
	__int32 listSize = 0;
public:
	LinkedList() { this->head = nullptr; this->tail = nullptr; listSize = 0; }
	T add(T toAdd);
	T addLast(T toAdd);
	inline __int32 size() { return listSize; }
	void print() {
		std::cout << "\n";
		LinkedNode<T>* iterator = this->head;
		while (iterator != nullptr) {
			std::cout << iterator->getData() << " ";
			iterator = iterator->getNext();
		}
		std::cout << "\n";
	}
};

template class LinkedList<int>;
template class LinkedList<GameObject*>;
template class LinkedList<CollidingGameObject*>;
template class LinkedList<MobileGameObject*>;