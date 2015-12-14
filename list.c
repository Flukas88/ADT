#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EL 5
#define STRING_SIZE 6

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
    return -1;
  }
  node *curr = head;
  while (curr->next != NULL) {
    printf("[%s]\t", curr->el);
    curr = curr->next;
  }
  printf("[%s]\n", curr->el);
  return 0;
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
  char *n = (char *)malloc(STRING_SIZE * sizeof(char));
  strcpy(n, pop(&head));
  printList(head);
  strcpy(n, pop(&head));
  printList(head);
#ifdef DEBUG
  printf("\nStarts freeing \n\n");
#endif
  free(n);
  freeList(head);
  return 0;
}
