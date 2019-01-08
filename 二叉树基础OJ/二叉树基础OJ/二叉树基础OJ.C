

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
int judge_sam(Btree* root1, Btree* root2)
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
//二叉树的高度
int GetHeight(Btree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int l = GetHeight(root->left);
	int r = GetHeight(root->right);
	if (l > r)
	{
		return l + 1;
	}
	else
	{
		return r + 1;
	}
}
//平衡二叉树
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

int isBalanced(Btree* root) {
		if (root == NULL )
		{
			return 1;
		}
		int l = GetHeight(root->left);
		int r = GetHeight(root->right);
		if ( -1 <=(l - r) <= 1)
		{
			return 1;
		}
		return 0;
}

//建二叉树
//接口结构体
typedef struct MyStruct
{
	Btree* node;
	int used;
}MyStruct;
MyStruct CreateTree(char arr[], int size)
{
	Btree* tree = (Btree*)malloc(sizeof(Btree));

}