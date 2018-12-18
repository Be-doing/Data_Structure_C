#pragma once
typedef int BTDataType;
typedef struct BinaryTree
{
	BTDataType data;
	struct Binary* left;
	struct Binary* right;
}BTnode;

//����������
BTnode* BinaryTreeCreate(BTDataType* arr, int size, BTDataType* root);

//������������
void BinaryTreeDestroy(BTnode* root);

//Ҷ�ӵĶ�
int BinaryTreeLeafSize(BTnode* root);

//���ҽ��
BTnode* BinaryTreeFindNode(BTnode* root, BTDataType data);

//ǰ�к����

//�ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTnode* root);