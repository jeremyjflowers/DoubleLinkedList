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
	Node<T> m_current;
};

template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
	m_current = node;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
	m_current = m_current.next;
	return *this;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	m_current = m_current.previous;
	return this;
}

template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	return iter.m_current == m_current;
}

template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	return iter.m_current.data != m_current.data;
}

template<typename T>
inline T Iterator<T>::operator*()
{
	return m_current.data;
}