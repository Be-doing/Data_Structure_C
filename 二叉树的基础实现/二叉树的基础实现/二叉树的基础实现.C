#include"BinaryTree.h"
#include<assert.h>
//构建二叉树
BTnode* BinaryTreeCreate(BTDataType* arr, int size, int sign)
{
	assert(arr);
	if (arr[sign] == '#')
	{
		return;
	}
	BTnode* node = (BTnode*)malloc(sizeof(BTnode));
	node->data = arr[sign];
	++sign;
	node->left = BinaryTreeCreate(arr, size, sign);
	++sign;
	node->right = BinaryTreeCreate(arr, size, sign);
	return node;
}

//二叉树的销毁
void BinaryTreeDestroy(BTnode* root);

//叶子的度
int BinaryTreeLeafSize(BTnode* root);

//查找结点
BTnode* BinaryTreeFindNode(BTnode* root, BTDataType data);

//前中后遍历
void BinaryTreePrevorder(BTnode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	BinaryTreePrevorder(root->left);
	BinaryTreePrevorder(root->right);
}
void BinaryTreeInorder(BTnode* root)
{
	if (root == NULL)
	{
		return;
	}

	BinaryTreeInorder(root->left);
	printf("%d ", root->data);
	BinaryTreeInorder(root->right);
}
void BinaryTreePostorder(BTnode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePostorder(root->left);
	BinaryTreePostorder(root->right);
	printf("%d ", root->data);
}
//判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTnode* root);