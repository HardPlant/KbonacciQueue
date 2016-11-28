#include "MaxHeap.h"
#include <stdio.h>
#include <stdlib.h>
MaxHeap* makeMaxHeap()
{
	MaxHeap* toMake = (MaxHeap*)malloc(sizeof(MaxHeap));
	toMake->heap_size = 0;
	return toMake;
}
void insertMaxHeap(MaxHeap *head, MHelement item)
{
	int i;
	i = ++(head->heap_size);
	while ((i != 1) && (item.key > head->heap[i / 2].key))
	{
		head->heap[i] = head->heap[i / 2];
		i /= 2;
	}
	head->heap[i] = item;
}
void insertMaxHeapInt(MaxHeap *head, int data)
{
	MHelement item;
	item.key = data;
	insertMaxHeap(head, item);
}
MHelement deleteMaxHeap(MaxHeap *head)
{
	int parent, child;
	MHelement item, temp;
	item = head->heap[1];
	temp = head->heap[(head->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= head->heap_size)
	{
		if ((child < head->heap_size)
			&& (head->heap[child].key) < head->heap[child + 1].key)
			child++;
		if (temp.key >= head->heap[child].key)
			break;
		head->heap[parent] = head->heap[child];
		parent = child;
		child *= 2;
	}
	head->heap[parent] = temp;
	return item;
}
KeyType searchMaxHeap(MaxHeap *head, KeyType key)
{
	int left, right, current;
	current = 1;
	while (head->heap[current].key != key)
	{
		left = MHgoLeft(current);
		right = MHgoRight(current);
		if (head->heap[left].key == 0 && head->heap[right].key == 0) // �ܸ� ��� ����
		{
			fprintf(stderr, "ã�� �� ����\n");
			return -1;
		}

		if (head->heap[left].key < key && head->heap[right].key < key) // Ű�� ���� ��尪�� �ƴϰ� �ڽ� ���麸�� Ŭ ��� ����
		{
			fprintf(stderr, "ã�� �� ����\n");
			return -1;
		}
		if (head->heap[left].key < key && head->heap[right].key >= key)
			current = right;
		else
			current = left;
	}
}
void listMaxHeap(MaxHeap *head)
{
	int rootIndex = 1;
	inorderPrint(head, rootIndex);
}
void inorderPrint(MaxHeap *head, int current)
{
	if (!isNull(head, current))
	{
		inorderPrint(head, MHgoLeft(current));
		printf("%d ", head->heap[current].key);
		inorderPrint(head, MHgoRight(current));
	}
}
int MHgoLeft(int index)
{
	return index * 2;
}
int MHgoRight(int index)
{
	return (index * 2)+1;
}
int MHgoParent(int index)
{
	return index / 2;
}
int isNull(MaxHeap *head, int current)
{
	if (head->heap[current].key == 0)
		return 1;
	else
		return 0;
}