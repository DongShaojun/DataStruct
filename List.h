/**************************
单向链表的实现
version：1.0   2019.6.25
***************************/

#pragma once
#ifndef LIST_H_
#define LIST_H_

#include"ListNode.h"
#include<iostream>

template<typename T>
class List
{
private:
	ListNode<T>* head;
	size_t size;
	void checkIndex(size_t theIndex);	//索引位置检测
public:
	List(size_t initCapacity=10);	//构造函数，函数参数无意义
	List(const List& list);		//复制构造函数
	~List();					//析构函数
	bool empty() const;		//判断是否为空
	size_t Size() const;	//链表大小
	T& get(size_t theIndex) const;		//获取元素
	void insert(size_t theIndex, const T& value);		//插入元素
	void Push_back(const T& value);		//尾部插入元素
	void remove(size_t theIndex);		//删除元素
	void output(std::ostream &os);		//打印元素
	size_t IndexOf(const T& value);		//获取元素位置
	void operator=(const List& list);	//赋值构造函数
	T& operator[](const size_t theIndex);		//重载下标运算
};



template<typename T>
inline void List<T>::checkIndex(size_t theIndex)	//检查索引值是否有效
{
	if (theIndex <= 0 || theIndex > size)
		std::cout << "索引位置无效，应大于0小于" << size << std::endl;
}

template<typename T>
inline List<T>::List(size_t initCapacity)		//默认复制构造函数，函数参数无意义
{
	head = nullptr;
	size = 0;
}

template<typename T>
inline List<T>::List(const List<T> & list)		//复制构造函数
{
	if (list.head == nullptr)		//链表为空
	{
		head = nullptr;
		size = 0;
	}
	else
	{
		head = new ListNode<T>(list.head->data);		//构造一个新链表的头结点
		ListNode<T>* sourceNode = list.head->next;		//用于遍历源链表的指针
		ListNode<T>* targetNode = head;					//新链表的位置指针
		while (sourceNode != nullptr)
		{
			targetNode->next = new ListNode<T>(sourceNode->data);	//构造新的结点加入到新链表中
			targetNode = targetNode->next;		//新链表位置指针后移
			sourceNode = sourceNode->next;		//源链表位置指针后移
		}
		targetNode->next = nullptr;		
		size = list.Size();
	}
}

template<typename T>
inline List<T>::~List()		//析构函数
{
	if (head != nullptr)
	{
		ListNode<T>* targetNode = head;
		while (targetNode != nullptr)
		{
			targetNode = head->next;
			delete head;
			head = targetNode;
		}
	}
}

template<typename T>
inline bool List<T>::empty() const	//判断链表是否为空，空返回1，非空返回0
{
	if (size == 0)
		return true;
	else
		return false;
}

template<typename T>
inline size_t List<T>::Size() const
{
	return size;
}

template<typename T>
inline T & List<T>::get(size_t theIndex) const		//获取元素,不能处理链表为空的情况
{
	//checkIndex(theIndex);
	/*if (head == nullptr)
	{
		std::cout << "链表为空" << std::endl;
		return ;
	}*/
	ListNode<T>* targetNode = head;
	for(size_t i=1;i<theIndex;++i)
	{ 
		targetNode = targetNode->next;
	}
	return targetNode->data;
}

template<typename T>
inline void List<T>::insert(size_t theIndex, const T & value)	//插入元素，在theIndex之后插入
{
	if (theIndex > size)	//插入位置大于链表尺寸，就在链表尾部插入
		theIndex = size;
	if (theIndex == 0)		//插入位置为0时，在头部插入
	{
		ListNode<T>* temp = new ListNode<T>(value);
		temp->next = head;
		head = temp;
		++size;
	}
	else                   //正常插入元素
	{
		ListNode<T>* targetNode = head;
		for (size_t i = 1;i < theIndex;++i)		//找到索引位置结点
		{
			targetNode = targetNode->next;
		}
		ListNode<T>* temp = targetNode->next;	//保存插入位置后一个结点信息
		targetNode->next = new ListNode<T>(value);	//插入结点
		targetNode->next->next = temp;		
		++size;
	}
}

