/*
 * TDParser.h
 *
 *  Created on: Feb 20, 2022
 *      Author 1: claudiacortell
 *      Author 2: Nadine Eldallal
 */

#ifndef TDPARSER_H_
#define TDPARSER_H_

#include "ParsingTree.h"

extern char* return_inString();

extern int** makeProdTable ();
extern int** makeParsingTable ();

extern void prodTable_print(int**p, int numProductions);
extern void prodTable_free(int**p);

extern void parseTable_print(int**a, int numProductions);
extern void parseTable_free(int**a);

extern bool isASyntCat (int** parsingTable, int nSyntCat, char x);
ParsingTree runTDParser(int** productions, int** parsingTable, int numProductions, char* inpString);

#endif /* TDPARSER_H_ */
