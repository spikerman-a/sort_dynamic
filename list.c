#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

/*
    display: Prints the linked list to the terminal.
    @param head: pointer to first node of list
*/
void display(list* head){
    list* curr_node = head;
    while (curr_node != NULL) {
        printf("%s", curr_node->data);
        curr_node = curr_node->next;
    }
}

/*
    insertTail: Inserts a node to the list at the tail.
    @param head: pointer to first node of list
    @param val: character pointer to the value of the new node
*/
list* insertTail(list* head, char* val){
    list* new_node = (list*) malloc(sizeof(list));
    list* current;
    strcpy(new_node->data, val);

    // if the list is empty, insert at front
    if (head == NULL) {
        head = new_node;
        new_node->next = NULL;
    }
    // if the list is not empty, insert at tail
    else {
        current = head;
        new_node->next = NULL;
        while (1) {
            if (current->next == NULL) {
                current->next = new_node;
                break;
            }
            current = current->next;
        }
    }
    return head;
}

/*
    countElement: Counts the number of elements in the linked list.
    @param head: pointer to first node of list
*/
int countElement(list* head){
    int elements = 0;

    while (head != NULL) {
        elements++;
        head = head->next;
    }

    return elements;
}

/*
    destroyList: Destroys the entire list.
    @param head: pointer to first node of list
*/
list* destroyList(list* head){
    list* del_node;
    del_node = head;
    list* next_node = head->next;

    while (del_node != NULL) {
        next_node = del_node->next;
        free(del_node);
        del_node = next_node;
    }

    head = del_node;
    return head;
}

/*
    compStrings: Compares two string arrays.
    Function for qsort.
*/
int compStrings(const void* a, const void* b) {
    const char** aa = (const char**) a;
    const char** bb = (const char**) b;
    return strcmp(*aa, *bb);
}
