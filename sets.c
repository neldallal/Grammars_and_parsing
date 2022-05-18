/*
 * sets.c
 *
 *  Created on: Feb 10, 2022
 *      Author 1: claudiacortell
 *      Author 2: Nadine Eldallal
 */

#include <stdio.h>
#include <stdlib.h>
#include "RDParser.h"
#include "LCRSTree.h"
#include "TDParser.h"
#include "ParsingTree.h"




int main(int argc, char *argv[]) {
	printf("Hello! Claudia and Nadine's CSC173 Project 2\n\n");
	TREE parseTree; /* holds the result of the parse */
	char *nextTerminal; /* current position in input string */
	printf("Running a Recursive-Descent Parser:\n");
	char* input = (char*) malloc(127*sizeof(char));
	do {
		printf("Enter an input (\"q\" to quit):");
		scanf("%s",input);
		if (input[0]!='q'||input[1]!=0){
			nextTerminal = input; /* in practice, a string of terminals would be read from input */
			set_inputString(nextTerminal);
			parseTree = Expr();
			char* x = return_inputString();
			if (parseTree == NULL || x[0] != 0){
				printf("This input is not accepted by the grammar.\n");
			} else{
				DFSPrint(1,parseTree);
			}
			tree_free(parseTree);
		}
	} while(input[0] != 'q'||input[1]!=0);
	free(input);
	printf("Finished running RD parser\n");

	printf("\nRunning a Table-Driven Parser:\n");
	char* input2 = (char*) malloc(127*sizeof(char));
	int** proTable = makeProdTable();
	int** parseTable = makeParsingTable();

	//prodTable_print(proTable, 26);
	//parseTable_print(parseTable, 11);
//	for (int k = 0; k < 11; k++){
//		printf("%c ", parseTable[k][128]);
//
//	}
	printf("\n");

	do {
		printf("Enter an input (\"q\" to quit):");
		scanf("%s",input2);
		if (input2[0]!='q'||input2[1]!=0){
			ParsingTree tdParseTree = runTDParser(proTable, parseTable, 11, input2);
			char* y = return_inString();

			if (tdParseTree == NULL || y[0] != 0){
				printf("\nThis input is not accepted by the grammar.\n");
			} else{
				print_with_depth(1,tdParseTree);
			}
			PT_free(tdParseTree);
		}
	} while(input2[0] != 'q'||input2[1]!=0);
	printf("Finished running TD parser\n");

	prodTable_free(proTable);
	parseTable_free(parseTable);
	free(input2);


}



