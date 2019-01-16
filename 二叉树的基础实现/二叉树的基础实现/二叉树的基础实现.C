#include"BinaryTree.h"
#include"BTquene.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
//构建二叉树
BTnode* BinaryTreeCreate(BTDataType* arr, int size, int *sign)
{
	assert(arr);
	if (size == 0)
	{
		return NULL;
	}
	if (arr[*sign]== '#')
	{
		return NULL;
	}
	BTnode* node = (BTnode*)malloc(sizeof(BTnode));
	node->data = arr[*sign];
	++*sign;
	node->left = BinaryTreeCreate(arr , size,sign);
	++*sign;
	node->right = BinaryTreeCreate(arr, size,sign);

	return node;
}

//二叉树的销毁
void BinaryTreeDestroy(BTnode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);
	free(root);
	root = NULL;
}
//结点个数
int BinaryTreeSize(BTnode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
//叶子的个数
int BinaryTreeLeafSize(BTnode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root ->left) + BinaryTreeLeafSize(root ->right);
}

//第K层叶子结点的个数
int BinaryTreeLevelKSize(BTnode* root, int k)
{
	if (root == NULL || k <= 0)
	{
		return 0;
	}
	if (root != NULL && k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, k--) + BinaryTreeLevelKSize(root->right, k--);
}
//前中后遍历
void BinaryTreePrevorder(BTnode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->data);
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
	printf("%c ", root->data);
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
	printf("%c ", root->data);
}
//查找结点
BTnode* BinaryTreeFindNode(BTnode* root, BTDataType data)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == data)
	{
		return root;
	}
	BTnode* node = BinaryTreeFindNode(root->left, data);
	if (node == NULL)
	{
		BTnode* node2 = BinaryTreeFindNode(root->right, data);
		if (node2 == NULL)
		{
			return NULL;
		}
		else
		{
			return node2;
		}
	}
	else
	{
		return node;
	}
}

//非递归操作
BTqueue queue;
//层序遍历
void BinaryTreeLevelorder(BTnode* root)
{
	printf("非递归层序遍历：");
	if (root == NULL)
	{
		return;
	}
	btqueue_insert(&queue, root);
	//取首结点
	while (bt_empty(&queue))
	{
		BTnode* node = btqueue_front(&queue);
		printf("%c\t",node->data);
		btqueue_del(&queue);
		if (node->left)
		{
			btqueue_insert(&queue, node->left);
		}
		if (node->right)
		{
			btqueue_insert(&queue, node->right);
		}
	}
	printf("\n");
}
//判断二叉树是否是完全二叉树
//int BinaryTreeComplete(BTnode* root)
//{
//	if (root == NULL)
//	{
//		return 1;
//	}
//	BTnode* node = queue.front;
//	while (node)
//	{
//
//	}
//}

//前序非递归

/*
while(cur != NULL || stack)
{
	while(cur != NULL)
	{
	printf;
	stack_push();
	cur = cur->left;
	}
	top = stcak_top();
	stack_pop();
	cur = top->right;
}
*/
//后序遍历
/*while (cur != NULL || s.empty())
{
	while(cur != NULL)
	{
	push(cur)
	cur = cur->left
	}
	top = s.top;
	if(top == NULL)
	{
	print
	pop
	last = top;
	}
	else if(top->right == last)
	{
	print
	pop
	last = top
	}
	else
	{
	cur = top->right;
	}
}*/