#include<iostream>
using namespace std;
template <class T>
class BSTnode
{
public:
	T info;
	BSTnode<T> *left;
	BSTnode<T> *right;
	BSTnode()
	{
		info = 0;
		left = right = NULL;
	}
};
template <class T>
class BST
{
public:
	BSTnode<T> *root;
	int lcount;
	int ncount;
	void insert(BSTnode<T>*, BSTnode<T>*);
	void preorder(BSTnode<T>*);
	void postorder(BSTnode<T>*);
	void inorder(BSTnode<T>*);
	void display(BSTnode<T>*, int);
	int maxH(BSTnode<T>*);
     void printlevelorder(BSTnode<T>*);
     void printGivenLevel(BSTnode<T>* , int);
	BST()
	{
		root = NULL;
		lcount = 0;
		ncount = 0;
	}
};
template <class T>
void BST<T>:: insert(BSTnode<T>* tree, BSTnode<T>* newnode)
{
	if (root == NULL)
	{
		root = newnode;
		return;
	}
	if (tree->info > newnode->info)
	{
		if (tree->left != NULL)
			insert(tree->left, newnode);
		else
			tree->left = newnode;
		return;
	}
	else
	{
		if (tree->right != NULL)
			insert(tree->right, newnode);
		else
			tree->right = newnode;
		return;
	}
}
template<class T>
void BST<T>::preorder(BSTnode<T>* n)
{
	if (root == NULL)
	{
		cout << "Tree is empty. Cannot Display...";
	}
	if (n != NULL)
	{
		cout << n->info << "	";
		preorder(n->left);
		preorder(n->right);
	}
}
template <class T>
void BST<T>:: postorder(BSTnode<T>* n)
{
	if (root == NULL)
	{
		cout << "Tree is empty. Cannot Display...";
	}
	if (n != NULL)
	{
		postorder(n->left);
		postorder(n->right);
		cout << n->info << "	";
	}
}
template <class T>
void BST<T>::inorder(BSTnode<T>* n)
{
	if (root == NULL)
	{
		cout << "Tree is empty. Cannot Display...";
	}
	if (n != NULL)
	{
		inorder(n->left);
		cout << n->info << "	";
		inorder(n->right);
	}
}
template <class T>
void BST<T>:: display(BSTnode<T>* ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr -> right, level + 1);
		cout << endl;
		if (ptr == root)
			cout << "Root->: ";
		else
		{
			for (i = 0;i < level;i++)
				cout << "	 ";
		}
		cout << ptr->info;
		display(ptr->left, level + 1);
	}
}
template <class T>
int BST<T>::maxH(BSTnode<T>* n)
{
	if (n == NULL)
		return 0;
	else
	{
		int lheight = maxH(n->left);
		int rheight = maxH(n->right);
		if (lheight > rheight)
			return lheight + 1;
		else
			return rheight + 1;
	}
}
template <class T>
void BST<T>::printlevelorder(BSTnode<T>* p)
{
    int h=maxH(root);
    int i;
    for(i=1; i<=h; i++)
       printGivenLevel(p,i);
}
template <class T>
void BST<T>::printGivenLevel(BSTnode<T>*p, int level)
{
   if(p==NULL)
   return;
   if(level==1)
     cout<<p->info<<" ";
   if(level>1)
   {
       printGivenLevel(p->left, level-1);
       printGivenLevel(p->right, level-1);
   }
}
int main()
{
	BST<int> b;
	int choice, h;
	BSTnode<int>* temp;
	int t;
	bool f;
	char ch;
	do
	{
		cout << "\nMenu:";
		cout << "\n 1.Insert";
		cout << "\n 2.Preorder";
		cout << "\n 3.Postorder";
		cout << "\n 4.Inorder";
		cout << "\n 5.Display";
		cout<<"\n 6. maximum height";
		cout<<"\n 7.traversal(top to bottom left to right)";
		cout << "\nEnter your choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			temp = new BSTnode<int>;
			cout << "\nEnter the info part for the node:";
			cin >> temp->info;
			b.insert(b.root, temp);
			break;
		case 2:
			cout << "\nPreorder traversal";
			b.preorder(b.root);
			break;
		case 3:
			cout << "\nPostorder traversal";
			b.postorder(b.root);
			break;
		case 4:
			cout << "\nInorder traversal";
			b.inorder(b.root);
			break;
		case 5:
			cout << "\nDisplaying elements";
			b.display(b.root, 1);
			break;

		case 6:
			h = b.maxH(b.root);
			cout << "Height of the tree is " << h;
			break;
        case 7: cout<<"Level by level traversal  ";
		        b.printlevelorder(b.root);
				cout<<endl;
				break;
		default:
			cout << "\nWrong Input";
		}
		cout << "\nDo you want to continue?(y/n)";
		cin >> ch;
	}
	 while(ch=='y'||ch=='Y');;
	return 0;
}
