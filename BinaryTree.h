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
	BinaryTree(const T& value);			//����һ�������
	BinaryTree(BinaryTree<T>& bt);	//���ƹ��캯��
	~BinaryTree();					//��������
	//search(T& value);			//����Ԫ��
	void visit(BinaryTreeNode<T>* r);		//���ʲ���ӡ�������
	void preOrder(BinaryTreeNode<T>* r);	//ǰ�����
	void inOrder(BinaryTreeNode<T>* r);		//�������
	void postOrder(BinaryTreeNode<T>* r);	//�������
	void iterativePreOrder();	//�ǵݹ�ǰ�����
	void levelOrder(BinaryTreeNode<T>* r);	//��α���
	void insert(const T& value);			//����
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
inline void BinaryTree<T>::visit(BinaryTreeNode<T>* r)		//���ʲ���ӡ�������
{
	std::cout << r->data << std::endl;
}

template<typename T>
inline void BinaryTree<T>::preOrder(BinaryTreeNode<T>* r)	//ǰ�����
{
	if (r != nullptr)
	{
		visit(r);
		preOrder(r->left);
		preOrder(r->right);
	}
}

template<typename T>
inline void BinaryTree<T>::inOrder(BinaryTreeNode<T>* r)	//�������
{
	if (r != nullptr)
	{
		inOrder(r->left);
		visit(r);
		inOrder(r->right);
	}
}

template<typename T>
inline void BinaryTree<T>::postOrder(BinaryTreeNode<T>* r)	//�������
{
	if (r != nullptr)
	{
		postOrder(r->left);
		postOrder(r->right);
		visit(r);
	}
}

template<typename T>
inline void BinaryTree<T>::iterativePreOrder()	//�ǵݹ�ǰ�����
{
#ifndef MYSTACK_H_	//ʹ�ñ�׼���stack
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
inline void BinaryTree<T>::levelOrder(BinaryTreeNode<T>* r)		//��α���
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