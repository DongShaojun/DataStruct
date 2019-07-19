#pragma once
#ifndef DOUBLYLINEDLISTNODE_H_
#define DOUBLYLINEDLISTNODE_H_

template<typename T>
class DoublyLinkedListNode	//˫��������
{
public:
	T data;
	DoublyLinkedListNode<T>* previous;	//ǰ�����
	DoublyLinkedListNode<T>* next;		//��̽��
	DoublyLinkedListNode();
	DoublyLinkedListNode(const T &value);
	DoublyLinkedListNode(const T& value, const DoublyLinkedListNode<T>* temp_prev, const DoublyLinkedListNode<T>* temp_next);
	
};

template<typename T>
inline DoublyLinkedListNode<T>::DoublyLinkedListNode()
{
	previous = nullptr;
	next = nullptr;
}

template<typename T>
inline DoublyLinkedListNode<T>::DoublyLinkedListNode(const T & value)
{
	previous = nullptr;
	next = nullptr;
	data = value;
}

template<typename T>
inline DoublyLinkedListNode<T>::DoublyLinkedListNode(const T & value, const DoublyLinkedListNode<T>* temp_prev, const DoublyLinkedListNode<T>* temp_next)
{
	previous = temp_prev;
	next = temp_next;
	data = value;
}

#endif // !DOUBLYLINEDLISTNODE_H_