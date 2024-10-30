#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
  printf("Write your Tests for your linked list implementation\n");
  list_t *mylist;
  mylist = list_alloc();
  list_print(mylist);
  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);
  list_print(mylist);
  list_add_to_front(mylist, 40);
  list_add_to_front(mylist, 50);
  list_add_to_front(mylist, 60);
  list_add_to_front(mylist, 70);
  list_add_to_front(mylist, 80);
  list_add_to_front(mylist, 90);
  list_add_to_front(mylist, 100);

  // if(strcmp("100->90->80->70->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  // {
  //       printf("list_add_to_front : FAILED\n");
  // }

  list_print(mylist);
  // list_remove_at_index(mylist, 3);
  list_print(mylist);

  // if(strcmp("100->90->70->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  // {
  //       printf("list_remove_at_index : FAILED\n");
  // }

  // list_remove_at_index(mylist, 20);
  list_print(mylist);
  // list_remove_at_index(mylist, 1);
  list_print(mylist);
  // list_remove_at_index(mylist, 6);
  list_print(mylist);

  // if(strcmp("90->80->60->50->30->20->10->NULL",listToString(mylist)) != 0)
  // {
  //       printf("list_remove_at_index : FAILED\n");
  // }
  

  // printf("The list length is %d\n", list_length(mylist));

  // list_add_to_back(mylist, 39);
  // list_print(mylist);
  // list_add_to_back(mylist, 18);
  // list_add_to_back(mylist, 42);
  // list_add_to_back(mylist, 190);
  // list_print(mylist);
  // list_free(mylist);
  // list_print(mylist);

  // list_add_to_front(mylist, 81);
  // list_add_to_back(mylist, 4);
  // list_add_to_front(mylist, 308);
  // list_add_to_back(mylist, 70);
  // list_add_to_front(mylist, 290);
  // list_print(mylist);
  // printf("The list length is %d\n", list_length(mylist));
  
  // list_add_at_index(mylist, 21, 1);
  // list_add_at_index(mylist, 65, 0);
  // list_add_at_index(mylist, 10, 8);
  // list_print(mylist);
  // list_add_at_index(mylist, 10, 7);
  // list_print(mylist);

  // list_remove_from_back(mylist);
  // list_print(mylist);
  // list_remove_from_front(mylist);
  // list_print(mylist);
  // list_remove_at_index(mylist, 3);
  // list_print(mylist);

  // printf("Is %d in the list?: %d\n", 21, list_is_in(mylist, 21));
  printf("Value at %d in the list?: %d\n", 3, list_get_elem_at(mylist, 3));
  printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(mylist, 5));
  printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  printf("Value at %d in the list?: %d\n", -2, list_get_elem_at(mylist, -2));
  printf("Value at %d in the list?: %d\n", 12, list_get_elem_at(mylist, 12));
  printf("Value at %d in the list?: %d\n", 7, list_get_elem_at(mylist, 7));
  printf("Index of %d?: %d\n", 70, list_get_index_of(mylist, 70));
  printf("Index of %d?: %d\n", 20, list_get_index_of(mylist, 20));
  printf("Index of %d?: %d\n", 0, list_get_index_of(mylist, 0));
  printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
  printf("Index of %d?: %d\n", 90, list_get_index_of(mylist, 90));
  // printf("Index of %d?: %d\n", 81, list_get_index_of(mylist, 81));
  
  // list_free(mylist);
  // list_add_at_index(mylist, -1, -1);
  // list_print(mylist);
  // list_add_at_index(mylist, -1, -1);
  // list_print(mylist);
  // list_add_at_index(mylist, 10, 0);
  // list_print(mylist);
  // list_add_at_index(mylist, 20, 1);
  // list_print(mylist);
  // list_free(mylist);
  // printf("The list length is %d\n", list_length(mylist));
  // list_print(mylist);

  // list_remove_from_back(mylist);
  // list_remove_from_front(mylist);
  // list_remove_at_index(mylist, -3);
  // list_remove_at_index(mylist, 0);
  // list_remove_at_index(mylist, 2);
  // list_add_to_front(mylist, 10);
  // list_add_to_front(mylist, 20);
  // list_add_to_front(mylist, 30);
  // list_add_to_front(mylist, 40);
  // list_add_to_front(mylist, 60);
  // list_add_at_index(mylist, 50, 1);
  // list_add_at_index(mylist, 0, 6);
  // list_add_at_index(mylist, 70, 0);
  // list_add_at_index(mylist, 80, 12);
  // list_print(mylist);

  // list_free(mylist);
  // list_free(mylist);
  // list_add_to_back(mylist, 100);
  // list_print(mylist);
  // list_remove_from_front(mylist);
  // list_print(mylist);
  // list_add_to_back(mylist, 13);  
  // list_print(mylist);
  // list_remove_from_back(mylist);
  // list_print(mylist);

  // list_add_to_front(mylist, 10);
  // list_add_to_front(mylist, 20);
  // list_add_to_front(mylist, 30);
  // list_add_to_front(mylist, 40);
  // list_add_to_front(mylist, 60);
  // list_print(mylist);
  // list_remove_at_index(mylist, 0);
  // list_print(mylist);
  // list_remove_at_index(mylist, -2);
  // list_print(mylist);
  // list_remove_at_index(mylist, 7);
  // list_print(mylist);
  // list_remove_at_index(mylist, 4);
  // list_print(mylist);

  // list_free(mylist);
  // list_print(mylist);
  // list_remove_at_index(mylist, 0);
  // list_print(mylist);
  // list_add_to_front(mylist, 60);
  // list_print(mylist);
  // list_remove_at_index(mylist, 1);
  // list_print(mylist);
  // list_add_to_front(mylist, 80);
  // list_print(mylist);
  // list_remove_at_index(mylist, 0);
  // list_print(mylist);

  // printf("Is %d in the list?: %d\n", 60, list_is_in(mylist, 60));
  // list_add_to_back(mylist, 50);
  // list_add_to_back(mylist, 60);
  // list_add_to_back(mylist, 70);
  // list_add_to_back(mylist, 80);
  // list_add_to_back(mylist, 90);
  // list_print(mylist);
  // printf("Is %d in the list?: %d\n", 30, list_is_in(mylist, 30));
  // printf("Is %d in the list?: %d\n", 60, list_is_in(mylist, 60));
  // printf("Is %d in the list?: %d\n", 80, list_is_in(mylist, 80));
  // list_add_to_back(mylist, 70);
  // list_print(mylist);
  // printf("Is %d in the list?: %d\n", 70, list_is_in(mylist, 70));
  
  // printf("The list length is %d\n", list_length(mylist));
  // printf("Value at %d in the list?: %d\n", -4, list_get_elem_at(mylist, -4));
  // printf("Value at %d in the list?: %d\n", 10, list_get_elem_at(mylist, 10));
  // printf("Value at %d in the list?: %d\n", 6, list_get_elem_at(mylist, 6));
  // printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(mylist, 5));
  // printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  // list_free(mylist);
  // list_print(mylist);
  // printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  // list_remove_at_index(mylist, 0);
  // printf("Is %d in the list?: %d\n", 21, list_is_in(mylist, 21));
  // printf("Index of %d?: %d\n", 21, list_get_index_of(mylist, 21));
  // list_add_to_front(mylist, 10);
  // list_add_to_front(mylist, 20);
  // list_add_to_front(mylist, 30);
  // list_add_to_front(mylist, 40);
  // list_add_to_front(mylist, 50);
  // list_print(mylist);
  // printf("Index of %d?: %d\n", 50, list_get_index_of(mylist, 50));
  // printf("Index of %d?: %d\n", 81, list_get_index_of(mylist, 81));
  // printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
  // printf("Index of %d?: %d\n", 30, list_get_index_of(mylist, 30));
  // list_add_to_front(mylist, 60);
  // list_print(mylist);
  // printf("Index of %d?: %d\n", 50, list_get_index_of(mylist, 50));
  // printf("Index of %d?: %d\n", 60, list_get_index_of(mylist, 60));
  // list_add_to_front(mylist, 10);
  // list_print(mylist);
  // printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
  // list_add_to_back(mylist, 40);
  // list_print(mylist);
  // printf("Index of %d?: %d\n", 40, list_get_index_of(mylist, 40));

