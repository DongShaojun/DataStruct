#pragma once
#ifndef BINARYTREE_H_
#define BINARYTREE_H_

template<typename T>
class BinaryTreeNode	//二叉树结点类
{
public:
	T data;
	BinaryTreeNode<T>* left;
	BinaryTreeNode<T>* right;
//public:
	BinaryTreeNode();	
	BinaryTreeNode(const T& value);
	BinaryTreeNode(const T& value,BinaryTreeNode<T>*, BinaryTreeNode<T>*);
	//friend class BinaryTree;
};

template<typename T>
inline BinaryTreeNode<T>::BinaryTreeNode():left(nullptr),right(nullptr)
{
}

template<typename T>
inline BinaryTreeNode<T>::BinaryTreeNode(const T & value):data(value), left(nullptr), right(nullptr)
{

}

template<typename T>
inline BinaryTreeNode<T>::BinaryTreeNode(const T & value, BinaryTreeNode<T>* temp_left, BinaryTreeNode<T>* temp_right)
{
	data = value;
	left = temp_left;
	right = temp_right;
}

#endif // !BINARYTREE_H_