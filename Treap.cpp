#include <iostream>
using namespace std;

struct TreapNode
{
	int key, priority;
	TreapNode* left, * right;
};

//xoay phải
TreapNode* rightRotate(TreapNode* y)
{
	TreapNode* x = y->left, * T2 = x->right;
	x->right = y;
	y->left = T2;
	return x;
}
//xoay trái
TreapNode* leftRotate(TreapNode* x)
{
	TreapNode* y = x->right, * T2 = y->left;
	y->left = x;
	x->right = T2;
	return y;
}
//tạo nút
TreapNode* newNode(int key)
{
	TreapNode* temp = new TreapNode;
	temp->key = key;
	temp->priority = rand() % 100;
	temp->left = temp->right = NULL;
	return temp;
}
//tìm nút
TreapNode* search(TreapNode* root, int key)
{
	if (root == NULL || root->key == key)
		return root;
	if (root->key < key)
		return search(root->right, key);
	return search(root->left, key);
}

//thêm nút
TreapNode* insert(TreapNode* root, int key)
{
	if (!root)
		return newNode(key);

	if (key <= root->key)
	{
		root->left = insert(root->left, key);
		if (root->left->priority > root->priority)
			root = rightRotate(root);
	}
	else
	{
		root->right = insert(root->right, key);
		if (root->right->priority > root->priority)
			root = leftRotate(root);
	}
	return root;
}
//xóa nút
TreapNode* deleteNode(TreapNode* root, int key)
{
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);


	else if (root->left == NULL)
	{
		TreapNode* temp = root->right;
		delete(root);
		root = temp;
	}


	else if (root->right == NULL)
	{
		TreapNode* temp = root->left;
		delete(root);
		root = temp;
	}

	else if (root->left->priority < root->right->priority)
	{
		root = leftRotate(root);
		root->left = deleteNode(root->left, key);
	}
	else
	{
		root = rightRotate(root);
		root->right = deleteNode(root->right, key);
	}

	return root;
}
//duyệt treap
void inorder(TreapNode* root)
{
	if (root)
	{
		inorder(root->left);
		cout << "key: " << root->key << " | priority: %d "
			<< root->priority;
		if (root->left)
			cout << " | left child: " << root->left->key;
		if (root->right)
			cout << " | right child: " << root->right->key;
		cout << endl;
		inorder(root->right);
	}
}


int main()
{
	int x;
	srand(time(NULL));

	struct TreapNode* root = NULL;
	cout << "Nhap cac nut can them vao. Nhap -1 de dung.\n";
	do {
		cin >> x;
		if (x != -1)
			root = insert(root, x);
	} while (x != -1);

	inorder(root);

	cout << "Nhap cac nut can xoa. Nhap -1 de dung.\n";
	do {
		cin >> x;
		if (x != -1)
			root = deleteNode(root, x);
	} while (x != -1);
	inorder(root);
	cout << "Nhap nut can tim: ";
	cin >> x;
	TreapNode* res = search(root, x);
	(res == NULL) ? cout << x << " Not Found " :
		cout << x << " found";

	return 0;
}
