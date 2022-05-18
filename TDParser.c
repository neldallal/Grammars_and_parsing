/*
 * TDParser.c
 *
 *  Created on: Feb 20, 2022
 *      Author 1: claudiacortell
 *      Author 2: Nadine Eldallal
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "TDParser.h"
#include "ParsingTree.h"
#include "LinkedList.h"

char*inString;


char* return_inString(){
	return inString;
}

int** makeProdTable (){
	int** prodTable = (int**)malloc(26* sizeof(int*));
	for (int i = 0; i <26; i++){
		prodTable[i] = (int*)malloc(4 * sizeof(int));
	}

	for (int f = 0; f < 26; f++){
		for (int d = 0; d < 4; d++){
			prodTable[f][d] = -1;
		}
	}
	prodTable[0][0] = 'X';
	prodTable[0][1] = 'A';
	prodTable[0][2] = 'R';

	prodTable[1][0] = 'R';
	prodTable[1][1] = 'U';
	prodTable[1][2] = 'X';

	prodTable[2][0] = 'R';
	prodTable[2][1] = '^';
	prodTable[2][2] = 'X';

	prodTable[3][0] = 'R';

	prodTable[4][0] = 'A';
	prodTable[4][1] = '(';
	prodTable[4][2] = 'X';
	prodTable[4][3] = ')';

	prodTable[5][0] = 'A';
	prodTable[5][1] = 'S';

	prodTable[6][0] = 'S';
	prodTable[6][1] = '{';
	prodTable[6][2] = 'T';

	prodTable[7][0] = 'T';
	prodTable[7][1] = '}';

	prodTable[8][0] = 'T';
	prodTable[8][1] = 'M';
	prodTable[8][2] = '}';

	prodTable[9][0] = 'M';
	prodTable[9][1] = 'E';
	prodTable[9][2] = 'L';

	prodTable[10][0] = 'L';
	prodTable[10][1] = ',';
	prodTable[10][2] = 'M';

	prodTable[11][0] = 'L';

	prodTable[12][0] = 'E';
	prodTable[12][1] = 'N';

	prodTable[13][0] = 'N';
	prodTable[13][1] = 'D';
	prodTable[13][2] = 'B';

	prodTable[14][0] = 'B';
	prodTable[14][1] = 'N';

	prodTable[15][0] = 'B';

	prodTable[16][0] = 'D';
	prodTable[16][1] = '0';

	prodTable[17][0] = 'D';
	prodTable[17][1] = '1';

	prodTable[18][0] = 'D';
	prodTable[18][1] = '2';

	prodTable[19][0] = 'D';
	prodTable[19][1] = '3';

	prodTable[20][0] = 'D';
	prodTable[20][1] = '4';

	prodTable[21][0] = 'D';
	prodTable[21][1] = '5';

	prodTable[22][0] = 'D';
	prodTable[22][1] = '6';

	prodTable[23][0] = 'D';
	prodTable[23][1] = '7';

	prodTable[24][0] = 'D';
	prodTable[24][1] = '8';

	prodTable[25][0] = 'D';
	prodTable[25][1] = '9';

	return prodTable;
}

int** makeParsingTable (){
	int** pTable = (int**)malloc(11* sizeof(int*));
	for (int i = 0; i <11; i++){
		pTable[i] = (int*)malloc(129 * sizeof(int));
	}

	for (int f = 0; f < 11; f++){
		for (int d = 0; d < 129; d++){
			pTable[f][d] = -1;
		}
	}

	pTable[0][128] = 'X';
	pTable[0][123] = 0;
	pTable[0][40] = 0;

	pTable[1][128] = 'R';
	pTable[1][85] = 1;
	pTable[1][94] = 2;
	pTable[1][41] = 3;
	pTable[1][0] = 3;

	pTable[2][128] = 'A';
	pTable[2][123] = 5;
	pTable[2][40] = 4;

	pTable[3][128] = 'S';
	pTable[3][123] = 6;

	pTable[4][128] = 'T';
	pTable[4][48] = 8;
	pTable[4][49] = 8;
	pTable[4][50] = 8;
	pTable[4][51] = 8;
	pTable[4][52] = 8;
	pTable[4][53] = 8;
	pTable[4][54] = 8;
	pTable[4][55] = 8;
	pTable[4][56] = 8;
	pTable[4][57] = 8;
	pTable[4][125] = 7;

	pTable[5][128] = 'M';
	pTable[5][48] = 9;
	pTable[5][49] = 9;
	pTable[5][50] = 9;
	pTable[5][51] = 9;
	pTable[5][52] = 9;
	pTable[5][53] = 9;
	pTable[5][54] = 9;
	pTable[5][55] = 9;
	pTable[5][56] = 9;
	pTable[5][57] = 9;

	pTable[6][128] = 'L';
	pTable[6][44] = 10;
	pTable[6][125] = 11;

	pTable[7][128] = 'E';
	pTable[7][48] = 12;
	pTable[7][49] = 12;
	pTable[7][50] = 12;
	pTable[7][51] = 12;
	pTable[7][52] = 12;
	pTable[7][53] = 12;
	pTable[7][54] = 12;
	pTable[7][55] = 12;
	pTable[7][56] = 12;
	pTable[7][57] = 12;

	pTable[8][128] = 'N';
	pTable[8][48] = 13;
	pTable[8][49] = 13;
	pTable[8][50] = 13;
	pTable[8][51] = 13;
	pTable[8][52] = 13;
	pTable[8][53] = 13;
	pTable[8][54] = 13;
	pTable[8][55] = 13;
	pTable[8][56] = 13;
	pTable[8][57] = 13;

	pTable[9][128] = 'B';
	pTable[9][48] = 14;
	pTable[9][49] = 14;
	pTable[9][50] = 14;
	pTable[9][51] = 14;
	pTable[9][52] = 14;
	pTable[9][53] = 14;
	pTable[9][54] = 14;
	pTable[9][55] = 14;
	pTable[9][56] = 14;
	pTable[9][57] = 14;
	pTable[9][44] = 15;
	pTable[9][125] = 15;

	pTable[10][128] = 'D';
	pTable[10][48] = 16;
	pTable[10][49] = 17;
	pTable[10][50] = 18;
	pTable[10][51] = 19;
	pTable[10][52] = 20;
	pTable[10][53] = 21;
	pTable[10][54] = 22;
	pTable[10][55] = 23;
	pTable[10][56] = 24;
	pTable[10][57] = 25;

	return pTable;
}

void prodTable_print(int**p, int numProductions){
	printf("Printing Production Table:\n");
	for (int i = 0; i < numProductions; i++){
		printf("#%d: %c --> ", i, p[i][0]);
		for (int j = 1; j < 4; j++){
			if ((char)p[i][j]!= -1){
				printf("%c ", p[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

void prodTable_free(int** p){
	for (int i = 0; i < 25; i++){
		free(p[i]);
	}
	free(p);
}

void parseTable_print(int**a, int numSyntCat){
	printf("Printing Parsing Table:\n");
	for (int j = 0; j < numSyntCat; j++){
		printf("%c:  ",a[j][128]);
		for (int b = 0; b < 128; b++){
			printf("%d ", a[j][b]);
		}
		printf("\n");
	}
	printf("\n");
}

void parseTable_free(int**a){
	for (int i = 0; i < 11; i++){
		free(a[i]);
	}
	free(a);
}

bool isASyntCat (int** parsingTable, int nSyntCat, char x){
	for (int k = 0; k < nSyntCat; k++){
		if (x == parsingTable[k][128]){
			return true;
		}
	}

	return false;
}

ParsingTree runTDParser(int** productions, int** parsingTable, int nSyntCat, char* inpString){

	inString = inpString;
	LinkedList stack = new_LinkedList();
	//NOTE: top of the stack = front of linked list
	LinkedList_add_at_front(stack, &productions[0][0]);

	//create a tree root, have node = new_Node(productionsn[0][0];
	ParsingTree currNode = new_Node(productions[0][0]);


	while (LinkedList_isEmpty(stack) == false){
		char top = *((char *)LinkedList_pop(stack));


		//if currNode's value != the value on the top of the stack,
		if (top != get_value(currNode)){
			//set currNode equal to the child of currNode that's equal to the top of the stack
			currNode = get_child_with_value(top, currNode);

		}


//		printf("popped the top, top is %c\n", top);


		//if the top is a syntatic category:
		//push the symbols in the correct production in reverse order
		if (isASyntCat(parsingTable, nSyntCat, top) == true){
//			printf("the top of the stack IS A synt cat: ");

			int row;
			for (int k = 0; k < nSyntCat; k++){
				if (top == parsingTable[k][128]){
					row = k;
				}
			}
			int firstChar = *inString;
			int production = parsingTable[row][firstChar];
			//if the entry was initialized to -1, meaning no entry, FAIL
			if (production < 0){
//				printf("no entry in parsing table, FAIL\n");
				return NULL;
			} else{
//				printf("production chosen: %d\n", production);
				int* prodArray=(int*)malloc(4*sizeof(int));
				//copy the chars in the production table to another array
				int count = 0;
				for (int e = 1; e < 4; e++){
					prodArray[e] = productions[production][e];
					if (prodArray[e] != -1){
						count++;
					}
				}
				//add each production body as a child Node of currNnode
				if (count == 1){
					currNode = set_one_child (prodArray[1], currNode);
				} else if (count == 2){
					currNode = set_two_child (prodArray[1], prodArray[2], currNode);
				} else if (count == 3){
					currNode = set_three_child (prodArray[1], prodArray[2], prodArray[3], currNode);
				} else{ //if body empty, so the empty string
					currNode = set_one_child ('e', currNode);
				}

				void *temp;
				//char* pT = "";
				//adding the body of the production in right to left order
				for (int counter = 3; counter > 0; counter--){
					//add it to the linked list
					if (prodArray[counter] != -1){
						char t = prodArray[counter];
						char *pT = malloc(1*sizeof(char));
						pT[0] = t;
						temp = (void*)pT;
						LinkedList_add_at_front(stack, temp);
					}
				}


				if (count ==0){
					if (LinkedList_isEmpty(stack) == false){
						while (get_rightSibling(currNode)==NULL){
							currNode = get_parent(currNode);
						}
						//then, currNode = currNode->rightSibling
						currNode = get_rightSibling(currNode);
					}
				}



				free(prodArray);

			}


			//if the top is a terminal, try to match w/ input and consume, otherwise fail
		} else{
//			printf("the top of the stack IS A terminal: ");

			if (top == *inString){	//try to match
				inString++;	//consume
//				printf("MATCHED %c\n", top);


				//while currNode->rightSibling == NULL, currNode = currNode->parent

				while (get_rightSibling(currNode)==NULL){
					currNode = get_parent(currNode);
				}
				//then, currNode = currNode->rightSibling
				currNode = get_rightSibling(currNode);

			} else{
//				printf("char %c caused parser to FAIL\n", top);
				return NULL;	//FAIL
			}
		}

//		LinkedList_print_string_list(stack);
//		printf("\n");

	}

	currNode = get_root(currNode);

	LinkedList_free(stack, false);

	return currNode;

}




