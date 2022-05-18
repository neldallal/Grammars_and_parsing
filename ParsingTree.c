/*
 * Created by nadin on 2/22/2022.
 *     Author 1: claudiacortell
 *     Author 2: Nadine Eldallal
 */


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "ParsingTree.h"

bool Node_isLeaf(Node node) {
    if(node->leftChild==NULL && node->rightSibling==NULL) {
        return true;
    }
    return false;
}

ParsingTree new_Node(char v) {
    ParsingTree new_node = (ParsingTree)malloc(sizeof(struct Node));
    new_node->value = v;
    new_node->parent = NULL;
    new_node->leftChild = NULL;
    new_node->rightSibling = NULL;

    return new_node;
}

extern ParsingTree set_one_child(char value, Node n) {
    ParsingTree currNode = new_Node(value);
    n->leftChild = currNode;
    currNode->parent = n;
    return n;
}

extern ParsingTree set_two_child(char v1,char v2, Node n) {
    ParsingTree currNode1 = new_Node(v1);
    ParsingTree currNode2 = new_Node(v2);
    n->leftChild = currNode1;
    currNode1->rightSibling = currNode2;
    currNode1->parent = n;
    currNode2->parent = n;
    return n;
}

extern ParsingTree set_three_child(char v1, char v2, char v3, Node n) {
    ParsingTree currNode1 = new_Node(v1);
    ParsingTree currNode2 = new_Node(v2);
    ParsingTree currNode3 = new_Node(v3);

    n->leftChild = currNode1;
    currNode1->rightSibling = currNode2;
    currNode2->rightSibling = currNode3;
    currNode1->parent = n;
    currNode2->parent = n;
    currNode3->parent = n;

    return n;
}


void PT_free(ParsingTree tree){
    if (tree == NULL){
        free(tree);
        return;
    }
    PT_free(tree->leftChild);
    PT_free(tree->rightSibling);
}


void print_with_depth(int d, Node n) {
    if (n==NULL) {
        return;
    }
    else {
        for(int i=1; i<=d; i++) {
            printf("   ");
        }
        printf("%c\n", n->value);
    }
    print_with_depth(d+1, n->leftChild);
    print_with_depth(d, n->rightSibling);
}

char get_value(ParsingTree tree) {
    if (tree != NULL) {
        return tree->value;
    }
    return 0;
}

ParsingTree get_parent(ParsingTree tree) {
    return tree->parent;
}

ParsingTree get_rightSibling(ParsingTree tree) {
    return tree->rightSibling;
}

ParsingTree get_root(ParsingTree tree) {
    while (get_parent(tree)!=NULL){
        tree = get_parent(tree);
    }
    return tree;
}

ParsingTree get_child_with_value(char v, Node n) {
    //iterate through the children of the node
    //if it matches the value with a child, return tree
    //else return null

    //traversing the tree
    ParsingTree temp = n->leftChild;
    if (get_value(temp)==v) {
        return temp;
    }
    while(temp->rightSibling!=NULL) {
        if (get_value(temp)==v) {
            return temp;
        }
        else {
            temp = temp->rightSibling;
        }
    }
    return NULL;
}
