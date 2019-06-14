//
//  stringtest.c
//  OOPExample
//
//  Created by Eliot Lash on 6/14/19.
//

#include <string.h>
#include "stringtest.h"

void enumerateString(const char* str) {
    for (int i = 0; i < strlen(str); ++i) {
        printf("string[%i] : %c\n", i, str[i]);
    }
}

void doStringTest() {
    const char* helloWorld = "Hello, World!\n";
    char helloWorld2[] = "Hello World Char Array";
    char helloWorld3[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    
    //    printf(helloWorld);
    printf("\nhelloWorld: %s\n", helloWorld);
    enumerateString(helloWorld);
    
    printf("\nhelloWorld2: %s\n", helloWorld2);
    enumerateString(helloWorld2);
    
    printf("\nhelloWorld3: %s\n", helloWorld3);
    enumerateString(helloWorld3);
}
