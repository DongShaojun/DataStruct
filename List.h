/**************************
���������ʵ��
version��1.0   2019.6.25
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
	void checkIndex(size_t theIndex);	//����λ�ü��
public:
	List(size_t initCapacity=10);	//���캯������������������
	List(const List& list);		//���ƹ��캯��
	~List();					//��������
	bool empty() const;		//�ж��Ƿ�Ϊ��
	size_t Size() const;	//�����С
	T& get(size_t theIndex) const;		//��ȡԪ��
	void insert(size_t theIndex, const T& value);		//����Ԫ��
	void Push_back(const T& value);		//β������Ԫ��
	void remove(size_t theIndex);		//ɾ��Ԫ��
	void output(std::ostream &os);		//��ӡԪ��
	size_t IndexOf(const T& value);		//��ȡԪ��λ��
	void operator=(const List& list);	//��ֵ���캯��
	T& operator[](const size_t theIndex);		//�����±�����
};



template<typename T>
inline void List<T>::checkIndex(size_t theIndex)	//�������ֵ�Ƿ���Ч
{
	if (theIndex <= 0 || theIndex > size)
		std::cout << "����λ����Ч��Ӧ����0С��" << size << std::endl;
}

template<typename T>
inline List<T>::List(size_t initCapacity)		//Ĭ�ϸ��ƹ��캯������������������
{
	head = nullptr;
	size = 0;
}

template<typename T>
inline List<T>::List(const List<T> & list)		//���ƹ��캯��
{
	if (list.head == nullptr)		//����Ϊ��
	{
		head = nullptr;
		size = 0;
	}
	else
	{
		head = new ListNode<T>(list.head->data);		//����һ���������ͷ���
		ListNode<T>* sourceNode = list.head->next;		//���ڱ���Դ�����ָ��
		ListNode<T>* targetNode = head;					//�������λ��ָ��
		while (sourceNode != nullptr)
		{
			targetNode->next = new ListNode<T>(sourceNode->data);	//�����µĽ����뵽��������
			targetNode = targetNode->next;		//������λ��ָ�����
			sourceNode = sourceNode->next;		//Դ����λ��ָ�����
		}
		targetNode->next = nullptr;		
		size = list.Size();
	}
}

template<typename T>
inline List<T>::~List()		//��������
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
inline bool List<T>::empty() const	//�ж������Ƿ�Ϊ�գ��շ���1���ǿշ���0
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
inline T & List<T>::get(size_t theIndex) const		//��ȡԪ��,���ܴ�������Ϊ�յ����
{
	//checkIndex(theIndex);
	/*if (head == nullptr)
	{
		std::cout << "����Ϊ��" << std::endl;
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
inline void List<T>::insert(size_t theIndex, const T & value)	//����Ԫ�أ���theIndex֮�����
{
	if (theIndex > size)	//����λ�ô�������ߴ磬��������β������
		theIndex = size;
	if (theIndex == 0)		//����λ��Ϊ0ʱ����ͷ������
	{
		ListNode<T>* temp = new ListNode<T>(value);
		temp->next = head;
		head = temp;
		++size;
	}
	else                   //��������Ԫ��
	{
		ListNode<T>* targetNode = head;
		for (size_t i = 1;i < theIndex;++i)		//�ҵ�����λ�ý��
		{
			targetNode = targetNode->next;
		}
		ListNode<T>* temp = targetNode->next;	//�������λ�ú�һ�������Ϣ
		targetNode->next = new ListNode<T>(value);	//������
		targetNode->next->next = temp;		
		++size;
	}
}

template<typename T>
inline void List<T>::Push_back(const T & value)		//������β������Ԫ��
{
	if (head == nullptr)	//����Ϊ��
	{
		head = new ListNode<T>(value);	//����һ��ͷ���
		head->next = nullptr;
		++size;
	}
	else
	{
		ListNode<T>* targetNode = head;			//����ָ��
		while (targetNode->next != nullptr)		//�ҵ�β�����
		{
			targetNode = targetNode->next;
		}
		ListNode<T>* myNode = new ListNode<T>(value);	//�����½��
		targetNode->next = myNode;						//������
		targetNode->next->next = nullptr;
		++size;
	}
}

template<typename T>
inline void List<T>::remove(size_t theIndex)	//ɾ��theIndex��һ�����
{
	if (head != nullptr)	//����Ϊ��
	{
		if (theIndex > size)		//ɾ��λ�ô���������
		{
			std::cout << "λ����Ч��ӦС��" << size << std::endl;
			return;
		}
		if (theIndex == 0)		//ɾ��λ��Ϊ0ʱ��ɾ��ͷ���
		{
			ListNode<T>* tempNode;
			tempNode = head->next;
			delete head;
			head = tempNode;
			--size;
		}
		ListNode<T>* targetNode = head;
		for (size_t i = 1;i < theIndex;++i)		//�ҵ�����λ�ý��
		{
			targetNode = targetNode->next;
		}
		ListNode<T>* temp = targetNode->next->next;	//�������λ�ú�һ�������Ϣ
		delete targetNode->next;
		targetNode->next = temp;
		--size;
	}
	else
	{
		std::cout << "����Ϊ��" << std::endl;
		return;
	}
}

template<typename T>
inline void List<T>::output(std::ostream & os)	//��ӡ��������Ԫ��
{
	if (head == nullptr)
	{
		os << "����Ϊ��" << std::endl;
	}
	else
	{
		ListNode<T>* targetNode = head;		//����ָ��
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
	if (head == nullptr)		//����Ϊ�գ�����0
	{
		std::cout << "����Ϊ��" << std::endl;
		return 0;
	}
	ListNode<T>* targetNode = head;			//����ָ��
	for(size_t i=1;targetNode != nullptr;++i)
	{
		if (targetNode->data == value)		//�ҵ�Ԫ�أ�����λ��
			return i;
		targetNode = targetNode->next;
	}
	if (targetNode == nullptr)		//��������β����δ�ҵ�Ԫ��
	{
		std::cout << "δ�ҵ�Ԫ��" << value<<std::endl;
		return 0;
	}
}

template<typename T>
inline void List<T>::operator=(const List & list)	//��ֵ���캯��
{
	if (list.head == nullptr)		//����Ϊ��
	{
		head = nullptr;
		size = 0;
	}
	else
	{
		head = new ListNode<T>(list.head->data);		//����һ���������ͷ���
		ListNode<T>* sourceNode = list.head->next;		//���ڱ���Դ�����ָ��
		ListNode<T>* targetNode = head;					//�������λ��ָ��
		while (sourceNode != nullptr)
		{
			targetNode->next = new ListNode<T>(sourceNode->data);	//�����µĽ����뵽��������
			targetNode = targetNode->next;		//������λ��ָ�����
			sourceNode = sourceNode->next;		//Դ����λ��ָ�����
		}
		targetNode->next = nullptr;
		size = list.Size();
	}
}

template<typename T>
inline T& List<T>::operator[](const size_t theIndex)	//�����±�����,���ܴ�������Ϊ�յ����
{
	if (head != nullptr)	//����Ϊ��
	{
		if (theIndex < 0 || theIndex > size)	//����±��Ƿ�Խ��
		{
			std::cout << "λ����Ч��Ӧ���ڵ���0С�ڵ���" << size << std::endl;
			return head->data;
		}
		ListNode<T>* targetNode = head;
		for (size_t i = 0;i<theIndex;++i)	//��ȡ�±�λ�ý��
		{
			targetNode = targetNode->next;
		}
		return targetNode->data;
	}
	/*else
	{
		std::cout << "����Ϊ��" << std::endl;
		return;
	}*/
}

#endif // !LIST_H_