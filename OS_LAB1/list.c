// list/list.c
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

list_t *list_alloc() { 
  list_t* mylist = (list_t *) malloc(sizeof(list_t)); 
  if(mylist == NULL) return NULL;  // check for failed memory allocation
  mylist->head = NULL;
  return mylist;
}

void list_free(list_t *l) {
    node_t* current = l->head;
    node_t* next;
    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(l);
}

void list_print(list_t *l) {
    node_t* current = l->head;
    while(current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int list_length(list_t *l) {
    int count = 0;
    node_t* current = l->head;
    while(current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void list_add_to_back(list_t *l, elem value) {
    node_t* new_node = (node_t *) malloc(sizeof(node_t));
    if(new_node == NULL) return;  // check for failed memory allocation
    new_node->value = value;
    new_node->next = NULL;
    
    if(l->head == NULL) {
        l->head = new_node;
    } else {
        node_t* current = l->head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void list_add_to_front(list_t *l, elem value) {
     node_t* cur_node = (node_t *) malloc(sizeof(node_t));
     if(cur_node == NULL) return;  // check for failed memory allocation
     cur_node->value = value;
     cur_node->next = l->head;
     l->head = cur_node; // you forgot to update the head pointer of the list
}

void list_add_at_index(list_t *l, elem value, int index) {
    if(index < 0 || index > list_length(l)) return;  // invalid index
    if(index == 0) {
        list_add_to_front(l, value);
        return;
    }

    node_t* new_node = (node_t *) malloc(sizeof(node_t));
    if(new_node == NULL) return;  // check for failed memory allocation
    new_node->value = value;

    node_t* current = l->head;
    for(int i = 0; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

elem list_remove_from_back(list_t *l) {
    if(l->head == NULL) return -1;  // empty list

    if(l->head->next == NULL) {  // only one element
        elem value = l->head->value;
        free(l->head);
        l->head = NULL;
        return value;
    }

    node_t* current = l->head;
    while(current->next->next != NULL) {
        current = current->next;
    }
    elem value = current->next->value;
    free(current->next);
    current->next = NULL;
    return value;
}

elem list_remove_from_front(list_t *l) {
    if(l->head == NULL) return -1;  // empty list

    node_t* to_delete = l->head;
    elem value = to_delete->value;
    l->head = l->head->next;
    free(to_delete);
    return value;
}

bool list_is_in(list_t *l, elem value) {
    node_t* current = l->head;
    while(current != NULL) {
        if(current->value == value) return true;
        current = current->next;
    }
    return false;
}

elem list_get_elem_at(list_t *l, int index) {
    if(index < 0 || index >= list_length(l)) return -1;

    node_t* current = l->head;
    for(int i = 0; i < index && current != NULL; i++) {
        current = current->next;
    }
    return current->value;
}

int list_get_index_of(list_t *l, elem value) {
    int index = 0;
    node_t* current = l->head;
    while(current != NULL) {
        if(current->value == value) return index;
        index++;
        current = current->next;
    }
    return -1;  // value not found
}