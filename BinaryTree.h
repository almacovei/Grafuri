#ifndef _BinaryTREE_
#define _BinaryTREE_

#include <iostream>

using namespace std;

template < typename T >
struct Node
{
	T info;
	Node *left, *right;

	Node()
	{
		info = 0;
		left = right = NULL;
	}

	Node(const T& info)
	{
		this -> info = info;
		this->left = NULL;
		this->right = NULL;
	}
};

template < typename T >
class BinaryTree
{
	private:
		Node<T> *leaf;

	void insertNode( const T& info, Node<T>* &leaf)
	{
		if(leaf == NULL)
		{
			leaf = new Node<T>(info);
		}

		if( leaf->info > info)
		{
			insertNode(info, leaf->left);
		}
		else
			if( leaf->info < info)
			{
				insertNode(info, leaf->right);
			}
	}

	void deleteNode(Node<T>* leaf)
	{
		if (leaf != NULL )
		{
			deleteNode(leaf->left);
			deleteNode(leaf->right);
			delete leaf;
		}
	}

	Node<T>* findKey(const T& info, Node<T>* leaf)
	{
		if (leaf == NULL)
		{
			return leaf;
		}

		if (leaf->info == info)
		{
			return leaf;
		}

		if (info < leaf->info)
		{
			return findKey(info, leaf->left);
		}

		if (info > leaf->info)
		{
			return findKey(info, leaf->right);
		}
	}

	void preOrder(Node<T> *leaf)
	{
		if(leaf)
		{
			cout<<leaf->info<<" ";
			preOrder(leaf->left);
			preOrder(leaf->right);
		}
	}

	void inOrder(Node<T> *leaf)
	{
		if(leaf)
		{
			inOrder(leaf->left);
			cout<<leaf->info<<" ";
			inOrder(leaf->right);
		}
	}

	void postOrder(Node<T> *leaf)
	{
		if(leaf)
		{
			postOrder(leaf->left);
			postOrder(leaf->right);
			cout<<leaf->info<<" ";
		}
	}

	void print(Node<T> *leaf)
	{
		if(!leaf)
			return NULL;
		print(leaf->left);
		cout<<leaf->info<<" ";
		print(leaf->right);
	}

	public:

	BinaryTree()
	{
		leaf = NULL;
	}
	~BinaryTree()
	{
		deleteNode(leaf);
	}

	void insert(const T& info)
	{
		insertNode(info, leaf);
	}

	void remove(const T& info)
	{
		deleteNode(leaf);
	}

	void inorder()
	{
		inOrder(leaf);
	}

	void preorder()
	{
		preOrder(leaf);
	}

	void postorder()
	{
		postOrder(leaf);
	}

	bool search(const T& info)
	{
		findKey(info, leaf);
	}

	Node<T>* getNode()
	{
		return leaf;
	}

};

#endif // _BinaryTREE_