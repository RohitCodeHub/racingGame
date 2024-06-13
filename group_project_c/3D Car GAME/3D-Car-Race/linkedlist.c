#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a list item
typedef struct ListItem {
    void* Data;
    struct ListItem* Next;
    struct ListItem* Prev;
} ListItem;

// Define the structure for the linked list
typedef struct {
    ListItem* Head;
    ListItem* Tail;
    int NoItems;
} gbpsLinkedList;

// Function prototypes
void EmptyList(gbpsLinkedList* List);
void FreeItem(ListItem* i);
void* PopItem(gbpsLinkedList* List);
int AddItem(gbpsLinkedList* List, void* Data);

void EmptyList(gbpsLinkedList* List) {
    ListItem* i;
    while ((i = PopItem(List)) != NULL) {
        FreeItem(i);
    }
}

void FreeItem(ListItem* i) {
    free(i);
}

void* PopItem(gbpsLinkedList* List) {
    void* Data;
    if (List->NoItems == 0) {
        return NULL;
    } else if (List->NoItems == 1) {
        Data = List->Head->Data;
        FreeItem(List->Head);
        List->Head = NULL;
        List->Tail = NULL;
        List->NoItems = 0;
        return Data;
    }
    Data = List->Head->Data;
    ListItem* temp = List->Head;
    List->Head = List->Head->Next;
    List->Head->Prev = NULL;
    FreeItem(temp);
    List->NoItems--;
    return Data;
}

int AddItem(gbpsLinkedList* List, void* Data) {
    ListItem* NewItem = (ListItem*)malloc(sizeof(ListItem));
    if (NewItem == NULL) {
        return -1; // Allocation failed
    }
    NewItem->Data = Data;
    NewItem->Next = NULL;
    NewItem->Prev = NULL;

    if (List->NoItems == 0) {
        List->Head = NewItem;
        List->Tail = NewItem;
    } else {
        NewItem->Prev = List->Tail;
        List->Tail->Next = NewItem;
        List->Tail = NewItem;
    }
    return ++List->NoItems;
}

void printList(gbpsLinkedList* List) {
    ListItem* current = List->Head;
    while (current != NULL) {
        printf("%s -> ", (char*)current->Data);
        current = current->Next;
    }
    printf("NULL\n");
}

int main() {
    printf("Welcome, Rohit Kumar!\n");

    gbpsLinkedList myList;
    myList.Head = NULL;
    myList.Tail = NULL;
    myList.NoItems = 0;

    AddItem(&myList, "Car1");
    AddItem(&myList, "Car2");
    AddItem(&myList, "Car3");

    printf("Initial list:\n");
    printList(&myList);

    printf("Popping item: %s\n", (char*)PopItem(&myList));
    printf("List after pop:\n");
    printList(&myList);

    EmptyList(&myList);
    printf("List after emptying:\n");
    printList(&myList);

    return 0;
}

