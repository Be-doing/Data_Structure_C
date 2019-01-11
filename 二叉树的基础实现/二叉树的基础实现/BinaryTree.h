#pragma once
typedef char BTDataType;
typedef struct BinaryTree
{
	BTDataType data;
	struct BinaryTree* left;
	struct BinaryTree* right;
}BTnode;

//����������
BTnode* BinaryTreeCreate(BTDataType* arr, int size, int* sign);

//������������
void BinaryTreeDestroy(BTnode* root);

//������
int BinaryTreeSize(BTnode* root);

//Ҷ�ӵĸ���
int BinaryTreeLeafSize(BTnode* root);

//��K��Ҷ�ӽ��ĸ���
int BinaryTreeLevelKSize(BTnode* root, int k);

//���ҽ��
BTnode* BinaryTreeFindNode(BTnode* root, BTDataType data);

//ǰ�к����
void BinaryTreePrevorder(BTnode* root);
void BinaryTreeInorder(BTnode* root);
void BinaryTreePostorder(BTnode* root);
//�ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTnode* root);