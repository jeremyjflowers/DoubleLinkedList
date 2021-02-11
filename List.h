#pragma once
#include "Iterator.h"
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
	const Iterator<T> begin(Iterator<T>);

	/// <summary>
	/// Returns the next item after the last Node in the List
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	const Iterator<T> end(Iterator<T>);

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
inline const Iterator<T> List<T>::begin(Iterator<T>)
{
	return m_first;
}

template<typename T>
inline const Iterator<T> List<T>::end(Iterator<T>)
{
	return m_last;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	Node<T> newNode.data = value;
	newNode.next = m_first;
	m_first = newNode;
	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	Node<T> newNode.data = value;
	m_last->next = newNode;
	newNode->previous = m_last;
	m_last = newNode;
	newNode->next = nullptr;
	m_nodeCount++;
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

	m_nodeCount++;
	return true;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{


	Iterator<T> iter = Iterator();
	contains(value);

	iter->next->previous = iter->previous;
	iter->previous = iter->next->previous;


	//If the to be removed is first, then change the next to first
	//Use pushfront
	//Vice versa with last


	//Node N = new Node(value);
	//if (m_head)
	//	N = head;

	//if (m_head.next)
	//	m_head.next->previous = nullptr;

	//m_head = m_head.next;

	//delete(N);
		
	//return true;

	m_nodeCount--;
}

template<typename T>
inline void List<T>::print() const
{
	for (Iterator<int> iter = begin(); iter != end(); ++iter)
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
inline int List<T>::getLength() const
{
	return m_nodeCount;
}

template<typename T>
inline void List<T>::operator=(const List<T>& otherList)
{
	Iterator<T> tempIter = new Iter(m_first);
	Iterator<T> tempIterOther = new Iter(otherList->m_first));
	do
	{
		for (int i = 0; i < otherList->getLength(); i++)
		{
			tempIter->m_current = tempIterOther->m_current;
		}
	} while (tempIter != otherList.m_tail);
}