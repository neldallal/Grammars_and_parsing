/*
 * Created by nadin on 2/22/2022.
 *     Author 1: claudiacortell
 *     Author 2: Nadine Eldallal
 */

#ifndef PROJECT2_PARSINGTREE_H
#define PROJECT2_PARSINGTREE_H

#include <stdbool.h>

typedef struct Node* ParsingTree;
typedef struct Node* Node;

struct Node{
    char value;
    ParsingTree parent;
    ParsingTree leftChild;
    ParsingTree rightSibling;
};

extern ParsingTree new_Node(char value);
extern ParsingTree set_one_child(char value, Node n);
extern ParsingTree set_two_child(char v1,char v2, Node n);
extern ParsingTree set_three_child(char v1, char v2, char v3, Node n);
extern void PT_free(ParsingTree tree);
extern void print_with_depth(int depth, Node node);
extern char get_value(ParsingTree tree);
extern ParsingTree get_parent(ParsingTree tree);
extern ParsingTree get_child_with_value(char v, Node n);
extern ParsingTree get_rightSibling(ParsingTree tree);
extern ParsingTree get_root(ParsingTree tree);

#endif //PROJECT2_PARSINGTREE_H
