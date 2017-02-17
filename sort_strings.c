/*
    sort_strings.c
    Created by Alyxandra Spikerman on 1/31/17.
    Copyright © 2017 Computer Systems. All rights reserved.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

int main(int argc, const char * argv[]) {
    list* head = NULL; // declare an empty linked list
    char string[80];

    // insert values from stdin into a linked list
    while (fgets(string, 80, stdin) != NULL) {
        head = insertTail(head, string);
    }

    int length = countElement(head);
    char* string_arr[length]; // declare string array

    list* current = head;
    for(int j = 0; j < length; j++) {
        string_arr[j] = (char*)malloc(sizeof(char) * 80);
        strcpy(string_arr[j], current->data); // copy list into array
        current = current->next;
    }

    // destroy the list
    head = destroyList(head);
    // sort array
    qsort(string_arr, sizeof(string_arr)/sizeof(char*), sizeof(char*), compStrings);

    // print the sorted array
    for (int i = 0; i < length; i++) {
        printf("%s\n", string_arr[i]);
        free(string_arr[i]); // free the memory for the array
    }

    return 0;
}
