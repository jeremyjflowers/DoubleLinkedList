#pragma once
#include "Node.h"
template <typename T>
class Iterator
{
public:
	Iterator();
	Iterator(Node<t>* node);

	Iterator<T> operator ++();
	Iterator<T> operator --();
	const bool operator ==(const Iterator<T>, Iterator);
	const bool operator !=(const Iterator<T>, Iterator);
	T operator*();

private:
	Node<T> current;
};