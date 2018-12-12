

#include<stdlib.h>
typedef struct BinaryTree
{
	int arr;
	struct BinaryTree* left;
	struct BinaryTree* right;
}Btree;

void front_tra(Btree* root)
{
	if (root == NULL)
	{
		printf("нч\n");
	}
	printf("%d ",root->arr);
	front_tra(root->left);
	front_tra(root->right);
}
void mid_tra(Btree* root)
{
	if (root == NULL)
	{
		printf("нч\n");
	}
	
	front_tra(root->left);
	printf("%d ", root->arr);
	front_tra(root->right);
}
void end_tra(Btree* root)
{
	if (root == NULL)
	{
		printf("нч\n");
	}
	front_tra(root->left);
	front_tra(root->right);
	printf("%d ", root->arr);
}