#include <stdio.h>
#include "dynamic_array.h"

int main() {
    
    List list = newList(5);

   
    initList(&list);

    
    insertFront(&list, 10);
    insertRear(&list, 20);
    insertSorted(&list, 15);
    insertAt(&list, 25, 2);

   
    displayList(list);

    
    DATA key = 20;
    bool found = searchItem(list, key);
    if (found) {
        printf("Item %d found in the list.\n", key);
    } else {
        printf("Item %d not found in the list.\n", key);
    }

    
    int index = getItem(list, 15);
    if (index != -1) {
        printf("Item 15 found at index %d in the list.\n", index);
    } else {
        printf("Item 15 not found in the list.\n");
    }

    deleteFront(&list);
    deleteRear(&list);
    int deletedItem = deleteAt(&list, 1);
    printf("Deleted item: %d\n", deletedItem);

   
    displayList(list);

    return 0;
}
