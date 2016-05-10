#include <iostream>
#include "BinaryTree.h"


using namespace std;

int main()
{
	BinaryTree<int> tree;

	tree.insert(23);
	tree.insert(54);
	tree.insert(31);
	tree.insert(10);
	tree.insert(75);
	tree.insert(2);

	cout<<"Inorder: ";
	tree.inorder();
	cout<<endl;

	cout<<"Preorder: ";
	tree.preorder();
	cout<<endl;

	cout<<"Postorder: ";
	tree.postorder();
	cout<<endl;


	if(tree.search(75))
	{
		cout<<"Key exists."<<endl;
	}
	else cout<<"Key doesn't exist."<<endl;

	tree.remove(75);
	cout<<"After remove: "<<endl;
	if(tree.search(75))
	{
		cout<<"Key still exists."<<endl;
	}
	else cout<<"Key doesn't exist anymore."<<endl;

}