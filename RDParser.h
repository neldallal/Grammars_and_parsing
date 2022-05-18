/*
 * RDParser.h
 *
 *  Created on: Feb 10, 2022
 *      Author 1: claudiacortell
 *      Author 2: Nadine Eldallal
 */

#ifndef RDPARSER_H_
#define RDPARSER_H_

#include "LCRSTree.h"
#include <stdbool.h>

extern void set_inputString(char* inputStr);

extern char* return_inputString();

extern TREE Expr();

extern TREE ExprTail();

extern TREE Atomic();

extern TREE Set();

extern TREE SetTail();

extern TREE Elements();

extern TREE ElementsTail();

extern TREE Element();

extern TREE Number();

extern TREE NumberTail();

extern TREE Digit();

extern bool checkDigit();

#endif /* RDPARSER_H_ */
