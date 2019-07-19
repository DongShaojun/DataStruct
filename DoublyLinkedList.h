#pragma once
#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

#include "DoublyLinkedListNode.h"

template<typename T>
class DoublyLinkedList
{
private:
	DoublyLinkedListNode<T>* head;	//头结点
	DoublyLinkedListNode<T>* tail;	//尾结点
	size_t size;
public:
	DoublyLinkedList();
	DoublyLinkedList(DoublyLinkedList<T>& list);	//复制构造函数
	~DoublyLinkedList();	//析构函数
	bool empty() const;		//判断是否为空
	size_t Size() const;	//链表大小
	T& get(size_t theIndex) const;		//获取元素
	void insert(size_t theIndex, const T& value);		//插入元素
	void Push_back(const T& value);		//尾部插入元素
	void remove(size_t theIndex);		//删除元素
	void output(std::ostream &os);		//打印元素
	size_t IndexOf(const T& value);		//获取元素位置
	void operator=(const DoublyLinkedList& list);	//赋值构造函数
	T& operator[](const size_t theIndex);	    	//重载下标运算
};

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>& list)		//复制构造函数
{
	if (list.head != nullptr)	//list不为空
	{
		head = new DoublyLinkedListNode<T>(list.head->data);
		head->previous = nullptr;
		DoublyLinkedListNode<T>* sourceNode = list.head->next;
		DoublyLinkedListNode<T>* tail = head;
		DoublyLinkedListNode<T>* targetNode = head;
		while (sourceNode != nullptr)
		{
			tail = new DoublyLinkedListNode<T>(sourceNode->data);
			tail->previous = targetNode;
			targetNode->next = tail;
			targetNode = targetNode->next;
			sourceNode = sourceNode->next;
		}
		tail->next = nullptr;
		size = list.size;
	}
	else
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
}

template<typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
	if (head != nullptr)
	{
		DoublyLinkedListNode<T>* targetNode = head->next;
		delete head;
		head = targetNode;
	}
}

template<typename T>
inline bool DoublyLinkedList<T>::empty() const
{
	return false;
}

template<typename T>
inline size_t DoublyLinkedList<T>::Size() const
{
	return size_t();
}

template<typename T>
inline T & DoublyLinkedList<T>::get(size_t theIndex) const
{
	// TODO: 在此处插入 return 语句
}

template<typename T>
inline void DoublyLinkedList<T>::insert(size_t theIndex, const T & value)
{
	DoublyLinkedListNode<T>* targetNode = head;
	for (size_t i=1;i < theIndex;++i)
	{
		targetNode = targetNode->next;
	}

}

template<typename T>
inline void DoublyLinkedList<T>::Push_back(const T & value)
{
	if (head == nullptr)
	{
		head = new DoublyLinkedListNode<T>(value);
		tail = head;
		head->previous = nullptr;
		head->next = nullptr;
		++size;
		return;
	}
	tail->next = new DoublyLinkedListNode<T>(value);
	tail->next->previous = tail;
	tail = tail->next;
	tail->next = nullptr;
	++size;
}

template<typename T>
inline void DoublyLinkedList<T>::remove(size_t theIndex)
{
}

template<typename T>
inline void DoublyLinkedList<T>::output(std::ostream & os)
{
	DoublyLinkedListNode<T>* targetNode = head;
	while (targetNode != nullptr)
	{
		os << targetNode->data << std::endl;
		targetNode = targetNode->next;
	}
}

template<typename T>
inline size_t DoublyLinkedList<T>::IndexOf(const T & value)
{
	return size_t();
}

template<typename T>
inline void DoublyLinkedList<T>::operator=(const DoublyLinkedList& list)
{
	if (list.head != nullptr)	//list不为空
	{
		head = new DoublyLinkedListNode<T>(list.head->data);
		head->previous = nullptr;
		DoublyLinkedListNode<T>* sourceNode = list.head->next;
		DoublyLinkedListNode<T>* tail = head;
		DoublyLinkedListNode<T>* targetNode = head;
		while (sourceNode != nullptr)
		{
			tail = new DoublyLinkedListNode<T>(sourceNode->data);
			tail->previous = targetNode;
			targetNode->next = tail;
			targetNode = targetNode->next;
			sourceNode = sourceNode->next;
		}
		tail->next = nullptr;
		size = list.size;
	}
	else
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
}

template<typename T>
inline T & DoublyLinkedList<T>::operator[](const size_t theIndex)
{
	// TODO: 在此处插入 return 语句
}

#endif // !DOUBLYLINKEDLIST_H_