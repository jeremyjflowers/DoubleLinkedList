#pragma once
#include "Iterator.h"
#include <iostream>
template <typename T>
class List
{
public:
	List() {};
	List(List<T>& otherList);

	/// <summary>
	/// Returns an Iterator pointing to the first Node in the List
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Iterator<T> begin() const;

	/// <summary>
	/// Returns the next item after the last Node in the List
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Iterator<T> end() const;

	/// <summary>
	/// Deletes all nodes in the List
	/// </summary>
	void destroy();

	/// <summary>
	/// Adds a new Node to the beginning of the List
	/// </summary>
	/// <param name="value"></param>
	void pushFront(const T& value);

	/// <summary>
	/// Adds a new Node to the end of the List
	/// </summary>
	/// <param name="value"></param>
	void pushBack(const T& value);

	/// <summary>
	/// Adds a new Node to the List at the given index
	/// </summary>
	/// <param name="value"></param>
	/// <param name="index">The position in the List that the Node will be added</param>
	/// <returns></returns>
	bool insert(const T& value, int index);

	/// <summary>
	/// Removes all Nodes with the given value
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	bool remove(const T& value);

	void sort();

	/// <summary>
	/// Prints the values of all the Nodes
	/// </summary>
	void print() const;

	void initialize();

	/// <summary>
	/// Checks to see if the given item is in the List
	/// </summary>
	/// <param name="object"></param>
	/// <returns></returns>
	bool contains(const T& object);

	/// <summary>
	/// Returns whether or not the List has any Nodes in it
	/// </summary>
	/// <returns></returns>
	bool isEmpty() const;

	/// <summary>
	/// Sets the given Iterator to point at the Node at the given Index
	/// </summary>
	/// <param name="iter"></param>
	/// <param name="index"></param>
	/// <returns></returns>
	bool getData(Iterator<T>& iter, int index);

	/// <summary>
	/// Returns the amount of Nodes in the List
	/// </summary>
	/// <returns></returns>
	int getLength() const;

	void operator =(const List<T>& otherList);

private:
	Node<T> m_first, m_head;
	Node<T> m_last, m_tail;
	int m_nodeCount = 0;
};

template<typename T>
inline List<T>::List(List<T>& otherList)
{
	this = otherList;
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	return Iterator<T>(m_first);
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	return Iterator<T>(m_last);
}

template<typename T>
inline void List<T>::destroy()
{
	for (Iterator<T> iter = begin(); iter != end(); ++iter)
	{
		remove(iter.m_current);
	}
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	//Node<T> newNode = new Node<T>();
	//newNode.data = value;
	//m_first.previous = newNode;
	//newNode.next = m_first;
	//m_first = newNode;
	//newNode.previous = nullptr;

	Node<T>* newNode = new Node<T>(value);
	m_first.previous = newNode;
	newNode->next = new Node<T>(m_first.data);
	newNode->previous = nullptr;

	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	//Node<T> newNode = new Node<T>(); 
	//newNode.data = value;
	//m_last->next = newNode;
	//newNode->previous = m_last;
	//m_last = newNode;
	//newNode->next = nullptr;

	Node<T>* newNode = new Node<T>(value);
	m_last.next = newNode;
	newNode->previous = new Node<T>(m_last.data);
	newNode->next = nullptr;

	m_nodeCount++;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	Iterator<T> iter = begin();
	for (int i = 0; i < index; i++)
		iter++;

	Node<T> newNode = new Node<T>(value);

	newNode.previous = iter.m_current.previous;
	newNode.next = iter.m_current;

	iter.m_current.previous->next = newNode;
	iter.m_current.previous = newNode;

	newNode.previous = newNode;

	if (iter.m_current == m_head)
		m_head = newNode;

	if (iter.m_current == m_tail)
		m_tail = newNode;

	m_nodeCount++;
	return true;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	Iterator<T> iter = Iterator<T>();
	for (Iterator<T> iter = begin(); iter != end(); ++iter)
		if (contains(value))
		{
			if (iter == m_head)
				m_head = iter--;

			iter.m_current.next.previous = iter.m_current.previous;
			iter.m_current.next = iter.m_current.next;

			delete(iter.m_current);
			m_nodeCount--;
			return true;
		}
	return false;
}

template<typename T>
inline void List<T>::sort()
{
	Iterator<T> iter = begin();
	Iterator<T> jter = end();
	for (int i = 0; i < getLength(); i++)
	{
		for (int j = getLength() - 1; j > i; j--)
		{
			getData(iter, j - 1);
			getData(jter, j);
			if (*jter < *iter)
			{
				Iterator<T> temp;
				temp = jter;
				jter = iter;
				iter = temp;
			}
		}
	}
}

template<typename T>
inline void List<T>::print() const 
{
	for (Iterator<T> iter = begin(); iter != end(); ++iter)
		std::cout << *iter << std::endl;
}

template<typename T>
inline void List<T>::initialize()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline bool List<T>::contains(const T& object)
{
	for (int i = 0; i < getLength(); i++)
		if (i == object)
			return true;
	return false;
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	return (!m_first);
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	iter = begin();

	for (int i = 0; i < index; i++)
		iter++;
	
	return false;
}

template<typename T>
inline int List<T>::getLength() const
{
	return m_nodeCount;
}

template<typename T>
inline void List<T>::operator=(const List<T>& otherList)
{
	Iterator<T> tempIter = new Iterator<T>(begin());
	Iterator<T> tempIterOther = new Iterator<T>(otherList->m_first);
	while (tempIter.m_current != otherList.m_tail)
	{
		for (int i = 0; i < otherList->getLength(); i++)
		{
			tempIter->m_current = tempIterOther->m_current;
		}
	};
}