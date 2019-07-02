/****************************
��̬�����ʵ��
version��1.0	2019.6.20
****************************/

#pragma once
#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_

#include<iostream>

template<typename T>
class Dynamic_Array
{
private:
	T *data;
	size_t capacity;	//��������
	size_t size;		//����洢��������
	void checkIndex(size_t theIndex) const;	//�����������
public:
	Dynamic_Array();
	Dynamic_Array(size_t n);
	Dynamic_Array(const Dynamic_Array<T> &arr);	//���ƹ��캯��
	~Dynamic_Array();
	bool empty() const;	//�ж������Ƿ�Ϊ��
	size_t Capacity() const;	//��ȡ��������
	size_t Size() const;	//��ȡ����洢��������
	T& get(size_t location) const;	//��ȡԪ��
	void Push_Back(T value);	//����β�����Ԫ��
	void Pop_Back();	//ɾ������β��Ԫ��
	void insert(size_t theIndex, const T &value);	//����Ԫ��
	void erase(size_t theIndex);	//ɾ��Ԫ��
	size_t IndexOf(const T &value) const;	//���ص�һ�γ���value��λ��
	void output(std::ostream &os) const;	//��ӡԪ��
	T &operator[](size_t index) const;		//�����±�����
	T &operator=(Dynamic_Array &arr);		//��ֵ���캯��
};

template<typename T>
void Dynamic_Array<T>::checkIndex(size_t theIndex) const	//�����������
{
	if (theIndex < 0 || theIndex >= size)
	{
		std::cout << "����λ�ô���Ӧ���ڵ���0��С��" << size << std::endl;
		return;
	}
}

template<typename T>
Dynamic_Array<T>::Dynamic_Array()	//���캯����Ĭ����������10
{
	capacity = 10;
	size = 0;
	data = new T[capacity];
}

template<typename T>
Dynamic_Array<T>::Dynamic_Array(size_t n)	//���캯��
{
	if (n < 1)
	{
		std::cout << "���ڳ�ʼ������" << n << ",�������0" << std::endl;
	}
	capacity = n;
	size = 0;
	data = new T[capacity];
}

template<typename T>
Dynamic_Array<T>::Dynamic_Array(const Dynamic_Array<T>& arr) //���ƹ��캯��
{
	capacity = arr.capacity;
	data = new T[capacity];
	//��������
	for (size_t i=0;i < arr.size;++i)
	{
		data[i] = arr.data[i];
	}
	size = arr.size;
}

template<typename T>
Dynamic_Array<T>::~Dynamic_Array()	//��������
{
	delete[] data;
}

template<typename T>
bool Dynamic_Array<T>::empty() const	//�ж��Ƿ�Ϊ��
{
	if (size == 0)
		return false;
	else
		return true;
}

template<typename T>
size_t Dynamic_Array<T>::Capacity() const	//��ȡ��������
{
	return capacity;
}

template<typename T>
size_t Dynamic_Array<T>::Size() const	//��ȡ����洢��������
{
	return size;
}

template<typename T>
T  &Dynamic_Array<T>::get(size_t location) const	//��ȡԪ��
{
	checkIndex(location);
	return data[location-1];
}

template<typename T>
void Dynamic_Array<T>::Push_Back(T value)	//��β������Ԫ��
{
	if (size == capacity)	//���������������������ռ�
	{
		capacity = 2 * capacity;
		T *temp = new T[capacity];
		for (size_t i = 0;i < size;++i)	//��������
		{
			temp[i] = data[i];
		}
		temp[size] = value;	//����Ԫ��
		delete[]data;	
		data = temp;
		++size;
	}
	else
	{	//ֱ�Ӳ�������
		data[size] = value;
		++size;
	}
}

template<typename T>
void Dynamic_Array<T>::Pop_Back()	//ɾ��β��Ԫ�أ�β��Ԫ�ز�û����������������
{
	if (size != 0)
		--size;
}

template<typename T>
void Dynamic_Array<T>::insert(size_t theIndex,const T & value)	//����Ԫ��
{
	if (theIndex < 0 || theIndex > size)
	{
		std::cout << "����λ��Խ��,Ӧ����0��С�ڵ���" << size << std::endl;
		return;
	}
	if (size == capacity)	//���������������������ռ�
	{
		capacity = capacity * 2;
		T *temp = new T[capacity];
		for (size_t i = 0;i < theIndex-1;++i)	//�Ѿ�����Ĳ���λ��ǰ��Ԫ�ؿ�����������
		{
			temp[i] = data[i];
		}
		temp[theIndex-1] = value;	//����Ԫ��
		for (size_t i = theIndex-1;i < size;++i)	//�Ѿ��������λ�ú��Ԫ�ؿ�����������
		{
			temp[i+1] = data[i];
		}
		
		delete[]data;
		data = temp;
	}
	else
	{
		for (size_t i = size;i < theIndex;--i)	//����Ԫ������
		{
			data[i] = data[i - 1];
		}
		data[theIndex] = value;
	}
	++size;
}

template<typename T>
void Dynamic_Array<T>::erase(size_t theIndex)	//ɾ��Ԫ�أ���������
{
	checkIndex(theIndex);
	for (size_t i = theIndex;i < size;++i)
	{
		data[i - 1] = data[i];
	}
	data[size - 1].~T();	//�������������ǲ�̫�����������
	--size;
}

template<typename T>
inline size_t Dynamic_Array<T>::IndexOf(const T & value) const	//���ص�һ�γ���value��λ��
{
	for (size_t i=0;i<size;++i)
	{
		if (data[i] == value)
			return i+1;
	}
	std::cout << "������Ԫ��::" << value << std::endl;
	return 0;
}

template<typename T>
void Dynamic_Array<T>::output(std::ostream & os) const	//��ӡ����
{
	for (size_t i=0;i < size;++i)
		os << data[i] << std::endl;
}

template<typename T>
inline T& Dynamic_Array<T>::operator[](size_t index) const	//�����±�����
{
	return data[index];
}

template<typename T>
inline T & Dynamic_Array<T>::operator=(Dynamic_Array & arr)	//��ֵ���캯��
{
	capacity = arr.capacity;
	data = new T[capacity];
	//��������
	for (size_t i = 0;i < arr.size;++i)
	{
		data[i] = arr.data[i];
	}
	size = arr.size;
	return *this;
}

#endif // !DYNAMIC_ARRAY_H_


