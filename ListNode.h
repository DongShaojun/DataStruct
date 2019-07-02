/*单向链表结点*/
#pragma once
#ifndef LISTNODE_H_
#define LISTNODE_H_

template<typename T>
class ListNode
{
public:
	T data;
	ListNode* next;
	ListNode();
	ListNode(const T& value);
	ListNode(const T& value, const ListNode* temp_next);
};

template<typename T>
inline ListNode<T>::ListNode()
{
}

template<typename T>
inline ListNode<T>::ListNode(const T & value)
{
	data = value;
	next = nullptr;
}

template<typename T>
inline ListNode<T>::ListNode(const T & value, const ListNode * temp_next)
{
	data = value;
	this->next = temp_next;
}


#endif // !LISTNODE_H_