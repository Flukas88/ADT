#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#define MAX_EL 5

int main() {
  char first_element[] = "String0";
  node *head = push(NULL, first_element);
  printList(head);
  char text[] = "String1";
  for (int i = 1; i < MAX_EL; i++) {
    text[6] = i + '0';
    push(head, text);
    printList(head);
  }
#ifdef DEBUG
  printf("\nStarts with pop(ing)\n\n");
#endif
  char *n = calloc(sizeof(char), STRING_SIZE);
  strcpy(n, pop(&head));
  printList(head);
  strcpy(n, pop(&head));
  printList(head);
#ifdef DEBUG
  printf("\nStarts freeing \n\n");
#endif
  free(n);
  freeList(head);
  return OK;
}
