//
//  stackVsHeap.c
//  OOPExample
//
//  Created by Eliot Lash on 6/14/19.
//

#include "stackVsHeap.h"
#include <stdlib.h>

void passByValueFunc(int intPassedByValue, char charPassedByValue) {
    ++intPassedByValue;
    charPassedByValue = 'b';
    printf("passByValueFunc finished, intPassedByValue:%i, charPassedByValue:%c\n", intPassedByValue, charPassedByValue);
}

void passByReferenceFunc(int* intPassedByRef, char* charPassedByRef) {
    ++(*intPassedByRef);
    *charPassedByRef = 'b';
    printf("passByReferenceFunc finished, intPassedByRef:%i, charPassedByRef:%c\n", *intPassedByRef, *charPassedByRef);
}


int* stackVsHeap() {
    int stackInt;
    stackInt = 1;
    char stackChar;
    stackChar = 'a';
    
    passByValueFunc(stackInt, stackChar);
    
    printf("passByValueFunc called, stackInt:%i, stackChar:%c\n", stackInt, stackChar);
    
    passByReferenceFunc(&stackInt, &stackChar);
    
    printf("passByReferenceFunc called, stackInt:%i, stackChar:%c\n", stackInt, stackChar);
    
    int* heapInt = malloc(sizeof(int));
    char* heapChar = malloc(sizeof(char));
    *heapInt = 10;
    *heapChar = 'z';
    
    passByReferenceFunc(heapInt, heapChar);
    printf("passByReferenceFunc called, heapInt:%i, heapChar:%c\n", *heapInt, *heapChar);
    
    // Avoid leaking memory
    free(heapChar);
    heapChar = 0;
    
    // Caller is responsible for freeing memory for returned pointer
    return heapInt;
}
