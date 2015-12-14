#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_SIZE 6

typedef enum {ERROR=-1, OK=0} status;

typedef struct _node {
  struct _node *next;
  char *el;
} node;

node *push(node *head, char *el) {
  if (head == NULL) {
    node *first = (node *)malloc(sizeof(struct _node));
    first->el = (char *)malloc(STRING_SIZE * sizeof(char));
    strcpy(first->el, el);
    first->next = NULL;
#ifdef DEBUG
    printf("Element [%s] added as head\n", el);
#endif
    return first;
  }
  node *curr = head;
  while ((curr->next != NULL) && (curr != NULL)) {
    curr = curr->next;
  }
  node *tmp = (node *)malloc(sizeof(struct _node));
  tmp->el = (char *)malloc(STRING_SIZE * sizeof(char));
  strcpy(tmp->el, el);
  tmp->next = NULL;
  curr->next = tmp;
#ifdef DEBUG
  printf("Element [%s] added\n", el);
#endif
  return curr;
}

char *pop(node **head) {
  if ((*head) == NULL) {
    return NULL;
  }
  node *curr = (*head);
  char *ret = (char *)malloc(STRING_SIZE * sizeof(char));
#ifdef DEBUG
  printf("Popping element [%s] \n", curr->el);
#endif
  strcpy(ret, curr->el);
  (*head) = (*head)->next;
  free(curr->el);
  free(curr);
  return ret;
}

int printList(node *head) {
  if (head == NULL) {
    return ERROR;
  }
  node *curr = head;
  while (curr->next != NULL) {
    printf("[%s]\t", curr->el);
    curr = curr->next;
  }
  printf("[%s]\n", curr->el);
  return OK;
}

void freeList(node *head) {
  node *curr = head;
  node *tmp = NULL;
  while (curr != NULL) {
    tmp = curr;
#ifdef DEBUG
    printf("Freeing element [%s] \n", curr->el);
#endif
    curr = curr->next;
    free(tmp->el);
    free(tmp);
  }
}
#endif
