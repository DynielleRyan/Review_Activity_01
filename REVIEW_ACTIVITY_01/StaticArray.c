#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StaticArray.h"

void initList(List *list) {
    list->count = 0;
}

List newList() {
    List list;
    list.count = 0;
    return list;
}

void displayList(List list) {
    printf("List elements: ");
    for (int i = 0; i < list.count; i++) {
        printf("%d ", list.elems[i]);
    }
    printf("\n");
}

bool insertFront(List *list, DATA item) {
    if (list->count >= MAX) {
        return false;  
    }

 
    for (int i = list->count; i > 0; i--) {
        list->elems[i] = list->elems[i - 1];
    }

    list->elems[0] = item;
    list->count++;
    return true;
}

bool insertRear(List *list, DATA item) {
    if (list->count >= MAX) {
        return false;  
    }

    list->elems[list->count] = item;
    list->count++;
    return true;
}

bool insertSorted(List *list, DATA item) {
    if (list->count >= MAX) {
        return false;  
    }

    int i = list->count - 1;
    while (i >= 0 && list->elems[i] > item) {
        list->elems[i + 1] = list->elems[i];
        i--;
    }

    list->elems[i + 1] = item;
    list->count++;
    return true;
}

bool insertAt(List *list, DATA item, int loc) {
    if (list->count >= MAX || loc < 0 || loc > list->count) {
        return false;  
    }

    
    for (int i = list->count; i > loc; i--) {
        list->elems[i] = list->elems[i - 1];
    }

    list->elems[loc] = item;
    list->count++;
    return true;
}

bool searchItem(List list, DATA key) {
    for (int i = 0; i < list.count; i++) {
        if (list.elems[i] == key) {
            return true;  
    }

    return false;  
}

int getItem(List list, DATA key) {
    for (int i = 0; i < list.count; i++) {
        if (list.elems[i] == key) {
            return i;  
        }
    }

    return -1;  
}

bool deleteFront(List *list) {
    if (list->count <= 0) {
        return false;  
    }

    
