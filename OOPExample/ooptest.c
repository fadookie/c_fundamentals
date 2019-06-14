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

typedef struct {
    const char* id;
    inventoryItem inventory[2];
} inventoryGroup;

void printItem (inventoryItem this) {
    printf("inventoryItem { id:'%s' count:'%i' }", this.id, this.count);
}

void printGroup (inventoryGroup this) {
    printf("inventoryGroup { id:'%s' inventory: [\n", this.id);
    for (int i = 0; i < sizeof(this.inventory) / sizeof(inventoryItem); ++i) {
        printf("  ");
        printItem(this.inventory[i]);
        printf(",\n");
    }
    printf("]}\n");
}

void printGroups(inventoryGroup* groups, const int numGroups) {
    for (int groupIdx = 0; groupIdx < numGroups; ++groupIdx) {
        inventoryGroup group = groups[groupIdx];
        printGroup(group);
    }
}

void doOopTest() {
    puts("do OOP test");
    
    inventoryGroup groups[] = {
        {
            .id = "fruits",
            .inventory = {
                { .id = "apples", .count = 5 },
                { .id = "bananas", .count = 0 }
            }
        },
        {
            .id = "vegetables",
            .inventory = {
                { .id = "potatoes", .count = 4 },
                { .id = "carrots", .count = 2 }
            }
        },
    };
    const int numGroups = sizeof(groups) / sizeof(inventoryGroup);
    
    puts("Initial values:");
    printGroups(groups, numGroups);
    
    puts("\nCopy of fruit:");
    inventoryGroup groupCopy = groups[0];
    ++groupCopy.inventory[1].count;
    printGroup(groupCopy);
    
    puts("New values:");
    printGroups(groups, numGroups);
}
