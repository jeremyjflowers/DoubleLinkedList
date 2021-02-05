#pragma once
#include "Node.h"
template <typename T>
class Iterator
{
public:
	Iterator() {};
	Iterator(Node<T>* node);

	Iterator<T> operator ++();
	Iterator<T> operator --();
	const bool operator ==(const Iterator<T>& iter);
	const bool operator !=(const Iterator<T>& iter);
	T operator *();

private:
	Node<T> current;
};

template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
	current = node;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
	current = current.next;
	return Iterator<T>(current);
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	current = current.previous;
	return Iterator<T>(current);
}

template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	return iter.current == current;
}

template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	return iter.current != current;
}
