#pragma once
typedef int BTDataType;
typedef struct BinaryTree
{
	BTDataType data;
	struct Binary* left;
	struct Binary* right;
}BTnode;

//构建二叉树
BTnode* BinaryTreeCreate(BTDataType* arr, int size, BTDataType* root);

//二叉树的销毁
void BinaryTreeDestroy(BTnode* root);

//叶子的度
int BinaryTreeLeafSize(BTnode* root);

//查找结点
BTnode* BinaryTreeFindNode(BTnode* root, BTDataType data);

//前中后遍历

//判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTnode* root);