printf("\nTesting list_add_to_back:\n");
list_add_to_back(mylist, 99);
list_print(mylist);

printf("\nTesting list_remove_from_back:\n");
list_remove_from_back(mylist);
list_print(mylist);

printf("\nTesting list_remove_from_front:\n");
list_remove_from_front(mylist);
list_print(mylist);

printf("\nTesting list_length:\n");
printf("The list length is %d\n", list_length(mylist));

printf("\nTesting list_add_at_index:\n");
list_add_at_index(mylist, 123, 2); // Adding to middle
list_add_at_index(mylist, 321, 0); // Adding to front
list_add_at_index(mylist, 789, list_length(mylist)); // Adding to back
list_print(mylist);

printf("\nTesting list_remove_at_index with various indices:\n");
// list_remove_at_index(mylist, -1); // Invalid index
// list_remove_at_index(mylist, 0); // Removing from front
// list_remove_at_index(mylist, list_length(mylist) - 1); // Removing from back
list_print(mylist);

printf("\nTesting list_is_in:\n");
int val = 123;
if (list_is_in(mylist, val)) {
    printf("%d is in the list.\n", val);
} else {
    printf("%d is not in the list.\n", val);
}

val = 999; // Non-existing value
if (list_is_in(mylist, val)) {
    printf("%d is in the list.\n", val);
} else {
    printf("%d is not in the list.\n", val);
}

printf("\nTesting list_get_elem_at with various indices:\n");
for (int i = -1; i <= list_length(mylist) + 1; i++) {
    printf("Value at %d in the list: %d\n", i, list_get_elem_at(mylist, i));
}

printf("\nTesting list_get_index_of:\n");
for (int i = 0; i < list_length(mylist); i++) {
    int elem = list_get_elem_at(mylist, i);
    printf("Index of %d: %d\n", elem, list_get_index_of(mylist, elem));
}

printf("\nFreeing the list:\n");
list_free(mylist);
list_print(mylist);

printf("\nTesting operations on an empty list:\n");
list_remove_from_front(mylist);
list_remove_from_back(mylist);
// list_remove_at_index(mylist, 2);
list_print(mylist);

printf("\nRebuilding the list:\n");
for (int i = 0; i < 10; i++) {
    list_add_to_front(mylist, i*10);
}
list_print(mylist);

printf("\nTesting list_length again:\n");
printf("The list length is %d\n", list_length(mylist));

printf("\nFreeing the list again:\n");
list_free(mylist);
list_print(mylist);
  return 0;
  
}