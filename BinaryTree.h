#pragma once
#ifndef BINARYTRR_H_
#define BINARYTRR_H_

#include"BinaryTreeNode.h"
#include<stack>
#include<queue>

template<typename T>
class BinaryTree
{
public:
	BinaryTreeNode<T>* root;
//public:
	BinaryTree();
	BinaryTree(const T& value);			//构造一个根结点
	BinaryTree(BinaryTree<T>& bt);	//复制构造函数
	~BinaryTree();					//析构函数
	//search(T& value);			//查找元素
	void visit(BinaryTreeNode<T>* r);		//访问并打印结点数据
	void preOrder(BinaryTreeNode<T>* r);	//前序遍历
	void inOrder(BinaryTreeNode<T>* r);		//中序遍历
	void postOrder(BinaryTreeNode<T>* r);	//后序遍历
	void iterativePreOrder();	//非递归前序遍历
	void levelOrder(BinaryTreeNode<T>* r);	//层次遍历
	void insert(const T& value);			//插入
};

template<typename T>
inline BinaryTree<T>::BinaryTree()
{
	
}

template<typename T>
inline BinaryTree<T>::BinaryTree(const T & value)
{
	root = new BinaryTreeNode<T>(value);
	//root->data = value;
	root->left = nullptr;
	root->right = nullptr;
}

template<typename T>
inline BinaryTree<T>::BinaryTree(BinaryTree<T>& bt)
{
}

template<typename T>
inline BinaryTree<T>::~BinaryTree()
{
}

template<typename T>
inline void BinaryTree<T>::visit(BinaryTreeNode<T>* r)		//访问并打印结点数据
{
	std::cout << r->data << std::endl;
}

template<typename T>
inline void BinaryTree<T>::preOrder(BinaryTreeNode<T>* r)	//前序遍历
{
	if (r != nullptr)
	{
		visit(r);
		preOrder(r->left);
		preOrder(r->right);
	}
}

template<typename T>
inline void BinaryTree<T>::inOrder(BinaryTreeNode<T>* r)	//中序遍历
{
	if (r != nullptr)
	{
		inOrder(r->left);
		visit(r);
		inOrder(r->right);
	}
}

template<typename T>
inline void BinaryTree<T>::postOrder(BinaryTreeNode<T>* r)	//后序遍历
{
	if (r != nullptr)
	{
		postOrder(r->left);
		postOrder(r->right);
		visit(r);
	}
}

template<typename T>
inline void BinaryTree<T>::iterativePreOrder()	//非递归前序遍历
{
#ifndef MYSTACK_H_	//使用标准库的stack
	std::stack<BinaryTreeNode<T>*> my_stack;
	BinaryTreeNode<T>* p;
	if (root != nullptr)
	{
		my_stack.push(root);
		while (!my_stack.empty())
		{
			p = my_stack.top();
			visit(p);
			my_stack.pop();
			if (p->right != nullptr)
				my_stack.push(p->right);
			if (p->left != nullptr)
				my_stack.push(p->left);
		}
	}
#endif // !MYSTACK_H_
}

template<typename T>
inline void BinaryTree<T>::levelOrder(BinaryTreeNode<T>* r)		//层次遍历
{
	std::queue<BinaryTreeNode<T>*> my_queue;
	BinaryTreeNode<T>* p = r;
	if (r != nullptr)
	{
		my_queue.push(r);
		while (!my_queue.empty())
		{
			p = my_queue.front();
			visit(p);
			if (p->left != nullptr)
				my_queue.push(p->left);
			if (p->right != nullptr)
				my_queue.push(p->right);
			my_queue.pop();			
		}
	}
}

template<typename T>
inline void BinaryTree<T>::insert(const T& value)
{
	BinaryTreeNode<T>* target = root;
	BinaryTreeNode<T>* prev = root;
	if (root == nullptr)
	{
		root = new BinaryTreeNode<T>(value);
		root->left = nullptr;
		root->right = nullptr;
	}
	else
	{
		while (target != nullptr)
		{
			prev = target;
			if (target->data >= value)
			{
				target = target->left;
			}
			else
			{
				target = target->right;
			}
		}
		if (prev->data >= value)
			prev->left = new BinaryTreeNode<T>(value);
		else
			prev->right = new BinaryTreeNode<T>(value);
	}
}

#endif // !BINARYTRR_H_