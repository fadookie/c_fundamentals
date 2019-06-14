//
//  ooptest.c
//  OOPExample
//
//  Created by Eliot Lash on 6/14/19.
//

#include "ooptest.h"

typedef struct {
    const char* id;
    int count;
} inventoryItem;

void printStruct (inventoryItem this) {
    printf("inventoryItem { id:'%s' count:'%i' }\n", this.id, this.count);
}

void doOopTest() {
    puts("do OOP test");
    
    inventoryItem inventory[] = {
        { .id = "apples", .count = 5 },
        { .id = "bananas", .count = 3 }
    };
    for (int i = 0; i < sizeof(inventory) / sizeof(inventoryItem); ++i) {
        printStruct(inventory[i]);
    }
}
