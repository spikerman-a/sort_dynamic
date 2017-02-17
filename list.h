#ifndef LIST_H
#define LIST_H

// declares struct list
typedef struct list {
    char data[80];
    struct list* next;
} list;

void display(list* head); // prints out linked list
list* insertTail(list* head, char* data); // inserts node at tail
int countElement(list* head); // counts the # of elements
list* destroyList(list* head); // deletes the list
int compStrings(const void* a, const void* b); // compares string arrays

#endif
