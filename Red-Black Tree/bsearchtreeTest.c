#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "testframework.h"
#include "bsearchtree.h"


int compileTest(){
    _assert(TRUE);
    return 0;
}

int makeNodeTest(){
    int data[2] = {1,0};
    _BTreeNode* Node = makeNode(0, data, sizeof(data));
    _assert(Node);
    _assert(Node->data);
    int* testdata = (int*)Node->data;
    _assert((testdata[0] == 1));
    _assert(testdata[1] == 0);

    int* mallocdata = calloc(4, sizeof(int));
    int mallocdatasize = 4*sizeof(int);
    mallocdata[0] = 1;
    mallocdata[1] = 1;
    mallocdata[2] = 1;
    mallocdata[3] = 1;
    free(Node);
    Node = makeNode(0, mallocdata, sizeof(mallocdatasize));
    _assert(Node);
    _assert(Node->data);
    testdata = (int*)Node->data;
    _assert(testdata[0] == 1);
    _assert(testdata[1] == 1);
    _assert(testdata[2] == 1);
    _assert(testdata[3] == 1);
    free(testdata);
    free(Node);
    
    return 0;
}
int makeTreeTest(){
    BTREE Tree = makeTree();
    int* testdata;
    int data[1] = {1};
    int data2[1] = {0};
    int data3[1] = {2};
    _assert(Tree);
    _assert(Tree->data == NULL);
    _assert(BTREE_insert(Tree, data, sizeof(data)));
    _assert(Tree->data != NULL);
    testdata = Tree->data;
    _assert(testdata[0] == 1);
    _assert(BTREE_insert(Tree, data2, sizeof(data)));
    _assert(Tree->left != NULL);
    testdata = Tree->left->data;
    _assert(testdata[0] == 0);
    _assert(BTREE_insert(Tree, data3, sizeof(data)));
    _assert(Tree->right != NULL);
    testdata = Tree->right->data;
    _assert(testdata[0] == 2);
    BTREE_destroy(Tree);
    return 0;
}
int insertTree321(){
    BTREE Tree = makeTree();
    int* testdata;
    int data[1] = {3};
    int data2[1] = {2};
    int data3[1] = {1};
    _assert(Tree);
    _assert(Tree->data == NULL);
    _assert(BTREE_insert(Tree, data, sizeof(data)));
    _assert(BTREE_insert(Tree, data2, sizeof(data)));
    _assert(BTREE_insert(Tree, data3, sizeof(data)));

    _assert(Tree->data != NULL);
    _assert(Tree->right != NULL);
    _assert(Tree->left != NULL);

    testdata = Tree->left->data;
    _assert(testdata[0] == 1);
    testdata = Tree->data;
    _assert(testdata[0] == 2);
    testdata = Tree->right->data;
    _assert(testdata[0] == 3);
    BTREE_destroy(Tree);
    return 0;
}
int insertTree417(){
    BTREE Tree = makeTree();
    int* testdata;
    int data[1] = {4};
    int data2[1] = {1};
    int data3[1] = {7};
    _assert(Tree);
    _assert(Tree->data == NULL);
    _assert(BTREE_insert(Tree, data, sizeof(data)));
    _assert(BTREE_insert(Tree, data2, sizeof(data)));
    _assert(BTREE_insert(Tree, data3, sizeof(data)));

    _assert(Tree->data != NULL);
    _assert(Tree->right != NULL);
    _assert(Tree->left != NULL);

    testdata = Tree->left->data;
    _assert(testdata[0] == 1);
    testdata = Tree->data;
    _assert(testdata[0] == 4);
    testdata = Tree->right->data;
    _assert(testdata[0] == 7);
    BTREE_destroy(Tree);
    return 0;
}
int insertTree3624157(){
    BTREE Tree = makeTree();
    int* testdata;
    int data[1] = {3};
    int data2[1] = {6};
    int data3[1] = {2};
    int data4[1] = {4};
    int data5[1] = {1};
    int data6[1] = {5};
    int data7[1] = {7};
    _assert(Tree);
    _assert(Tree->data == NULL);
    _assert(BTREE_insert(Tree, data, sizeof(data)));
    _assert(BTREE_insert(Tree, data2, sizeof(data)));
    _assert(BTREE_insert(Tree, data3, sizeof(data)));
    _assert(BTREE_insert(Tree, data4, sizeof(data)));
    _assert(BTREE_insert(Tree, data5, sizeof(data)));
    _assert(BTREE_insert(Tree, data6, sizeof(data)));
    _assert(BTREE_insert(Tree, data7, sizeof(data)));

    BTREE_fprintf(Tree, 1);

    _assert(Tree->data != NULL);
    _assert(Tree->left->left != NULL);
    _assert(Tree->left->right != NULL);
    _assert(Tree->right->left != NULL);
    _assert(Tree->right->right != NULL);
    _assert(Tree->right != NULL);
    _assert(Tree->left != NULL);
    

    return 0;
}
int all_tests() {
	_verify(compileTest);
	_verify(makeNodeTest);
	_verify(insertTree321);
	_verify(insertTree417);
	_verify(insertTree3624157);
	return 0;
}

int main(){
    testmain();
}