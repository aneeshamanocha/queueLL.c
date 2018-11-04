#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    char datum;
    struct list *nextPtr;
} List;

int purge(List ** head);
int pop(List ** head, List ** tail);
int push(List ** head, List ** tail, char datum);
char peek(List ** head);
int print(List ** head);

int main(void) {
  List *head = NULL;
  List *tail = NULL;

  push(&head, &tail, 'a');
  push(&head, &tail, 'b');
  push(&head, &tail, 'c');
  push(&head, &tail, 'p');
  push(&head, &tail, 'z');
  print(&head);
  printf("Peek: %c\n", peek(&head));

  pop(&head, &tail);
  pop(&head, &tail);
  pop(&head, &tail);
  print(&head);
  purge(&head);
}

int purge(List ** head) {
  if(*head ==  NULL) {
    //puts("its working");
    return 0;
  }
  //puts("hello");
  purge(&(*head)->nextPtr);
  free(*head);
  *head = NULL;
  return 0;
}

int pop(List ** head, List ** tail) {
  //check if list is empty
  if(*head == NULL) {
    return 1;
  }

  //check if one element
  if(*head == *tail){
    free(head);
    free(tail);
    return 1;
  }

  List *tmp = *head;
  *head = (*head)->nextPtr;
  free(tmp);

}

int push(List ** head, List ** tail, char datum){
  List *newNode = malloc(sizeof(List));

  //check if enough space
  if(newNode == NULL){
    return 1;
  }

  newNode->datum = datum;
  newNode->nextPtr = NULL;

  //if no list, create list
  if(*head == NULL) {
    //initially sets node
    *head = newNode;
    *tail = newNode;
    return 0;
  }

  //make new head & move tail
  (*tail)->nextPtr = newNode;
  *tail = newNode;

  return 0;
}

char peek(List ** head){
  return (*head)->datum;
}

int print(List ** head){
  //if starting head is null, don't print anything
  if(*head == NULL) {
    return 0;
  }

  //create temporary List
  List *tmp = *head;
  //print first element of list
  printf ("%c ",tmp->datum);
  while (tmp->nextPtr != NULL){
    //puts("hello");
    tmp = tmp->nextPtr;
    printf ("%c ",tmp->datum);
  }
  puts("");
  return 0;
}

/* add to beginning (head) & remove from end (tail)*/
