//
//  main.c
//  OOPExample
//
//  Created by Eliot Lash on 6/14/19.
//

#include <stdio.h>
#include "stringtest.h"
#include "ooptest.h"
#include "stackVsHeap.h"

int main(int argc, const char * argv[]) {
    // insert code here...
//    doStringTest();

//    doOopTest();
    
    int* heapInt = stackVsHeap();
    printf("main got heapInt: %i\n", *heapInt);
    
    return 0;
}
