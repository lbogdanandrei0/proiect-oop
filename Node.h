#pragma once

template <class T> class Node {
private:
	T data;
	Node* next;
public:
	Node(T d) : data(d), next(nullptr) {};
	inline T getData() { return data; }
	inline void nextNode(Node* n) { next = n; }
	inline Node* getNext() { return next; }
};