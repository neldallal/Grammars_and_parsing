/*
 * LCRSTree.c
 *
 *  Created on: Feb 10, 2022
 *      Author 1: claudiacortell
 *      Author 2: Nadine Eldallal
 *
 *
 */

/**
 * Code taken from Fundamentals of Computer Science by Alfred Aho and Jeffrey Ullman
 * Section 11.6 p. 619
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LCRSTree.h"



TREE makeNode0(char x);
TREE makeNode1(char x, TREE t);
TREE makeNode4(char x, TREE t1, TREE t2, TREE t3, TREE t4);



TREE makeNode0(char x){
	TREE root;
	root = (TREE) malloc(sizeof(struct NODE));
	root->label = x;
	root->leftmostChild = NULL;
	root->rightSibling = NULL;
	return root;
}

TREE makeNode1(char x, TREE t){
	TREE root;
	root = makeNode0(x);
	root->leftmostChild = t;
	return root;
}

TREE makeNode2(char x, TREE t1, TREE t2){
	TREE root;
	root = makeNode1(x, t1);
	t1->rightSibling = t2;
	return root;
}

TREE makeNode3(char x, TREE t1, TREE t2, TREE t3){
	TREE root;
	root = makeNode1(x, t1);
	t1->rightSibling = t2;
	t2->rightSibling = t3;
	return root;
}

TREE makeNode4(char x, TREE t1, TREE t2, TREE t3, TREE t4){
	TREE root;
	root = makeNode1(x, t1);
	t1->rightSibling = t2;
	t2->rightSibling = t3;
	t3->rightSibling = t4;
	return root;
}

void tree_free(TREE t){
	if (t == NULL){
		free(t);
		return;
	}
	tree_free(t->leftmostChild);
	tree_free(t->rightSibling);
}



void DFSPrint(int depth, TREE t){
	if (t == NULL){
		return;
	} else{
		for (int i = 1; i <= depth; i++){
			printf("   ");
		}
		printf("%c\n", t->label);
	}
	DFSPrint(depth+1, t->leftmostChild);
	DFSPrint(depth, t->rightSibling);
}
