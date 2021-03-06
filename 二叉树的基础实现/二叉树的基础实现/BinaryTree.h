#pragma once
typedef char BTDataType;
typedef struct BinaryTree
{
	BTDataType data;
	struct BinaryTree* left;
	struct BinaryTree* right;
}BTnode;

//构建二叉树
BTnode* BinaryTreeCreate(BTDataType* arr, int size, int* sign);

//二叉树的销毁
void BinaryTreeDestroy(BTnode* root);

//结点个数
int BinaryTreeSize(BTnode* root);

//叶子的个数
int BinaryTreeLeafSize(BTnode* root);

//第K层叶子结点的个数
int BinaryTreeLevelKSize(BTnode* root, int k);

//查找结点
BTnode* BinaryTreeFindNode(BTnode* root, BTDataType data);

//前中后遍历
void BinaryTreePrevorder(BTnode* root);
void BinaryTreeInorder(BTnode* root);
void BinaryTreePostorder(BTnode* root);

//非递归操作
//层序遍历
void BinaryTreeLevelorder(BTnode* root);

//判断二叉树是否是完全二叉树
char* BinaryTreeComplete(BTnode* root);

//前中后序遍历
void BinaryTreePrevOrderNonP(BTnode* root);
void BinaryTreeInOrderNonP(BTnode* root);
void BinaryTreePostOrderNonP(BTnode* root);