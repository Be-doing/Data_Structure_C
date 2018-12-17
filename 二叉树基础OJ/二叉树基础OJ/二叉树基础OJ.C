

#include<stdlib.h>
typedef struct BinaryTree
{
	int data;
	struct BinaryTree* left;
	struct BinaryTree* right;
}Btree;
//前中后序遍历
void front_tra(Btree* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ",root->data);
	front_tra(root->left);
	front_tra(root->right);
}
void mid_tra(Btree* root)
{
	if (root == NULL)
	{
		return;
	}
	
	front_tra(root->left);
	printf("%d ", root->data);
	front_tra(root->right);
}
void end_tra(Btree* root)
{
	if (root == NULL)
	{
		return;
	}
	front_tra(root->left);
	front_tra(root->right);
	printf("%d ", root->data);
}
//检查两棵树是否相同
int judge_same(Btree* root1, Btree* root2)
{
	if ((root1 == NULL) && (root2 == NULL))
	{
		return 1;
	}
	if ((root1 == NULL) || (root2 == NULL))
	{
		return 0;
	}
	return (root1->data == root2->data) &&
		judge_same(root1->left, root2->left) &&
		judge_same(root1->right, root2->right);
}
//对称二叉树
int judge_sym(Btree* root1, Btree* root2)
{
	if ((root1 == NULL) && (root2 == NULL))
	{
		return 1;
	}
	if ((root1 == NULL) || (root2 == NULL))
	{
		return 0;
	}
	return (root1->data == root2->data) &&
		judge_sym(root1->left, root2->right) &&
		judge_sym(root1->right, root2->left);
}