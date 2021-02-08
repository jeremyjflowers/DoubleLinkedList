#pragma once
#include "Iterator.h"
template <typename T>
class List
{
public:
	List() {};
	List(List<T>&);

	/// <summary>
	/// Returns an Iterator pointing to the first Node in the List
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Iterator<T> begin(Iterator<T>);

	/// <summary>
	/// Returns the next item after the last Node in the List
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Iterator<T> end(Iterator<T>);

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
	bool isEmpty const();

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
	int m_nodeCount;
};

template<typename T>
inline Iterator<T> List<T>::begin(Iterator<T>)
{
	return m_first;
}

template<typename T>
inline Iterator<T> List<T>::end(Iterator<T>)
{
	return m_last;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	Node<T> newNode.data = value;
	newNode.previous = begin;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	Node N = new Node(value);
	N.next = Node;

	if (Node)
		N.previous = Node.previous;

	if (Node.previous)
		Node.previous.next = N;
	Node.previous = N;

	if (m_head == Node)
		m_head = N;

	if (!m_tail)
		m_tail = N;

	return true;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	Node N = new Node(value);
	if (m_head)
		N = head;

	if (m_head.next)
		m_head.next->previous = nullptr;

	m_head = m_head.next;

	delete(N);
		
	return true;
}

template<typename T>
inline void List<T>::operator=(const List<T>& otherList)
{
	Iterator<T> tempIter = new Iter();
	do
	{
		for (int i = 0; i < getLength(); i++)
			tempIter.m_current.data =
			tempIter++;
	} while (tempIter != otherList.m_tail);
}