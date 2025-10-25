#include <stdio.h>
#include <stdlib.h>

/*declaration what node's inside*/
typedef struct Node {
  int data;
  struct Node *next; //point to the next node
} Node;

/*declaration list with 2 pointer*/
typedef struct list {
  Node *pHead;
  Node *pTail;
} list;

/*create node*/
Node *createNode(int data) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

/*insert time*/
void insertTime(list *l, int data) {
  Node *newNode = createNode(data);
  if (!newNode) {
    return;
  }
  if (l->pHead == NULL) {
    l->pHead = newNode;
    l->pTail = newNode;
  } else {
    newNode->next = l->pTail;
    l->pTail = newNode;
  }  
}

/*for debug*/
void printAll(list *l) {
  Node *entry = l->pTail;
  while (entry) {
    printf("%d\n", entry->data);
    entry = entry->next;
  }  
}

/*delete all map*/
void removeList(list *l) {
  Node *pNode = NULL;
  while (l->pTail) {
    pNode = l->pTail;
    l->pTail = l->pTail->next;
    free(pNode);
  }
  l->pTail = NULL;
  l->pHead = NULL;
}

int main() {

  list l;
  
  //make sure create list without garbage value
  l.pHead = NULL;
  l.pTail = NULL;

  // insert time
  insertTime(&l, 4);
  insertTime(&l, 4);  
  printAll(&l);
  removeList(&l);
  
  return EXIT_SUCCESS;  
}  
