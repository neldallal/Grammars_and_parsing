/*
 * RDParser.c
 *
 *  Created on: Feb 10, 2022
 *      Author 1: claudiacortell
 *      Author 2: Nadine Eldallal
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "RDParser.h"
#include "LCRSTree.h"



char*inputString;

void set_inputString(char* inputStr){
	inputString = inputStr;
}

char* return_inputString(){
	return inputString;
}

//⟨Expr ⟩ → ⟨Atomic⟩ ⟨ExprTail⟩
//labeled X in the trees
TREE Expr (){
    TREE firstA = Atomic();
    if (firstA != NULL) {
        TREE secondExpT = ExprTail();
        if (secondExpT != NULL) {
            return makeNode2('X', firstA, secondExpT);
        }
    }
	return NULL;
}

//⟨ExprTail⟩ → U ⟨Expr⟩ | ^ ⟨Expr⟩ | ϵ
//labeled R in the trees
TREE ExprTail(){
    if (*inputString == 'U') {
        inputString++;
        TREE firstExp = Expr();
        if (firstExp != NULL) {
            return makeNode2('R', makeNode0('U'), firstExp);
        }
    }
    else if (*inputString == '^') {
            inputString++;
            TREE secondExp = Expr();
            if (secondExp != NULL) {
                return makeNode2('R', makeNode0('^'), secondExp);
            }
    }
    else {
        return makeNode1('R', makeNode0('e')); //the empty string
    }
	return NULL;
}

//⟨Atomic⟩ → ( ⟨Expr ⟩ ) | ⟨Set⟩
//labeled A in the trees
TREE Atomic(){
    if (*inputString == '(') {
        inputString++;
        TREE firstExp = Expr();
        if (firstExp != NULL) {
            if (*inputString == ')') {
                inputString++;
                return makeNode3('A', makeNode0('('), firstExp, makeNode0(')'));
            }
        }
    }
    else if (*inputString != '(') {
        TREE secondSet = Set();
        if (secondSet != NULL) {
            return makeNode1('A', secondSet);
        }
    }
    else {
        return NULL;
    }
    return NULL;
}

//⟨Set⟩ → { ⟨SetTail⟩
//labeled S in the trees
TREE Set(){
	if(*inputString == '{'){
		inputString++;
		TREE firstST = SetTail();
		if (firstST != NULL){
			return makeNode2('S',makeNode0('{'), firstST);
		}
		return NULL;
	} else{
		return NULL;
	}
}

//⟨SetTail⟩ → } | ⟨Elements⟩ }
//labeled T in the trees
TREE SetTail(){
	if(*inputString == '}'){
        inputString++;
		return makeNode1('T', makeNode0('}'));
	}
    else if (*inputString != '}') {
        TREE firstElem = Elements();
        if (firstElem!= NULL){
            if (*inputString == '}') {
                inputString++;
                return makeNode2('T',firstElem, makeNode0('}'));
            }
        }
    }
    else {
        return NULL;
    }
	return NULL;
}

//⟨Elements⟩ → ⟨Element⟩ ⟨ElementsTail⟩
//labeled M in the trees
TREE Elements(){
	TREE firstE = Element();
	if (firstE!=NULL){
		TREE secondET = ElementsTail();
		if (secondET != NULL){
			return makeNode2('M',firstE,secondET);
		}
	}
	return NULL;
}

//⟨ElementsTail⟩ → , ⟨Elements⟩ | ϵ
//labeled L in the trees
TREE ElementsTail(){
	if(*inputString == ','){
		inputString++;
		TREE firstElements = Elements();
		if (firstElements != NULL){
			return makeNode2('L', makeNode0(','), firstElements);
		}
	} else if (*inputString!= ','){
		return makeNode1('L', makeNode0('e'));
	} else {
		return NULL;
	}
	return NULL;
}

//⟨Element⟩ → ⟨Number ⟩
//labeled E in the trees
TREE Element(){
	TREE firstElement = Number();
	if (firstElement != NULL){
		return makeNode1('E', firstElement);
	}
	return NULL;
}

//⟨Number ⟩ → ⟨Digit⟩ ⟨NumberTail⟩
//labeled N in the trees
TREE Number() {
	TREE firstDigit = Digit();
	if (firstDigit!=NULL){
		TREE secondNT = NumberTail();
		if (secondNT!= NULL){
			return makeNode2('N', firstDigit, secondNT);
		}
	}
	return NULL;
}

//⟨NumberTail⟩ → ⟨Number ⟩ | ϵ
//labeled B in the trees
TREE NumberTail(){
	TREE firstNT = Number();
	if (firstNT!=NULL){
		return makeNode1('B', firstNT);
	}
	if (checkDigit()==false){
		return makeNode1('B', makeNode0('e'));
	} else{
		return NULL;
	}
}

//⟨Digit⟩ → 0 | 1 | · · · | 9
//labeled D in the trees
TREE Digit(){
	//	printf("%s\n",inputString);
	if(*inputString == '0'){
		inputString++;
		return makeNode1(('D'), makeNode0('0'));
	} else if (*inputString == '1'){
		inputString++;
		return makeNode1(('D'), makeNode0('1'));
	} else if (*inputString == '2'){
		inputString++;
		return makeNode1(('D'), makeNode0('2'));
	} else if (*inputString == '3') {
		inputString++;
		return makeNode1(('D'), makeNode0('3'));
	} else if (*inputString == '4'){
		inputString++;
		return makeNode1(('D'), makeNode0('4'));
	} else if (*inputString == '5') {
		inputString++;
		return makeNode1(('D'), makeNode0('5'));
	} else if (*inputString == '6') {
		inputString++;
		return makeNode1(('D'), makeNode0('6'));
	} else if (*inputString == '7') {
		inputString++;
		return makeNode1(('D'), makeNode0('7'));
	} else if (*inputString == '8') {
		inputString++;
		return makeNode1(('D'), makeNode0('8'));
	} else if (*inputString == '9') {
		inputString++;
		return makeNode1(('D'), makeNode0('9'));
	} else{
		return NULL;
	}
}

bool checkDigit(){
	//check if its the end of a number
	if (*inputString!='0'|| *inputString!='1'|| *inputString!='2'|| *inputString!='3'|| *inputString!='4'|| *inputString!='5'
			|| *inputString!='6'|| *inputString!='7'|| *inputString!='8'|| *inputString!='9'){
		return false;
	}
	return true;


}