template<typename T>
inline void List<T>::Push_back(const T & value)		//在链表尾部插入元素
{
	if (head == nullptr)	//链表为空
	{
		head = new ListNode<T>(value);	//创建一个头结点
		head->next = nullptr;
		++size;
	}
	else
	{
		ListNode<T>* targetNode = head;			//遍历指针
		while (targetNode->next != nullptr)		//找到尾部结点
		{
			targetNode = targetNode->next;
		}
		ListNode<T>* myNode = new ListNode<T>(value);	//创建新结点
		targetNode->next = myNode;						//插入结点
		targetNode->next->next = nullptr;
		++size;
	}
}

template<typename T>
inline void List<T>::remove(size_t theIndex)	//删除theIndex后一个结点
{
	if (head != nullptr)	//链表不为空
	{
		if (theIndex > size)		//删除位置大于链表长度
		{
			std::cout << "位置无效，应小于" << size << std::endl;
			return;
		}
		if (theIndex == 0)		//删除位置为0时，删除头结点
		{
			ListNode<T>* tempNode;
			tempNode = head->next;
			delete head;
			head = tempNode;
			--size;
		}
		ListNode<T>* targetNode = head;
		for (size_t i = 1;i < theIndex;++i)		//找到索引位置结点
		{
			targetNode = targetNode->next;
		}
		ListNode<T>* temp = targetNode->next->next;	//保存插入位置后一个结点信息
		delete targetNode->next;
		targetNode->next = temp;
		--size;
	}
	else
	{
		std::cout << "链表为空" << std::endl;
		return;
	}
}

template<typename T>
inline void List<T>::output(std::ostream & os)	//打印链表所有元素
{
	if (head == nullptr)
	{
		os << "链表为空" << std::endl;
	}
	else
	{
		ListNode<T>* targetNode = head;		//遍历指针
		while (targetNode != nullptr)
		{
			os << targetNode->data << std::endl;
			targetNode = targetNode->next;
		}
	}
}

template<typename T>
inline size_t List<T>::IndexOf(const T & value)
{
	if (head == nullptr)		//链表为空，返回0
	{
		std::cout << "链表为空" << std::endl;
		return 0;
	}
	ListNode<T>* targetNode = head;			//遍历指针
	for(size_t i=1;targetNode != nullptr;++i)
	{
		if (targetNode->data == value)		//找到元素，返回位置
			return i;
		targetNode = targetNode->next;
	}
	if (targetNode == nullptr)		//到达链表尾部，未找到元素
	{
		std::cout << "未找到元素" << value<<std::endl;
		return 0;
	}
}

template<typename T>
inline void List<T>::operator=(const List & list)	//赋值构造函数
{
	if (list.head == nullptr)		//链表为空
	{
		head = nullptr;
		size = 0;
	}
	else
	{
		head = new ListNode<T>(list.head->data);		//构造一个新链表的头结点
		ListNode<T>* sourceNode = list.head->next;		//用于遍历源链表的指针
		ListNode<T>* targetNode = head;					//新链表的位置指针
		while (sourceNode != nullptr)
		{
			targetNode->next = new ListNode<T>(sourceNode->data);	//构造新的结点加入到新链表中
			targetNode = targetNode->next;		//新链表位置指针后移
			sourceNode = sourceNode->next;		//源链表位置指针后移
		}
		targetNode->next = nullptr;
		size = list.Size();
	}
}

template<typename T>
inline T& List<T>::operator[](const size_t theIndex)	//重载下标运算,不能处理链表为空的情况
{
	if (head != nullptr)	//链表不为空
	{
		if (theIndex < 0 || theIndex > size)	//检查下标是否越界
		{
			std::cout << "位置无效，应大于等于0小于等于" << size << std::endl;
			return head->data;
		}
		ListNode<T>* targetNode = head;
		for (size_t i = 0;i<theIndex;++i)	//获取下标位置结点
		{
			targetNode = targetNode->next;
		}
		return targetNode->data;
	}
	/*else
	{
		std::cout << "链表为空" << std::endl;
		return;
	}*/
}

#endif // !LIST_H_