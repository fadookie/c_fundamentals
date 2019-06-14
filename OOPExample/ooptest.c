//
//  ooptest.c
//  OOPExample
//
//  Created by Eliot Lash on 6/14/19.
//

#include "ooptest.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

struct inventoryItem {
    const char* id;
    int count;
    struct inventoryItem* next;
};

typedef struct inventoryItem inventoryItem;

typedef struct {
    const char* id;
    inventoryItem* inventory;
} inventoryGroup;

// Creates a linked list from variadic struct arguments
inventoryItem* makeItemList(const int count, ...) {
    va_list args;
    va_start(args, count);
    inventoryItem *firstItem = 0; // First item in list
    inventoryItem *prevItem = 0; // Scratch variable for previous item in list
    
    // Loop over arguments
    for (int i = 0; i < count; ++i) {
        inventoryItem inputItem = va_arg(args, inventoryItem);
        
        // Allocate memory on the heap to store the input item
        inventoryItem *item = malloc(sizeof(inventoryItem));
        
        // Copy the input item from the stack to the heap
        memcpy(item, &inputItem, sizeof(*item));
        
        // Save pointer to first item if needed
        if (!firstItem) firstItem = item;
        
        // Set up linkage with previous item if needed
        if (prevItem) prevItem->next = item;
        prevItem = item;
    }
    va_end(args);
    
    // Return pointer to first item in list
    return firstItem;
}

void printItem (const inventoryItem* this) {
    printf("inventoryItem { id:'%s' count:'%i' }", this->id, this->count);
}

void printGroup (const inventoryGroup* this) {
    printf("inventoryGroup { id:'%s' inventory: [\n", this->id);
    for (inventoryItem* item = this->inventory; item != 0; item = item->next) {
        printf("  ");
        printItem(item);
        printf(",\n");
    }
    printf("]}\n");
}

void printGroups(const inventoryGroup* groups, const int numGroups) {
    for (int groupIdx = 0; groupIdx < numGroups; ++groupIdx) {
        const inventoryGroup* group = &groups[groupIdx];
        printGroup(group);
    }
}

void doOopTest() {
    puts("do OOP test");
    
    // Allocate & initialize some inventory groups on the stack
    inventoryGroup groups[] = {
        {
            .id = "fruits",
            // Groups can have different numbers of items in them so we can't allocate memory for them statically.
            // Allocate them on the heap instead using a linked list (a dynamic array would also work.)
            .inventory = makeItemList(
                2,
                (inventoryItem){ .id = "apples", .count = 5 },
                (inventoryItem){ .id = "bananas", .count = 0 }
            )
        },
        {
            .id = "vegetables",
            .inventory =  makeItemList(
                3,
                (inventoryItem){ .id = "potatoes", .count = 4 },
                (inventoryItem){ .id = "carrots", .count = 2 },
                (inventoryItem){ .id = "kohlrabi", .count = 9 }
            )
        },
    };
    const int numGroups = sizeof(groups) / sizeof(inventoryGroup); // groups.length would be too fancy for good old fashioned C!
    
    puts("Initial values:");
    printGroups(groups, numGroups);
    
    puts("\nCopy of fruit:");
    // Copy fruit group to a new location on the stack.
    inventoryGroup groupCopy = groups[0];
    // Mutate an item in our copy so we have 6 apples
    ++groupCopy.inventory->count;
    printGroup(&groupCopy);
    
    puts("\nNew values:");
    printGroups(groups, numGroups);
    
    // Whoops! We caused a mutation in the original since our copy was still pointing to the same item's memory address. To fix this we would need to implement a "deep copy" of all children.
    
    // In a real application you'd need to free the heap memory when you're done with these objects, or you will get a memory leak!
    // Also in a real application you should probably be using Rust or something.
}
