#include "binarySearchTree.h"
#include "tree.h"
goingCount = 0;
BTreeNode* makeBTreeNode(ElementType data)
{
	BTreeNode* toMake = (BTreeNode*)malloc(sizeof(TreeNode));
	if (toMake == NULL)
	{
		sprintf_s(stderr, sizeof(__func__), "할당 실패! : %s", __func__);
		return NULL;
	}
	toMake->key = data;
	toMake->left = NULL;
	toMake->right = NULL;
	return toMake;
}
BTree* makeBTree(ElementType data)
{
	return makeBTreeNode(data);
}

int isTerminalNode(BTreeNode* node)
{
	return (node->left == NULL && node->right == NULL);
}
void initGoingCount()
{
	goingCount = 0;
}

int getGoingCount()
{
	return goingCount;
}
BTreeNode* goLeft(BTreeNode* current)
{
	goingCount += 1;
	return current->left;
}
BTreeNode* goRight(BTreeNode* current)
{
	goingCount += 1;
	return current->right;
}
BTreeNode* searchBTree(BTreeNode *node, ElementType key)
{
	while (node != NULL)
	{
		if (key == node->key)
			return node;
		else if (key < node->key)
			node = goLeft(node);
		else
			node = goRight(node);
	}
	return NULL; // 실패
}

BTree* insertBTree(BTreeNode** root, ElementType key)
{
	BTreeNode *parent, *temp;
	BTreeNode *toInsert;
	initGoingCount();
	temp = *root;
	parent = NULL;
	while (temp != NULL)
	{
		if (key == temp->key) // 이미 존재하면 추가하지 않고 그대로 반환.
			return *root;	  // 존재한다면 오른쪽 노드를 한번 타서 그대로 왼쪽이 NULL일 떄까지 들어가서 할당하면 될 듯함.
		parent = temp;
		if (key < parent->key)
			temp = goLeft(parent);
		else
			temp = goRight(parent);
	}
	toInsert = makeBTreeNode(key);
	if (parent != NULL)
		if (key < parent->key)
			parent->left = toInsert;
		else parent->right = toInsert;
	else *root = toInsert;
	printf("삽입 시 방문 횟수 : %d\n", getGoingCount());
	return *root; // root가 그대로거나 toInsert임.
}
BTreeNode* deleteBTree(BTreeNode **root, ElementType key)
{
	BTreeNode *parent, *child, *successor, *succesorParent, *temp;
	parent = NULL;
	temp = *root;
	while (temp != NULL && temp->key != key)
	{
		parent = temp;
		if (key < parent->key)
			temp = parent->left;
		else
			temp = parent->right;
	}
	if (temp == NULL)
		return *root;
	else if (isTerminalNode(temp))
	{
		if (parent != NULL)
		{
			if (parent->left == temp)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else
			*root = NULL;
	}
	else if ((temp->left == NULL) || (temp->right == NULL))
	{
		child = (temp->left != NULL) ? temp->left : temp->right;
		if (parent != NULL)
			if (parent->left == temp)
				parent->left = child;
			else
				parent->right = child;
		else
			*root = child;
	}
	else
	{
		succesorParent = temp;
		successor = temp->right;
		while (successor->left != NULL)
		{
			succesorParent = successor;
			successor = successor->left;
		}
		if (succesorParent->left == successor)
			succesorParent->left = successor->right;
		else
			succesorParent->right = successor->right;
		temp->key = successor->key;
		temp = successor;
	}
	free(temp);
	return *root;
}
void printBTreeNode(BTreeNode* root)
{
	goingCount++;
	printf("%d ", root->key);
}
void printBTree(BTree* head)
{
	if (head == NULL)
		return;
	inorder((TreeNode*)head, printBTreeNode);
}
