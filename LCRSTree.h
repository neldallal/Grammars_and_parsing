/*
 * LCRSTree.h
 *
 *  Created on: Feb 10, 2022
 *      Author 1: claudiacortell
 *      Author 2: Nadine Eldallal
 */

/**
 * Code taken from Fundamentals of Computer Science by Alfred Aho and Jeffrey Ullman
 * Section 11.6 p. 619
 * */

#ifndef LCRSTREE_H_
#define LCRSTREE_H_

typedef struct NODE* TREE;
struct NODE {
	char label;
	TREE leftmostChild, rightSibling;
};

extern TREE makeNode0(char x);
extern TREE makeNode1(char x, TREE t);
extern TREE makeNode2(char x, TREE t1, TREE t2);
extern TREE makeNode3(char x, TREE t1, TREE t2, TREE t3);
extern TREE makeNode4(char x, TREE t1, TREE t2, TREE t3, TREE t4);
extern void tree_free(TREE t);
extern void DFSPrint(int depth, TREE t);


#endif /* LCRSTREE_H_ */
