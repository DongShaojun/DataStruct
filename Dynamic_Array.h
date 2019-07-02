/****************************
动态数组的实现
version：1.0	2019.6.20
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
	size_t capacity;	//数组容量
	size_t size;		//数组存储数据数量
	void checkIndex(size_t theIndex) const;	//数组索引检查
public:
	Dynamic_Array();
	Dynamic_Array(size_t n);
	Dynamic_Array(const Dynamic_Array<T> &arr);	//复制构造函数
	~Dynamic_Array();
	bool empty() const;	//判断数组是否为空
	size_t Capacity() const;	//获取数组容量
	size_t Size() const;	//获取数组存储数据数量
	T& get(size_t location) const;	//获取元素
	void Push_Back(T value);	//数组尾部添加元素
	void Pop_Back();	//删除数组尾部元素
	void insert(size_t theIndex, const T &value);	//插入元素
	void erase(size_t theIndex);	//删除元素
	size_t IndexOf(const T &value) const;	//返回第一次出现value的位置
	void output(std::ostream &os) const;	//打印元素
	T &operator[](size_t index) const;		//重载下标运算
	T &operator=(Dynamic_Array &arr);		//赋值构造函数
};

template<typename T>
void Dynamic_Array<T>::checkIndex(size_t theIndex) const	//数组索引检查
{
	if (theIndex < 0 || theIndex >= size)
	{
		std::cout << "索引位置错误，应大于等于0，小于" << size << std::endl;
		return;
	}
}

template<typename T>
Dynamic_Array<T>::Dynamic_Array()	//构造函数，默认数组容量10
{
	capacity = 10;
	size = 0;
	data = new T[capacity];
}

template<typename T>
Dynamic_Array<T>::Dynamic_Array(size_t n)	//构造函数
{
	if (n < 1)
	{
		std::cout << "现在初始容量是" << n << ",必须大于0" << std::endl;
	}
	capacity = n;
	size = 0;
	data = new T[capacity];
}

template<typename T>
Dynamic_Array<T>::Dynamic_Array(const Dynamic_Array<T>& arr) //复制构造函数
{
	capacity = arr.capacity;
	data = new T[capacity];
	//复制数据
	for (size_t i=0;i < arr.size;++i)
	{
		data[i] = arr.data[i];
	}
	size = arr.size;
}

template<typename T>
Dynamic_Array<T>::~Dynamic_Array()	//析构函数
{
	delete[] data;
}

template<typename T>
bool Dynamic_Array<T>::empty() const	//判断是否为空
{
	if (size == 0)
		return false;
	else
		return true;
}

template<typename T>
size_t Dynamic_Array<T>::Capacity() const	//获取数组容量
{
	return capacity;
}

template<typename T>
size_t Dynamic_Array<T>::Size() const	//获取数组存储数据数量
{
	return size;
}

template<typename T>
T  &Dynamic_Array<T>::get(size_t location) const	//获取元素
{
	checkIndex(location);
	return data[location-1];
}

template<typename T>
void Dynamic_Array<T>::Push_Back(T value)	//在尾部插入元素
{
	if (size == capacity)	//数组容量已满，申请更大空间
	{
		capacity = 2 * capacity;
		T *temp = new T[capacity];
		for (size_t i = 0;i < size;++i)	//复制数据
		{
			temp[i] = data[i];
		}
		temp[size] = value;	//插入元素
		delete[]data;	
		data = temp;
		++size;
	}
	else
	{	//直接插入数据
		data[size] = value;
		++size;
	}
}

template<typename T>
void Dynamic_Array<T>::Pop_Back()	//删除尾部元素，尾部元素并没有析构，存在问题
{
	if (size != 0)
		--size;
}

template<typename T>
void Dynamic_Array<T>::insert(size_t theIndex,const T & value)	//插入元素
{
	if (theIndex < 0 || theIndex > size)
	{
		std::cout << "插入位置越界,应大于0，小于等于" << size << std::endl;
		return;
	}
	if (size == capacity)	//数组容量已满，申请更大空间
	{
		capacity = capacity * 2;
		T *temp = new T[capacity];
		for (size_t i = 0;i < theIndex-1;++i)	//把旧数组的插入位置前的元素拷贝到新数组
		{
			temp[i] = data[i];
		}
		temp[theIndex-1] = value;	//插入元素
		for (size_t i = theIndex-1;i < size;++i)	//把旧数组插入位置后的元素拷贝到新数组
		{
			temp[i+1] = data[i];
		}
		
		delete[]data;
		data = temp;
	}
	else
	{
		for (size_t i = size;i < theIndex;--i)	//数组元素右移
		{
			data[i] = data[i - 1];
		}
		data[theIndex] = value;
	}
	++size;
}

template<typename T>
void Dynamic_Array<T>::erase(size_t theIndex)	//删除元素，存在问题
{
	checkIndex(theIndex);
	for (size_t i = theIndex;i < size;++i)
	{
		data[i - 1] = data[i];
	}
	data[size - 1].~T();	//析构函数，但是不太明白如何运作
	--size;
}

template<typename T>
inline size_t Dynamic_Array<T>::IndexOf(const T & value) const	//返回第一次出现value的位置
{
	for (size_t i=0;i<size;++i)
	{
		if (data[i] == value)
			return i+1;
	}
	std::cout << "不存在元素::" << value << std::endl;
	return 0;
}

template<typename T>
void Dynamic_Array<T>::output(std::ostream & os) const	//打印数据
{
	for (size_t i=0;i < size;++i)
		os << data[i] << std::endl;
}

template<typename T>
inline T& Dynamic_Array<T>::operator[](size_t index) const	//重载下标运算
{
	return data[index];
}

template<typename T>
inline T & Dynamic_Array<T>::operator=(Dynamic_Array & arr)	//赋值构造函数
{
	capacity = arr.capacity;
	data = new T[capacity];
	//复制数据
	for (size_t i = 0;i < arr.size;++i)
	{
		data[i] = arr.data[i];
	}
	size = arr.size;
	return *this;
}

#endif // !DYNAMIC_ARRAY_H_


